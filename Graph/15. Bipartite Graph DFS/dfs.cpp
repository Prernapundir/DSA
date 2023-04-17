class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int src,vector<int> &color){
       
        for(auto x: graph[src]){
            if(color[x]==-1){
                color[x]-=color[src];
                if(!dfs(graph,x,color)) return false;
            }else if(color[src]==color[x]) return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> color(v,-1);
        
        for(int i=0;i<v;i++){
            if(color[i]==-1 ){
                color[i]=1;
                if(!dfs(graph,i,color)){
                    return false;
                }
            }
        }
        return true;
    }
};
