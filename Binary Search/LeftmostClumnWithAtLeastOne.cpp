/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int n=binaryMatrix.dimensions()[0];
        int m=binaryMatrix.dimensions()[1];
        int ans=-1;
        for(int i=n-1,j=m-1;i>=0&&j>=0;){
            if(binaryMatrix.get(i,j)==0){
                i--;
            }else{
                ans=j;
                j--;
            }
        }
        return ans;
    }
};