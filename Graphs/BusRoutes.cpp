class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        
        int b=routes.size();
        if(b==0) return 0;
        map<int,bool> visited_stop;
        
        map<int,vector<int>> m; // stop-buses.
        for(int i=0;i<routes.size();i++)
        {
            for(int j=0;j<routes[i].size();j++)
            {
                m[routes[i][j]].push_back(i);
                visited_stop[j]=false;
            }
        }
        if(m.size()==0) return 0;
        
        int visited_bus[b]={0};
        queue<pair<int,int>> q;
        q.push(make_pair(S,0));
        visited_stop[S]=true;
        
        while(!q.empty())
        {
            pair p=q.front();
            q.pop();
            if(p.first==T) return p.second;
            for(auto i:m[p.first])
            {
                if(!visited_bus[i])
                {
                    visited_bus[i]=1;
                    for(auto j:routes[i]) //pushing all unvisited stops covered by this bus
                    {
                        if(!visited_stop[j])
                        {
                            visited_stop[j]=true;
                            q.push(make_pair(j,p.second+1));
                        }
                    }
                    cout<<endl;
                }
            }
        }
        return -1;
    }
};