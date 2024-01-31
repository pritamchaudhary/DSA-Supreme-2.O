// GFG :- Detect cycle in a directed graph

// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool checkCyclic(int src, unordered_map<int, bool> &vis, unordered_map<int, bool> &dfsTrack, vector<int> adj[]){
        vis[src] = true;
        dfsTrack[src] = true;
        
        for(auto nbr: adj[src]) {
            if(!vis[nbr]) {
                bool ans = checkCyclic(nbr, vis, dfsTrack, adj);
                if(ans == true) {
                    return true;
                }
            }
            if(vis[nbr]==1 && dfsTrack[nbr]==1) {
                //cycle present
                return true;
            }
        }
        //backtrack
        dfsTrack[src] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
       unordered_map<int,bool> vis;
       unordered_map<int,bool> dfsTrack;
       
       for(int node=0; node<V; node++) {
           if(!vis[node]) {
               bool isCyclic = checkCyclic(node, vis, dfsTrack, adj);
               if(isCyclic) {
                   return true;
               }
           }
       }
       return false;
    }
};