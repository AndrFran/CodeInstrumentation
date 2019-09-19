#include "pch.h"
#include "FlowGraphNode.h"


namespace WpfApplication2
{

	void FlowGraphNode::setNodeLocation(const std::string rStr)
	{
		strNodeLocation = rStr;
	}

	std::string FlowGraphNode::getNodeLocation() const
	{
		return strNodeLocation;
	}

	FlowGraphNode* OperationNode::getleft()
	{
		return privateleft;
	}

	void OperationNode::setleft(FlowGraphNode *value)
	{
		privateleft = value;
	}

	FlowGraphNode *OperationNode::getright()
	{
		return privateright;
	}

	void OperationNode::setright(FlowGraphNode *value)
	{
		privateright = value;
	}

	OperationNode::OperationNode(int id)
	{
		InitializeInstanceFields();
		this->type = NodeType::E_ASSIGMENT;
		this->id = id;
	}

	NodeType OperationNode::getNodeType()
	{
		return this->type;
	}

	void OperationNode::setNodeType(NodeType type)
	{
		this->type = type;
	}

	std::string OperationNode::ToString()
	{
		return this->getleft()->ToString() + std::string("=") + this->getright()->ToString();
	}

	int OperationNode::getId()
	{
		return this->id;
	}

	void OperationNode::InitializeInstanceFields()
	{
		id = 0;
		type = (WpfApplication2::NodeType)0;
	}

	DeclNode::DeclNode(int id)
	{
		InitializeInstanceFields();
		this->id = id;
		this->settype(NodeType::E_DECL);
		this->setArrayLevel(0);
		this->setPointerLevel(0);
	}

	const NodeType &DeclNode::gettype() const
	{
		return privatetype;
	}

	void DeclNode::settype(const NodeType &value)
	{
		privatetype = value;
	}

	const int &DeclNode::getArrayLevel() const
	{
		return privateArrayLevel;
	}

	void DeclNode::setArrayLevel(const int &value)
	{
		privateArrayLevel = value;
	}

	const int &DeclNode::getPointerLevel() const
	{
		return privatePointerLevel;
	}

	void DeclNode::setPointerLevel(const int &value)
	{
		privatePointerLevel = value;
	}

	const bool &DeclNode::getisArray() const
	{
		return privateisArray;
	}

	void DeclNode::setisArray(const bool &value)
	{
		privateisArray = value;
	}

	const bool &DeclNode::getisPointer() const
	{
		return privateisPointer;
	}

	void DeclNode::setisPointer(const bool &value)
	{
		privateisPointer = value;
	}

	const bool &DeclNode::getisInited() const
	{
		return privateisInited;
	}

	void DeclNode::setisInited(const bool &value)
	{
		privateisInited = value;
	}

	const std::string &DeclNode::getDeclType() const
	{
		return privateDeclType;
	}

	void DeclNode::setDeclType(const std::string &value)
	{
		privateDeclType = value;
	}

	const std::string &DeclNode::getDeclName() const
	{
		return privateDeclName;
	}

	void DeclNode::setDeclName(const std::string &value)
	{
		privateDeclName = value;
	}

	NodeType DeclNode::getNodeType()
	{
		return this->gettype();
	}

	void DeclNode::setNodeType(NodeType type)
	{
		this->settype(type);
	}

	std::string DeclNode::ToString()
	{
		std::string array_Renamed = "";
		std::string pointer = "";
		std::string inited = "Declaration";
		if (this->getisArray())
		{
			std::string  *str = new std::string();
			for (int i = 0; i < this->getArrayLevel(); i++)
			{
				str->append("[]");

			}
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
			array_Renamed = *str;
		}
		if (this->getisPointer())
		{
			std::string  *str = new std::string();
			for (int i = 0; i < this->getPointerLevel(); i++)
			{
				str->append("*");

			}
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
			pointer = *str;
		}
		if (this->getisInited())
		{
			inited = "initialized";
		}
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		return inited + std::string("  variable  ") + this->getDeclName() + std::string(".ToString()\n of type ") + this->getDeclType() + array_Renamed + pointer;
	}

	int DeclNode::getId()
	{
		return this->id;
	}

	void DeclNode::InitializeInstanceFields()
	{
		id = 0;
	}

