/* Approach
1. Build the graph using the DSU , firstly type 3 edges as they have max impact
2. Build the graph for bob and alice and see after the graph they covered all the nodes 
*/

class DSU {
    public:
    int n;
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    DSU(int n){
      this->n=n;
      parent.resize(n);
      rank.resize(n);
      size.resize(n);

      for(int i=0;i<n;i++){
          parent[i]=i;
          rank[i]=0;
          size[i]=1;
      }
    }

    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }

    bool _union(int u,int v){
        int x=find(u);
        int y=find(v);

        if(x!=y){
            if(rank[x]<rank[y]){
            parent[x]=y;
            }else if(rank[y]<rank[x]) {
                parent[y]=x;
            }else{
                parent[x]=y;
                rank[y]++;
            }
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [&](auto const &a, auto const &b){
            return a[0] > b[0];
        });
        
        DSU alice_dsu(n+1),bob_dsu(n+1);

        int alice_edges=0,bob_edges=0,removed_edges=0;

        for(auto e:edges){
            if(e[0]==3){  // firstly iterate the type 3 edges as they cover both bob and alice
                if(alice_dsu._union(e[1],e[2])){
                    bob_dsu._union(e[1],e[2]);
                    bob_edges++;
                    alice_edges++;
                }else removed_edges++;
            }else if(e[0]==1){ // only alice edges
                if(alice_dsu._union(e[1],e[2])){
                    alice_edges++;
                }else removed_edges++;
            }else{  // only bob edges
                if(bob_dsu._union(e[1],e[2])){
                    bob_edges++;
                }else removed_edges++;
            }
        }

        return (alice_edges==n-1 && bob_edges==n-1)?removed_edges:-1;
    }
};
