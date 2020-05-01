class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int f1 = 0, f2 = 1;
        while (f2 <= k) {
            swap(f1, f2);
            f2 += f1;
        }
        return 1 + (k == f1 ? 0 : findMinFibonacciNumbers(k - f1));
    }
};