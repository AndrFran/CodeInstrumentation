#pragma once

#include "FlowGraphNode.h"
#include "SyntaxTree.h"
#include <string>
#include <vector>
#include <iostream>


namespace WpfApplication2
{
	class CheckAssigment
	{

	};
	class Variable
	{
	private:
		std::string privatetype;
	public:
		const std::string &gettype() const;
		void settype(const std::string &value);
		Variable(std::string, std::string);
		Variable();
	private:
		std::string privatename;
	public:
		const std::string &getname() const;
		void setname(const std::string &value);
	private:
		std::string privatevalue;
	public:
		const std::string &getvalue() const;
		void setvalue(const std::string &value);
	private:
		std::string privateisarray;
	public:
		const std::string &getisarray() const;
		void setisarray(const std::string &value);
	private:
		std::string privateispointer;
	public:
		const std::string &getispointer() const;
		void setispointer(const std::string &value);
	private:
		std::string privatecomma;
	public:
		const std::string &getcomma() const;
		void setcomma(const std::string &value);
	};
	class CheckReturn
	{
	private:
		Variable *privateToCheck;
	public:
		Variable *getToCheck() const;
		void setToCheck(Variable *value);
		CheckReturn(Variable toCheck);
	private:
		bool privateintcheck;
	public:
		const bool &getintcheck() const;
		void setintcheck(const bool &value);
	private:
		bool privatepointercheck;
	public:
		const bool &getpointercheck() const;
		void setpointercheck(const bool &value);
	private:
		bool privateboolchecl;
	public:
		const bool &getboolchecl() const;
		void setboolchecl(const bool &value);
	private:
		bool privatecharcheck;
	public:
		const bool &getcharcheck() const;
		void setcharcheck(const bool &value);
	private:
		bool privatememcheck;
	public:
		const bool &getmemcheck() const;
		void setmemcheck(const bool &value);
	};
	
	class TestCase
	{
	private:
		std::string privateresult;
	public:
		const std::string &getresult() const;
		void setresult(const std::string &value);
	private:
		std::string privatefunction_name;
	public:
		const std::string &getfunction_name() const;
		void setfunction_name(const std::string &value);
	private:
		Variable *privatefunction_type;
	public:
		Variable *getfunction_type() const;
		void setfunction_type(Variable *value);
	private:
		int privateid;
	public:
		const int &getid() const;
		void setid(const int &value);
	private:
		std::vector<Variable*> *privateCheckVars;
	public:
		std::vector<Variable*> *getCheckVars() const;
		void setCheckVars(std::vector<Variable*> *value);
	private:
		std::vector<Variable*> *privateArguments;
	public:
		std::vector<Variable*> *getArguments() const;
		void setArguments(std::vector<Variable*> *value);
	private:
		std::vector<FuncCallNode*> *privateFuncCalls;
	public:
		std::vector<FuncCallNode*> *getFuncCalls() const;
		void setFuncCalls(std::vector<FuncCallNode*> *value);
	private:
		std::vector<FlowGraphNode*> *privatepath;
	public:
		std::vector<FlowGraphNode*> *getpath() const;
		void setpath(std::vector<FlowGraphNode*> *value);
	private:
		std::vector<FlowGraphNode*> privatefunction_nodes;
	public:
		std::vector<FlowGraphNode*> getfunction_nodes() const;
		void setfunction_nodes(const std::vector<FlowGraphNode*> &value);
	private:
		CheckReturn *privatereturnchecker;
	public:
		CheckReturn *getreturnchecker() const;
		void setreturnchecker(CheckReturn *value);
	};
	class ThreadData
	{
	private:
		Function *privatef;
	public:
		Function *getf() const;
		void setf(Function *value);
	private:
		std::vector<FlowGraphNode*> privateGlobalScope;
	public:
		std::vector<FlowGraphNode*> getGlobalScope() const;
		void setGlobalScope(const std::vector<FlowGraphNode*> &value);
	private:
		std::vector<FlowGraphNode*> privatepath;
	public:
		std::vector<FlowGraphNode*> getpath() const;
		void setpath(const std::vector<FlowGraphNode*> &value);
	private:
		int privateid;
	public:
		const int &getid() const;
		void setid(const int &value);
	};
	class TestCases
	{
	private:
		std::string privatefilename;
	public:
		const std::string &getfilename() const;
		void setfilename(const std::string &value);
	private:
		std::vector<TestCase*> *privatetestcases;
	public:
		std::vector<TestCase*> *gettestcases() const;
		void settestcases(std::vector<TestCase*> *value);

	};
	class TestCaseBuilder
	{
	private:
		static int id;
		static int ProcessorsCount;
		static int CurrentThreadCount;

		//static Mutex *mutex;
		//static Semaphore *ProcessorMutex;
		static std::vector<TestCase*> testcases;

	public:
		TestCaseBuilder();
	private:
		void releaseProcessor();
		bool GetFreeProcessors();
		int SetByte(int id);
		void AddTestCase(void *data);

	public:
		std::vector<TestCase*> GenerateCases(Function *f, std::vector<FlowGraphNode*> GlobalScope);

	private:
		std::string GetTypeOfTypeDef(const std::string &type, std::vector<FlowGraphNode*> GlobalScope);
		Variable *DeclNodeToVar(DeclNode *node, Function *f);
	public:
		TestCase *BuildTestCase(Function *f, std::vector<FlowGraphNode*> GlobalScope, std::vector<FlowGraphNode*> &path);
		std::vector<TestCase*> BuildTestCases(Function *f, std::vector<FlowGraphNode*> GlobalScope);
	};
}
