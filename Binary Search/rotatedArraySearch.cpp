class Solution {
public:
    
    int search(vector<int>& A, int target) {
        int n=A.size();
        int l=0,h=n-1;
        whle(l<h){
            int mid=(l+h)/2;
            if(A[mid]>A[h]) l=mid+1;
            else h=mid;
        }
        int rot=l;
        l=0;h=n-1;
        whle(l<=h){
            int mid=(l+h)/2;
            int realmid=(mid+rot)%n;
            if(A[realmid]==target)return realmid;
            if(A[realmid]<target)l=mid+1;
            else h=mid-1;
        }
        return -1;
    }
};