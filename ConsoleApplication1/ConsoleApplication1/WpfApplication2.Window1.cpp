#include "WpfApplication2.Window1.h"
#include "Presenter.h"
#include "TestCaseBuilder.h"
#include "Properties/Resources.Designer.h"
#include "WpfApplication2.MainWindow.h"

using namespace Microsoft::Win32;
using namespace Nustache::Core;

namespace WpfApplication2
{

	Window1::Window1()
	{
		InitializeComponent();
	}

	void Window1::button2_Click(std::any sender, RoutedEventArgs *e)
	{
		Presenter *preseter = Presenter::getInstance();
		std::wstring directory = L"cd C:\\Users\\andre\\Downloads\\Dyplom\\pycparser-master";
		std::wstring pythonpath = L"python";
//C# TO C++ CONVERTER TODO TASK: There is no C++ equivalent to 'ToString':
		std::wstring GenerateAstCommand = pythonpath + L" " + L"examples\\c_json.py  " + L" " + input->Text->ToString() + L"  " + preseter->getpreprocessorpath() + L" " + preseter->getprepargs();
		std::wstring Text = L"/C " + directory + L"&" + GenerateAstCommand;
		Process *process = System::Diagnostics::Process::Start(L"CMD.exe", Text);
		process->WaitForExit();
		std::vector<std::wstring> names = preseter->ParseFuncNames(System::IO::File::ReadAllText(L"C:\\Users\\andre\\Downloads\\Dyplom\\pycparser-master\\ssss.json"));
		listBox::Items->Clear();
		for (auto str : names)
		{
			CheckBox *tempVar = new CheckBox();
			tempVar->IsChecked = std::make_optional(false);
			tempVar->Content = str;
			listBox::Items->Add(tempVar);

//C# TO C++ CONVERTER TODO TASK: A 'delete tempVar' statement was not added since tempVar was passed to a method or constructor. Handle memory management manually.
		}

	}

	void Window1::button_Click(std::any sender, RoutedEventArgs *e)
	{
		OpenFileDialog *openFileDialog = new OpenFileDialog();
		if (openFileDialog->ShowDialog() == true)
		{

			input->Text = openFileDialog->FileName;
		}

		delete openFileDialog;
	}

	void Window1::button1_Click(std::any sender, RoutedEventArgs *e)
	{
		OpenFileDialog *openFileDialog = new OpenFileDialog();
		if (openFileDialog->ShowDialog() == true)
		{

			output->Text = openFileDialog->FileName;
		}

		delete openFileDialog;
	}

	void Window1::button2_Copy_Click(std::any sender, RoutedEventArgs *e)
	{
		Presenter *preseter = Presenter::getInstance();
		std::vector<std::wstring> names;
		for (CheckBox *box : listBox::Items)
		{
			if (true == box->IsChecked)
			{
//C# TO C++ CONVERTER TODO TASK: There is no C++ equivalent to 'ToString':
				names.push_back(box->Content.ToString());

			}
		}

	   TestCases *cases = preseter->generateCases(names);
		auto html = Render::StringToString(Properties->Resources->gettemplate(), cases);
//C# TO C++ CONVERTER TODO TASK: There is no C++ equivalent to 'ToString':
		System::IO::File::WriteAllText(output->Text->ToString(), html);
		MainWindow *w = new MainWindow(cases->gettestcases().ToList());
		w->Show();

		delete w;
	}
}
