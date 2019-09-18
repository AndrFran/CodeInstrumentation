#pragma once

#include <string>
#include <vector>


namespace WpfApplication2
{
	enum class NodeType
	{
		E_ASSIGMENT,
		E_DECL,
		E_IF,
		E_FUNC_CALL,
		E_CYCLE,
		E_COSNT,
		E_ID,
		E_ARRAY_REF,
		E_BIN_OP,
		E_UN_OP,
		E_FOR,
		E_WHILE,
		E_RETURN,
		E_TYPEDEF,
		E_TYPEDECL,
		E_STRUCT,
		E_ENUM,
		E_ENUMVALUE,
		E_STRUCTREF,
		E_TYPENAME,
		E_TYPEDECL_ID,
		E_CAST,
	};
	class FlowGraphNode
	{
	public:
		virtual NodeType getNodeType() = 0;
		virtual void setNodeType(NodeType type) = 0;
		virtual int getId() = 0;
		virtual std::string ToString() = 0;
	};

	class OperationNode : public FlowGraphNode
	{
	private:
		int id;
		FlowGraphNode *privateleft;
	public:
		FlowGraphNode *getleft();
		void setleft(FlowGraphNode *value);
	private:
		FlowGraphNode *privateright;
	public:
		FlowGraphNode *getright();
		void setright(FlowGraphNode *value);
	private:
		NodeType type;
	public:
		OperationNode(int id);

		NodeType getNodeType();

		void setNodeType(NodeType type);
		virtual std::string ToString() override;

		int getId();


	private:
		void InitializeInstanceFields();
	};
	class DeclNode : public FlowGraphNode
	{
	private:
		int id;
	public:
		DeclNode(int id);
	private:
		NodeType privatetype;
		const NodeType &gettype() const;
		void settype(const NodeType &value);
		int privateArrayLevel;
	public:
		const int &getArrayLevel() const;
		void setArrayLevel(const int &value);
	private:
		int privatePointerLevel;
	public:
		const int &getPointerLevel() const;
		void setPointerLevel(const int &value);
	private:
		bool privateisArray;
	public:
		const bool &getisArray() const;
		void setisArray(const bool &value);
	private:
		bool privateisPointer;
	public:
		const bool &getisPointer() const;
		void setisPointer(const bool &value);
	private:
		bool privateisInited;
	public:
		const bool &getisInited() const;
		void setisInited(const bool &value);

	private:
		std::vector<std::string> InitValues;
		std::string privateDeclType;
	public:
		const std::string &getDeclType() const;
		void setDeclType(const std::string &value);
	private:
		std::string privateDeclName;
	public:
		const std::string &getDeclName() const;
		void setDeclName(const std::string &value);

		NodeType getNodeType();

		void setNodeType(NodeType type);
		virtual std::string ToString() override;
		int getId();

	private:
		void InitializeInstanceFields();
	};

	class FuncCallNode : public FlowGraphNode
	{
	private:
		int id;
		NodeType privatetype;
		const NodeType &gettype() const;
		void settype(const NodeType &value);
		std::string privateFunctionName;
	public:
		const std::string &getFunctionName() const;
		void setFunctionName(const std::string &value);
	private:
		std::vector<FlowGraphNode*> privateargs;
	public:
		std::vector<FlowGraphNode*> getargs() const;
		void setargs(const std::vector<FlowGraphNode*> &value);
		FuncCallNode(int id);
		NodeType getNodeType();

		void setNodeType(NodeType type);
		virtual std::string ToString() override;
		int getId();

	private:
		void InitializeInstanceFields();
	};

	class IfNode : public FlowGraphNode
	{
	private:
		int id;
		NodeType privatetype;
		const NodeType &gettype() const;
		void settype(const NodeType &value);
	public:
		IfNode(int id);
	private:
		FlowGraphNode *privatecondition;
	public:
		FlowGraphNode *getcondition() const;
		void setcondition(FlowGraphNode *value);

	private:
		std::vector<FlowGraphNode*> privateleft;
	public:
		std::vector<FlowGraphNode*> getleft() const;
		void setleft(const std::vector<FlowGraphNode*> &value);
	private:
		std::vector<FlowGraphNode*> privateright;
	public:
		std::vector<FlowGraphNode*> getright() const;
		void setright(const std::vector<FlowGraphNode*> &value);

