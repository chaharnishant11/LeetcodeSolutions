/* This problem is very similar to "Redundant Connection". 
But the description on the parent/child relationships is much better clarified.

There are two cases for the tree structure to be invalid.
1) A node having two parents;
   including corner case: e.g. [[4,2],[1,5],[5,2],[5,3],[2,4]]
2) A circle exists
If we can remove exactly 1 edge to achieve the tree structure, a single node can have at most two parents. 
So my solution works in two steps.

1) Check whether there is a node having two parents. 
    If so, store them as candidates A and B, and set the second edge invalid. 
2) Perform normal union find. 
    If the tree is now valid 
           simply return candidate B
    else if candidates not existing 
           we find a circle, return current edge; 
    else 
           remove candidate A instead of B.

*/
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0), candA, candB;
        // step 1, check whether there is a node with two parents
        for (auto &edge:edges) {
            if (parent[edge[1]] == 0)
                parent[edge[1]] = edge[0]; 
            else {
                candA = {parent[edge[1]], edge[1]};
                candB = edge;
                edge[1] = 0;
            }
        } 
        // step 2, union find
        for (int i = 1; i <= n; i++) parent[i] = i;
        for (auto &edge:edges) {
            if (edge[1] == 0) continue;
            int u = edge[0], v = edge[1], pu = root(parent, u);
            // Now every node only has 1 parent, so root of v is implicitly v
            if (pu == v) {
                if (candA.empty()) return edge;
                return candA;
            }
            parent[v] = pu;
        }
        return candB;
    }
private:
    int root(vector<int>& parent, int k) {
        if (parent[k] != k) 
            parent[k] = root(parent, parent[k]);
        return parent[k];
    }
};