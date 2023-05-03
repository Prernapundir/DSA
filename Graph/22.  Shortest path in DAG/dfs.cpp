/* 
Approach: (Using topoSort)
1. Find the toposort first {Processing the vertices in topological order ensures that by the time you get to a vertex, you’ve already processed all the vertices
that can precede it which reduces the computation time significantly. }
- Dijkstra’s algorithm is necessary for graphs that can contain cycles because they can’t be topologically sorted. In other cases, the 
  topological sort would work fine as we start from the first node, and then move on to the others in a directed manner.
2. keep a distance array with intilization to INT_MAX
3. It might be possible the source node and topoSort order would be different , so pop from the stack until you got the source node.
3. Iterate over the topsort order one by one and do the dfs and relax the weighted nodes {update the dist array }

*/
class Solution {
  public:
  
  // topo sort
    void topoSort(int src,vector<bool>&vis,vector<pair<int,int>>adj[],stack<int>&st){
        vis[src]=true;
        for(auto x:adj[src]){
            if(!vis[x.first]){
                topoSort(x.first,vis,adj,st);
            }
        }
        st.push(src);
        return;
    }
    
  //dfs
    void dfs(int src,vector<int>&dist,vector<pair<int,int>>adj[]){
        
        for(auto x:adj[src]){
            if(dist[x.first]>dist[src]+x.second){
                dist[x.first]=dist[src]+x.second;
                dfs(x.first,dist,adj);
            }
    
        }
        return;
    }
    
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<int> dist(N,INT_MAX);
        vector<pair<int,int>> adj[N];
        vector<bool> vis(N);
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        stack<int> st;
        
        for(int i=0;i<N;i++){
            if(!vis[i]){
                topoSort(i,vis,adj,st);
            }
        }
        
        while(!st.top()==0){
            st.pop();
        }
        
       // do the dfs to relax the nodes on toposort order
        dist[0]=0;
        while(!st.empty()){
            dfs(st.top(),dist,adj);
            st.pop();
        }
 
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        
        return dist;
    }
};
