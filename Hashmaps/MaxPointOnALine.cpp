class Solution {
public:
    struct hash_pair { 
        template <class T1, class T2> 
        size_t operator()(const pair<T1, T2>& p) const
        { 
            auto hash1 = hash<T1>{}(p.first); 
            auto hash2 = hash<T2>{}(p.second); 
            return hash1 ^ hash2; 
        } 
    };
    int maxPoints(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size();
        if(n<=1)return n;
        for(int i=0;i<n;i++)
        {
            int same=1;
            int local=0;
            int x1=points[i][0],y1=points[i][1];
            unordered_map<pair<int,int>,int,hash_pair> m;
            for(int j=i+1;j<n;j++)
            {
                int x2=points[j][0],y2=points[j][1];
                if(x1==x2 and y1==y2)same++;
                else if(x1==x2)m[{INT_MAX,0}]++;
                else
                {
                    int num=y2-y1;
                    int den=x2-x1;
                    int g=__gcd(num,den);
                    num/=g;
                    den/=g;
                    m[{num,den}]++;
                }
            }
            for(auto it:m)
                local=max(local,it.second);
            local+=same;
            ans=max(ans,local);
        }
        return ans;
    }
};