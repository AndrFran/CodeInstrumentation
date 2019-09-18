#include "pch.h"
#include "TestCaseBuilder.h"
#include "FlowGraphWalker.h"


namespace WpfApplication2
{

	Variable *CheckReturn::getToCheck() const
	{
		return privateToCheck;
	}

	void CheckReturn::setToCheck(Variable *value)
	{
		privateToCheck = value;
	}

	CheckReturn::CheckReturn(Variable toCheck)
	{
		this->privateToCheck = new Variable(toCheck);
	}

	const bool &CheckReturn::getintcheck() const
	{
		return privateintcheck;
	}

	void CheckReturn::setintcheck(const bool &value)
	{
		privateintcheck = value;
	}

	const bool &CheckReturn::getpointercheck() const
	{
		return privatepointercheck;
	}

	void CheckReturn::setpointercheck(const bool &value)
	{
		privatepointercheck = value;
	}

	const bool &CheckReturn::getboolchecl() const
	{
		return privateboolchecl;
	}

	void CheckReturn::setboolchecl(const bool &value)
	{
		privateboolchecl = value;
	}

	const bool &CheckReturn::getcharcheck() const
	{
		return privatecharcheck;
	}

	void CheckReturn::setcharcheck(const bool &value)
	{
		privatecharcheck = value;
	}

	const bool &CheckReturn::getmemcheck() const
	{
		return privatememcheck;
	}

	void CheckReturn::setmemcheck(const bool &value)
	{
		privatememcheck = value;
	}

	const std::string &Variable::gettype() const
	{
		return privatetype;
	}

	void Variable::settype(const std::string &value)
	{
		privatetype = value;
	}

	Variable::Variable(std::string type, std::string val)
	{
		this->privatetype = type;
		this->privatevalue = val;
	}

	Variable::Variable()
	{
	}

	const std::string &Variable::getname() const
	{
		return privatename;
	}

	void Variable::setname(const std::string &value)
	{
		privatename = value;
	}

	const std::string &Variable::getvalue() const
	{
		return privatevalue;
	}

	void Variable::setvalue(const std::string &value)
	{
		privatevalue = value;
	}

	const std::string &Variable::getisarray() const
	{
		return privateisarray;
	}

	void Variable::setisarray(const std::string &value)
	{
		privateisarray = value;
	}

	const std::string &Variable::getispointer() const
	{
		return privateispointer;
	}

	void Variable::setispointer(const std::string &value)
	{
		privateispointer = value;
	}

	const std::string &Variable::getcomma() const
	{
		return privatecomma;
	}

	void Variable::setcomma(const std::string &value)
	{
		privatecomma = value;
	}

	const std::string &TestCase::getresult() const
	{
		return privateresult;
	}

	void TestCase::setresult(const std::string &value)
	{
		privateresult = value;
	}

	const std::string &TestCase::getfunction_name() const
	{
		return privatefunction_name;
	}

	void TestCase::setfunction_name(const std::string &value)
	{
		privatefunction_name = value;
	}

	Variable *TestCase::getfunction_type() const
	{
		return privatefunction_type;
	}

	void TestCase::setfunction_type(Variable *value)
	{
		privatefunction_type = value;
	}

	const int &TestCase::getid() const
	{
		return privateid;
	}

	void TestCase::setid(const int &value)
	{
		privateid = value;
	}

	std::vector<Variable*> *TestCase::getCheckVars() const
	{
		return privateCheckVars;
	}

	void TestCase::setCheckVars(std::vector<Variable*> *value)
	{
		privateCheckVars = value;
	}

	std::vector<Variable*> *TestCase::getArguments() const
	{
		return privateArguments;
	}

	void TestCase::setArguments(std::vector<Variable*> *value)
	{
		privateArguments = value;
	}

	std::vector<FuncCallNode*> *TestCase::getFuncCalls() const
	{
		return privateFuncCalls;
	}

	void TestCase::setFuncCalls(std::vector<FuncCallNode*> *value)
	{
		privateFuncCalls = value;
	}

	std::vector<FlowGraphNode*> *TestCase::getpath() const
	{
		return privatepath;
	}

	void TestCase::setpath(std::vector<FlowGraphNode*> *value)
	{
		privatepath = value;
	}

	std::vector<FlowGraphNode*> TestCase::getfunction_nodes() const
	{
		return privatefunction_nodes;
	}

	void TestCase::setfunction_nodes(const std::vector<FlowGraphNode*> &value)
	{
		privatefunction_nodes = value;
	}

