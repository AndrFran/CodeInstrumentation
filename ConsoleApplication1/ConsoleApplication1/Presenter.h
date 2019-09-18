#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <limits>

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace WpfApplication2 { class SyntaxTree; }
namespace WpfApplication2 { class MyGrid; }
namespace WpfApplication2 { class FlowGraphNode; }
namespace WpfApplication2 { class TestCases; }

namespace WpfApplication2

{
	class Presenter
	{
	private:
		std::wstring preprocessorpath;
		std::wstring prepargs;
		static std::vector<std::wstring> chosen;

		static Presenter *instance;
		SyntaxTree *tree;
	public:
		virtual ~Presenter()
		{
			delete tree;
		}

		std::wstring getpreprocessorpath() const;
		void setpreprocessorpath(const std::wstring &value);
		std::wstring getprepargs() const;
		void setprepargs(const std::wstring &value);
//		#region pidor
	private:
		int depth = 0;
		static constexpr int linelenght = 20;
		static constexpr int smallLineshift = 5;
	public:
		std::vector<MyGrid*> grids;
//		#endregion
		static std::vector<std::wstring> getchosen();
		static void setchosen(const std::vector<std::wstring> &value);
	private:
		Presenter();
	public:
		static Presenter *getInstance();
	private:
		MyGrid *getNextRect(int x, int y, FlowGraphNode *node, std::vector<FlowGraphNode*> &path);
		MyGrid *getNextDiamond(int x, int y, FlowGraphNode *node, std::vector<FlowGraphNode*> &path);
	private:
		enum class Direction
		{
			E_RIGHT,
			E_LEFT,
			E_TOP,
			E_DOWN
		};
	private:
		std::vector<System::Windows::UIElement*> getArrows(int x, int y, Direction dir);
	   std::vector<System::Windows::UIElement*> getNextLine(int x, int y);
		std::vector<System::Windows::UIElement*> getNextifLine(int x, int y, int x2);
	public:
		std::vector<std::wstring> ParseFuncNames(const std::wstring &json);
		TestCases *generateCases(std::vector<std::wstring> &funcnames);
		std::vector<System::Windows::UIElement*> BuildFlowControlGraph(int &y, std::vector<FlowGraphNode*> &Nodes, std::vector<FlowGraphNode*> &path);
		std::vector<System::Windows::UIElement*> generateShapes(std::vector<FlowGraphNode*> &nodes, int x, int &y, std::vector<FlowGraphNode*> &path);
	};

	class MyGrid : public Grid
	{
	private:
		int xpos = 0;
		int ypos = 0;

	public:
		int getxpos() const;
		void setxpos(int value);
		int getypos() const;
		void setypos(int value);
	};
}
