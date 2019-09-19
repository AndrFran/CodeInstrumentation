#include "pch.h"
#include "SyntaxTree.h"
#include "FlowGraphNode.h"
#include "rapidjson-master/include/rapidjson/document.h"
#include "ValuableCopible.h"
#include <iostream>
using namespace rapidjson;
namespace WpfApplication2
{

int SyntaxTree::Id = 0;

	std::vector<FlowGraphNode*> SyntaxTree::getGlobalScope() const
	{
		return privateGlobalScope;
	}

	void SyntaxTree::setGlobalScope(const std::vector<FlowGraphNode*> &value)
	{
		privateGlobalScope = value;
	}

	SyntaxTree::SyntaxTree()
	{
		InitializeInstanceFields();
		Id = 0;
		globals = std::vector<ValueCopibable>();
		functions = std::vector<ValueCopibable>();
		ParsedFunctions = std::vector<Function*>();
		setGlobalScope(std::vector<FlowGraphNode*>());
	}

	std::vector<std::string> SyntaxTree::Create(ValueCopibable dic)
	{
		std::vector<std::string> names = std::vector<std::string>();
		std::vector<ValueCopibable> * val = new std::vector<ValueCopibable>();
	    Value & a = dic["ext"];
		assert(a.IsArray());
		for (auto& v : a.GetArray())
		{
			std::cout << v["_nodetype"].GetString() << "\n";
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':

			if (std::string("FuncDef") == v["_nodetype"].GetString())
			{
				std::cout << (v["decl"].GetObject())["name"].GetString()<< "\n";
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
				names.push_back((v["decl"].GetObject())["name"].GetString());
				this->functions.push_back(v);
			}
			else
			{
				globals.push_back(v);
			}
		}
		for (auto glob : globals)
		{
			getGlobalScope().push_back(ParseNode(glob));
		}
		return names;
	}


	std::vector<Function*> SyntaxTree::GetFunctionByNames(std::vector<std::string> &names)
	{
		std::vector<Function*> functions = std::vector<Function*>();
		for (auto func : this->ParsedFunctions)
		{
			if (std::find(names.begin(), names.end(), func->getname()) != names.end())
			{
				functions.push_back(func);
			}
		}
		return functions;
	}

	void SyntaxTree::ParseFunctions()
	{
		for (int i = 0;i < this->functions.size();i++)
		{
			CreateFlowControlGraph(i);
		}
	}

	std::vector<FlowGraphNode*> SyntaxTree::CreateFlowControlGraph(int id)
	{
		if (graph.size() > 0)
		{
		graph.clear();
		}
		Function *func = new Function();

//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		func->setname((this->functions[id]["decl"].GetObject())["name"].GetString());


		ValueCopibable type = ((this->functions[id]["decl"]));

		func->setreturntype(static_cast<DeclNode*>(ParseDeclaration(type)));

		// get function body set
		Value & a = (this->functions[id]["body"]).GetObject()["block_items"];
		assert(a.IsArray());
		// recursive parse function body
		for (auto& v : a.GetArray())
		{
			func->getnodes()->push_back(ParseNode(v));
		}
		
		if (NodeType::E_RETURN != (*func->getnodes())[func->getnodes()->size() - 1]->getNodeType())
		{
			ReturnNode *node = new ReturnNode(Id++);
			func->getnodes()->push_back(node);
		}
		Value & tmp = ((this->functions[id]["decl"]).GetObject()["type"]).GetObject()["args"];

		if (!tmp.IsNull())
		{
			if (tmp.HasMember("params"))
			{
				Value & prameters = tmp["params"];
				assert(prameters.IsArray());
				for (auto& v : prameters.GetArray())
				{
					func->AddParam(static_cast<DeclNode*>(ParseDeclaration(v)));
				}
			}
		}
		ParsedFunctions.push_back(func);
		return *func->getnodes();
	}

