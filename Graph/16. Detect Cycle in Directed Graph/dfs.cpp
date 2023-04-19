/*
Approach 
1. If node is visited again in the same path , then it's a cycle else it's not
2. So use pathVis array to stote the visited nodes in that path

*/

class Solution {
  public:
  
    bool dfs(int src, vector<int> adj[],vector<bool> &vis,vector<bool> &pathVis){
        vis[src]=true;
        pathVis[src]=true;
        
        for(auto x:adj[src]){
            if(!vis[x]){
                if(dfs(x,adj,vis,pathVis)){
                    return true;
                }
            }else if(pathVis[x]) return true;
        }
        
        pathVis[src]=false;
        return false;
    }
    

    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V);
        vector<bool> pathVis(V);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathVis)){
                    return true;
                }
            }
        }
        
        return false;
    }
};
