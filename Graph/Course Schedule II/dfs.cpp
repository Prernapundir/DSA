/*Approach 
Print Topological sort using dfs 
*/


class Solution {
public:
    
    bool dfs(int src,vector<bool>&vis,vector<bool>&dfsVis,stack<int>&st,vector<int>adj[]){
        vis[src]=1;
        dfsVis[src]=1;
        for(auto x:adj[src]){
            if(!vis[x]){
                if(!dfs(x,vis,dfsVis,st,adj)) return false;
            }else if(dfsVis[x]==1) return false;
        }
        st.push(src);
        dfsVis[src]=0;
        return true;
    }
    vector<int> findOrder(int n, vector<vector<int>>& a) {
        vector<int>adj[n];
        
        for(auto x:a){
           adj[x[1]].push_back(x[0]);
        }
        
        vector<bool>vis(n),dfsVis(n);
        vector<int>ans;
        stack<int>st;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(!dfs(i,vis,dfsVis,st,adj)) return {};
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};
