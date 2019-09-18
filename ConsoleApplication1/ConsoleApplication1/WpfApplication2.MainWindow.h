#pragma once

#include <vector>
#include <any>

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace WpfApplication2 { class TestCase; }

using namespace WpfApplication2::Properties;
using namespace Nustache::Core;
using namespace Microsoft::Win32;

namespace WpfApplication2
{
	/// <summary>
	/// Interaction logic for MainWindow.xaml
	/// </summary>
	class MainWindow : public Window
	{
	private:
		int index = 0;
		std::vector<TestCase*> cases;
	public:
		MainWindow();
		MainWindow(std::vector<TestCase*> &cases);
	private:
		void button_Click(std::any sender, RoutedEventArgs *e);

		void button_Click_1(std::any sender, RoutedEventArgs *e);
		void Next(std::any sender, RoutedEventArgs *e);



		void richTextBox_TextChanged(std::any sender, TextChangedEventArgs *e);
		void Prev(std::any sender, RoutedEventArgs *e);
		void Draw(TestCase *caseToDraw);
	};
}
