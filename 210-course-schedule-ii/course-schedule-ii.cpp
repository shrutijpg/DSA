class Solution {
private:
bool dfsCheck(int node,vector<vector<int>>& adj,vector<int>&  vis, vector<int>&  pathVis,vector<int>& topo){
    vis[node]=1;
    pathVis[node]=1;


    //Traversing forthe adjacent nodes
    for(auto it : adj[node]){
        //when node is not visited
        if(!vis[it]){
            if(dfsCheck(it,adj,vis,pathVis,topo)) return true;
        }
        //node has been previously visited
        //but it has to be visited on the same path
        else if(pathVis[it]){
            return true;
        }

    }
    pathVis[node]=0;
    topo.push_back(node); 
    return false;
}
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]); // Directed edge: pre[1] → pre[0]
        }
        vector<int> vis(numCourses, 0), pathVis(numCourses, 0), topo;

        for(int i=0;i<numCourses;++i){
            if(!vis[i]){
                if(dfsCheck(i,adj,vis,pathVis,topo)) return {};

            }
        }
        reverse(topo.begin(), topo.end()); // reverse to get correct topological order
        return topo;
        
    }
};