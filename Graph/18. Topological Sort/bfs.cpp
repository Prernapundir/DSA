/* Kahn's Algorithm */

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans,indegree(V);

        for(int i=0;i<V;i++){
            for(auto x:adj[i]){
                indegree[x]++;
            }

        }
        
        queue<int>q;
        for(int i=0;i<V;i++){
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
        return ans;
	}
};
