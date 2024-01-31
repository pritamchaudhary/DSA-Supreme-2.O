// GFG:-> Detect cycle in an undirected graph

// Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool checkCycle(int src, unordered_map<int, bool> &visited, int parent, vector<int> adj[]){
        visited[src] = true;
        for(auto nbr: adj[src]){
            if(nbr == parent){
                continue;    
            }
            
            if(!visited[nbr]){
                bool ans = checkCycle(nbr, visited, src, adj);
                if(ans == true){
                    return true;
                }
            }
            else if(visited[nbr] == 1){
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int, bool> visited;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                int parent = -1;
                bool isCyclic = checkCycle(i, visited, parent, adj);
                if(isCyclic == true){
                    return true;
                }
            }
        }
        return false;
    }
};