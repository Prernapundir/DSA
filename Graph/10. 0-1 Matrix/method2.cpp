class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};

    bool isSafe(int m,int n,int x,int y){
        return x>=0 and y>=0 and x<m and y<n;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>> ans(m,vector<int>(n));
        vector<vector<bool>> vis(m,vector<bool>(n));

        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(mat[i][j]==0){
                   q.push({{i,j},0});
               }
            }
        }

        while(!q.empty()){
            auto front=q.front();
            q.pop();
            auto node=front.first;
            int dis=front.second;

            for(int k=0;k<4;k++){
                int nx=dx[k]+node.first;
                int ny=dy[k]+node.second;

                if(isSafe(m,n,nx,ny) and !vis[nx][ny] and  mat[nx][ny]==1){
                    vis[nx][ny]=true;
                    ans[nx][ny]=dis+1;
                    q.push({{nx,ny},dis+1});
                }
            }
        }

        return ans;
    }
};
