#include "WpfApplication2.MainWindow.h"
#include "TestCaseBuilder.h"
#include "Properties/Resources.Designer.h"
#include "Presenter.h"

using namespace WpfApplication2::Properties;
using namespace Nustache::Core;
using namespace Microsoft::Win32;

namespace WpfApplication2
{

	MainWindow::MainWindow()
	{
		InitializeComponent();
	}

	MainWindow::MainWindow(std::vector<TestCase*> &cases)
	{
		index = -1;
		InitializeComponent();
		this->cases = cases;
		Next(std::any(), nullptr);
	}

	void MainWindow::button_Click(std::any sender, RoutedEventArgs *e)
	{

	}

	void MainWindow::button_Click_1(std::any sender, RoutedEventArgs *e)
	{


	}

	void MainWindow::Next(std::any sender, RoutedEventArgs *e)
	{
		if (index + 1 < cases.size())
		{
			TestCase *NewCase = cases[++index];
			Draw(NewCase);
		}
	}

	void MainWindow::richTextBox_TextChanged(std::any sender, TextChangedEventArgs *e)
	{

	}

	void MainWindow::Prev(std::any sender, RoutedEventArgs *e)
	{
		if (index - 1 > -1)
		{
			TestCase *NewCase = cases[--index];
			Draw(NewCase);
		}
	}

	void MainWindow::Draw(TestCase *caseToDraw)
	{
		auto html = Render::StringToString(Properties->Resources::gettestcase(), caseToDraw);
		richTextBox::Document->Blocks->Clear();
		richTextBox::AppendText(html);
		DrawingField::Children->Clear();
		Presenter *presenter = Presenter::getInstance();
		int y = 0;
		std::vector<UIElement*> nodes = presenter->BuildFlowControlGraph(y, caseToDraw->getfunction_nodes(), caseToDraw->getpath().ToList());
		DrawingField->Height = y;
		for (auto elem : nodes)
		{
			DrawingField::Children->Add(elem);
		}
		for (auto elem : presenter->grids)
		{
			DrawingField::Children->Add(elem);
			Canvas::SetLeft(elem, elem->getxpos());
			Canvas::SetTop(elem, elem->getypos());
		}
	}
}
