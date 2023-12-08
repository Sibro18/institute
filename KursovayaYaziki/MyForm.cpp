#include "MyForm.h"
#include "AddEdge.h"
#include "FormForK.h"
//#include "YenKspFunc.h"
#include "YenKspSec.h"
#pragma comment(lib, "Gdiplus.lib")
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

using namespace System::Windows::Forms;


[STAThread]
void main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	KursovayaYaziki::MyForm form;
	Application::Run(% form);
}
std::vector<std::vector<double>> v;
int counterForEdgePaint = 0;
std::pair<bool, double> coords;
std::pair<bool, double> coords2;

void dgwCreateColums(DataGridView^ dgw, int ways);
void calculate(DataGridView^ dgw, RichTextBox^ RTB,TextBox^ start, TextBox^ end, TextBox^ path,Panel^ panel);
void drawGraph(Panel^ a, int size);
void drawEdges(Panel^ a, std::vector<std::vector<double>> b, DataGridView^ dgw);
void DrawShortestPath(Panel^ a, String^ path, DataGridView^ dgw, std::vector<std::vector<double>> b);
void DrawCandidate(Panel^ a, array<String^>^ path, DataGridView^ dgw, std::vector<std::vector<double>> b, int numOfPath);

System::String^ stringToSystemString(std::string a)
{
	System::String^ str3 = gcnew System::String(a.data());
	return str3;
}

System::Void KursovayaYaziki::MyForm::buttonCalculate_Click(System::Object^ sender, System::EventArgs^ e)
{

	if (dataGridView1->ColumnCount > 1)
	{
		bool flag = true;
		KursovayaYaziki::MyForm::counterGraph = 0;
		int counter = 0;
		for (int i = 0; i < dataGridView1->ColumnCount; i++)
		{
			for (int j = 0; j < dataGridView1->RowCount; j++)
			{
				if (!dataGridView1->Rows[j]->Cells[i]->Value && dataGridView1->Rows[j]->Cells[i]->Style->BackColor != Color::Aqua)
				{
					dataGridView1->Rows[i]->Cells[j]->Style->BackColor = Color::Aqua;
					dataGridView1->Rows[j]->Cells[i]->Style->BackColor = Color::LightGreen;
					dataGridView1->Rows[j]->Cells[i]->Value = "0";
					dataGridView1->Rows[i]->Cells[j]->Value = "0";
					dataGridView1->Rows[i]->Cells[j]->ReadOnly = true;
				}
			}
		}
		for (int i = 0; i < dataGridView1->Columns->Count; i++)
		{
			for (int j = 0; j < dataGridView1->Rows->Count; j++)
			{
				if (!dataGridView1->Rows[j]->Cells[i]->Value)
				{
					flag = false;
				}
			}
			if (flag)
			{
				counter++;
			}
		}

		if (String::IsNullOrEmpty(textBoxStart->Text) || String::IsNullOrEmpty(textBoxEnd->Text))
		{
			MessageBox::Show("Fill Path in TextBoxes");
		}
		else if ((Convert::ToInt32(textBoxStart->Text) == Convert::ToInt32(textBoxEnd->Text))
			|| Convert::ToInt32(textBoxStart->Text) >= counter || Convert::ToInt32(textBoxEnd->Text) >= counter)
		{
			MessageBox::Show("Input only correct path");
		}
		else
		{

			if (flag)
			{
				coords.first = 0;
				coords.second = 0;
				coords2.first = 0;
				coords2.second = 0;
				KursovayaYaziki::MyForm::counterGraph=0;
				KursovayaYaziki::MyForm::blueTopOrNot = false;
				counterForEdgePaint = 0;
				calculate(dataGridView1, richTextBox1, textBoxStart, textBoxEnd, textBoxPath, panel2);
			}
			else
			{
				MessageBox::Show("Fill all cells");
			}

		}
	}
	else
	{
		MessageBox::Show("Table is empty");
	}
}

