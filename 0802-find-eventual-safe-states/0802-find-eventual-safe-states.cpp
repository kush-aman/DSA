class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph, vector<int>&vis,vector<int>&safe){
        vis[node]=1;
        for(auto &it : graph[node]){
            if(!vis[it]){
                if(dfs(it,graph,vis,safe)==false) return false;
            }
            else if(!safe[it]) return false;
            
        }
        safe[node]=1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,0);
        vector<int>safe(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i])dfs(i,graph,vis,safe);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(safe[i]) ans.push_back(i);
        }
        return ans;
    }
};