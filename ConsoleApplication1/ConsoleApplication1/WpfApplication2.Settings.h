#pragma once

#include <string>
#include <any>

namespace WpfApplication2
{
	/// <summary>
	/// Interaction logic for Settings.xaml
	/// </summary>
	class Settings : public Window
	{
	public:
		Settings();

	private:
		void button_Click(std::any sender, RoutedEventArgs *e);

		void button_Copy_Click(std::any sender, RoutedEventArgs *e);

		void textBox_TextChanged(std::any sender, TextChangedEventArgs *e);
	};
}
