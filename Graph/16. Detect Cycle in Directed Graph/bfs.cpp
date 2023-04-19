/* Kahn's algorithm approach

 1. If able to make topo sort of the graph , then there is no cycle , else there is cycle
 2. Becoz Topological sort works only in DAG (Directed Acylic Graph )
  
  */

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V);
        
        for(int i=0;i<V;i++){
            for(auto x: adj[i]){
                indegree[x]++;
            }
        }
   
        queue<int> q;
        vector<int> ans;
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int f=q.front();
            q.pop();
            ans.push_back(f);
            
            for(auto x:adj[f]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
        
        return ans.size()==V?false:true;
    }
};