		NodeType getNodeType();

		void setNodeType(NodeType type);

		virtual std::string ToString() override;
		int getId();

	private:
		void InitializeInstanceFields();
	};
	class WhileNode : public FlowGraphNode
	{
	private:
		int id;
		NodeType privatetype;
		const NodeType &gettype() const;
		void settype(const NodeType &value);
	public:
		WhileNode(int id);
	private:
		FlowGraphNode *privatecondition;
	public:
		FlowGraphNode *getcondition() const;
		void setcondition(FlowGraphNode *value);

	private:
		std::vector<FlowGraphNode*> privateloop;
	public:
		std::vector<FlowGraphNode*> getloop() const;
		void setloop(const std::vector<FlowGraphNode*> &value);

		NodeType getNodeType();

		void setNodeType(NodeType type);
		int getId();

		virtual std::string ToString() override;

	private:
		void InitializeInstanceFields();
	};
	class ForNode : public FlowGraphNode
	{
	private:
		int id;
		NodeType privatetype;
		const NodeType &gettype() const;
		void settype(const NodeType &value);
	public:
		ForNode(int id);
	private:
		FlowGraphNode *privatecondition;
	public:
		FlowGraphNode *getcondition() const;
		void setcondition(FlowGraphNode *value);

	private:
		std::vector<FlowGraphNode*> privateloop;
	public:
		std::vector<FlowGraphNode*> getloop() const;
		void setloop(const std::vector<FlowGraphNode*> &value);
	private:
		FlowGraphNode *privateinit;
	public:
		FlowGraphNode *getinit() const;
		void setinit(FlowGraphNode *value);
	private:
		FlowGraphNode *privatenext;
	public:
		FlowGraphNode *getnext() const;
		void setnext(FlowGraphNode *value);
		NodeType getNodeType();

		void setNodeType(NodeType type);
		int getId();

		virtual std::string ToString() override;

	private:
		void InitializeInstanceFields();
	};

	class ID : public FlowGraphNode
	{
	private:
		int id;
		NodeType type;
	public:
		ID(int id);
		NodeType getNodeType();

		void setNodeType(NodeType type);
		virtual std::string ToString() override;
	private:
		std::string privateName;
	public:
		const std::string &getName() const;
		void setName(const std::string &value);
		int getId();

	private:
		void InitializeInstanceFields();
	};
	class ConstantNode : public FlowGraphNode
	{
	private:
		int id;
		NodeType type;
	public:
		ConstantNode(int id);
		NodeType getNodeType();

		void setNodeType(NodeType type);
	private:
		std::string privateValType;
	public:
		const std::string &getValType() const;
		void setValType(const std::string &value);
	private:
		std::string privateValue;
	public:
		const std::string &getValue() const;
		void setValue(const std::string &value);

		virtual std::string ToString() override;
		int getId();

	private:
		void InitializeInstanceFields();
	};
	class ArrayRef : public FlowGraphNode
	{
	private:
		int id;
		NodeType type;
	public:
		ArrayRef(int id);
		NodeType getNodeType();

		void setNodeType(NodeType type);

	private:
		FlowGraphNode *privateName;
	public:
		FlowGraphNode *getName() const;
		void setName(FlowGraphNode *value);
	private:
		FlowGraphNode *privateindex;
	public:
		FlowGraphNode *getindex() const;
		void setindex(FlowGraphNode *value);

		virtual std::string ToString() override;
		int getId();

	private:
		void InitializeInstanceFields();
	};
	class StructRef : public FlowGraphNode
	{
	private:
		int id;
		NodeType type;
	public:
		StructRef(int id);
		NodeType getNodeType();

		void setNodeType(NodeType type);

	private:
		std::string privatereftype;
	public:
		const std::string &getreftype() const;
		void setreftype(const std::string &value);
	private:
		FlowGraphNode *privatestructfield;
	public:
		FlowGraphNode *getstructfield() const;
		void setstructfield(FlowGraphNode *value);
	private:
		FlowGraphNode *privatestructname;
	public:
		FlowGraphNode *getstructname() const;
		void setstructname(FlowGraphNode *value);
		virtual std::string ToString() override;
		int getId();

	private:
		void InitializeInstanceFields();
	};

