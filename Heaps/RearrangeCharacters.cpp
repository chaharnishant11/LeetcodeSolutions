#include <bits/stdc++.h>
using namespace std;

bool helper(string s){
    if(s.size()==0) return true;
    map<char,int> m;
    for(int i=0;i<s.size();i++){
        m[s[i]]++;
    }
    priority_queue<pair<int,char>> q;
    for(auto i:m){
        q.push({i.second,i.first});
    }
    string ans="";
    int i=0;
    auto temp=q.top();
    q.pop();
    ans+=temp.second;
    temp.first--;
    while(!q.empty()){
        auto x=q.top();
        q.pop();
        ans+=x.second;
        x.first--;
        if(temp.first>0) q.push(temp);
        temp=x;
    }
    return ans.size()==s.size();
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    string s;
	    cin >> s;
	    bool ans = helper(s);
	    if(ans) cout << 1 << endl;
	    else cout << 0 <<  endl;
	}
	return 0;
}