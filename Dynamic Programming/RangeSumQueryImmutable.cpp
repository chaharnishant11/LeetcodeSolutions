class NumArray {
public:
    vector<int> sums;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return;
        sums.push_back(nums[0]);
        for(int i=1;i<n;i++){
            sums.push_back(nums[i]);
        }
        for(int i=1;i<n;i++){
            sums[i]+=sums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        if(sums.size()==0) return 0;
        if(i==0) return sums[j];
        return sums[j]-sums[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */