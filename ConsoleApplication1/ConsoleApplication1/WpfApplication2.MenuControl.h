#pragma once

#include <any>

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace WpfApplication2 { class TestCases; }
namespace WpfApplication2 { class Settings; }

namespace WpfApplication2
{
	/// <summary>
	/// Interaction logic for MenuControl.xaml
	/// </summary>
	class MenuControl : public UserControl
	{
	public:
		MenuControl();
private:
	void TestCases(std::any sender, RoutedEventArgs *e);

	void Settings(std::any sender, RoutedEventArgs *e);
	void File(std::any sender, RoutedEventArgs *e);
	void EditTemplate(std::any sender, RoutedEventArgs *e);
	};
}
