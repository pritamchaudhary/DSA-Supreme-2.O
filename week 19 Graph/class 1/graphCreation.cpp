#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<int>> adjLIst;
    void addEdge(int u, int v, bool direction){
        // direction -> 0 -> undirected
        // direction -> 1 -> directed
        if(direction == 1){
            // u -> v
            adjLIst[u].push_back(v);
        }
        else{
            // direction = 0
            // u -> v
            adjLIst[u].push_back(v);
            // v -> u
            adjLIst[v].push_back(u);
        }
        cout<<endl<<"Printing adjList"<<endl;
        printAdjList();
        cout<<endl;
    }
    void printAdjList(){
        for(auto i: adjLIst){
            cout<<i.first<<"->{";
            for(auto neighbour: i.second){
                cout<<neighbour<<",";
            }
            cout<<"}"<<endl;
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 1);
    
    return 0;
}