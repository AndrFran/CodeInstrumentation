#include "WpfApplication2.Settings.h"
#include "Presenter.h"

namespace WpfApplication2
{

	Settings::Settings()
	{
		InitializeComponent();
	}

	void Settings::button_Click(std::any sender, RoutedEventArgs *e)
	{
		Microsoft::Win32::OpenFileDialog *openFileDialog = new Microsoft::Win32::OpenFileDialog();
		if (openFileDialog->ShowDialog() == true)
		{
			textBox->Text = openFileDialog->FileName;
			Presenter::getInstance()->setpreprocessorpath(openFileDialog->FileName);
		}

		delete openFileDialog;
	}

	void Settings::button_Copy_Click(std::any sender, RoutedEventArgs *e)
	{
		std::wstring args = textBox_Copy->Text;
		Presenter::getInstance()->setprepargs(args);
	}

	void Settings::textBox_TextChanged(std::any sender, TextChangedEventArgs *e)
	{

	}
}
