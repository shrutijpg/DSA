class Solution {
private:
//colors components individually
    bool check(int start,int n,vector<vector<int>>& graph,vector<int>& color){
        queue<int>q;
        q.push(start);
      //  int n= graph.size();
        
        color[start]=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : graph[node]){
                //if the adjacent node is yet not colored
                //you will give the oposite color 

                if(color[it]==-1) {
                    color[it] = !color[node];
                    //color[neighbor] = 1 - color[node];
                    q.push(it);
                }
                //adj guy having the samecolor
                //so someone would have colored it before

                else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;


    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> color(n, -1);
        

        for(int i=0;i<n;i++){
            color[i]=-1;
        }
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(check(i,n,graph,color)==false) return false;
            }
        }
        return true;
    }
};