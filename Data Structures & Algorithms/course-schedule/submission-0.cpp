class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(auto it: prerequisites){
            int u = it[0];
            int v = it[1]; 
            adj[u].push_back(v);
        }


        
        for(int i = 0; i<adj.size(); i++){
           for(auto it:adj[i]){
                indegree[it]++;
           }
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        if(topo.size() == numCourses) return true;
        return false;
    }
};
