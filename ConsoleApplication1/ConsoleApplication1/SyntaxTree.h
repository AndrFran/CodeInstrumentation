#pragma once

#include "FlowGraphNode.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "ValuableCopible.h"


namespace WpfApplication2
{
	class Function
	{
	private:
		std::vector<DeclNode*> parametrs;
		DeclNode *privatereturntype;
	public:
		DeclNode *getreturntype() const;
		void setreturntype(DeclNode *value);
	private:
		std::vector<FlowGraphNode*> privatenodes;
	public:
		std::vector<FlowGraphNode*> * getnodes();
		std::vector<FlowGraphNode*> getNodeswithCopy();
		void setnodes(const std::vector<FlowGraphNode*> &value);
	private:
		std::string privatename;
	public:
		const std::string &getname() const;
		void setname(const std::string &value);
		void AddParam(DeclNode *var);
		std::vector<DeclNode*> Getparams();
		Function();
	};

	class Operation
	{
	private:
		void Oparation();
	public:
	};
    class SyntaxTree
	{
	private:
		static int Id;
		std::vector<ValueCopibable> globals;
		std::vector<ValueCopibable> functions;
		std::vector<Function*> ParsedFunctions;
		std::vector<FlowGraphNode*> privateGlobalScope;
	public:
		std::vector<FlowGraphNode*> getGlobalScope() const;
		void setGlobalScope(const std::vector<FlowGraphNode*> &value);
	private:
		std::vector<FlowGraphNode*> graph;
	public:
		SyntaxTree();

		std::vector<std::string> Create(ValueCopibable dic);
		std::vector<Function*> GetFunctionByNames(std::vector<std::string> &names);
		void ParseFunctions();
		std::vector<FlowGraphNode*> CreateFlowControlGraph(int id);
	private:
		FlowGraphNode *ParseNode(ValueCopibable item);
		FlowGraphNode *ParseTypeDeclIdentifierType(ValueCopibable item);
		FlowGraphNode *ParseDeclaration(ValueCopibable item);
		FlowGraphNode *ParseFuncCall(ValueCopibable item);
		FlowGraphNode *ParseConstant(ValueCopibable item);
		FlowGraphNode *ParseID(ValueCopibable item);
		FlowGraphNode *ParseArrayRef(ValueCopibable item);
		FlowGraphNode *ParseStructRef(ValueCopibable item);
		FlowGraphNode *ParseBinOp(ValueCopibable item);
		FlowGraphNode *ParseAssigmet(ValueCopibable item);
		FlowGraphNode *ParseUnaryOp(ValueCopibable item);
		FlowGraphNode *ParseCast(ValueCopibable item);
		FlowGraphNode *ParseTypeDef(ValueCopibable item);
		FlowGraphNode *ParseTypeDecl(ValueCopibable item);
		FlowGraphNode *ParseTypeName(ValueCopibable item);
		FlowGraphNode *ParseStruct(ValueCopibable item);
		FlowGraphNode *ParseEnum(ValueCopibable item);
		FlowGraphNode *ParseEnumValue(ValueCopibable item);
		FlowGraphNode *ParseReturn(ValueCopibable item);
		FlowGraphNode *ParseIf(ValueCopibable item);
		void addNewNode(FlowGraphNode *node);
		FlowGraphNode *ParseWhile(ValueCopibable item);

	FlowGraphNode *ParseFor(ValueCopibable item);

	private:
		void InitializeInstanceFields();
	};
	
}
