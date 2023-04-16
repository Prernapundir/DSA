/*
Learnings and Approach 
------------------------

1. MultiSource BFS { putting all source together at start in the queue }
2. SImilar to TopoSort  {process 0's cell first , then keep increasing }


Why BFS?
--------
Becoz we have to find the shortest distnace , that we an find only using BFS 

Why MultiSource BFS ?
----------------------
Becoz we have to travserse nodes with shortest distnace first , so we have to traverse level wise , 0--last level


Steps :
1. Put all the 0's inside the queuue
2. Mark 1 cell with -1 {they are unvisited}
3. Run BFS , and keep updating the distance if found cell with -1 and push back to queue as well

*/


class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    
    bool isSafe(int m,int n,int x,int y){
        return x<m and y<n and x>=0 and y>=0;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        
        vector<vector<int>> ans(m,vector<int>(n,0));
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1) ans[i][j]=-1;  // Replace all 1's with -1
                else q.push({i,j}); // Put all 0's to the queue
            }
        }
        
        while(!q.empty()){
            int size=q.size();
            
            while(size--){
                auto front=q.front();
                q.pop();
                int x=front.first;
                int y=front.second;
                
                for(int i=0;i<4;i++){
                    int nx=dx[i]+x;
                    int ny=dy[i]+y;
                    
                    if(isSafe(m,n,nx,ny) and ans[nx][ny]==-1){
                        ans[nx][ny]=ans[x][y]+1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        
        return ans;
    }
};