System::Void KursovayaYaziki::MyForm::InputButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!String::IsNullOrEmpty(textBox1->Text) && Convert::ToInt32(textBox1->Text) > 1)
	{
		
		KursovayaYaziki::MyForm::counterGraph = 0;
		counterForEdgePaint = 0;
		panel2->Refresh();
		coords.first = 0;
		coords.second = 0;
		coords2.first = 0;
		coords2.second = 0;
		KursovayaYaziki::MyForm::blueTopOrNot = false;
		dataGridView1->RowHeadersWidth = 50;
		textBoxPath->Clear();
		richTextBox1->Clear();
		dgwCreateColums(dataGridView1, Convert::ToInt32(textBox1->Text));

		int size = dataGridView1->Columns->Count;
		v.resize(size);
		for (int i = 0; i < size; i++)
		{
			v[i].resize(size);
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				v[i][j] = 0;
			}
		}
		
		drawGraph(panel2,dataGridView1->Columns->Count);
		
	}
	else MessageBox::Show("Input number of vertices greater than 1 ");
}

System::Void KursovayaYaziki::MyForm::dataGridView1_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	panel2->Refresh();
	int a = dataGridView1->CurrentCell->RowIndex;
	int b = dataGridView1->CurrentCell->ColumnIndex;
	if (dataGridView1->CurrentCell->Value != "")
	{
		dataGridView1->CurrentCell->Style->BackColor = Drawing::Color::LightGreen;
		dataGridView1->Rows[b]->Cells[a]->Value = dataGridView1->CurrentCell->Value;
		dataGridView1->Rows[b]->Cells[a]->Style->BackColor = Drawing::Color::Aqua;
		dataGridView1->Rows[b]->Cells[a]->ReadOnly = true;
	}
	drawEdges(panel2, v, dataGridView1);
	drawGraph(panel2, v.size());
	if (textBoxPath->Text != "")
	{
		DrawShortestPath(panel2, ShP, dataGridView1, v);
	}
}

System::Void KursovayaYaziki::MyForm::panel2_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	
	int x = e->X;
	int y = e->Y;
	static int top1;
	for (int i = 0; i < KursovayaYaziki::MyForm::nodes->Length; i++)
	{
		int circleX = nodes[i].X;
		int circleY = nodes[i].Y;
		if ((coords.first && coords.second != nodes[i].X) && (x - circleX) * (x - circleX) + (y - circleY) * (y - circleY) <= 400)
		{
			if ((x - circleX) * (x - circleX) + (y - circleY) * (y - circleY) <= 400)
			{
				counterForEdgePaint++;
				Drawing::Font^ fnt = gcnew Drawing::Font("Arial", 9);
				Graphics^ pero = panel2->CreateGraphics();
				pero->FillEllipse(Brushes::Aqua, circleX - 10, circleY - 10, 20, 20);
				pero->DrawString(i.ToString(), fnt, Brushes::Black, circleX - 5, circleY - 6);
				coords2.first = true;
				coords2.second = nodes[i].X;
				if (counterForEdgePaint >= 2)
				{
					AddEdge^ form = gcnew AddEdge();
					
					if (top1 > i)
					{
						form->LabelVer1->Text = i.ToString();
						form->LabelVer2->Text = top1.ToString();
					}
					else
					{
						form->LabelVer1->Text = top1.ToString();
						form->LabelVer2->Text = i.ToString();
					}
					form->ShowDialog();
					if (form->add)
					{
						dataGridView1->Rows[Convert::ToInt32(form->LabelVer2->Text)]->Cells[Convert::ToInt32(form->LabelVer1->Text)]->Style->BackColor = Drawing::Color::LightGreen;
						dataGridView1->Rows[Convert::ToInt32(form->LabelVer2->Text)]->Cells[Convert::ToInt32(form->LabelVer1->Text)]->Value = Convert::ToInt32(form->textBox1->Text);

						for (int i = 0; i < dataGridView1->Columns->Count; i++)
						{
							for (int j = 0; j < dataGridView1->Rows->Count; j++)
							{
								if (dataGridView1->Rows[j]->Cells[i]->Value != dataGridView1->Rows[i]->Cells[j]->Value)
								{
									dataGridView1->Rows[i]->Cells[j]->Style->BackColor = Drawing::Color::Aqua;
									dataGridView1->Rows[i]->Cells[j]->Value = dataGridView1->Rows[j]->Cells[i]->Value;
									dataGridView1->Rows[i]->Cells[j]->ReadOnly = true;
								}

							}
						}
						for (int i = 0; i < dataGridView1->Columns->Count; i++)
						{
							DataGridViewCellStyle^ style = gcnew DataGridViewCellStyle();
							style->BackColor = Drawing::Color::Red;

							dataGridView1->Rows[i]->Cells[i]->Value = "0";
							dataGridView1->Rows[i]->Cells[i]->ReadOnly = true;
							dataGridView1->Rows[i]->Cells[i]->Style = style;
						}
						KursovayaYaziki::MyForm::counterGraph = 0;
						drawEdges(panel2, v,dataGridView1);
						KursovayaYaziki::MyForm::blueTopOrNot = true;
						if (textBoxPath->Text != "")
						{
							DrawShortestPath(panel2, ShP, dataGridView1, v);
						}
					}
					coords2.first = false;
					coords2.second = 0;
					counterForEdgePaint = 1;
					pero->FillEllipse(Drawing::Brushes::LightGreen, circleX - 10, circleY - 10, 20, 20);
					pero->DrawString(i.ToString(), fnt, Brushes::Black, circleX - 5, circleY - 6);
				}
			}
		}
		else
		{
			if (coords.first && coords.second == nodes[i].X && (x - circleX) * (x - circleX) + (y - circleY) * (y - circleY) <= 400)
			{
				Drawing::Font^ fnt = gcnew Drawing::Font("Arial", 9);
				Graphics^ pero = panel2->CreateGraphics();
				pero->FillEllipse(Drawing::Brushes::LightGreen, circleX - 10, circleY - 10, 20, 20);
				pero->DrawString(i.ToString(), fnt, Brushes::Black, circleX - 5, circleY - 6);
				coords.first = false;
				coords.second = 0;
				coords2.first = false;
				coords2.second = 0;
				counterForEdgePaint = 0;
				KursovayaYaziki::MyForm::blueTopOrNot = false;
				drawEdges(panel2,v, dataGridView1);
				if (textBoxPath->Text != "")
				{
					DrawShortestPath(panel2, ShP, dataGridView1, v);
				}
			}
			else if ((x - circleX) * (x - circleX) + (y - circleY) * (y - circleY) <= 400 && !coords.first)
			{
				counterForEdgePaint++;
				Drawing::Font^ fnt = gcnew Drawing::Font("Arial", 9);
				Graphics^ pero = panel2->CreateGraphics();
				pero->FillEllipse(Brushes::Aqua, circleX - 10, circleY - 10, 20, 20);
				pero->DrawString(i.ToString(), fnt, Brushes::Black, circleX - 5, circleY - 6);
				coords.first = true;
				coords.second = nodes[i].X;
				top1 = i;
				if (counterForEdgePaint >= 2)
				{
					AddEdge^ form = gcnew AddEdge();
					form->ShowDialog();
						counterForEdgePaint = 0;
				}
			}
		}
	}
	
}

