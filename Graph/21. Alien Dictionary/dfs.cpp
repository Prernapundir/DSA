/*Approach

1. The intuition is to check every consecutive pair of words and find out the differentiating factor. 
With these factors, we will form a directed graph, and the whole problem boils down to a topological sort of problem.

2. Just need to check two pairs of words everytime why ?
 if “abcd” is appearing before “abca” and “baa” is appearing before “abcd”, “baa” will obviously appear before “abca”. 

*/

class Solution{
    public:
    
  // topological sort function
    void topoSort(vector<int> adj[],int src,vector<bool>&vis,stack<int> &st){
        vis[src]=true;
        for(auto x:adj[src]){
            if(!vis[x]){
                topoSort(adj,x,vis,st);
            }
        }
        st.push(src);
        return;
    }
    
    string findOrder(string dict[], int n, int K) {
        vector<int> adj[K];
        vector<bool> vis(K);
        
      // make the DSG here 
        for(int i=0;i<n-1;i++){
            string a=dict[i];
            string b=dict[i+1];
            
           int len=min(a.length(),b.length());
           for(int k=0;k<len;k++){
               if(a[k]!=b[k]){
                   adj[a[k]-'a'].push_back(b[k]-'a');
                   break;
               }
           }
        }
        
      // do the topological sort on the DAG created to find the order of alien dictionary
        stack<int> st;
        for(int i=0;i<K;i++){
            if(!vis[i]){
                topoSort(adj,i,vis,st);
            }
        }
        
        string ans="";
        while(!st.empty()){
            ans+=char(st.top()+'a');
            st.pop();
        }
        
        return ans;
        
        
        
    }
};
