class Solution {
public:
    
    void bfs(vector<int> adj[],int src,vector<bool>&vis){
        queue<int> q;
        q.push(src);

        while(!q.empty()){
            int front=q.front();
            q.pop();

            for(auto x:adj[front]){
                if(!vis[x]){
                    vis[x]=true;
                    q.push(x);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n];
        vector<bool> vis(n);
        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                bfs(adj,i,vis);
            }
        }

        return count;
    }
};