System::Void KursovayaYaziki::MyForm::MyForm_Resize(System::Object^ sender, System::EventArgs^ e)
{
	panel2->Refresh();
	drawGraph(panel2, v.size());
	coords.first = 0;
	coords.second = 0;
	coords2.first = 0;
	coords2.second = 0;
	KursovayaYaziki::MyForm::counterGraph =0;
	counterForEdgePaint = 0;
	KursovayaYaziki::MyForm::blueTopOrNot = false;
	drawEdges(panel2, v, dataGridView1);
	if (textBoxPath->Text != "")
	{
		DrawShortestPath(panel2, KursovayaYaziki::MyForm::ShP, dataGridView1, v);
	}
	if (!String::IsNullOrEmpty(richTextBox1->Text) && KursovayaYaziki::MyForm::CandidatesPaths->Length != 0)
	{
		int currentLine = richTextBox1->GetLineFromCharIndex(richTextBox1->SelectionStart);
		if (!String::IsNullOrEmpty(richTextBox1->Lines[currentLine]))
		{
			DrawCandidate(panel2, KursovayaYaziki::MyForm::CandidatesPaths, dataGridView1, v, currentLine);
		}
	}
	
}

System::Void KursovayaYaziki::MyForm::richTextBox1_SelectionChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (!String::IsNullOrEmpty(richTextBox1->Text))
	{
		coords.first = 0;
		coords.second = 0;
		coords2.first = 0;
		coords2.second = 0;
		KursovayaYaziki::MyForm::counterGraph = 0;
		counterForEdgePaint = 0;
		KursovayaYaziki::MyForm::blueTopOrNot = false;
		panel2->Refresh();
		int currentLine = richTextBox1->GetLineFromCharIndex(richTextBox1->SelectionStart);
		drawEdges(panel2, v, dataGridView1);
		DrawShortestPath(panel2, KursovayaYaziki::MyForm::ShP, dataGridView1, v);
		if (!String::IsNullOrEmpty(richTextBox1->Lines[currentLine]))
		{
			DrawCandidate(panel2, KursovayaYaziki::MyForm::CandidatesPaths, dataGridView1, v, currentLine);
		}
		
		drawGraph(panel2, v.size());
	}
	
}


