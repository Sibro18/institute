#pragma once
#include <utility>
#include <map>
namespace KursovayaYaziki {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBoxPath;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxEnd;
	private: System::Windows::Forms::TextBox^ textBoxStart;
	private: System::Windows::Forms::Button^ InputButton;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ buttonCalculate;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	public: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Panel^ panel2;
	public:static array<Drawing::PointF>^ nodes;
		  static array<String^>^ CandidatesPaths;
		   static int counterGraph = 0;
		   static String^ ShP = "";
		   static bool blueTopOrNot = false;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ referenceToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ taskToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;

	protected:

















	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxPath = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxEnd = (gcnew System::Windows::Forms::TextBox());
			this->textBoxStart = (gcnew System::Windows::Forms::TextBox());
			this->InputButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->buttonCalculate = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->referenceToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->taskToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->textBoxPath);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->textBoxEnd);
			this->panel1->Controls->Add(this->textBoxStart);
			this->panel1->Controls->Add(this->InputButton);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->buttonCalculate);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->richTextBox1);
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Controls->Add(this->menuStrip1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(830, 593);
			this->panel1->TabIndex = 16;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(351, 366);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(152, 31);
			this->label5->TabIndex = 28;
			this->label5->Text = L"Candidates";
			// 
			// textBoxPath
			// 
			this->textBoxPath->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxPath->Location = System::Drawing::Point(8, 332);
			this->textBoxPath->Name = L"textBoxPath";
			this->textBoxPath->ReadOnly = true;
			this->textBoxPath->Size = System::Drawing::Size(814, 26);
			this->textBoxPath->TabIndex = 27;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(769, 25);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(45, 24);
			this->label4->TabIndex = 26;
			this->label4->Text = L"End";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(710, 25);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 24);
			this->label3->TabIndex = 25;
			this->label3->Text = L"Start";
			// 
			// textBoxEnd
			// 
			this->textBoxEnd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxEnd->Location = System::Drawing::Point(773, 52);
			this->textBoxEnd->Name = L"textBoxEnd";
			this->textBoxEnd->Size = System::Drawing::Size(49, 24);
			this->textBoxEnd->TabIndex = 24;
			this->textBoxEnd->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBoxEnd_KeyPress);
			// 
			// textBoxStart
			// 
			this->textBoxStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxStart->Location = System::Drawing::Point(706, 52);
			this->textBoxStart->Name = L"textBoxStart";
			this->textBoxStart->Size = System::Drawing::Size(49, 24);
			this->textBoxStart->TabIndex = 23;
			this->textBoxStart->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBoxStart_KeyPress);
			// 
			// InputButton
			// 
			this->InputButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->InputButton->Location = System::Drawing::Point(76, 51);
			this->InputButton->Name = L"InputButton";
			this->InputButton->Size = System::Drawing::Size(624, 27);
			this->InputButton->TabIndex = 22;
			this->InputButton->Text = L"Input";
			this->InputButton->UseVisualStyleBackColor = true;
			this->InputButton->Click += gcnew System::EventHandler(this, &MyForm::InputButton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 24);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(242, 24);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Input the number of vertices";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(5, 54);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(65, 24);
			this->textBox1->TabIndex = 20;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyPress);
			// 
			// buttonCalculate
			// 
			this->buttonCalculate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->buttonCalculate->Location = System::Drawing::Point(5, 558);
			this->buttonCalculate->Name = L"buttonCalculate";
			this->buttonCalculate->Size = System::Drawing::Size(822, 30);
			this->buttonCalculate->TabIndex = 19;
			this->buttonCalculate->Text = L"Calculate";
			this->buttonCalculate->UseVisualStyleBackColor = true;
			this->buttonCalculate->Click += gcnew System::EventHandler(this, &MyForm::buttonCalculate_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(354, 298);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(176, 31);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Shortest path";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox1->Location = System::Drawing::Point(5, 400);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(814, 152);
			this->richTextBox1->TabIndex = 17;
			this->richTextBox1->Text = L"";
			this->richTextBox1->SelectionChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_SelectionChanged);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(5, 86);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataGridView1->Size = System::Drawing::Size(817, 209);
			this->dataGridView1->TabIndex = 16;
			this->dataGridView1->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellEndEdit);
			this->dataGridView1->CellValidating += gcnew System::Windows::Forms::DataGridViewCellValidatingEventHandler(this, &MyForm::dataGridView1_CellValidating);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->referenceToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(830, 24);
			this->menuStrip1->TabIndex = 29;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// referenceToolStripMenuItem
			// 
			this->referenceToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->taskToolStripMenuItem,
					this->helpToolStripMenuItem
			});
			this->referenceToolStripMenuItem->Name = L"referenceToolStripMenuItem";
			this->referenceToolStripMenuItem->Size = System::Drawing::Size(71, 20);
			this->referenceToolStripMenuItem->Text = L"Reference";
			// 
			// taskToolStripMenuItem
			// 
			this->taskToolStripMenuItem->Name = L"taskToolStripMenuItem";
			this->taskToolStripMenuItem->Size = System::Drawing::Size(99, 22);
			this->taskToolStripMenuItem->Text = L"Task";
			this->taskToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::taskToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(99, 22);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::helpToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(38, 20);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// panel2
			// 
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(830, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(361, 593);
			this->panel2->TabIndex = 17;
			this->panel2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel2_MouseClick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1191, 593);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Yen algorithm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void buttonCalculate_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void InputButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void dataGridView1_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && !Char::IsControl(e->KeyChar))
	{
		e->Handled = true;
	}
}
private: System::Void textBoxStart_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && !Char::IsControl(e->KeyChar))
	{
		e->Handled = true;
	}
}
private: System::Void textBoxEnd_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && !Char::IsControl(e->KeyChar))
	{
		e->Handled = true;
	}
}
private: System::Void dataGridView1_CellValidating(System::Object^ sender, System::Windows::Forms::DataGridViewCellValidatingEventArgs^ e) {
	int colInd = dataGridView1->CurrentCell->ColumnIndex;
	if (e->ColumnIndex == colInd) // замените yourColumnIndex на индекс вашего столбца
	{
		String^ value = e->FormattedValue->ToString();
		for each (char c in value)
		{
			if (!Char::IsDigit(c))
			{
				e->Cancel = true;
				MessageBox::Show("Input only digits");
				break;
			}
		}
	}
}
private: System::Void panel2_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void taskToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	MessageBox::Show("Дан связный неориентированный взвешенный граф G = <V, E> (V – конечное множество\
вершин, E – набор неупорядоченных пар вершин).Граф описывается целочисленной \
матрицей смежности. 1.3.Ввод с помощью матрицы и графа. Реализовать алгоритм Йена \
- найти несколько кратчайших путей без циклов между двумя заданными точками(K путей, \
	K задается).Предполагается, что умеем находить один кратчайший путь в графе : будем \
вести список кандидатов в кратчайшие пути, находится 1 кратчайший путь.Так как все \
другие пути не должны совпадать с 1 путем, то эти остальные пути не содержат как \
минимум одно из ребер 1 пути.Удаляем по 1 ребру из 1 пути и находим кратчайшие пути в \
получаемых графах.Найденные пути(с пометкой о том, какое ребро было выкинуто) \
добавляем в список кандидатов.Из списка кандидатов выбираем самый короткий путь — это \
2 самый короткий путь.Далее аналогично.При нахождении каждого самого короткого пути \
в список кандидатов добавляется не более N новых путей(обычно меньше).При удалении 1 \
ребра кратчайший путь в новом графе ищется с использованием деревьев, полученных для \
исходного графа");
}
private: System::Void helpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	MessageBox::Show("Программа созданна для нахождения кратчайшего пути и его кандидатов с помощью алгоритма Йена\n" \
		"Версия : 1.0\nГод разработки : 2023\nМесто разработки : Киров, ВятГУ\nРазработчик:Бровцын Александр ИнБс - 2301\n\n\
Указания к использованию: вводятся число вершин(больше 1 вершины), ввод осуществляется с помощью таблицы и/или графа. \
чтобы ввести вершину с помощью графа нужно нажать сначала на 1 любую вершину, потом на другую, введённое число отобразится в таблице. \
При не заполнении ячеек таблицы будет автозаполнение пустых ячеек 0-ми.\nМакс. кол-во вершин = 20, счёт идёт от 0", "Help");
}
private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Application::Exit();
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
{
	this->WindowState = FormWindowState::Maximized;
	this->DoubleBuffered = true;
}
private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e);
private: System::Void richTextBox1_SelectionChanged(System::Object^ sender, System::EventArgs^ e);
};
}