	FlowGraphNode *SyntaxTree::ParseNode(ValueCopibable item)
	{
//C# TO C++ CONVERTER NOTE: The variable NodeType was renamed since it is named the same as a user-defined type:
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		std::string NodeType_Renamed = item["_nodetype"].GetString();
		FlowGraphNode *node = nullptr;
		if (std::string("Decl") == NodeType_Renamed)
		{
			node = ParseDeclaration(item);
		}
		if (std::string("FuncCall") == NodeType_Renamed)
		{
			node = ParseFuncCall(item);
		}
		if (std::string("If") == NodeType_Renamed)
		{
			node = ParseIf(item);
		}
		if (std::string("Constant") == NodeType_Renamed)
		{
			node = ParseConstant(item);
		}
		if (std::string("ArrayRef") == NodeType_Renamed)
		{
			node = ParseArrayRef(item);
		}
		if (std::string("ID") == NodeType_Renamed)
		{
			node = ParseID(item);
		}
		if (std::string("BinaryOp") == NodeType_Renamed)
		{
			node = ParseBinOp(item);
		}
		if (std::string("UnaryOp") == NodeType_Renamed)
		{
			node = ParseUnaryOp(item);
		}
		if (std::string("Assignment") == NodeType_Renamed)
		{
			node = ParseAssigmet(item);
		}
		if (std::string("Return") == NodeType_Renamed)
		{
			node = ParseReturn(item);
		}
		if (std::string("While") == NodeType_Renamed)
		{
			node = ParseWhile(item);
		}
		if (std::string("For") == NodeType_Renamed)
		{
			node = ParseFor(item);
		}
		if (std::string("Typedef") == NodeType_Renamed)
		{
			node = ParseTypeDef(item);
		}
		if (std::string("TypeDecl") == NodeType_Renamed)
		{
			node = ParseTypeDecl(item);
		}
		if (std::string("Enum") == NodeType_Renamed)
		{
			node = ParseEnum(item);
		}
		if (std::string("Enumerator") == NodeType_Renamed)
		{
			node = ParseEnumValue(item);
		}
		if (std::string("Struct") == NodeType_Renamed)
		{
			node = ParseStruct(item);
		}
		if (std::string("StructRef") == NodeType_Renamed)
		{
			node = ParseStructRef(item);
		}
		if (std::string("Typename") == NodeType_Renamed)
		{
			node = ParseTypeName(item);
		}
		if (std::string("IdentifierType") == NodeType_Renamed)
		{
			node = ParseTypeDeclIdentifierType(item);
		}

		if (node != nullptr && !item.IsNull())
		{
			if (item.HasMember("coord"))
			{
				if (item["coord"].IsString())
				{
					node->setNodeLocation(item["coord"].GetString());
				}
			}
		}
		return node;
	}

	FlowGraphNode *SyntaxTree::ParseTypeDeclIdentifierType(ValueCopibable item)
	{
		TypeDeclIdentifierType *node = new TypeDeclIdentifierType(Id++);
		std::string *str = new std::string();

		Value & type1 = (item["names"]);
		for (int i = 0; i < type1.GetArray().Size(); i++)
		{
			if (i == type1.GetArray().Size() - 1)
			{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
				*str+=(type1.GetArray()[i].GetString());
			}
			else
			{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
				*str+=(type1.GetArray()[i].GetString() + std::string(" "));
			}
		}
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		node->name = *str;
		return node;
	}

	FlowGraphNode* SyntaxTree::ParseDeclaration(ValueCopibable item)
	{
		DeclNode *node = new DeclNode(Id++);
		ValueCopibable type;
		if (item.HasMember("name"))
		{
			if (item["name"].IsNull() == false)
			{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
			node->setDeclName(item["name"].GetString());
			}
		}
		if (item.HasMember("init"))
		{
			if (item["init"].IsNull())
			{
				node->setisInited(false);
			}
			else
			{
				node->setisInited(true);
			}
		}
		do
		{
			std::string var;
			if (item.HasMember("type"))
			{
				if (type.IsNull() == true)
				{
					type = (item["type"]);
				}
				else
				{
					type = (type["type"]);
				}
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
				var = type["_nodetype"].GetString();

			}
			else
			{
				type = item;
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
				var = item["_nodetype"].GetString();
			}
				if (std::string("ArrayDecl") == var)
				{
				node->setArrayLevel(node->getArrayLevel() + 1);
				node->setisArray(true);
				}
			if (std::string("PtrDecl") == var)
			{
				node->setPointerLevel(node->getPointerLevel() + 1);
				node->setisPointer(true);
			}
			if (std::string("TypeDecl") == var)
			{

			}
			if (std::string("IdentifierType") == var)
			{
				std::string *str = new std::string;

				ValueCopibable type1 =type["names"];
				assert(type1.IsArray());
				for (int i = 0; i < type1.GetArray().Size(); i++)
				{
					if (i == type1.GetArray().Size() - 1)
					{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
						*str+=(type1.GetArray()[i].GetString());
					}
					else
					{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
						*str+=(type1.GetArray()[i].GetString() + std::string(" "));
					}
				}
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
				node->setDeclType(*str);
			}
		} while (type.HasMember("type"));

		return node;
	}

	FlowGraphNode *SyntaxTree::ParseFuncCall(ValueCopibable item)
	{
		FuncCallNode *node = new FuncCallNode(Id++);
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		node->setFunctionName((item["name"].GetObject())["name"].GetString());
		ValueCopibable arguments = (item["args"].GetObject())["exprs"];
		std::vector<FlowGraphNode*> args = std::vector<FlowGraphNode*>();
		for (auto & argument : arguments.GetArray())
		{
			args.push_back(ParseNode(argument));
		}
		node->setargs(args);
		return node;

	}

