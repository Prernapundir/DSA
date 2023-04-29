class DSU {
    public:
    int n;
    vector<int> parent;
    vector<int> rank;

    DSU(int n){
        this->n=n;
        parent.resize(n);
        rank.resize(n);

        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }

    int find(int i){
        if(parent[i]==i){
            return i;
        }

        return parent[i]=find(parent[i]);
    }

    void _union(int u,int v){
        int x=find(u);
        int y=find(v);

        if(rank[x]<rank[y]){
           parent[x]=y;
        }else if(rank[y]<rank[x]) {
            parent[y]=x;
        }else{
            parent[x]=y;
            rank[y]++;
        }
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DSU ds(n);
        vector<bool> ans(queries.size());

        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
         
        sort(queries.begin(), queries.end(), [&](auto const &a, auto const &b){
            return a[2] < b[2];
        });

        sort(edgeList.begin(),edgeList.end(),[&](auto const &a,auto const &b){
            return a[2]<b[2];
        });
        
        int k=0;
        for(auto q:queries){
           while(k<edgeList.size() and edgeList[k][2]<q[2]){
               ds._union(edgeList[k][0],edgeList[k][1]);
               k++;
           }
           if(ds.find(q[0])==ds.find(q[1])){
               ans[q[3]]=true;
           }
        }

        return ans;
    }
};
