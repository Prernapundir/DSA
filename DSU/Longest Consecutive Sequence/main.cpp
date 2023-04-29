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

    void _union(int u,int v){
        int x=find(u);
        int y=find(v);

        if(rank[x]<rank[y]){
           parent[x]=y;
           size[y]+=size[x];
        }else if(rank[y]<rank[x]) {
            parent[y]=x;
            size[x]+=size[y];
        }else{
            parent[x]=y;
            size[y]+=size[x];
            rank[y]++;
        }
    }

    int maxConnectedComponent(){
        int ans=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                ans=max(ans,size[i]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        DSU ds(nums.size());
        unordered_map<int,int> m;

        // iterate over the array and for every (i, i+1) , (i,i-1) make the graph
        // largest connected graph will give the answer
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                continue;
            };

            if(m.find(nums[i]-1)!=m.end()){
                ds._union(i,m[nums[i]-1]);
            };

            if(m.find(nums[i]+1)!=m.end()){
                ds._union(i,m[nums[i]+1]);
            };

            m[nums[i]]=i;
        }

        return ds.maxConnectedComponent();
    }
};