	CheckReturn *TestCase::getreturnchecker() const
	{
		return privatereturnchecker;
	}

	void TestCase::setreturnchecker(CheckReturn *value)
	{
		privatereturnchecker = value;
	}

	Function *ThreadData::getf() const
	{
		return privatef;
	}

	void ThreadData::setf(Function *value)
	{
		privatef = value;
	}

	std::vector<FlowGraphNode*> ThreadData::getGlobalScope() const
	{
		return privateGlobalScope;
	}

	void ThreadData::setGlobalScope(const std::vector<FlowGraphNode*> &value)
	{
		privateGlobalScope = value;
	}

	std::vector<FlowGraphNode*> ThreadData::getpath() const
	{
		return privatepath;
	}

	void ThreadData::setpath(const std::vector<FlowGraphNode*> &value)
	{
		privatepath = value;
	}

	const int &ThreadData::getid() const
	{
		return privateid;
	}

	void ThreadData::setid(const int &value)
	{
		privateid = value;
	}

	const std::string &TestCases::getfilename() const
	{
		return privatefilename;
	}

	void TestCases::setfilename(const std::string &value)
	{
		privatefilename = value;
	}

	std::vector<TestCase*> *TestCases::gettestcases() const
	{
		return privatetestcases;
	}

	void TestCases::settestcases(std::vector<TestCase*> *value)
	{
		privatetestcases = value;
	}

int TestCaseBuilder::id = 0;
int TestCaseBuilder::ProcessorsCount = 0;
int TestCaseBuilder::CurrentThreadCount = 0;


std::vector<TestCase*> TestCaseBuilder::testcases = std::vector<TestCase*>();

	TestCaseBuilder::TestCaseBuilder()
	{
		ProcessorsCount = 3;
		CurrentThreadCount = 0;
	}

	void TestCaseBuilder::releaseProcessor()
	{
		//ProcessorMutex->Release();
	}

	bool TestCaseBuilder::GetFreeProcessors()
	{
		//ProcessorMutex->WaitOne();
		return true;
	}

	int TestCaseBuilder::SetByte(int id)
	{
		int OneByteValue = 0x1;
		switch (id)
		{
			case 0:
			{
					OneByteValue = 0x1;
					break;
			}
			case 1:
			{
					OneByteValue = 0x2;
					break;
			}
			case 2:
			{
					OneByteValue = 0x4;
					break;
			}
			case 3:
			{
					OneByteValue = 0x8;
					break;
			}
			case 4:
			{
					OneByteValue = 0x10;
					break;
			}
			case 5:
			{
					OneByteValue = 0x20;
					break;
			}
		}
		return OneByteValue;
	}

	void TestCaseBuilder::AddTestCase(void *data)
	{
		ThreadData *d = static_cast<ThreadData*>(data);
		Function *f = static_cast<Function*>(d->getf());
		std::vector<FlowGraphNode*> GlobalScope = static_cast<std::vector<FlowGraphNode*>>(d->getGlobalScope());
		std::vector<FlowGraphNode*> path = static_cast<std::vector<FlowGraphNode*>>(d->getpath());
		TestCase *test = BuildTestCase(f, GlobalScope, path);

		//mutex->WaitOne();
		testcases.push_back(test);
		//mutex->ReleaseMutex();
		releaseProcessor();
	}

	std::vector<TestCase*> TestCaseBuilder::GenerateCases(Function *f, std::vector<FlowGraphNode*> GlobalScope)
	{
		FlowGraphWalker *graphwalker = new FlowGraphWalker();
		// measure here



		std::vector<std::vector<FlowGraphNode*>> pathes = graphwalker->CalculateAllPathes(f->getNodeswithCopy());


		std::cout << std::string("Elapsed for calculting pathes=") << std::endl;
		for (int i = 0;i < pathes.size();i++)
		{
			BuildTestCase(f, GlobalScope, pathes[i]);
			//auto thread = new Thread(AddTestCase);
		   //while (false == GetFreeProcessors())
		   {
			//	ProcessorMutex->WaitOne();
		   }
			//thread->Start(new ThreadData[i], id = thread->ManagedThreadId});
		}
		//wait;
		//delay(500);
		return testcases;
	}

	std::string TestCaseBuilder::GetTypeOfTypeDef(const std::string &type, std::vector<FlowGraphNode*> GlobalScope)
	{
		std::string result = "";
		for (auto glob : GlobalScope)
		{
			if (glob->getNodeType() == NodeType::E_TYPEDEF)
			{
				TypeDef *node = static_cast<TypeDef*>(glob);
				if (node->name == type)
				{
					TypeDecl *decl = static_cast<TypeDecl*>(node->TypeDecl_Renamed);
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
					result = decl->Type->ToString();
				}
			}
		}
		return result;
	}