void dgwCreateColums(DataGridView^ dgw, int ways)
{
	dgw->Columns->Clear();
	int count = dgw->Columns->Count;
	if (dgw->Columns->Count + ways < 21)
	{
		for (int i = count; i < count + ways; i++)
		{
			dgw->Columns->Add("id" + i.ToString(), i.ToString());
			dgw->Rows->Add();
			dgw->Rows[i]->HeaderCell->Value = i.ToString();
			dgw->Rows[i]->HeaderCell->Style->Alignment = DataGridViewContentAlignment::MiddleLeft;
		}
		for (int i = 0; i < dgw->Columns->Count; i++)
		{
			DataGridViewCellStyle^ style = gcnew DataGridViewCellStyle();
			style->BackColor = Drawing::Color::Red;

			dgw->Rows[i]->Cells[i]->Value = "0";
			dgw->Rows[i]->Cells[i]->ReadOnly = true;
			dgw->Rows[i]->Cells[i]->Style = style;
		}
		for each (DataGridViewColumn ^ column in dgw->Columns)
		{
			column->SortMode = DataGridViewColumnSortMode::NotSortable;
		}
	}
	else
	{
		MessageBox::Show("The maximum number of vertices has been reached");
	}
	

}


void calculate(DataGridView^ dgw, RichTextBox^ RTB, TextBox^ start, TextBox^ end, TextBox^ path, Panel^ panel)
{
	
	int zeroCounter = 0;
	for (int i = 0; i < dgw->RowCount; i++)
	{
		String^ a = dgw->Rows[Convert::ToInt32(end->Text)]->Cells[i]->Value->ToString();
		if (a == "0")
		{
			zeroCounter++;
		}
	}
	if (zeroCounter != v.size())
	{
		KursovayaYaziki::FormForK^ form = gcnew KursovayaYaziki::FormForK();
		form->ShowDialog();
		if (form->exist)
		{
			for (int i = 0; i < dgw->ColumnCount; i++)
			{
				for (int j = 0; j < dgw->RowCount; j++)
				{
					v[i][j] = Convert::ToDouble(dgw->Rows[j]->Cells[i]->Value->ToString());
				}
			}
			panel->Refresh();
			RTB->Clear();
			path->Clear();
			Graph^ graph = DataReader::ReadGraph(dgw);
			YensAlgorithm^ yen = gcnew YensAlgorithm(graph);
			String^ pathInput = "";
			int costDijekstra = 0;
			List<Vertex^>^ DijekstraPath = gcnew List<Vertex^>();
			Vertex^ startVertex = graph->GetVertex(start->Text);
			Vertex^ endVertex = graph->GetVertex(end->Text);
			yen->Dijkstra(startVertex);
			costDijekstra = yen->verticesInfo[endVertex]->DistanceToVertex;
			DijekstraPath->AddRange(yen->verticesInfo[endVertex]->Path);
			for each (Vertex ^ item in DijekstraPath)
			{
				pathInput += item->Name + " ";
			}
			path->Text = "Shortest path: " + pathInput + " Weight: " + costDijekstra;
			KursovayaYaziki::MyForm::ShP = pathInput;
			List<Path^>^ temp1 = gcnew List<Path^>();
			temp1->AddRange(yen->Yen(startVertex, endVertex, Convert::ToInt32(form->numericUpDown1->Text)));
			List<String^>^ candPaths = gcnew List<String^>();
			for each (Path ^ item in temp1)
			{
				int weight = 0;
				String^ pyt = " ";

				for each (Vertex ^ jtem in item->Route)
				{
					pyt += jtem->Name + " ";
				}
				weight = item->Weight;
				RTB->Text += " Path:" + pyt + " Path weight : " + weight + " Remoted edge : " + item->DeletedEdge->Item1->Name + "\
 - > " + item->DeletedEdge->Item2->Name + stringToSystemString("\n");
				candPaths->Add(pyt);
			}
			KursovayaYaziki::MyForm::CandidatesPaths = candPaths->ToArray();
			drawEdges(panel, v,dgw);
			drawGraph(panel, v.size());
			DrawShortestPath(panel, KursovayaYaziki::MyForm::ShP, dgw, v);
			
		}
		else
		{
			MessageBox::Show("Input number of candidates");
		}
	}
	else
	{
		MessageBox::Show("It is impossible to calculate the shortest path");
	}
}





