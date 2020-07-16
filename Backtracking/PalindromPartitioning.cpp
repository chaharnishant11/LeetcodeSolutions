bool is_palindrome(const string &A, int l, int r) {
    while (l < r) {
        if (A[l++] != A[r--]) {
            return false;
        }
    }
    return true;
}

void helper(const string &A, vector<string> &palindrome, int l, vector<vector<string>> &palindromes) {
    if (l == A.size()) {
        palindromes.push_back(palindrome);
        return;
    }
    for (int r = l; r < A.size(); ++r) {
        if (is_palindrome(A, l, r)) {
            palindrome.push_back(A.substr(l, r+1-l));
            helper(A, palindrome, r+1, palindromes);
            palindrome.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    vector<vector<string>> palindromes;
    vector<string> palindrome;
    
    helper(A, palindrome, 0, palindromes);

    return palindromes;
}