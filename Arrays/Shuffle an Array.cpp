class Solution {
public:
    vector<int> org;
    vector<int> aux;
    
    Solution(vector<int>& nums) {
        org= nums;
        aux= nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        aux= org;
        return org;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n= aux.size();
        for(int size=n; size>0; size--) {
            int in= rand()%size;
            swap(aux[in], aux[size-1]);
        }
        return aux;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
