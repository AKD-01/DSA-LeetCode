/* You can simply plug in this class any many different codes. This class is a generic implementation of union-find. */
class UnionFind {
    vector<int> component;
    int distinctComponents;
public:
    /*
     *   Initially all 'n' nodes are in different components.
     *   e.g. component[2] = 2 i.e. node 2 belong to component 2.
     */
    UnionFind(int n) {
	    distinctComponents = n;
        for (int i=0; i<=n; i++) {
            component.push_back(i);
        }
    }
    
    /*
     *   Returns true when two nodes 'a' and 'b' are initially in different
     *   components. Otherwise returns false.
     */
    bool unite(int a, int b) {       
        if (findComponent(a) == findComponent(b)) {
            return false;
        }
        component[findComponent(a)] = b;
        distinctComponents--;
        return true;
    }
    
    /*
     *   Returns what component does the node 'a' belong to.
     */
    int findComponent(int a) {
        if (component[a] != a) {
            component[a] = findComponent(component[a]);
        }
        return component[a];
    }
    
    /*
     *   Are all nodes united into a single component?
     */
    bool united() {
        return distinctComponents == 1;
    }
};

class Solution {    
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // Sort edges by their type such that all type 3 edges will be at the beginning.
        sort(edges.begin(), edges.end(), [] (vector<int> &a, vector<int> &b) { return a[0] > b[0]; });
        
        int edgesAdded = 0; // Stores the number of edges added to the initial empty graph.
        
        UnionFind bob(n), alice(n); // Track whether bob and alice can traverse the entire graph,
                                    // are there still more than one distinct components, etc.
        
        for (auto &edge: edges) { // For each edge -
            int type = edge[0], one = edge[1], two = edge[2];
            switch(type) {
                case 3:
                    edgesAdded += (bob.unite(one, two) | alice.unite(one, two));
                    break;
                case 2:
                    edgesAdded += bob.unite(one, two);
                    break;
                case 1:
                    edgesAdded += alice.unite(one, two);
                    break;
            }
        }
        
        return (bob.united() && alice.united()) ? (edges.size()-edgesAdded) : -1; // Yay, solved.
    }
};