	Variable *TestCaseBuilder::DeclNodeToVar(DeclNode *node, Function *f)
	{
		Variable *v = new Variable();
		v->setname(node->getDeclName());
		v->settype(node->getDeclType());
		if (f->Getparams().size() > 0)
		{
			if (node == f->Getparams()[f->Getparams().size()-1])
			{
				v->setcomma("");
			}
			else
			{
				v->setcomma(",");
			}
		}
		if (true == node->getisPointer())
		{
			std::string *str = new std::string();
			for (int i = 0; i < node->getPointerLevel(); i++)
			{
				*str+=("*");

			}
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
			v->setispointer(*str);
		}
		else
		{
			v->setispointer("");
		}
		if (true == node->getisArray())
		{
			std::string *str = new std::string();
			for (int i = 0; i < node->getArrayLevel(); i++)
			{
				*str+=("[]");

			}
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
			v->setisarray(*str);
		}
		else
		{
			v->setisarray("");
		}
		v->setvalue("{0}");
		//calc var value
		return v;

	}

	TestCase *TestCaseBuilder::BuildTestCase(Function *f, std::vector<FlowGraphNode*> GlobalScope, std::vector<FlowGraphNode*> &path)
	{

		TestCase *NewCase = new TestCase();
		NewCase->setid(TestCaseBuilder::id++);
		std::vector<Variable*> args = std::vector<Variable*>();
		for (auto node : f->Getparams())
		{
			args.push_back(DeclNodeToVar(node, f));
		}

		NewCase->setArguments(&args);
		NewCase->setfunction_name(f->getname());
		NewCase->setfunction_type(DeclNodeToVar(f->getreturntype(), f));
		NewCase->setfunction_nodes(f->getNodeswithCopy());
		NewCase->setpath(&path);
		for (auto testnode : path)
		{
			std::vector<DeclNode*> insideVars = std::vector<DeclNode*>();
			switch (testnode->getNodeType())
			{
				case NodeType::E_DECL:
				{
						DeclNode *insidevar = static_cast<DeclNode*>(testnode);
						insideVars.push_back(insidevar);
						break;
				}
				case NodeType::E_IF:
				{
						IfNode *insidevar = static_cast<IfNode*>(testnode);
						break;
				}
				case NodeType::E_WHILE:
				{
						break;
				}
				case NodeType::E_FOR:
				{
						for (int a = 0; a < 300; a++)
						{
							for (int b = 0; b < 300; b++)
							{

							}
						}
						break;
				}
				case NodeType::E_FUNC_CALL:
				{

						break;
				}
				case NodeType::E_ASSIGMENT:
				{
						OperationNode *node = static_cast<OperationNode*>(testnode);
						for (auto g : GlobalScope)
						{

							if (NodeType::E_DECL == g->getNodeType())
							{
								if (node->getleft()->getNodeType() == NodeType::E_STRUCTREF)
								{
									StructRef *Sref = static_cast<StructRef*>(node->getleft());

								}
								if (node->getleft()->getNodeType() == NodeType::E_ID)
								{

								}
								if (node->getleft()->getNodeType() == NodeType::E_ARRAY_REF)
								{

								}
								if (node->getleft()->getNodeType() == NodeType::E_STRUCT)
								{

								}

							}
						}
						break;
				}
				case NodeType::E_RETURN:
				{
						ReturnNode *ret = static_cast<ReturnNode*>(testnode);
						if (NewCase->getfunction_type()->gettype() == std::string("void"))
						{
							break;
						}
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
						NewCase->setreturnchecker(new CheckReturn(*(new Variable(NewCase->getfunction_type()->gettype(), ret->expr->ToString()))));
						if (NewCase->getfunction_type()->getispointer() != "" || NewCase->getfunction_type()->getisarray() != "")
						{
							NewCase->getreturnchecker()->setmemcheck(true);
						}

						if (NewCase->getfunction_type()->gettype().find("int") != std::string::npos)
						{
							NewCase->getreturnchecker()->getToCheck()->settype("int");
							NewCase->getreturnchecker()->setintcheck(true);

						}
						if (NewCase->getfunction_type()->gettype().find("char") != std::string::npos)
						{
							NewCase->getreturnchecker()->getToCheck()->settype("char");
							NewCase->getreturnchecker()->setcharcheck(true);

						}
						else
						{
							std::string type = GetTypeOfTypeDef(f->getreturntype()->getDeclType(), GlobalScope);
							if (type == "E_ENUM")
							{
								NewCase->getreturnchecker()->getToCheck()->settype(f->getreturntype()->getDeclType());
								NewCase->getreturnchecker()->setintcheck(true);
							}
						}
						break;
				}
				default:
				{
						break;
				}
			}

		}

		return (NewCase);

	}

