#pragma once

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <list>
#include <limits>
using namespace System;
using namespace System::Collections::Generic;


ref class Vertex //Класс Вершин, который содержит название вершины
{
public:
    String^ Name;

    Vertex(String^ n)
    {
        Name = n;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ref class Edge //Класс ребра, который содержит вес между 1 вершиной и 2-ой вершиной
{
public:
    int weight;
    Vertex^ Vertex1; //вершина 1
    Vertex^ Vertex2; //вершина 2

    Edge(Vertex^ v1, Vertex^ v2, int w)
    {
        Vertex1 = v1;
        Vertex2 = v2;
        weight = w;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ref class Graph 
{
public:
    //Словарь вершин содержавй ключ имени вершины и саму вершину
    Dictionary<String^, Vertex^>^ Vertices;  
    // Слоаврь который содержит 1 вершину в качестве ключа и словарь других вершин и их значений
    Dictionary<Vertex^, Dictionary<Vertex^, int>^>^ Struct;
    bool Bidirectional;
    //инизиалицая графа
    Graph() 
    {
        Vertices = gcnew Dictionary<String^, Vertex^>(); 
        Struct = gcnew Dictionary<Vertex^, Dictionary<Vertex^, int>^>();
    }
    //инизиалицая вершины
    void AddVertex(String^ vertexName)
    {
        if (!Vertices->ContainsKey(vertexName)) 
        {
            //Если словарь вершин не содержит вершину то создаём новый объект двух словарей
            Vertices[vertexName] = gcnew Vertex(vertexName);
            Struct[Vertices[vertexName]] = gcnew Dictionary<Vertex^, int>();
        }
    }


    Vertex^ GetVertex(String^ vertexName) 
    {
        return Vertices[vertexName];
    }

    //Добавлени ребра между первой и второй вершинами и их вес.
    void AddEdge(Tuple<Vertex^, Vertex^, int>^ v)
    {
        AddEdge(v->Item1, v->Item2, v->Item3);
    }
    
    //Добавление ребра между первой и второй вершинами и их вес используя String переменные.
    void AddEdge(String^ vertex1, String^ vertex2, String^ weight) 
    {
        AddEdge(Vertices[vertex1], Vertices[vertex2], Convert::ToInt32(weight));
    }
    //Добавление вершин и весов между вершинами в словар Struct.
    void AddEdge(Vertex^ vertex1, Vertex^ vertex2, int weight)
    {
        Struct[vertex1]->Add(vertex2, weight);
        //if (Bidirectional)
        Struct[vertex2]->Add(vertex1, weight);
    }
   
    //Создание триплента ребра
    Tuple<Vertex^, Vertex^, int>^ RemoveEdge(Vertex^ v1, Vertex^ v2) 
    {
        Tuple<Vertex^, Vertex^, int>^ delEdge = nullptr;
        int deletedEdgeWeight; //вес удалённого ребра
        if (Struct[v1]->TryGetValue(v2, deletedEdgeWeight))
        {
            Struct[v1]->Remove(v2); // удаление и добавление вершины к списку удалённых вершин
            //if (Bidirectional)
                Struct[v2]->Remove(v1); //то же самое
            delEdge = Tuple::Create(v1, v2, deletedEdgeWeight);
        }
        return delEdge;
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ref class Path 
{
public:
    List<Vertex^>^ Route; // Создание списка путей кандидатов
    int Weight; //вес пути
    Tuple<Vertex^, Vertex^, int>^ DeletedEdge; //триплет удалённого ребра

    Path(List<Vertex^>^ route, int weight, Tuple<Vertex^, Vertex^, int>^ deletedEdge)
    {
        this->Route = route;
        this->Weight = weight;
        this->DeletedEdge = deletedEdge;
    }

    Path() 
    {
        this->Route = gcnew List<Vertex^>();
        this->Weight = 0;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ref class VertexInfo //Класс содержащий всю информацию о вершине
{
public:
    Vertex^ vert; //Вершина
    bool IsVisited; // Посещали или нет
    int DistanceToVertex; // Дистанция до вершины
    List<Vertex^>^ Path; //Список путей

    VertexInfo(Vertex^ v, int dist, List<Vertex^>^ path) \
    {
        path = nullptr;
        dist = std::numeric_limits<int>::max();
        vert = v;
        DistanceToVertex = dist;
        if (!path)
        {
            Path = gcnew List<Vertex^>();
        }
        else
        {
            Path = path;
        }
        IsVisited = false;
    }

    int CompareTo(VertexInfo^ other)  //Сравнение нового объекта с другими объектами типа VertexInfo
    {
        int num = 0;
        if (DistanceToVertex != other->DistanceToVertex)
        {
            num = this->DistanceToVertex.CompareTo(other->DistanceToVertex);
        }
        else
        {
            num = this->vert->Name->CompareTo(other->vert->Name);
        }
        return num;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ref class YensAlgorithm 
{
public:
    Graph^ yenGraph; //Создание графа
    Dictionary<Vertex^, VertexInfo^>^ verticesInfo; //Создание словаря с ключом в виде вершины и информации о вершине.

    YensAlgorithm(Graph^ g) 
    {
        yenGraph = g;
        verticesInfo = gcnew Dictionary<Vertex^, VertexInfo^>();
        for each (Vertex^ kvp in g->Vertices->Values)
        {
            verticesInfo->Add(kvp,gcnew VertexInfo(kvp,INT32_MAX,nullptr));
        }
    }

    Vertex^ FindUnvisitedMin() //Поиск не посещённых вершин
    {
        Vertex^ nearestVertex = nullptr;
        int minDistance = INT32_MAX;
        for each (KeyValuePair<Vertex^, VertexInfo^>^ kvp in verticesInfo)
        {
            if (!kvp->Value->IsVisited)
            {
                if (minDistance > kvp->Value->DistanceToVertex)
                {
                    minDistance = kvp->Value->DistanceToVertex;
                    nearestVertex = kvp->Value->vert;
                }
            }
        }
        return nearestVertex;
    }

    void FillingDistanceAndPathInNears(Vertex^ graphVertex) //Заполнение Словаря дистанциями и расстоянием с ближайшими вершинами
    {
        int pathWeight = 0;
        List<Vertex^>^ verticesPath = gcnew List<Vertex^>();
        verticesPath->AddRange(verticesInfo[graphVertex]->Path);

        for each(KeyValuePair<Vertex^, int>^ kvp in yenGraph->Struct[graphVertex])
        {
            Vertex^ nearVertex = kvp->Key;
            pathWeight = verticesInfo[graphVertex]->DistanceToVertex + kvp->Value;
            if (pathWeight < verticesInfo[nearVertex]->DistanceToVertex) 
            {
                if (verticesInfo[nearVertex]->Path)
                {
                    verticesInfo[nearVertex]->Path->Clear();
                }
                verticesInfo[nearVertex]->Path->AddRange(verticesPath);
                verticesInfo[nearVertex]->Path->Add(nearVertex);
                verticesInfo[nearVertex]->DistanceToVertex = pathWeight;
            }
        }
    }
    void Dijkstra(String^ vertex) //Функция перенаправления получающая имя вершины
    {
        Dijkstra(yenGraph->GetVertex(vertex)); //перенаправление в функцию поиска кратчайшего пути
    }

    void Dijkstra(Vertex^ start) 
    {
        Vertex^ current = start;
        verticesInfo[current]->Path->Add(current);
        verticesInfo[current]->DistanceToVertex = 0;

        while (current != nullptr) //Заполнение VertexInfo пока есть доступные вершины
        {
            FillingDistanceAndPathInNears(current); 
            verticesInfo[current]->IsVisited= true;
            current = FindUnvisitedMin();
        }
    }

    void ResetVerticesInfo(Dictionary<String^, Vertex^>::Enumerator^ item) //удаляем ребро
    {
        item->MoveNext();
        if (item->Current.Key != nullptr)
        {
            
            KeyValuePair<String^, Vertex^>^ jtem = item->Current;
            verticesInfo[jtem->Value]->IsVisited = false;
            verticesInfo[jtem->Value]->DistanceToVertex = INT_MAX;
            verticesInfo[jtem->Value]->Path->Clear();
            
            ResetVerticesInfo(item);
        }
    }
    void MainAlgYenCircleFor(List<Path^>^& gen, List<Vertex^>^& shortestPathInGen,Vertex^& start,Vertex^& end,int i)
    {
        if (i < shortestPathInGen->Count - 1)
        {
            Tuple<Vertex^, Vertex^, int>^ deadEdge = yenGraph->RemoveEdge(shortestPathInGen[i], shortestPathInGen[i + 1]); //Добавляем удалённую вершину к списку.
            Dictionary<String^, Vertex^>::Enumerator^ enumerator = yenGraph->Vertices->GetEnumerator();
            ResetVerticesInfo(enumerator);
            Dijkstra(start); // запускаем дейкстру

            Path^ temp = gcnew Path();

            temp->Route->AddRange(verticesInfo[end]->Path);
            temp->Weight = verticesInfo[end]->DistanceToVertex;

            temp->DeletedEdge = Tuple::Create(deadEdge->Item1, deadEdge->Item2, deadEdge->Item3);

            gen->Add(temp);//добавляем новый найденный путь
            yenGraph->AddEdge(deadEdge); //Добавляем удалённое ребро
            MainAlgYenCircleFor(gen, shortestPathInGen, start, end, i + 1);
        }
    }
    List<Path^>^ YenAlg(Vertex^ start, Vertex^ end) 
    {
        List<Path^>^ gen = gcnew List<Path^>();
        List<Vertex^>^ shortestPathInGen = gcnew List<Vertex^>();
        shortestPathInGen->AddRange(verticesInfo[end]->Path);
        
        MainAlgYenCircleFor(gen, shortestPathInGen, start, end, 0);
        
        return gen;
    }

    void RecursiveForEachPaths(List<Path^>^& generation, int index, Path^ &bestItem, int &minLength)
    {
        bool flag = true;
        if (index >= generation->Count)
        {
            flag = false;
        }
        if (flag)
        {
            Path^ item = generation[index];
            if (item->Weight < minLength)
            {
                minLength = item->Weight;

                if (bestItem->Route != nullptr)
                {
                    bestItem->Route->Clear();
                }
                bestItem->Route->AddRange(item->Route);
                bestItem->Weight = item->Weight;
                bestItem->DeletedEdge = Tuple::Create(item->DeletedEdge->Item1, item->DeletedEdge->Item2, 0);
            }
            RecursiveForEachPaths(generation, index + 1, bestItem, minLength); // Рекурсивно вызываем функцию для следующего элемента
        }    
    }
    void RecursiveMainCirkleYen(List<Path^>^& generation, List<Path^>^& best, Vertex^& start, Vertex^& end, int& count,int index)
    {
        bool flag = true;
        if (index < count)
        {
            generation->AddRange(YenAlg(start, end));
            int minLength = INT_MAX;
            Path^ bestItem = gcnew Path();
            RecursiveForEachPaths(generation, 0, bestItem, minLength);
            if (minLength == INT_MAX)
            {
                flag = false;
            }
            if (flag)
            {
                generation->Clear();//Чистим список возможных новых путей
                yenGraph->RemoveEdge(bestItem->DeletedEdge->Item1, bestItem->DeletedEdge->Item2); //Добавляем удалённое ребро
                verticesInfo[end]->Path->Clear(); //чистим путь
                verticesInfo[end]->Path->AddRange(bestItem->Route);// и добавляем новый, лучший путь
                best->Add(bestItem); //Добавляем полную информацию о пути в список лучших.
                RecursiveMainCirkleYen(generation, best, start, end, count, index + 1);
            }
        }
       
    }
    List<Path^>^ Yen(Vertex^ start, Vertex^ end, int count)
    {
        List<Path^>^ generation = gcnew List<Path^>();
        List<Path^>^ best = gcnew List<Path^>();
        RecursiveMainCirkleYen(generation, best, start, end, count, 0);
        return best; //Возвращаем список лучших кандидатов
    }
   
};

ref class DataReader
{
public:
    static Graph^ ReadGraph(Windows::Forms::DataGridView^ Dgw)
    {
        Graph^ gr = gcnew Graph();
        for (int i = 0; i < Dgw->ColumnCount; i++)
        {
            for (int j = 0; j < Dgw->RowCount; j++)
            {
                if (Dgw->Rows[j]->Cells[i]->Style->BackColor == Drawing::Color::LightGreen)
                {
                    String^ value = Dgw->Rows[j]->Cells[i]->Value->ToString();
                    if (value != "0")
                    {
                        gr->AddVertex(i.ToString());
                        gr->AddVertex(j.ToString());
                        gr->AddEdge(i.ToString(), j.ToString(), value);
                    }
                }
            }
        }
        return gr;
    }
};