void drawGraph(Panel^ a, int size)
{
	System::Drawing::Graphics^ g = a->CreateGraphics();
	int n = size;
	float radius = 350.0f;
	float centerX = (float)a->Width / 2;
	float centerY = (float)a->Height / 2;
	KursovayaYaziki::MyForm::nodes = gcnew array<Drawing::PointF>(n);
	for (int i = 0; i < n; i++) {
		float angle = 2 * 3.14159 * i / n;
		float x = centerX + radius * Math::Cos(angle);
		float y = centerY + radius * Math::Sin(angle);
		float width = 20;
		float height = 20;
		/*	std::pair<Drawing::PointF, int> tempVal;
			tempVal.first = Drawing::PointF(x, y);
			tempVal.second = i;
			verticeAndCoords.push_back(tempVal);*/
		Drawing::Font^ fnt = gcnew Drawing::Font("Arial", 10);
		KursovayaYaziki::MyForm::nodes[i] = Drawing::PointF(x, y);
		//g->DrawString(i.ToString(), Drawing::Font("Arial", 9), Drawing::Brushes::Black, x - 10, y - 10);
		g->DrawEllipse(Drawing::Pens::Black, x - 10, y - 10, width, height);
		g->FillEllipse(Drawing::Brushes::LightGreen, x - 10, y - 10, width, height);
		g->DrawString(i.ToString(), fnt, Drawing::Brushes::Black, x - 5, y - 6);
	}
}

void drawEdges(Panel^a, std::vector<std::vector<double>> b, DataGridView^ dgw)
{
	
	System::Drawing::Graphics^ g = a->CreateGraphics();
	for (int i = 0; i < b.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			if (dgw->Rows[i]->Cells[j]->Value != "0" && dgw->Rows[i]->Cells[j]->Value != nullptr)
			{
				b[i][j] = Convert::ToDouble(dgw->Rows[i]->Cells[j]->Value->ToString());
			}
		}
	}
	int n = b.size();
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (b[i][j]) {
				// Рисуем линию между вершинами
				g->DrawLine(Drawing::Pens::Black, KursovayaYaziki::MyForm::nodes[i].X + 10, KursovayaYaziki::MyForm::nodes[i].Y + 10, KursovayaYaziki::MyForm::nodes[j].X + 10, KursovayaYaziki::MyForm::nodes[j].Y + 10);
				// Рисуем вес ребра
				int weight = b[i][j];
				float x = (KursovayaYaziki::MyForm::nodes[i].X + KursovayaYaziki::MyForm::nodes[j].X) / 2;
				float y = (KursovayaYaziki::MyForm::nodes[i].Y + KursovayaYaziki::MyForm::nodes[j].Y) / 2;
				g->FillEllipse(Drawing::Brushes::GhostWhite, x, y, 20.0f, 20.0f);
				g->DrawString(weight.ToString(), gcnew Drawing::Font("Arial", 10), Drawing::Brushes::Black, x, y);
			}
		}
	}
	if (!KursovayaYaziki::MyForm::counterGraph)
	{
		KursovayaYaziki::MyForm::counterGraph++;
	}
	else
	{
		drawGraph(a, n);
	}
	
	
}

