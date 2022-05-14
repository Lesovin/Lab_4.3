#include<list>
#include<vector>

template<typename TVertex, typename TEdge>
class Graph
{
private:
	struct Destination
	{
		int ID;
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
public:
	void Add_Vertex(TVertex Temp_Source)
	{
		Vertex New_Vertex;
		New_Vertex.ID = Table.size();
		New_Vertex.Source = Temp_Source;
		Table.push_back(New_Vertex);
	}
	
};

