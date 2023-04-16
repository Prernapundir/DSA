class Solution {
  public:
  
   //dfs
    bool dfs(int parent,vector<bool>&vis,int src,vector<int>adj[]){
        vis[src]=true;
        
        for(auto x: adj[src]){
            if(!vis[x]){
                if(dfs(src,vis,x,adj)) return true;
            }else if(parent!=x){
                return true;
            }
        }
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V);
        
        for(int i=0;i<V;i++){    // loop for disconnected components
            if(!vis[i]){
                if(dfs(-1,vis,i,adj)) return true;
            }
        }
        
        return false;
    }
};
