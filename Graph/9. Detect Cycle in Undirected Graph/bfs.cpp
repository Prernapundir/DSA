class Solution {
  public:
    bool bfs(int parent,vector<bool>&vis,int src,vector<int>adj[]){
        queue<pair<int,int>> q;
        q.push({src,-1});
        vis[src]=true;
        
        
        while(!q.empty()){
            auto front=q.front();
            int node=front.first;
            int parent=front.second;
            q.pop();
            
            for(auto x:adj[node]){
                if(!vis[x]){
                    vis[x]=true;
                    q.push({x,node});
                }else if(parent!=x){
                    return true;
                }
            }
        }
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<bool> vis(V);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(bfs(-1,vis,i,adj)) return true;
            }
        }
        
        return false;
    }
};
