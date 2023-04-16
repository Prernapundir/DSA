class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    
    bool isSafe(int x,int y,int m,int n){
        return x>=0 and x<m and y>=0 and y<n;
    }

    void bfs(vector<vector<int>>& image,int nc,int oc,int x,int y,int m,int n){
        queue<pair<int,int>> q;
        q.push({x,y});
        image[x][y]=nc;
        
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nx=dx[i]+p.first;
                int ny=dy[i]+p.second;
                
                if(isSafe(nx,ny,m,n) and image[nx][ny]==oc){
                    q.push({nx,ny});
                    image[nx][ny]=nc;
                }
            }
        }
        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int nc) {
        if(image[sr][sc]==nc) return image;
        bfs(image,nc,image[sr][sc],sr,sc,image.size(),image[0].size());
        return image;
    }
};
