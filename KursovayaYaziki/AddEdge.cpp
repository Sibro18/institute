#include "AddEdge.h"
#include "MyForm.h"
System::Void KursovayaYaziki::AddEdge::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    KursovayaYaziki::AddEdge::add = true;
    if (String::IsNullOrEmpty(textBox1->Text)) add = false;
    this->Close();
}

System::Void KursovayaYaziki::AddEdge::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    KursovayaYaziki::AddEdge::add = false;
    this->Close();
}
