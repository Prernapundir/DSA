/* Approach
1. If able to print the topological order , then it means we can finish all the courses else no
*/

class Solution {
public:
    
    
    bool canFinish(int n, vector<vector<int>>& a) {
        
        vector<int> adj[n];
        for(auto i:a){
           adj[i[0]].push_back(i[1]); 
        }
        
        queue<int> q;
        vector<bool> vis(n);
        int count=0;
        vector<int> indegree(n,0);
        
        for(int i=0;i<n;i++){
            for(auto x:adj[i]){
                indegree[x]++;
            }
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int f=q.front();
            q.pop();
            count++;
            
            for(auto x:adj[f]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
        if(count==n) return true;
        return false;
        
    }
};