	const NodeType &FuncCallNode::gettype() const
	{
		return privatetype;
	}

	void FuncCallNode::settype(const NodeType &value)
	{
		privatetype = value;
	}

	const std::string &FuncCallNode::getFunctionName() const
	{
		return privateFunctionName;
	}

	void FuncCallNode::setFunctionName(const std::string &value)
	{
		privateFunctionName = value;
	}

	std::vector<FlowGraphNode*> FuncCallNode::getargs() const
	{
		return privateargs;
	}

	void FuncCallNode::setargs(const std::vector<FlowGraphNode*> &value)
	{
		privateargs = value;
	}

	FuncCallNode::FuncCallNode(int id)
	{
		InitializeInstanceFields();
		this->id = id;
		this->settype(NodeType::E_FUNC_CALL);
	}

	NodeType FuncCallNode::getNodeType()
	{
		return this->gettype();
	}

	void FuncCallNode::setNodeType(NodeType type)
	{
		this->settype(type);
	}

	std::string FuncCallNode::ToString()
	{
		std::string *str = new std::string();
		for (auto arg : this->getargs())
		{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
			str->append(std::string("\n") + arg->ToString() + std::string("  "));
		}
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		return std::string("call  ") + this->getFunctionName() + std::string(" with ") + *str;
	}

	int FuncCallNode::getId()
	{
		return this->id;
	}

	void FuncCallNode::InitializeInstanceFields()
	{
		id = 0;
	}

	const NodeType &IfNode::gettype() const
	{
		return privatetype;
	}

	void IfNode::settype(const NodeType &value)
	{
		privatetype = value;
	}

	IfNode::IfNode(int id)
	{
		InitializeInstanceFields();
		this->id = id;
		this->settype(NodeType::E_IF);

	}

	FlowGraphNode *IfNode::getcondition() const
	{
		return privatecondition;
	}

	void IfNode::setcondition(FlowGraphNode *value)
	{
		privatecondition = value;
	}

	std::vector<FlowGraphNode*> IfNode::getleft() const
	{
		return privateleft;
	}

	void IfNode::setleft(const std::vector<FlowGraphNode*> &value)
	{
		privateleft = value;
	}

	std::vector<FlowGraphNode*> IfNode::getright() const
	{
		return privateright;
	}

	void IfNode::setright(const std::vector<FlowGraphNode*> &value)
	{
		privateright = value;
	}

	NodeType IfNode::getNodeType()
	{
		return this->gettype();
	}

	void IfNode::setNodeType(NodeType type)
	{
		this->settype(type);
	}

	std::string IfNode::ToString()
	{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		return std::string("IF(") + getcondition()->ToString() + std::string(")");
	}

	int IfNode::getId()
	{
		return this->id;
	}

	void IfNode::InitializeInstanceFields()
	{
		id = 0;
	}

	const NodeType &WhileNode::gettype() const
	{
		return privatetype;
	}

	void WhileNode::settype(const NodeType &value)
	{
		privatetype = value;
	}

	WhileNode::WhileNode(int id)
	{
		InitializeInstanceFields();
		this->settype(NodeType::E_WHILE);
		this->id = id;
	}

	FlowGraphNode *WhileNode::getcondition() const
	{
		return privatecondition;
	}

	void WhileNode::setcondition(FlowGraphNode *value)
	{
		privatecondition = value;
	}

	std::vector<FlowGraphNode*> WhileNode::getloop() const
	{
		return privateloop;
	}

	void WhileNode::setloop(const std::vector<FlowGraphNode*> &value)
	{
		privateloop = value;
	}

	NodeType WhileNode::getNodeType()
	{
		return this->gettype();
	}

	void WhileNode::setNodeType(NodeType type)
	{
		this->settype(type);
	}

	int WhileNode::getId()
	{
		return this->id;
	}

	std::string WhileNode::ToString()
	{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		return std::string("While ") + this->getcondition()->ToString();
	}

	void WhileNode::InitializeInstanceFields()
	{
		id = 0;
	}

	const NodeType &ForNode::gettype() const
	{
		return privatetype;
	}

	void ForNode::settype(const NodeType &value)
	{
		privatetype = value;
	}

	ForNode::ForNode(int id)
	{
		InitializeInstanceFields();
		this->settype(NodeType::E_FOR);
		this->id = id;
	}

