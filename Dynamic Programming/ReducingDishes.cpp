class Solution {
public:
      int maxSatisfaction(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0, total = 0, n = A.size();
        for (int i = n - 1; i >= 0 && A[i] > -total; --i) {// A[i]>-total keeps the res>0
            total += A[i]; // total sum tilll now
            res += total; // adds total so that if there is possibility of having something postitve then that could be added.
            cout << total << " " << res  << " " << A[i] << " " << i << endl;
        }
        return res;
    }
};