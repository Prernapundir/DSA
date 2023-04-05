// Time Complexity: O(V + E)
// Space Complexity: O(V)


#include <bits/stdc++.h> 
using namespace std;


// bfs logic
void bfs(int src,vector<int> adj[],vector<bool>&vis,vector<int>&ans){
    queue<int> q;
    q.push(src);
    vis[src]=true;

    while(!q.empty()){
       int front=q.front();
       q.pop();
       ans.push_back(front);

       for(auto x: adj[front]){
           if(!vis[x]){
               vis[x]=true;
               q.push(x);
           }
       }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> adj[vertex];

    // making adjacency list
    for(auto x:edges){
        adj[x.first].push_back(x.second);
        adj[x.second].push_back(x.first);
    }

    // becuase we have to print in sorted order
    for(int i=0;i<vertex;i++){
        sort(adj[i].begin(),adj[i].end());
    }
    
    vector<bool>vis(vertex);  // vector to store visited nodes
    vector<int> ans;    // vector to store answer

   // looping to handle disconnected graph case as well
    for(int i=0;i<vertex;i++){
        if(!vis[i]){
            bfs(i,adj,vis,ans);
        }
    }
   
    return ans;
}
