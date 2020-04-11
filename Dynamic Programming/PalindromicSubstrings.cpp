class Solution {
public:
   int countSubstrings(string s) {
        int N = s.size(), ans = 0;
        for (int center = 0; center <= 2*N-1; ++center) {
            int left = center / 2;
            int right = left + center % 2;
            while (left >= 0 && right < N && s[left]==s[right]){
                ans++;
                left--;
                right++;
            }
        }
        return ans;
    }
};