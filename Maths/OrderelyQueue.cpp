class Solution {
public:
    string orderlyQueue(string S, int K) {
        if (K > 1) {  // We can return any permuation that just means we need to return the sorted string (Bubble Sort)
            sort(S.begin(), S.end());
            return S;
        }
        string res = S; // k==1 is the case where we can just rotate the whole string
        for (int i = 1; i < S.length(); i++)
            res = min(res, S.substr(i) + S.substr(0, i));
        return res;
    }
};