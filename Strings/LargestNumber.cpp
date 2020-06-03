class Solution {
    public:
        string largestNumber(vector<int>& nums) {
            string ret;
            sort(nums.begin(),nums.end(),
                [](const int &m,const int&n){
                    return to_string(m)+to_string(n)>to_string(n)+to_string(m);});
            for(int i=0;i<nums.size();++i){
                ret+=to_string(nums[i]);
            }
            if(ret[0]=='0') //for the case nums are all zeros
                return "0";
            return ret;
        }  
    };