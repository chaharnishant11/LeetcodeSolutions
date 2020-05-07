class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        int y = 0, z = 1, cy = 0, cz = 0;
        for (auto x: a) {
          if (x == y) cy++;
          else if (x == z) cz++;
          else if (cy==0) y = x, cy = 1;
          else if (cz==0) z = x, cz = 1;
          else cy--, cz--;
        }
        cy = cz = 0;
        for (auto x: a)
          if (x == y) cy++;
          else if (x == z) cz++;
        vector<int> r;
        if (cy > a.size()/3) r.push_back(y);
        if (cz > a.size()/3) r.push_back(z);
        return r;
    }
};