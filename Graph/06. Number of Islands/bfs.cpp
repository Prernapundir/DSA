class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
    bool isSafe(int m,int n,int x,int y){
        return x>=0 && y>=0 && x<m && y<n;
    }

    void bfs(vector<vector<char>>& grid,int x,int y,int m,int n){
        queue<pair<int,int>> q;
        q.push({x,y});
        grid[x][y]='0';

        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nx=dx[i]+p.first;
                int ny=dy[i]+p.second;

                if(isSafe(m,n,nx,ny) and grid[nx][ny]=='1'){
                    q.push({nx,ny});
                    grid[nx][ny]='0';
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int count=0;

        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    count++;
                    bfs(grid,i,j,m,n);
                }
            }
        }
        
        return count;

    }
};
