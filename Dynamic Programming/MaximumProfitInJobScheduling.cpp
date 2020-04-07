class Solution {
public:
    class Job{
        public:
        int s;
        int e;
        int p;
        Job(int s,int e,int p){
            this->s=s;
            this->e=e;
            this->p=p;
        }
    };
    
    static bool compare(const Job a,const Job b){
        return a.e < b.e;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size(); 
        vector<Job> t;
        for(int i=0;i<n;i++){
            Job a=Job(startTime[i],endTime[i],profit[i]);
            t.push_back(a);
        }
        sort(t.begin(),t.end(),compare);
        vector<int> mp;
        for(int i=0;i<n;i++){
            mp.push_back(t[i].p);
        }
        for(int i=1;i<n;i++){
            mp[i]=max(mp[i-1],mp[i]);
            for(int j=i-1;j>=0;j--){
                if(t[i].s>=t[j].e){
                    mp[i]=max(mp[i],mp[j]+t[i].p);
                    break;
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,mp[i]);
        }
        return ans;
    }
};