class Solution {
public:
    char nextGreatestLetter(vector<char>& let, char t) {
        int l=0;
        int r=let.size();
        while(l<r){
            int mid=l+(r-l)/2;
            if(let[mid]<=t) l=mid+1;
            else r=mid;
        }
        return let[l%let.size()];
    }
};
 