	class BinaryOp : public FlowGraphNode
	{
	private:
		int id;
		NodeType type;
	public:
		BinaryOp(int id);
		NodeType getNodeType();

		void setNodeType(NodeType type);
		virtual std::string ToString() override;
	private:
		std::string privateOP;
	public:
		const std::string &getOP() const;
		void setOP(const std::string &value);
		FlowGraphNode *left;
		FlowGraphNode *right;
		int getId();

	private:
		void InitializeInstanceFields();
	};
	class UnaryOp : public FlowGraphNode
	{
	private:
		int id;
		NodeType type;
	public:
		UnaryOp(int id);
		NodeType getNodeType();

		void setNodeType(NodeType type);

	private:
		std::string privateOP;
	public:
		const std::string &getOP() const;
		void setOP(const std::string &value);
		FlowGraphNode *left;
		virtual std::string ToString() override;
		int getId();


	private:
		void InitializeInstanceFields();
	};

	class Cast : public FlowGraphNode
	{
	private:
		int id;
		NodeType type;
	public:
		Cast(int id);
		NodeType getNodeType();

		void setNodeType(NodeType type);

	private:
		std::string privateOP;
	public:
		const std::string &getOP() const;
		void setOP(const std::string &value);
		FlowGraphNode *expr;
		FlowGraphNode *typetocast;
		virtual std::string ToString() override;
		int getId();


	private:
		void InitializeInstanceFields();
	};
	class ReturnNode : public FlowGraphNode
	{
	private:
		int id;
		NodeType type;
	public:
		ReturnNode(int id);
		NodeType getNodeType();

		void setNodeType(NodeType type);

		FlowGraphNode *expr;

		virtual std::string ToString() override;
		int getId();

	private:
		void InitializeInstanceFields();
	};
	class TypeName : public FlowGraphNode
	{
	private:
		int id;
		NodeType type;
	public:
		TypeName(int id);
		NodeType getNodeType();

		void setNodeType(NodeType type);

		FlowGraphNode *Type;

		virtual std::string ToString() override;
		int getId();

	private:
		void InitializeInstanceFields();
	};
	class TypeDef : public FlowGraphNode
	{
	private:
		int id;
		NodeType type;
	public:
		TypeDef(int id);
		NodeType getNodeType();

		void setNodeType(NodeType type);

		std::string name;
//C# TO C++ CONVERTER NOTE: The variable TypeDecl was renamed since it is named the same as a user-defined type:
		FlowGraphNode *TypeDecl_Renamed;

		virtual std::string ToString() override;
		int getId();

	private:
		void InitializeInstanceFields();
	};


	class TypeDecl : public FlowGraphNode
	{
	private:
		int id;
		NodeType type;
	public:
		TypeDecl(int id);
		NodeType getNodeType();

		void setNodeType(NodeType type);

		std::string name;
		FlowGraphNode *Type;

		virtual std::string ToString() override;
		int getId();

	private:
		void InitializeInstanceFields();
	};

	class StructNode : public FlowGraphNode
	{
	private:
		int id;
		NodeType type;
	public:
		StructNode(int id);
		NodeType getNodeType();

		void setNodeType(NodeType type);


		std::vector<FlowGraphNode*> Decl;

		virtual std::string ToString() override;
		int getId();

	private:
		void InitializeInstanceFields();
	};

	class EnumNode : public FlowGraphNode
	{
	private:
		int id;
		NodeType type;
	public:
		EnumNode(int id);
		NodeType getNodeType();

		void setNodeType(NodeType type);


		std::vector<FlowGraphNode*> Values;
		std::string name;
		virtual std::string ToString() override;
		int getId();

	private:
		void InitializeInstanceFields();
	};
	class EnumValue : public FlowGraphNode
	{
	private:
		int id;
		NodeType type;
	public:
		EnumValue(int id);
		NodeType getNodeType();

		void setNodeType(NodeType type);


		std::string value;

		virtual std::string ToString() override;
		int getId();

	private:
		void InitializeInstanceFields();
	};

	class TypeDeclIdentifierType : public FlowGraphNode
	{
	private:
		int id;
		NodeType type;
	public:
		TypeDeclIdentifierType(int id);
		NodeType getNodeType();

		void setNodeType(NodeType type);

		std::string name;

		virtual std::string ToString() override;
		int getId();

	private:
		void InitializeInstanceFields();
	};
}