	std::vector<TestCase*> TestCaseBuilder::BuildTestCases(Function *f, std::vector<FlowGraphNode*> GlobalScope)
	{
		std::vector<TestCase*> testcases = std::vector<TestCase*>();
		FlowGraphWalker *graphwalker = new FlowGraphWalker();
		//Stopwatch *sw = new Stopwatch();
		//sw->Start();

		std::vector<std::vector<FlowGraphNode*>> pathes = graphwalker->CalculateAllPathes(f->getNodeswithCopy());

		//sw->Stop();
		//std::cout << std::string("Elapsed for calculting pathes=") << sw->Elapsed << std::endl;

		for (auto path : pathes)
		{
			TestCase *NewCase = new TestCase();
			NewCase->setid(TestCaseBuilder::id++);
			std::vector<Variable*> args = std::vector<Variable*>();
			for (auto node : f->Getparams())
			{
				args.push_back(DeclNodeToVar(node, f));
			}

			NewCase->setArguments(&args);
			NewCase->setfunction_name(f->getname());
			NewCase->setfunction_type(DeclNodeToVar(f->getreturntype(), f));
			NewCase->setfunction_nodes(f->getNodeswithCopy());
			NewCase->setpath(&path);
			for (auto testnode : path)
			{
				std::vector<DeclNode*> insideVars = std::vector<DeclNode*>();
				switch (testnode->getNodeType())
				{
					case NodeType::E_DECL:
					{
							DeclNode *insidevar = static_cast<DeclNode*>(testnode);
							insideVars.push_back(insidevar);
							break;
					}
					case NodeType::E_IF:
					{
							break;
					}
					case NodeType::E_WHILE:
					{
							break;
					}
					case NodeType::E_FOR:
					{
							for (int a = 0; a < 300; a++)
							{
								for (int b = 0; b < 300; b++)
								{

								}
							}

							break;
					}
					case NodeType::E_FUNC_CALL:
					{

							break;
					}
					case NodeType::E_ASSIGMENT:
					{
							OperationNode *node = static_cast<OperationNode*>(testnode);
							for (auto g : GlobalScope)
							{

								if (NodeType::E_DECL == g->getNodeType())
								{
									if (node->getleft()->getNodeType() == NodeType::E_STRUCTREF)
									{
										StructRef *Sref = static_cast<StructRef*>(node->getleft());

									}
									if (node->getleft()->getNodeType() == NodeType::E_ID)
									{

									}
									if (node->getleft()->getNodeType() == NodeType::E_ARRAY_REF)
									{

									}
									if (node->getleft()->getNodeType() == NodeType::E_STRUCT)
									{

									}

								}
							}
							break;
					}
					case NodeType::E_RETURN:
					{
							ReturnNode *ret = static_cast<ReturnNode*>(testnode);
							if (NewCase->getfunction_type()->gettype() == "void")
							{
								break;
							}
//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString'
							NewCase->setreturnchecker(new CheckReturn(*(new Variable(NewCase->getfunction_type()->gettype(),ret->expr->ToString()))));
							if (NewCase->getfunction_type()->getispointer() != "" || NewCase->getfunction_type()->getisarray() != "")
							{
								NewCase->getreturnchecker()->setmemcheck(true);
							}

								if (NewCase->getfunction_type()->gettype().find("int") != std::string::npos)
								{
								NewCase->getreturnchecker()->getToCheck()->settype("int");
								NewCase->getreturnchecker()->setintcheck(true);

								}
							if (NewCase->getfunction_type()->gettype().find("char") != std::string::npos)
							{
								NewCase->getreturnchecker()->getToCheck()->settype("char");
								NewCase->getreturnchecker()->setcharcheck(true);

							}
							else
							{
								std::string type = GetTypeOfTypeDef(f->getreturntype()->getDeclType(),GlobalScope);
									if (type == "E_ENUM")
									{
										NewCase->getreturnchecker()->getToCheck()->settype(f->getreturntype()->getDeclType());
										NewCase->getreturnchecker()->setintcheck(true);
									}
							}
							break;
					}
					default:
					{
							break;
					}
				}

			}
			testcases.push_back(NewCase);

		}
				return testcases;
	}
}
