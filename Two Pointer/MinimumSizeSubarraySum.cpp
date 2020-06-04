class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int left[n];
        left[0]=nums[0];
        for(int i=1;i<n;i++){
            left[i]=left[i-1]+nums[i];
        }
        int ans=n;
        if(left[n-1]<s) return 0;
        int j=0;
        for(int i=0;i<n;i++){
            //cout << j << " " << i << " " << left[i] << " " << left[j] << endl;
            if((j>0 && left[i]-left[j]>=s) || (left[i]>=s && j==0)){
                while(left[i]-left[j]>=s){
                    j++;
                }
                ans=min(ans,i-j+1);
            }
        }
        ans=min(ans,n-j);
        return ans;
    }
};