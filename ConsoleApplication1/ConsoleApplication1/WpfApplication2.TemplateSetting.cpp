#include "WpfApplication2.TemplateSetting.h"
#include "Properties/Resources.Designer.h"

namespace WpfApplication2
{

	TemplateSetting::TemplateSetting()
	{
		InitializeComponent();
		richTextBox::AppendText(Properties->Resources->gettemplate());
	}
}
