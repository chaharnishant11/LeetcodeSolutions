class Solution {
public:
    Solution(){ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);}
    
    int hIndex(vector<int>& citations) {
        int lens = citations.size(), lo = 0, hi = lens-1;
        while(lo <= hi){
            int mid = lo + (hi-lo) / 2;
            int cnt = lens - mid;
            if(citations[mid] == cnt)  return cnt;
            
            if(citations[mid] < cnt) 
                lo = mid + 1;
            else  
                hi = mid - 1;
        }
        return lens - lo;
    }
};