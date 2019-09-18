// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include "FlowGraphNode.h"
#include "FlowGraphWalker.h"
#include "rapidjson-master/include/rapidjson/document.h"
#include "rapidjson-master/include/rapidjson/writer.h"
#include "rapidjson-master/include/rapidjson/stringbuffer.h"
#include "rapidjson-master/include/rapidjson/filereadstream.h"
#include "ValuableCopible.h"
#include "SyntaxTree.h"
#include "TestCaseBuilder.h"
using namespace rapidjson;
using namespace WpfApplication2;
int main()
{
	FILE* fp = fopen("C:\\Users\\andre\\source\\repos\\ConsoleApplication1\\Debug\\out.json", "r"); // non-Windows use "r"
	if (fp == NULL)
		printf("Error opening file unexist.ent: %s\n", strerror(errno));
	char readBuffer[65536];
	FileReadStream is(fp, readBuffer, sizeof(readBuffer));
	Document d;
	Document::AllocatorType& allocator = d.GetAllocator();

	d.ParseStream(is);
	SyntaxTree tree;


	ValueCopibable test = d;
	std::vector<std::string> funcNames = tree.Create(test);
	tree.ParseFunctions();

	std::vector<Function*> funcs = tree.GetFunctionByNames(funcNames);
	TestCaseBuilder builder;
	for(int i=0;i<funcs.size();i++)
	{
		builder.GenerateCases(funcs[i], tree.getGlobalScope());
	}
	std::vector<ValueCopibable> vect = std::vector<ValueCopibable>();
	vect.push_back(d["ext"]);
	const Value& a = d["ext"];
	assert(a.IsArray());
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