	FlowGraphNode *ForNode::getcondition() const
	{
		return privatecondition;
	}

	void ForNode::setcondition(FlowGraphNode *value)
	{
		privatecondition = value;
	}

	std::vector<FlowGraphNode*> ForNode::getloop() const
	{
		return privateloop;
	}

	void ForNode::setloop(const std::vector<FlowGraphNode*> &value)
	{
		privateloop = value;
	}

	FlowGraphNode *ForNode::getinit() const
	{
		return privateinit;
	}

	void ForNode::setinit(FlowGraphNode *value)
	{
		privateinit = value;
	}

	FlowGraphNode *ForNode::getnext() const
	{
		return privatenext;
	}

	void ForNode::setnext(FlowGraphNode *value)
	{
		privatenext = value;
	}

	NodeType ForNode::getNodeType()
	{
		return this->gettype();
	}

	void ForNode::setNodeType(NodeType type)
	{
		this->settype(type);
	}

	int ForNode::getId()
	{
		return this->id;
	}

	std::string ForNode::ToString()
	{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		return std::string("For(") + this->getinit()->ToString() + std::string(";\n") + this->getcondition()->ToString() + std::string(";\n") + this->getnext()->ToString() + std::string(")");
	}

	void ForNode::InitializeInstanceFields()
	{
		id = 0;
	}

	ID::ID(int id)
	{
		InitializeInstanceFields();
		this->id = id;
		type = NodeType::E_ID;
	}

	NodeType ID::getNodeType()
	{
		return this->type;
	}

	void ID::setNodeType(NodeType type)
	{
		this->type = type;
	}

	std::string ID::ToString()
	{
		return this->getName();
	}

	const std::string &ID::getName() const
	{
		return privateName;
	}

	void ID::setName(const std::string &value)
	{
		privateName = value;
	}

	int ID::getId()
	{
		return this->id;
	}

	void ID::InitializeInstanceFields()
	{
		id = 0;
		type = (WpfApplication2::NodeType)0;
	}

	ConstantNode::ConstantNode(int id)
	{
		InitializeInstanceFields();
		this->id = id;
		type = NodeType::E_COSNT;
	}

	NodeType ConstantNode::getNodeType()
	{
		return this->type;
	}

	void ConstantNode::setNodeType(NodeType type)
	{
		this->type = type;
	}

	const std::string &ConstantNode::getValType() const
	{
		return privateValType;
	}

	void ConstantNode::setValType(const std::string &value)
	{
		privateValType = value;
	}

	const std::string &ConstantNode::getValue() const
	{
		return privateValue;
	}

	void ConstantNode::setValue(const std::string &value)
	{
		privateValue = value;
	}

	std::string ConstantNode::ToString()
	{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		return this->getValue();
	}

	int ConstantNode::getId()
	{
		return this->id;
	}

	void ConstantNode::InitializeInstanceFields()
	{
		id = 0;
		type = (WpfApplication2::NodeType)0;
	}

	ArrayRef::ArrayRef(int id)
	{
		InitializeInstanceFields();
		this->id = id;
		this->type = NodeType::E_ARRAY_REF;
	}

	NodeType ArrayRef::getNodeType()
	{
		return this->type;
	}

	void ArrayRef::setNodeType(NodeType type)
	{
		this->type = type;
	}

	FlowGraphNode *ArrayRef::getName() const
	{
		return privateName;
	}

	void ArrayRef::setName(FlowGraphNode *value)
	{
		privateName = value;
	}

	FlowGraphNode *ArrayRef::getindex() const
	{
		return privateindex;
	}

	void ArrayRef::setindex(FlowGraphNode *value)
	{
		privateindex = value;
	}

	std::string ArrayRef::ToString()
	{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		return this->getName()->ToString() + std::string("[") + getindex()->ToString() + std::string("]");
	}

	int ArrayRef::getId()
	{
		return this->id;
	}

	void ArrayRef::InitializeInstanceFields()
	{
		id = 0;
		type = (WpfApplication2::NodeType)0;
	}

	StructRef::StructRef(int id)
	{
		InitializeInstanceFields();
		this->id = id;
		this->type = NodeType::E_STRUCTREF;
	}