	FlowGraphNode *SyntaxTree::ParseConstant(ValueCopibable item)
	{
		ConstantNode *node = new ConstantNode(Id++);
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		node->setValType(item["type"].GetString());
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		node->setValue(item["value"].GetString());
		return node;
	}

	FlowGraphNode *SyntaxTree::ParseID(ValueCopibable item)
	{
		ID *node = new ID(Id++);
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		node->setName(item["name"].GetString());
		return node;
	}

	FlowGraphNode *SyntaxTree::ParseArrayRef(ValueCopibable item)
	{
		ArrayRef *node = new ArrayRef(Id++);
		node->setName(ParseNode((item["name"])));
		node->setindex(ParseNode(((item["subscript"]))));
		return node;
	}

	FlowGraphNode *SyntaxTree::ParseStructRef(ValueCopibable item)
	{
		StructRef *node = new StructRef(Id++);
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		node->setreftype(item["type"].GetString());
		node->setstructfield(ParseNode(((item["field"]))));
		node->setstructname(ParseNode(((item["name"]))));
		return node;
	}

	FlowGraphNode *SyntaxTree::ParseBinOp(ValueCopibable item)
	{
		BinaryOp *node = new BinaryOp(Id++);
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		node->setOP(item["op"].GetString());
		node->left = ParseNode(((item["left"])));
		node->right = ParseNode(((item["right"])));
		return node;
	}

	FlowGraphNode *SyntaxTree::ParseAssigmet(ValueCopibable item)
	{
		OperationNode *node = new OperationNode(Id++);
		node->setleft(ParseNode(((item["lvalue"]))));
		node->setright(ParseNode(((item["rvalue"]))));
		return node;
	}

	FlowGraphNode *SyntaxTree::ParseUnaryOp(ValueCopibable item)
	{
		UnaryOp *node = new UnaryOp(Id++);
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		node->setOP(item["op"].GetString());
		ValueCopibable tmp = (item["expr"]);
			if (tmp.HasMember("expr"))
			{
			node->left = ParseNode(((tmp["expr"])));
			}
		else
		{
			node->left = ParseNode(((item["expr"])));
		}
		return node;
	}

	FlowGraphNode *SyntaxTree::ParseCast(ValueCopibable item)
	{
		Cast *node = new Cast(Id++);
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		node->setOP(item["op"].GetString());
		ValueCopibable tmp = (item["expr"]);
		if (tmp.HasMember("expr"))
		{
			node->expr = ParseNode(((tmp["expr"])));
		}
		else
		{
			node->expr = ParseNode(((item["expr"])));
		}
		node->typetocast = ParseNode(((item["to_type"])));
		return node;
	}

	FlowGraphNode *SyntaxTree::ParseTypeDef(ValueCopibable item)
	{
		TypeDef *node = new TypeDef(Id++);
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		node->name = item["name"].GetString();
		node->TypeDecl_Renamed = ParseNode(((item["type"])));
		return node;
	}

	FlowGraphNode *SyntaxTree::ParseTypeDecl(ValueCopibable item)
	{
		TypeDecl *node = new TypeDecl(Id++);
		if (item.HasMember("name"))
		{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
			node->name = item["name"].GetString();
		}
			node->Type = ParseNode(((item["type"])));
		return node;
	}

	FlowGraphNode *SyntaxTree::ParseTypeName(ValueCopibable item)
	{
		TypeName *node = new TypeName(Id++);
		node->Type = ParseNode(((item["type"])));
		return node;
	}

	FlowGraphNode *SyntaxTree::ParseStruct(ValueCopibable item)
	{
		StructNode *node = new StructNode(Id++);
		node->Decl = std::vector<FlowGraphNode*>();
		Value & a = item["decls"];
		assert(a.IsArray());
		for (auto &decl : a.GetArray())
		{
			node->Decl.push_back(ParseNode(decl));
		}
		return node;
	}

	FlowGraphNode *SyntaxTree::ParseEnum(ValueCopibable item)
	{
		EnumNode *node = new EnumNode(Id++);
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		node->name = item["name"].GetString();
		node->Values = std::vector<FlowGraphNode*>();
		ValueCopibable values = ((item["values"]))["enumerators"];
		for (auto &val : values.GetArray())
		{
			node->Values.push_back(ParseNode(val));
		}
		return node;
	}

	FlowGraphNode *SyntaxTree::ParseEnumValue(ValueCopibable item)
	{
		EnumNode *node = new EnumNode(Id++);
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		node->name = item["name"].GetString();
		return node;
	}

	FlowGraphNode *SyntaxTree::ParseReturn(ValueCopibable item)
	{
		ReturnNode *node = new ReturnNode(Id++);
		if (!item["expr"].IsNull())
		{
		node->expr = ParseNode(((item["expr"])));
		}
		return node;
	}

