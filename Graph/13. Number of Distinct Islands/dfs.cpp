
/* Approach
1. Basically in this question , we have to figure out how to store shapes for identical comparisson
2. For comparing the shapes they are equal or not , we can store them in set data structure
3. But how to store te coordinates is the main question now, 
4. We can call one of the starting points a base{baseRow, baseCol}, and subtract the base coordinates from the land’s coordinates (Cell Coordinates – Base coordinates). 
e.g  Concept -> {x-baseRow, y-baseCol}
*/


class Solution {
  public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
    bool isSafe(int x,int y,int m,int n){
        return x>=0 && y>=0 && x<m && y<n;
    }
    
    void dfs(int x,int y,int basex,int basey,int m,int n,
    vector<vector<int>> &grid,vector<vector<bool>> &vis,vector<pair<int,int>>& temp){
        vis[x][y]=1;
        temp.push_back({x-basex,y-basey}); // storing the coordinates of cell
        
        for(int i=0;i<4;i++){
            int nx=dx[i]+x;
            int ny=dy[i]+y;
            if(isSafe(nx,ny,m,n) && grid[nx][ny]==1 && !vis[nx][ny]){
                dfs(nx,ny,basex,basey,m,n,grid,vis,temp);
            }
        }
        
        return ;
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n));
        set<vector<pair<int,int>>> ans;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] and grid[i][j]==1){
                    vector<pair<int,int>> temp;
                    dfs(i,j,i,j,m,n,grid,vis,temp);
                    ans.insert(temp);
                }
            }
        }
        
        return ans.size();
    }
};
