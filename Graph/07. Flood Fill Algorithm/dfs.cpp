class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    
    bool isSafe(int x,int y,int m,int n){
        return x>=0 and x<m and y>=0 and y<n;
    }
    void dfs(vector<vector<int>>& image,int nc,int oc,int x,int y,int m,int n){
        image[x][y]=nc;
        
        for(int i=0;i<4;i++){
            int nx=dx[i]+x;
            int ny=dy[i]+y;
            if(isSafe(nx,ny,m,n) and image[nx][ny]==oc){
                dfs(image,nc,oc,nx,ny,m,n);
            }
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int nc) {
        if(image[sr][sc]==nc) return image; // important condition to remember for runtime error
        dfs(image,nc,image[sr][sc],sr,sc,image.size(),image[0].size());
        return image;
    }
};
