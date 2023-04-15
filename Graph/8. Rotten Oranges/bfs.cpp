class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
    bool isSafe(int m,int n,int x,int y){
        return x<m and y<n and x>=0 and y>=0;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        
        int fresh=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1) fresh++;
            }
        }
        
        int minutes=0;
        
        while(!q.empty()){
            int size=q.size();
            
            while(size--){
                auto front=q.front();
                q.pop();
                
                for(int i=0;i<4;i++){
                    int nx=dx[i]+front.first;
                    int ny=dy[i]+front.second;
                
                    if(isSafe(m,n,nx,ny) and grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        fresh--;
                        q.push({nx,ny});
                    }
                }
                
            }
            
            if(!q.empty()) minutes++;
        }
        
        return fresh==0?minutes:-1;
    }
};
