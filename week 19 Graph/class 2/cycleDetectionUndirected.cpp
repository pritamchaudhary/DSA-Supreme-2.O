// detect cycle in an undirected graph

#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
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

    bool checkCycleUndirectedBFS(int src){
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        // initial state
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            for(auto nbr: adjLIst[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
                else if(visited[nbr] == true && nbr != parent[frontNode]){
                    // cycle present
                    return true;
                }
            }
        }
        // cycle not present
        return false;
    }
};

int main(){
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(2, 5, 0);

    int src = 0;
    bool isCyclic = g.checkCycleUndirectedBFS(src);
    if(isCyclic){
        cout<<"cycle present"<<endl;
    }
    else{
        cout<<"cycle absent"<<endl;
    }
    
    return 0;
}