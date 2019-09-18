#pragma once

#include <string>
#include <vector>
#include <any>

using namespace Microsoft::Win32;
using namespace Nustache::Core;

namespace WpfApplication2
{
	/// <summary>
	/// Interaction logic for Window1.xaml
	/// </summary>
	class Window1 : public Window
	{
	public:
		Window1();

	private:
		void button2_Click(std::any sender, RoutedEventArgs *e);


		void button_Click(std::any sender, RoutedEventArgs *e);

		void button1_Click(std::any sender, RoutedEventArgs *e);

		void button2_Copy_Click(std::any sender, RoutedEventArgs *e);
	};
}
