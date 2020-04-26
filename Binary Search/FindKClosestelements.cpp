class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = max(0, idx - k);
        int r = min(n - 1, idx + k - 1);
        while (r - l + 1 > k) {
            if (x - arr[l] > arr[r] - x) {
                l++;
            } else {
                r--;
            }
        }
        return vector<int>(arr.begin() + l, arr.begin() + r + 1);
    }
};