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
};

