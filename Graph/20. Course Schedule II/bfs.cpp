/* Approach 
print the topological sort order { Using Kahn's algorithm }

*/

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> ans,indegree(n),adj[n];

        for(auto i:pre){
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
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
        return ans.size()==n?ans:vector<int>();
    }
};