	NodeType StructRef::getNodeType()
	{
		return this->type;
	}

	void StructRef::setNodeType(NodeType type)
	{
		this->type = type;
	}

	const std::string &StructRef::getreftype() const
	{
		return privatereftype;
	}

	void StructRef::setreftype(const std::string &value)
	{
		privatereftype = value;
	}

	FlowGraphNode *StructRef::getstructfield() const
	{
		return privatestructfield;
	}

	void StructRef::setstructfield(FlowGraphNode *value)
	{
		privatestructfield = value;
	}

	FlowGraphNode *StructRef::getstructname() const
	{
		return privatestructname;
	}

	void StructRef::setstructname(FlowGraphNode *value)
	{
		privatestructname = value;
	}

	std::string StructRef::ToString()
	{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		return this->getstructname()->ToString() + getreftype() + getstructfield()->ToString();
	}

	int StructRef::getId()
	{
		return this->id;
	}

	void StructRef::InitializeInstanceFields()
	{
		id = 0;
		type = (WpfApplication2::NodeType)0;
	}

	BinaryOp::BinaryOp(int id)
	{
		InitializeInstanceFields();
		this->id = id;
		this->type = NodeType::E_BIN_OP;
	}

	NodeType BinaryOp::getNodeType()
	{
		return this->type;
	}

	void BinaryOp::setNodeType(NodeType type)
	{
		this->type = type;
	}

	std::string BinaryOp::ToString()
	{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		return this->left->ToString() + this->getOP() + this->right->ToString();
	}

	const std::string &BinaryOp::getOP() const
	{
		return privateOP;
	}

	void BinaryOp::setOP(const std::string &value)
	{
		privateOP = value;
	}

	int BinaryOp::getId()
	{
		return this->id;
	}

	void BinaryOp::InitializeInstanceFields()
	{
		id = 0;
		type = (WpfApplication2::NodeType)0;
	}

	UnaryOp::UnaryOp(int id)
	{
		InitializeInstanceFields();
		this->id = id;
		type = NodeType::E_UN_OP;
	}

	NodeType UnaryOp::getNodeType()
	{
		return this->type;
	}

	void UnaryOp::setNodeType(NodeType type)
	{
		this->type = type;
	}

	const std::string &UnaryOp::getOP() const
	{
		return privateOP;
	}

	void UnaryOp::setOP(const std::string &value)
	{
		privateOP = value;
	}

	std::string UnaryOp::ToString()
	{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		return this->getOP() + this->left->ToString();
	}

	int UnaryOp::getId()
	{
		return this->id;
	}

	void UnaryOp::InitializeInstanceFields()
	{
		id = 0;
		type = (WpfApplication2::NodeType)0;
	}

	Cast::Cast(int id)
	{
		InitializeInstanceFields();
		this->id = id;
		type = NodeType::E_CAST;
	}

	NodeType Cast::getNodeType()
	{
		return this->type;
	}

	void Cast::setNodeType(NodeType type)
	{
		this->type = type;
	}

	const std::string &Cast::getOP() const
	{
		return privateOP;
	}

	void Cast::setOP(const std::string &value)
	{
		privateOP = value;
	}

	std::string Cast::ToString()
	{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		return this->typetocast->ToString() + this->expr->ToString();
	}

	int Cast::getId()
	{
		return this->id;
	}

	void Cast::InitializeInstanceFields()
	{
		id = 0;
		type = (WpfApplication2::NodeType)0;
	}

	ReturnNode::ReturnNode(int id)
	{
		InitializeInstanceFields();
		this->id = id;
		type = NodeType::E_RETURN;
	}

	NodeType ReturnNode::getNodeType()
	{
		return this->type;
	}

	void ReturnNode::setNodeType(NodeType type)
	{
		this->type = type;
	}

	std::string ReturnNode::ToString()
	{
		if (expr != nullptr)
		{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
			return std::string("return ") + this->expr->ToString();
		}
		else
		{
			return "return";
		}
	}

	int ReturnNode::getId()
	{
		return this->id;
	}

	void ReturnNode::InitializeInstanceFields()
	{
		id = 0;
		type = (WpfApplication2::NodeType)0;
	}

	TypeName::TypeName(int id)
	{
		InitializeInstanceFields();
		this->id = id;
		type = NodeType::E_TYPENAME;
	}

