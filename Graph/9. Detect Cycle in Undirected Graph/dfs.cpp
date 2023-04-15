class Solution {
  public:
  
    // dffs code
    bool dfs(vector<int>&parent,vector<bool>&vis,int src,vector<int>adj[]){
        vis[src]=true;
        
        for(auto x: adj[src]){
            if(!vis[x]){
                parent[x]=src;
                if(dfs(parent,vis,x,adj)) return true;
            }else if(parent[src]!=x){   // condition to check for cycle { important to remember }
                return true;
            }
        }
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<int> parent(V,-1);
        vector<bool> vis(V);
        
        for(int i=0;i<V;i++){    // loop for disconnected components
            if(!vis[i]){
                if(dfs(parent,vis,i,adj)) return true;
            }
        }
        
        return false;
    }
};
