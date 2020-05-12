#include <bits/stdc++.h>
using namespace std;

bool helper(vector<vector<int>> g,int v,int e,int s){
    vector<int> dis(v,INT_MAX);
    dis[s]=0;
    for(int i=0;i<v-1;i++){
        for(int j=0;j<e;j++){
            if(dis[g[j][0]]+g[j][2]<dis[g[j][1]]){
                dis[g[j][1]]=dis[g[j][0]]+g[j][2];
            }
        }
    }
    for(int i=0;i<e;i++){
        if(dis[g[i][0]]!=INT_MAX && dis[g[i][0]]+g[i][2]<dis[g[i][1]]){
            return false;
        }
    }
    return true;
}

int main() {
	//code
	int t;
	cin >>t;
	while(t--){
	    int v,e;
	    cin >> v >> e;
	    vector<vector<int>> g;
	    for(int i=0;i<e;i++){
	        int x;
	        int y;
	        int w;
	        cin >> x >> y >> w;
	        g.push_back({x,y,w});
	    }
	    bool printed=false;
	    for(int i=0;i<v;i++){
	        if(!helper(g,v,e,i)){
	            cout << 1 << endl;
	            printed = true;
	            break;
	        }
	    }
	    if(!printed) cout << 0 << endl;
	}
	return 0;
}