class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> walls;
        vector<vector<int>> ans;
        for (auto b : buildings) {
            walls.push_back(make_pair(b[0], -b[2]));
            walls.push_back(make_pair(b[1], b[2]));
        }
        sort(walls.begin(), walls.end());                 
        multiset<int> leftWallHeights = {0};
        int top = 0;         
        for (auto w : walls) {
            if (w.second < 0) {                            
                leftWallHeights.insert(-w.second);
            } else {                                     
                leftWallHeights.erase(leftWallHeights.find(w.second));
            }
            if (*leftWallHeights.rbegin() != top) { 
                ans.push_back({w.first, top = *leftWallHeights.rbegin()});
            }
        }
        
        return ans;
    }
};