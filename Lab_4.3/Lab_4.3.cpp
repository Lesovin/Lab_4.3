#include "Graph.h"
#include <iostream>

int main()
{
    
    Graph<int, int> Town;
    Town.Add_Vertex(1);
    Town.Add_Vertex(2);
    Town.Add_Vertex(3);
    Town.Add_Vertex(4);
    Town.Add_Vertex(5);
    Town.Add_Edge(1, 4, 1);
    Town.Add_Edge(2, 4, 1);
    Town.Add_Edge(1, 2, 4);
    Town.Add_Edge(4, 3, 4);
    Town.Add_Edge(3, 5, 6);
    Town.Add_Edge(4, 2, 1);
    Town.Delete_Edge(5, 4);
    Town.Bellman_Ford(1, 2);
    std::cout << "\n";
    Town.Breadth_Search(1);
    Graph<int, int> Town2;
    Town2.Add_Vertex(6);
    Town2.Add_Vertex(7);
    if (Town2.Get(6) != Town2.Get(7))
    {
        std::cout << "\n";
        std::cout << "Yes";
    }
    return 0;
}


