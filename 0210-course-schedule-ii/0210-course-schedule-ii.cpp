class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        int V = numCourses;
        vector<int>adj[V]; // adjacency list to represent the directed graph
        // constructing the adjacency list from the given prerequisites
        for(auto it:prereq){
            vector<int> x = it;
            adj[x[1]].push_back(x[0]); // adding directed edge from prerequisite to the course
        }
        vector<int>topo; // to store topological order
        vector<int>indegree(V,0); // to store indegrees of all the vertices
        // calculating the indegrees of all the vertices
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
            indegree[it]++;
            }
        }
        queue<int>q; // to perform BFS
        // adding vertices with indegree 0 to the queue
        for(int i=0;i<V;i++){
            if(!indegree[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node); // adding the node to topological order
            // reducing the indegree of adjacent vertices and adding them to the queue if their indegree becomes 0
            for(auto it:adj[node]){
                indegree[it]--;
                if(!indegree[it]){
                    q.push(it);
                }
            }
        }
        if(topo.size()==V) // if a valid topological order is found, return it
            return topo;
        return {}; // otherwise, return an empty vector
    }
};