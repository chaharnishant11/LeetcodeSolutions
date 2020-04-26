class Solution {
public:
    bool canJump(vector<int>& A) {
        int n=A.size();
        int i = 0;
        for (int reach = 0; i < n && i <= reach; ++i)
            reach = max(i + A[i], reach);
        return i == n;
    }
};