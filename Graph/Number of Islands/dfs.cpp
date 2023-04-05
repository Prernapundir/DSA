class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
    bool isSafe(int x,int y,int m,int n){
        return x>=0 && y>=0 && x<m && y<n;
    }
    
    void dfs(int x,int y,int m,int n,vector<vector<char>>& grid,vector<vector<bool>>&vis){
        vis[x][y]=1;
        
        for(int i=0;i<4;i++){
            int nx=dx[i]+x;
            int ny=dy[i]+y;
            if(isSafe(nx,ny,m,n) && grid[nx][ny]=='1' && !vis[nx][ny]){
                dfs(nx,ny,m,n,grid,vis);
            }
        }
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] and grid[i][j]=='1'){
                    dfs(i,j,m,n,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};
