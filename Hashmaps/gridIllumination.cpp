class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        map<pair<int,int>,int> m;
        unordered_map<int,int> r,c,d1,d2;
        for(int k=0;k<lamps.size();k++){
            int i=lamps[k][0];
            int j=lamps[k][1];
            r[i]++;
            c[j]++;
            d1[i+j]++;
            d2[i-j]++;
            m[{i,j}]++;
        }
        vector<int> ans;
        for(int k=0;k<queries.size();k++){
            int i=queries[k][0];
            int j=queries[k][1];
            if(r[i]>0 || c[j]>0 || d1[i+j]>0 || d2[i-j]>0){
                ans.push_back(1);
                for(int a=-1;a<=1;a++){
                    for(int b=-1;b<=1;b++){
                        int l=i+a;
                        int n=j+b;
                        if(l>=0 && l<N && n>=0 && l<N && m.find({l,n})!=m.end()){
                            r[l]--;
                            c[n]--;
                            d1[l+n]--;
                            d2[l-n]--;
                            m.erase({l,n});
                        }
                    }
                }
            }else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};