#include <queue>
#include<vector>
#include <iostream>

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
		bool colour;
	};
	std::vector<Vertex> Table;
	int Index(TVertex Temp_Vertex) // проверка, есть ли вершина с таким ID в графе
	{
		for (size_t i = 0; i < Table.size(); i++)
		{
			if (Table[i].First == Temp_Vertex) return Table[i].ID;
		}
		return -1;
	}
public:
	void Add_Vertex(TVertex Temp_Source) // добавить вершину
	{
		if (Index(Temp_Source) < 0)
		{
			Vertex New_Vertex;
			New_Vertex.ID = Table.size();
			New_Vertex.First = Temp_Source;
			Table.push_back(New_Vertex);
			
		}
		else throw "This vertex already exist";
	}
	void Add_Edge(TVertex Temp_Source, TVertex Temp_Dest, TEdge Temp_Edge) // добавить ребро
	{
		int Temp_Source_ID = Index(Temp_Source);
		int Temp_Dest_ID = Index(Temp_Dest);
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
		for (size_t i = 0; i < Table[Temp_Source_ID].Dest.size(); i++)
		{
			if (Table[Temp_Source_ID].Dest[i].Dest == Temp_Dest_ID)
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
		if (index < 0) throw "Vertex does not exist";
		for (int i = 0; i < index; i++)
		{
			for (size_t j = 0; j < Table[i].Dest.size(); j++)
			{
				if (Table[i].Dest[j].Dest == index)
				{
					for (size_t k = j; k < Table[i].Dest.size() - 1; k++)
					{
						Table[i].Dest[k].Dest = Table[i].Dest[k + 1].Dest;
					}
					Table[i].Dest.pop_back();
				}
			}
		}
		for (size_t i = index + 1; i < Table.size(); i++)
		{
			for (size_t j = 0; j < Table[i].Dest.size(); j++)
			{
				if (Table[i].Dest[j].Dest == index)
				{
					for (size_t k = j; k < Table[i].Dest.size() - 1; k++)
					{
						Table[i].Dest[k].Dest = Table[i].Dest[k + 1].Dest;
					}
					Table[i].Dest.pop_back();
				}
			}
		}
		for (size_t i = index; i < Table.size() - 1; i++)
		{
			Table[i] = Table[i + 1];
			Table[i].ID--;
		}
		Table.pop_back();
	}
	void Bellman_Ford(TVertex Temp_Source, TVertex Temp_Dest)
	{
		std::vector<double> d(Table.size());
		std::fill(d.begin(),d.end(), INFINITY);
		d[Index(Temp_Source)] = 0;
		std::vector<std::vector<TVertex>> Ways(Table.size());
		for (size_t i = 0; i < Table.size(); i++)
		{
			for (size_t j = 0; j < Table[i].Dest.size(); j++)
			{
				if (d[i] + Table[i].Dest[j].Edge < d[Table[i].Dest[j].Dest])
				{
					d[Table[i].Dest[j].Dest] = d[i] + Table[i].Dest[j].Edge;
					Ways[Table[i].Dest[j].Dest] = Ways[i];
					Ways[Table[i].Dest[j].Dest].push_back(Table[i].ID + 1);
				}
			}
		}
		for (size_t i = 0; i < Table.size(); i++)
		{
			Ways[i].push_back(Table[i].ID + 1);
		}
		for (size_t i = 0; i < Table.size(); i++)
		{
			for (size_t j = 0; j < Ways[i].size(); j++)
			{
				std::cout << Ways[i][j];
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		for (int i = 0; i < Index(Temp_Source); i++)
		{
			if (d[i] == INFINITY)
			{
				std::cout << std::endl << Temp_Source << "->" << i + 1 << "=" << "No way";
			}
			else std::cout << std::endl << Temp_Source << "->" << i + 1 << "=" << d[i];
		}
		for (size_t i = Index(Temp_Source) + 1; i < Table.size(); i++)
		{
			if (d[i] == INFINITY)
			{
				std::cout << std::endl << Temp_Source << "->" << i + 1 << "=" << "No way";
			}
			else std::cout << std::endl << Temp_Source << "->" << i + 1 << "=" << d[i];
		}
	}
	void Breadth_Search(TVertex Temp_Source)
	{
		for (size_t i=0; i<Table.size();i++) 
		{
			Table[i].colour = false;
		}
		std::queue<Vertex> q;
		Vertex s = Table[Index(Temp_Source)];
		q.push(s);
		s.colour = true;
		while (!q.empty()) {
			Vertex u = q.front();
			q.pop();
			for (auto elem : u.Dest) {
				Vertex& v = Table[elem.Dest];
				if (v.colour == false) {
					v.colour = true;
					q.push(v);
				}
			}
			std::cout << u.First;
		}
	}
};

