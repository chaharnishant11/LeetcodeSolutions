class Solution {
public:
    int helper(vector<int> A,int t,int l,int r){
        if(l>r) return -1;
        int mid=(l+r)/2;
        if(A[mid]==t) return mid;
        if(A[mid]>=A[l]){
            if(t>=A[l] && t<A[mid])
                return helper(A,t,l,mid-1);
            return helper(A,t,mid+1,r);
        }
        if(t>A[mid] && t<=A[r]){
            return helper(A,t,mid+1,r);
        }
        return helper(A,t,l,mid-1);
    }
    int search(vector<int>& A, int target) {
        return helper(A,target,0,A.size()-1);
    }
};

class Solution {
public:
    
    int search(vector<int>& A, int target) {
        int n=A.size();
        int l=0,h=n-1;
        while(l<h){
            int mid=(l+h)/2;
            if(A[mid]>A[h]) l=mid+1;
            else h=mid;
        }
        int rot=l;
        l=0;h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            int realmid=(mid+rot)%n;
            if(A[realmid]==target)return realmid;
            if(A[realmid]<target)l=mid+1;
            else h=mid-1;
        }
        return -1;
    }
};