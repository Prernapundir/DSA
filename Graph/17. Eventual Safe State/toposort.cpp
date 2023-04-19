/* Approach (Reverse edges + Topo Sort)
1. Find the outdegree of all the nodes, and push the nodes who have outdegree=0 into the queueIntuition:

Intution :

Idea here is to reverse direction of all edges. And then perform simple topo sort.

This is because we need to start from nodes with outdegree = 0 (Terminal Nodes), and then move backwards to find safe nodes.
We cannot do move to backward BFS, due to which we need to reverse edges.
So, outdegree becomes indegree , and we can easily do topo sort using this.
Reversing edges will help us in classifying TERMINAL NODES => indegree is zero,

and all safe nodes i.e nodes reachable from terminal nodes, that are not in a cycle.

Also, doing topo sort will exclude all nodes that are present in a cyclic path.

So, topo sort will give us the all nodes that are either terminal or there is a path to terminal nodes.

*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> outdegree(V);
        vector<int> adj[V]; // Revers eedges store here
        vector<int> safeNodes;
        queue<int> q;

        for(int i=0;i<V;i++){
            for(auto x:graph[i]){
                adj[x].push_back(i);
            }
            outdegree[i]=graph[i].size();
            if(outdegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int f=q.front();
            q.pop();
            safeNodes.push_back(f);

            for(auto x:adj[f]){
                outdegree[x]--;
                if(outdegree[x]==0){
                    q.push(x);
                }
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};
