#include <bits/stdc++.h>
#include <iterator>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'paperCuttings' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER textLength
 *  2. INTEGER_ARRAY starting
 *  3. INTEGER_ARRAY ending
 */
int calc(vector<int> arr,int a){   
    int n=arr.size();
    int s,e;
    s=0;
    e=n-1;
    int ans=-1;
    while(s<=e)
    {   int m=(s+e)/2;
        if(arr[m]>a)
        { ans=m;
        e=m-1;
    }
    else {
        s=m+1;
    
    }
}
return ans;
}

long paperCuttings(int textLength, vector<int> starting, vector<int> ending) {
    long ans=0;
    vector<int> g1,g2;
    vector<pair<int,int>> g3;
    for(int i=0;i<starting.size();i++)
    { g3.push_back(make_pair(starting[i],ending[i]));
        //g1.push_back(starting[i]);
    //g2.push_back(ending[i]);
    }
    sort(g3.begin(),g3.end());
    vector<pair<int,int>> g4;
    for(int i=0;i<g3.size();i++){ 
        int t1,t2;
        t1=g3[i].first;
        t2=g3[i].second;
        g4.push_back(make_pair(t1,t2));
        while(i<g3.size())
        { if(g3[i].first==t1&&g3[i].second==t2)
            i++;
            else
            break;
        }
        i--;
    }
    for(int i=0;i<g4.size();i++){ 
        g1.push_back(g4[i].first);
        g2.push_back(g4[i].second);
    }
    sort(g1.begin(),g1.end());
    sort(g2.begin(),g2.end());
    for(int i=0;i<g2.size();i++){ 
        int t1=calc(g1,g2[i]);
        if(t1!=-1){ 
            ans+=(g1.size()-t1);
        }
    }
    return ans;
}
int main()

#include <bits/stdc++.h>
#include <iterator>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'paperCuttings' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER textLength
 *  2. INTEGER_ARRAY starting
 *  3. INTEGER_ARRAY ending
 */

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