
/* 
Approach
1. Similar to dfs ccycle detection in directed graph , just use one more check array for the safe nodes
2. Nodes who all are the prtv of cycle and attached to cycle are not safe nodes
*/


class Solution {
public:
    bool dfs(int src, vector<vector<int>>& graph,vector<bool> &vis,
    vector<bool> &pathVis,vector<bool> &check){
        vis[src]=true;
        pathVis[src]=true;
        
        for(auto x:graph[src]){
            if(!vis[x]){
                if(dfs(x,graph,vis,pathVis,check)){
                    check[src]=false;
                    return true;
                }
            }else if(pathVis[x]) {
                check[src]=false;
                return true;
            }
        }
        
        check[src]=true;
        pathVis[src]=false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();

        vector<bool> vis(V),check(V);
        vector<bool> pathVis(V);
        vector<int> safeNodes;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,graph,vis,pathVis,check);
            }
        }
        
        for(int i=0;i<V;i++){
            if(check[i]) safeNodes.push_back(i);
        }

        return safeNodes;
    }
};
