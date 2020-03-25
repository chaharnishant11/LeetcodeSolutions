class Solution {
public:
    
    string find(unordered_map<string, string> &parent, string s){
        if(parent[s]==s) return s;
        string ps=find(parent,parent[s]);
        parent[s]=ps;
        return ps;
    }
    
    void unionn(unordered_map<string, string> &parent, string a, string b){
        string pa=find(parent,a);
        string pb=find(parent,b);
        
        parent[pa]=pb;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        
        int n=stones.size();
        if(n==0) return 0;
        
        unordered_map<string, string> parent;
        for(int i=0;i<n;i++){
            string a= to_string(stones[i][0]); // x-cord => row
            string b= to_string(stones[i][1]) + "|"; // y-cord => column
            parent[a]=a;
            parent[b]=b;
        }
        
        //marking components
        for(int i=0;i<n;i++){
            string a= to_string(stones[i][0]); // x-cord => row
            string b= to_string(stones[i][1]) + "|"; // y-cord => column
            
            string pa=find(parent,a);
            string pb=find(parent,b);
            
            if(pa!=pb) unionn(parent,pa,pb);
        }
        
        int ans=0;
        for( auto i=parent.begin(); i!=parent.end();i++){
            if(i->first == i->second) ans++;
        }
        
        return n-ans;
    }
};