class Solution {
public:
    
    void dfs(vector<bool>&vis,vector<int>adj[],int src){
        vis[src]=true;
        
        for(auto neigh:adj[src]){
            if(!vis[neigh]){
                dfs(vis,adj,neigh);
            }
        }
        return;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        
        vector<int> adj[n];
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int count=0;
        
        vector<bool> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(vis,adj,i);
            }
        }
        
        return count;
    }
};