	FlowGraphNode *SyntaxTree::ParseIf(ValueCopibable item)
	{
		IfNode *node = new IfNode(Id++);
		std::vector<FlowGraphNode*> left = std::vector<FlowGraphNode*>();
		std::vector<FlowGraphNode*> right = std::vector<FlowGraphNode*>();
		ValueCopibable leftarr = (item["iffalse"]);
		ValueCopibable rightarr = (item["iftrue"]);
		if (!leftarr.IsNull())
		{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
			if (std::string("Compound") == leftarr["_nodetype"].GetString())
			{
				ValueCopibable  functionflow = leftarr["block_items"];
				if (functionflow.IsNull() == false)
				{
					for (auto &argument : functionflow.GetArray())
					{
						left.push_back(ParseNode(argument));
					}
				}
			}
			else
			{
				left.push_back(ParseNode(leftarr));
			}
		}
		if (!rightarr.IsNull())
		{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
			if (std::string("Compound") == rightarr["_nodetype"].GetString())
			{
				ValueCopibable  functionflow =(rightarr["block_items"]);
				if (functionflow.IsNull() == false)
				{
					for (auto & argument : functionflow.GetArray())
					{
						right.push_back(ParseNode(argument));
					}
				}
			}
			else
			{
				right.push_back(ParseNode(rightarr));
			}
		}
		node->setleft(left);
		node->setright(right);
		node->setcondition(ParseNode((item["cond"])));
		return node;
	}

	void SyntaxTree::addNewNode(FlowGraphNode *node)
	{
			graph.push_back(node);
	}

	FlowGraphNode *SyntaxTree::ParseWhile(ValueCopibable item)
	{
		WhileNode *node = new WhileNode(Id++);
		std::vector<FlowGraphNode*> stmt = std::vector<FlowGraphNode*>();
		ValueCopibable leftarr = item["stmt"];
		if (!leftarr.IsNull())
		{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
			if (std::string("Compound") == leftarr["_nodetype"].GetString())
			{
				ValueCopibable  functionflow = leftarr["block_items"];
				if (functionflow.IsNull() == false)
				{
					for (auto & argument : functionflow.GetArray())
					{
						stmt.push_back(ParseNode(argument));
					}
				}
			}
			else
			{
				stmt.push_back(ParseNode(leftarr));
			}
		}

		node->setloop(stmt);
		node->setcondition(ParseNode((item["cond"])));
		return node;
	}

	FlowGraphNode *SyntaxTree::ParseFor(ValueCopibable item)
	{
		ForNode *node = new ForNode(Id++);
		std::vector<FlowGraphNode*> stmt = std::vector<FlowGraphNode*>();
		ValueCopibable leftarr =(item["stmt"]);
		if (!leftarr.IsNull())
		{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
			if (std::string("Compound") == leftarr["_nodetype"].GetString())
			{
				ValueCopibable  functionflow = leftarr["block_items"];
				if (functionflow.IsNull() == false)
				{
					for (auto &argument : functionflow.GetArray())
					{
						stmt.push_back(ParseNode(argument));
					}
				}
			}
			else
			{
				stmt.push_back(ParseNode(leftarr));
			}
		}

		node->setloop(stmt);
			if (!item["cond"].IsNull())
			{
		node->setcondition(ParseNode((item["cond"])));
			}
			if (!item["init"].IsNull())
			{
				node->setinit(ParseNode((item["init"])));
			}
			if (!item["next"].IsNull())
			{
				node->setnext(ParseNode((item["next"])));
			}
			return node;
	}

	void SyntaxTree::InitializeInstanceFields()
	{
		graph = std::vector<FlowGraphNode*>();
	}

	DeclNode *Function::getreturntype() const
	{
		return privatereturntype;
	}

	void Function::setreturntype(DeclNode *value)
	{
		privatereturntype = value;
	}

	std::vector<FlowGraphNode*> * Function::getnodes()
	{
		return &privatenodes;
	}

	std::vector<FlowGraphNode*>  Function::getNodeswithCopy()
	{
		return privatenodes;
	}
	void Function::setnodes(const std::vector<FlowGraphNode*> &value)
	{
		privatenodes = value;
	}

	const std::string &Function::getname() const
	{
		return privatename;
	}

	void Function::setname(const std::string &value)
	{
		privatename = value;
	}

	void Function::AddParam(DeclNode *var)
	{
		parametrs.push_back(var);
	}

	std::vector<DeclNode*> Function::Getparams()
	{
		return this->parametrs;
	}

	Function::Function()
	{
		parametrs = std::vector<DeclNode*>();
		setnodes(std::vector<FlowGraphNode*>());
	}

	void Operation::Oparation()
	{

	}
}
