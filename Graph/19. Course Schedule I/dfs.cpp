/* Approach 
As we know Topological sort is possible only in DAG , so to finish all the courses , there should be no cycle
So check for cycle { now its converted into detect cycle in undirected graph problem } , if cycle presents , means won't be able to finich all the courses 
else we can finish all the courses
*/


class Solution {
public:
    
    bool dfs(vector<bool>&vis,vector<bool>&dfsVis,int src,vector<int> adj[]){
        vis[src]=true;
        dfsVis[src]=true;
        
        for(auto neigh:adj[src]){
            if(!vis[neigh]){
                if(dfs(vis,dfsVis,neigh,adj)) return true;
            }else if(dfsVis[neigh]) return true;
        }
        
        dfsVis[src]=false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses+1];
        
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        
        vector<bool> vis(numCourses+1),dfsVis(numCourses+1);
        
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(vis,dfsVis,i,adj)) return false;
            }
        }
        
        return true;
          
    }
};
