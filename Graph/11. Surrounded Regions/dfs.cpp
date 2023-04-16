// boundry dfs

class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    
    bool isSafe(int x,int y,int m,int n){
        return x>=0 and y>=0 and x<m and y<n;
    }

    void dfs(int x,int y,int m,int n,vector<vector<char>>& board){
        board[x][y]='P';

        for(int k=0;k<4;k++){
            int nx=dx[k]+x;
            int ny=dy[k]+y;

            if(isSafe(nx,ny,m,n) and board[nx][ny]=='O'){
                dfs(nx,ny,m,n,board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                dfs(0,i,m,n,board);
            }
            if(board[m-1][i]=='O'){
                dfs(m-1,i,m,n,board);
            }
        }

        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                dfs(i,0,m,n,board);
            }
            if(board[i][n-1]=='O'){
                dfs(i,n-1,m,n,board);
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='P') board[i][j]='O';
            }
        }
        return;
    }
};
