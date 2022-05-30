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
    //Town.Add_Edge(4, 1, 2);
    Town.Add_Edge(1, 4, 3);
    Town.Add_Edge(3, 4, 5);
    Town.Add_Edge(1, 2, 4);
    Town.Add_Edge(1, 3, 4);
    Town.Add_Edge(4, 3, 6);
    Town.Add_Edge(3, 2, 7);
    Town.Bellman_Ford(3, 4);
    std::cout << "\n";
    Town.Breadth_Search(1);
    return 0;
}


