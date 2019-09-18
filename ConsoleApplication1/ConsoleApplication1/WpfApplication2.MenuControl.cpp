#include "WpfApplication2.MenuControl.h"
#include "TestCaseBuilder.h"
#include "WpfApplication2.MainWindow.h"
#include "WpfApplication2.Settings.h"
#include "WpfApplication2.TemplateSetting.h"

namespace WpfApplication2
{

	MenuControl::MenuControl()
	{
		InitializeComponent();
	}

	void MenuControl::TestCases(std::any sender, RoutedEventArgs *e)
	{
			MainWindow *win2 = new MainWindow();
			win2->Show();

			delete win2;
	}

	void MenuControl::Settings(std::any sender, RoutedEventArgs *e)
	{
			WpfApplication2::Settings *win2 = new Settings();
			win2->Show();

			delete win2;
	}

	void MenuControl::File(std::any sender, RoutedEventArgs *e)
	{

	}

	void MenuControl::EditTemplate(std::any sender, RoutedEventArgs *e)
	{
			TemplateSetting *win2 = new TemplateSetting();
			win2->Show();

			delete win2;
	}
}
