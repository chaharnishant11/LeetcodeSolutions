class Solution {
public:
    int carFleet(int t, vector<int>& p, vector<int>& s) {
        map<int, double> m;
        for (int i = 0; i < p.size(); i++) 
            m[-p[i]] = (double)(t - p[i]) / s[i];
        int res = 0; double cur = 0;
        for (auto it : m) 
            if (it.second > cur) 
                cur = it.second, res++;
        return res;
    }
};