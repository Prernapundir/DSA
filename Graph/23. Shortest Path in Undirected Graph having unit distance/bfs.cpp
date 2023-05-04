/* Approach 
1. Plain Bfs with distance will work in undirected graph of unit weights
- In undirected graph if we reach the node first time in bfs its always shorest distance because 
  BFS do level order traversal , If a node is already visited and try to visit again means that we are currently ahead of that level , 
  going backwards always give bigger distance , so never update visited nodes.
2. In directed graph also if weight is unit , plain bfs will work
*/

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        vector<int> adj[N];
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int> q;
        q.push(src);
        vector<int> dist(N,INT_MAX);
        dist[src]=0;
      
        while(!q.empty()){
            int f=q.front();
            q.pop();       
            
            for(auto x:adj[f]){
                if(dist[x]>dist[f]+1){
                    dist[x]=dist[f]+1;
                    q.push(x);
                }
            }
        }
        
        for(int i=0;i<dist.size();i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        
        return dist;
        
    }
};
