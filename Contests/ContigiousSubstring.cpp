// Attlassain Test
#include <bits/stdc++.h>
#include <iterator>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

long paperCuttings(int textLength, vector<int> starting, vector<int> ending) {
    int n = starting.size();

    set<pair<int,int>> st;

    for(int i = 0; i < n; i++){
        st.insert({starting[i], ending[i]});
    }

    long ans = 0;

    vector<int> s, e;
    while(!st.empty()){
        auto p = st.begin();
        s.push_back(p->first);
        e.push_back(p->second);
        st.erase(st.begin());
    }
    n = s.size();
    for(int i = 0; i < n; i++){
        int x = upper_bound(s.begin(), s.end(), e[i]) - s.begin();
        ans += (n-x);
    }

    return ans;
}
int main()
