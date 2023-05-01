
/* 
Similar approach like : Surrounded regions
here just we have to count all the enclaves (surrounded components )
*/

class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
    bool isSafe(int m,int n,int x,int y){
        return x<m and y<n and x>=0 and y>=0;
    }
    
    void dfs(vector<vector<int>>&grid,int m,int n,int x,int y){
        grid[x][y]=0;
        
        for(int i=0;i<4;i++){
            int nx=dx[i]+x;
            int ny=dy[i]+y;
            
            if(isSafe(m,n,nx,ny) and grid[nx][ny]==1){
                dfs(grid,m,n,nx,ny);
            }
        }
        
        return;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        
        for(int i=0;i<n;i++){
            if(grid[0][i]==1) dfs(grid,m,n,0,i);
            if(grid[m-1][i]==1) dfs(grid,m,n,m-1,i);
        }
        
        for(int i=0;i<m;i++){
            if(grid[i][0]==1) dfs(grid,m,n,i,0);
            if(grid[i][n-1]==1) dfs(grid,m,n,i,n-1);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) count++;
            }
        }
        
        return count;
    }
};
