class Solution {
public:
    bool bfs(vector<vector<int>>& graph,int src,vector<int> color){
        queue<int> q;
        q.push(src);
        color[src]=1;

        while(!q.empty()){
            auto p=q.front();
            q.pop();

            for(auto x:graph[p]){
                if(color[x]==-1){
                    q.push(x);
                    color[x]-=color[p];
                }else if(color[p]==color[x]){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> color(v,-1);
        
        for(int i=0;i<v;i++){
            if(color[i]==-1 and !bfs(graph,i,color)){
                return false;
            }
        }
        return true;
    }
};
