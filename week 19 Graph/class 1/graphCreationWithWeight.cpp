#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template<typename T>
class Graph{
    public:
    unordered_map<T, list<pair<T, int>>> adjList;
    void addEdge(T u, T v, int wt, bool direction){
        if(direction == 1){
            // u -> v
            adjList[u].push_back(make_pair(v, wt));
        }
        else{
            // u -> v
            adjList[u].push_back(make_pair(v, wt));
            // v -> u
            adjList[v].push_back({u, wt});
        }
        printAdjList();
        cout<<endl;
    }
    void printAdjList(){
        for(auto i: adjList){
            cout<<i.first<<": {";
            for(pair<T, int>p: i.second){
                cout<<"{"<<p.first<<","<<p.second<<"},";
            }
            cout<<"}"<<endl;
        }
    }
};

int main(){
    Graph<int> g;
    g.addEdge(0, 1, 5, 0);
    g.addEdge(1, 2, 10, 0);
    g.addEdge(1, 3, 20, 0);
    g.addEdge(2, 3, 50, 0);
    
    return 0;
}