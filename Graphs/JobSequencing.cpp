#include <bits/stdc++.h>
using namespace std;

struct Job{
    int p;
    int d;
    int id;
};

bool compare(const Job& a,const Job& b){
    return a.p>b.p;
}

int Find(int x,int* parent){
    if(parent[x]==x){
        return x;
    }
    int px=Find(parent[x],parent);
    parent[x]=px;
    return px;
}

void Union(int a,int b,int* parent){
    int pa=Find(a,parent);
    int pb=Find(b,parent);
    parent[pb]=pa;
}

void helper(Job* a,int n,int md){
    sort(a,a+n,compare);
    int days[md+1];
    for(int i=0;i<md+1;i++)days[i]=i;
    int profit=0;
    int num=0;
    for(int i=0;i<n;i++){
        int pb=Find(a[i].d,days);
        if(pb>0){
            profit+=a[i].p;
            num++;
            Union(pb-1,pb,days);
        }
    }
    cout << num << " " << profit << endl;
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    Job a[n];
	    int maxd=-1;
	    for(int i=0;i<n;i++){
	        int p,d,id;
	        cin >> id >> d >> p;
	        Job x;
	        maxd=max(maxd,d);
	        x.id=id;
	        x.d=d;
	        x.p=p;
	        a[i]=x;
	    }
	    helper(a,n,maxd);
	}
	return 0;
}#include <bits/stdc++.h>
using namespace std;

struct Job{
    int p;
    int d;
    int id;
};

bool compare(const Job& a,const Job& b){
    return a.p>b.p;
}

int Find(int x,int* parent){
    if(parent[x]==x){
        return x;
    }
    int px=Find(parent[x],parent);
    parent[x]=px;
    return px;
}

void Union(int a,int b,int* parent){
    int pa=Find(a,parent);
    int pb=Find(b,parent);
    parent[pb]=pa;
}

void helper(Job* a,int n,int md){
    sort(a,a+n,compare);
    int days[md+1];
    for(int i=0;i<md+1;i++)days[i]=i;
    int profit=0;
    int num=0;
    for(int i=0;i<n;i++){
        int pb=Find(a[i].d,days);
        if(pb>0){
            profit+=a[i].p;
            num++;
            Union(pb-1,pb,days);
        }
    }
    cout << num << " " << profit << endl;
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    Job a[n];
	    int maxd=-1;
	    for(int i=0;i<n;i++){
	        int p,d,id;
	        cin >> id >> d >> p;
	        Job x;
	        maxd=max(maxd,d);
	        x.id=id;
	        x.d=d;
	        x.p=p;
	        a[i]=x;
	    }
	    helper(a,n,maxd);
	}
	return 0;
}