	NodeType TypeName::getNodeType()
	{
		return this->type;
	}

	void TypeName::setNodeType(NodeType type)
	{
		this->type = type;
	}

	std::string TypeName::ToString()
	{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		return std::string(" ") + this->Type->ToString();
	}

	int TypeName::getId()
	{
		return this->id;
	}

	void TypeName::InitializeInstanceFields()
	{
		id = 0;
		type = (WpfApplication2::NodeType)0;
	}

	TypeDef::TypeDef(int id)
	{
		InitializeInstanceFields();
		this->id = id;
		type = NodeType::E_TYPEDEF;
	}

	NodeType TypeDef::getNodeType()
	{
		return this->type;
	}

	void TypeDef::setNodeType(NodeType type)
	{
		this->type = type;
	}

	std::string TypeDef::ToString()
	{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		return std::string("type ") + this->name;
	}

	int TypeDef::getId()
	{
		return this->id;
	}

	void TypeDef::InitializeInstanceFields()
	{
		id = 0;
		type = (WpfApplication2::NodeType)0;
	}

	TypeDecl::TypeDecl(int id)
	{
		InitializeInstanceFields();
		this->id = id;
		type = NodeType::E_TYPEDEF;
	}

	NodeType TypeDecl::getNodeType()
	{
		return this->type;
	}

	void TypeDecl::setNodeType(NodeType type)
	{
		this->type = type;
	}

	std::string TypeDecl::ToString()
	{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		return std::string("type ") + this->Type->ToString();
	}

	int TypeDecl::getId()
	{
		return this->id;
	}

	void TypeDecl::InitializeInstanceFields()
	{
		id = 0;
		type = (WpfApplication2::NodeType)0;
	}

	StructNode::StructNode(int id)
	{
		InitializeInstanceFields();
		this->id = id;
		type = NodeType::E_STRUCT;
	}

	NodeType StructNode::getNodeType()
	{
		return this->type;
	}

	void StructNode::setNodeType(NodeType type)
	{
		this->type = type;
	}

	std::string StructNode::ToString()
	{

		return "struct ";
	}

	int StructNode::getId()
	{
		return this->id;
	}

	void StructNode::InitializeInstanceFields()
	{
		id = 0;
		type = (WpfApplication2::NodeType)0;
	}

	EnumNode::EnumNode(int id)
	{
		InitializeInstanceFields();
		this->id = id;
		type = NodeType::E_ENUM;
	}

	NodeType EnumNode::getNodeType()
	{
		return this->type;
	}

	void EnumNode::setNodeType(NodeType type)
	{
		this->type = type;
	}

	std::string EnumNode::ToString()
	{

		return this->name;
	}

	int EnumNode::getId()
	{
		return this->id;
	}

	void EnumNode::InitializeInstanceFields()
	{
		id = 0;
		type = (WpfApplication2::NodeType)0;
	}

	EnumValue::EnumValue(int id)
	{
		InitializeInstanceFields();
		this->id = id;
		type = NodeType::E_ENUMVALUE;
	}

	NodeType EnumValue::getNodeType()
	{
		return this->type;
	}

	void EnumValue::setNodeType(NodeType type)
	{
		this->type = type;
	}

	std::string EnumValue::ToString()
	{

		return value;
	}

	int EnumValue::getId()
	{
		return this->id;
	}

	void EnumValue::InitializeInstanceFields()
	{
		id = 0;
		type = (WpfApplication2::NodeType)0;
	}

	TypeDeclIdentifierType::TypeDeclIdentifierType(int id)
	{
		InitializeInstanceFields();
		this->id = id;
		type = NodeType::E_TYPEDECL_ID;
	}

	NodeType TypeDeclIdentifierType::getNodeType()
	{
		return this->type;
	}

	void TypeDeclIdentifierType::setNodeType(NodeType type)
	{
		this->type = type;
	}

	std::string TypeDeclIdentifierType::ToString()
	{
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
		return std::string("type ") + this->name;
	}

	int TypeDeclIdentifierType::getId()
	{
		return this->id;
	}

	void TypeDeclIdentifierType::InitializeInstanceFields()
	{
		id = 0;
		type = (WpfApplication2::NodeType)0;
	}
}
