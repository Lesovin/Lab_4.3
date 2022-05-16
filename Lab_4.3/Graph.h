#include<list>
#include<vector>

template<typename TVertex, typename TEdge>
class Graph
{
private:
	struct Destination
	{
		TVertex Dest;
		TEdge Edge;
	};
	struct Vertex 
	{
		int ID;
		TVertex First;
		std::vector<Destination> Dest;
	};
	std::vector<Vertex> Table;
	int Index(TVertex Temp_Vertex) // проверка, есть ли вершина с таким ID в графе
	{
		for (int i = 0; i < Table.size(); i++)
		{
			if (Table[i].First == Temp_Vertex) return Table[i].ID;
		}
		return -1;
	}
public:
	
	void Add_Vertex(TVertex Temp_Source) // добавить вершину
	{
		if (index(Temp_Source) < 0)
		{
			Vertex New_Vertex;
			New_Vertex.ID = Table.size();
			New_Vertex.Source = Temp_Source;
			Table.push_back(New_Vertex);
		}
		else throw "This vertex already exist";
	}
	void Add_Edge(TVertex Temp_Source, TVertex Temp_Dest, TEdge Temp_Edge) // добавить ребро
	{
		int Temp_Source_ID = index(Temp_Source);
		int Temp_Dest_ID = index(Temp_Dest);
		if (Temp_Source_ID < 0) throw "Source does not exist";
		if (Temp_Dest_ID < 0) throw "Destination does not exist";
		Destination New_Edge;
		New_Edge.Dest = Temp_Dest_ID;
		New_Edge.Edge = Temp_Edge;
		Table[Temp_Source_ID].Dest.push_back(New_Edge);
	}
	void Delete_Edge(TVertex Temp_Source, TVertex Temp_Dest) // удаление ребра
	{
		int Temp_Source_ID = Index(Temp_Source);
		int Temp_Dest_ID = Index(Temp_Dest);
		if (Temp_Source_ID * Temp_Dest_ID < 0)  throw "Edge does not exist"; 
		for (int i = 0; i < Table[Temp_Source_ID].Dest.size(); i++)
		{
			if (Table[Temp_Source_ID].Dest[i].ID == Temp_Dest_ID)
			{
				for (int j = i; j < Table[Temp_Source_ID].Dest.size() - 1; j++)
				{
					Table[Temp_Source_ID].Dest[i] = Table[Temp_Source_ID].Dest[i + 1];
					Table[Temp_Source_ID].Dest[i].ID--;
				}
				Table[Temp_Source_ID].Dest.pop_back();
			}
		}
	}
	void Delete_Vertex(TVertex Temp_Source) // удаление вершины
	{
		int index = Index(Temp_Source);
		for (int i = 0; i < index; i++)
		{
			for (int j = 0; j < Table[i].Dest.size(); j++)
			{
				if (Table[i].Dest[j].Des == index)
				{
					for (int k = j; k < Table[i].Dest.size() - 1; k++)
					{
						Table[i].Dest[k].Dest = Table[i].Dest[k + 1].Dest;
					}
					Table[i].Dest.pop_back();
				}
			}
		}
		for (int i = index + 1; i < Table.size(); i++)
		{
			for (int j = 0; j < Table[i].Dest.size(); j++)
			{
				if (Table[i].Dest[j].Dest == index)
				{
					for (int k = j; k < Table[i].Dest.size() - 1; k++)
					{
						Table[i].Dest[k].Dest = Table[i].Dest[k + 1].Dest;
					}
					Table[i].Dest.pop_back();
				}
			}
		}
		for (int i = index; i < Table.size() - 1; i++)
		{
			Table[i] = Table[i + 1];
			Table[i].ID--;
		}
		Table.pop_back();
	}
};

