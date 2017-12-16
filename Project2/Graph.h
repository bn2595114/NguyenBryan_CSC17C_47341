
#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include <list>
 
using namespace std;
 
class Graph{
    int V;
    list<int> *adj;   
public:
    Graph(int);
    void addEdge(int, int); 
    void BFS(int);  
};
 
#endif /* GRAPH_H */

