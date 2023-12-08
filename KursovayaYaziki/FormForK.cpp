#include "FormForK.h"

System::Void KursovayaYaziki::FormForK::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	KursovayaYaziki::FormForK::exist = true;
	this->Close();
}
