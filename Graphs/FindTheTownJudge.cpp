class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int id[N];
        int od[N];
        memset(id,0,sizeof(id));
        memset(od,0,sizeof(od));
        for(int i=0;i<trust.size();i++){
            id[trust[i][1]-1]++;
            od[trust[i][0]-1]++;
        }
        int ans=-1;
        for(int i=0;i<N;i++){
            if(id[i]==N-1 && od[i]==0) return i+1;
        }
        return ans;
    }
};