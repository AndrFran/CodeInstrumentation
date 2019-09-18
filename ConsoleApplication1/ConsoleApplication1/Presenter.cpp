//====================================================================================================
//The Free Edition of C# to C++ Converter limits conversion output to 100 lines per file.

//To subscribe to the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-csharp-to-cplus.html
//====================================================================================================

#include "Presenter.h"
#include "SyntaxTree.h"
#include "FlowGraphNode.h"
#include "JsonParser.h"
#include "TestCaseBuilder.h"

namespace WpfApplication2
{

std::vector<std::wstring> Presenter::chosen;
Presenter *Presenter::instance;

	std::wstring Presenter::getpreprocessorpath() const
	{
		return preprocessorpath;
	}

	void Presenter::setpreprocessorpath(const std::wstring &value)
	{
		preprocessorpath = value;
	}

	std::wstring Presenter::getprepargs() const
	{
		return prepargs;
	}

	void Presenter::setprepargs(const std::wstring &value)
	{
		prepargs = value;
	}

	std::vector<std::wstring> Presenter::getchosen()
	{
		return chosen;
	}

	void Presenter::setchosen(const std::vector<std::wstring> &value)
	{
		chosen = value;
	}

	Presenter::Presenter()
	{
		tree = new SyntaxTree();
		grids = std::vector<MyGrid*>();
		setpreprocessorpath(L"C:\\Users\\andre\\Downloads\\Dyplom\\LLVM\\bin\\clang.exe");
		setprepargs(L"-E");
	}

	Presenter *Presenter::getInstance()
	{
		if (instance == nullptr)
		{
			instance = new Presenter();
		}
		return instance;
	}

	MyGrid *Presenter::getNextRect(int x, int y, FlowGraphNode *node, std::vector<FlowGraphNode*> &path)
	{
		auto grid = new MyGrid();
		Rectangle *rect = nullptr;
		if (std::find(path.begin(), path.end(), node) != path.end())
		{
			rect = new Rectangle();
			rect->Width = NAN;
			rect->Height = NAN;
			rect->Fill = Brushes::LightBlue;
		}
		else
		{
			rect = new Rectangle();
			rect->Width = NAN;
			rect->Height = NAN;
			rect->Fill = Brushes::Azure;
		}
		rect->HorizontalAlignment = System::Windows::HorizontalAlignment::Stretch;
		rect->VerticalAlignment = System::Windows::VerticalAlignment::Stretch;
		grid->getChildren()->Add(rect);
		TextBlock *tex = new TextBlock();
//C# TO C++ CONVERTER TODO TASK: There is no C++ equivalent to 'ToString':
		tex->Text = node->ToString();
		tex->Foreground = Brushes::Black;
		grid->getChildren()->Add(tex);
		tex->Measure(System::Windows::Size(std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()));
		System::Windows::Size size = tex->DesiredSize;
		grid->setxpos(x - static_cast<int>(size.Width / 2));
		grid->setypos(y);

//C# TO C++ CONVERTER TODO TASK: A 'delete tex' statement was not added since tex was passed to a method or constructor. Handle memory management manually.
//C# TO C++ CONVERTER TODO TASK: A 'delete rect' statement was not added since rect was passed to a method or constructor. Handle memory management manually.
//C# TO C++ CONVERTER TODO TASK: A 'delete grid' statement was not added since grid was used in a 'return' or 'throw' statement.
		return grid;
	}

	MyGrid *Presenter::getNextDiamond(int x, int y, FlowGraphNode *node, std::vector<FlowGraphNode*> &path)
	{
		auto grid = new MyGrid();
		Rectangle *rect = nullptr;
		if (std::find(path.begin(), path.end(), node) != path.end())
		{
			rect = new Rectangle();
			rect->Width = 50;
			rect->Height = 50;
			rect->Fill = Brushes::LightBlue;
		}
		else
		{
			 rect = new Rectangle();
			 rect->Width = 50;
			 rect->Height = 50;
			 rect->Fill = Brushes::Azure;
		}
			rect->HorizontalAlignment = System::Windows::HorizontalAlignment::Stretch;
		rect->VerticalAlignment = System::Windows::VerticalAlignment::Stretch;
		RotateTransform *rotation = new RotateTransform();

		rotation->Angle = 45;
		rect->RenderTransform = rotation;
		grid->getChildren()->Add(rect);
		TextBlock *tex = new TextBlock();
//C# TO C++ CONVERTER TODO TASK: There is no C++ equivalent to 'ToString':
		tex->Text = L"\n" + node->ToString();
		tex->Foreground = Brushes::Black;
		grid->getChildren()->Add(tex);
		tex->Measure(System::Windows::Size(std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()));
		System::Windows::Size size = tex->DesiredSize;
		grid->setxpos(x - static_cast<int>(size.Width / 2) + 25);
		grid->setypos(y);

//C# TO C++ CONVERTER TODO TASK: A 'delete tex' statement was not added since tex was passed to a method or constructor. Handle memory management manually.
//C# TO C++ CONVERTER TODO TASK: A 'delete rotation' statement was not added since rotation was assigned to another object. Handle memory management manually.
//C# TO C++ CONVERTER TODO TASK: A 'delete rect' statement was not added since rect was passed to a method or constructor. Handle memory management manually.
//C# TO C++ CONVERTER TODO TASK: A 'delete grid' statement was not added since grid was used in a 'return' or 'throw' statement.
		return grid;
	}

	std::vector<System::Windows::UIElement*> Presenter::getArrows(int x, int y, Direction dir)
	{
		std::vector<System::Windows::UIElement*> l;
		Line *myLine1 = new Line();
		Line *myLine2 = new Line();

		switch (dir)
		{
			case Direction::E_RIGHT:
			{
					myLine1->X1 = x;
					myLine1->X2 = x + 10;
					myLine1->Y1 = y;
					myLine1->Y2 = y - 10;
					myLine2->X1 = x;
					myLine2->X2 = x + 10;
					myLine2->Y1 = y;
					myLine2->Y2 = y + 10;
					break;
			}
			case Direction::E_LEFT:
			{

					break;
			}
			case Direction::E_TOP:
			{

					break;
			}
			case Direction::E_DOWN:
			{

					break;
			}
		}
		myLine1->Stroke = System::Windows::Media::Brushes::LightSteelBlue;

		myLine1->StrokeThickness = 2;

//====================================================================================================
//End of the allowed output for the Free Edition of C# to C++ Converter.

//To subscribe to the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-csharp-to-cplus.html
//====================================================================================================