void DrawShortestPath(Panel^ a, String^ path, DataGridView^ dgw, std::vector<std::vector<double>> b)
{
	System::Drawing::Graphics^ g = a->CreateGraphics();
	for (int i = 0; i < b.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			if (dgw->Rows[i]->Cells[j]->Value != "0" && dgw->Rows[i]->Cells[j]->Value != nullptr)
			{
				b[i][j] = Convert::ToDouble(dgw->Rows[i]->Cells[j]->Value->ToString());
			}
		}
	}
	int n = b.size();
	array<String^>^ splitPath = path->Split();

	if (splitPath[splitPath->Length - 1] == "")
	{
		List<String^>^ list = gcnew List<String^>(splitPath);
		list->RemoveAt(list->Count - 1); // Удалить последний элемент

		splitPath = list->ToArray(); // Преобразовать список обратно в массив
	}
	for (int i = 0; i < splitPath->Length - 1; i++)
	{
		int itter = Convert::ToInt32(splitPath[i]);
		int itter2 = Convert::ToInt32(splitPath[i + 1]);
		if (b[itter][itter2])
		{
			Drawing::Pen^ redPen = gcnew Drawing::Pen(Drawing::Brushes::Red, 4.0F);
			redPen->StartCap = System::Drawing::Drawing2D::LineCap::RoundAnchor;
			redPen->Drawing::Pen::EndCap = System::Drawing::Drawing2D::LineCap::ArrowAnchor;
			g->DrawLine(redPen, KursovayaYaziki::MyForm::nodes[itter].X + 10, KursovayaYaziki::MyForm::nodes[itter].Y + 10,
				KursovayaYaziki::MyForm::nodes[itter2].X + 10, KursovayaYaziki::MyForm::nodes[itter2].Y + 10);
			// Рисуем вес ребра
			int weight = b[itter][itter2];
			float x = (KursovayaYaziki::MyForm::nodes[itter].X + KursovayaYaziki::MyForm::nodes[itter2].X) / 2;
			float y = (KursovayaYaziki::MyForm::nodes[itter].Y + KursovayaYaziki::MyForm::nodes[itter2].Y) / 2;
			g->FillEllipse(Drawing::Brushes::GhostWhite, x, y, 20.0f, 20.0f);
			g->DrawString(weight.ToString(), gcnew Drawing::Font("Arial", 10), Drawing::Brushes::Black, x, y);
		}
	}
	if (!KursovayaYaziki::MyForm::blueTopOrNot)
	{
		drawGraph(a, n);
	}	
}

void DrawCandidate(Panel^ a, array<String^>^ path, DataGridView^ dgw, std::vector<std::vector<double>> b, int numOfPath)
{
	System::Drawing::Graphics^ g = a->CreateGraphics();
	for (int i = 0; i < b.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			if (dgw->Rows[i]->Cells[j]->Value != "0" && dgw->Rows[i]->Cells[j]->Value != nullptr)
			{
				b[i][j] = Convert::ToDouble(dgw->Rows[i]->Cells[j]->Value->ToString());
			}
		}
	}
	array<String^>^ temp = path[numOfPath]->Split();
	if (temp[temp->Length-1] == "")
	{
		List<String^>^ list = gcnew List<String^>(temp);
		list->RemoveAt(list->Count - 1); // Удалить последний элемент

		temp = list->ToArray(); // Преобразовать список обратно в массив
	}
	if (temp[0] == "")
	{
		List<String^>^ list = gcnew List<String^>(temp);
		list->RemoveAt(0); // Удалить последний элемент

		temp = list->ToArray(); // Преобразовать список обратно в массив
	}
	for (int i = 0; i < temp->Length - 1; i++)
	{
		int itter = Convert::ToInt32(temp[i]);
		int itter2 = Convert::ToInt32(temp[i + 1]);
		if (b[itter][itter2])
		{
			Drawing::Pen^ BluePen = gcnew Drawing::Pen(Drawing::Brushes::Blue, 4.0F);
			BluePen->StartCap = System::Drawing::Drawing2D::LineCap::RoundAnchor;
			BluePen->Drawing::Pen::EndCap = System::Drawing::Drawing2D::LineCap::ArrowAnchor;
			g->DrawLine(BluePen, KursovayaYaziki::MyForm::nodes[itter].X + 10, KursovayaYaziki::MyForm::nodes[itter].Y + 10,
				KursovayaYaziki::MyForm::nodes[itter2].X + 10, KursovayaYaziki::MyForm::nodes[itter2].Y + 10);
			// Рисуем вес ребра
			int weight = b[itter][itter2];
			float x = (KursovayaYaziki::MyForm::nodes[itter].X + KursovayaYaziki::MyForm::nodes[itter2].X) / 2;
			float y = (KursovayaYaziki::MyForm::nodes[itter].Y + KursovayaYaziki::MyForm::nodes[itter2].Y) / 2;
			g->FillEllipse(Drawing::Brushes::GhostWhite, x, y, 20.0f, 20.0f);
			g->DrawString(weight.ToString(), gcnew Drawing::Font("Arial", 10), Drawing::Brushes::Black, x, y);
		}
	}
	drawGraph(a, b.size());
}