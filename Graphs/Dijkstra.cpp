#include <bits/stdc++.h>
#include <climits>
using namespace std;

void dijkstra(int** edges,int v){
    bool vis[v];
    int dis[v];
    for(int i=0;i<v;i++){
        vis[i]=false;
        dis[i]=INT_MAX;
    }
    dis[0]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // heap to get the minimum distance
    pq.push({0,0});
    while(!pq.empty()){
        int node=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        if(!vis[node]){
            dis[node]=d;
            vis[node]=true; // mark visited on removal not while pushing so that all the min paths are considered
            for(int i=0;i<v;i++){
                if(edges[node][i]!=0 && !vis[i]){
                    pq.push({d+edges[node][i],i});
                }
            }
        }
    }
    for(int i=0;i<v;i++){
        cout << i << " " << dis[i] << endl;
    }
}

int main()
{
    int V, E, tempX, tempY;
    cin >> V >> E;
    int **edges=new int*[V];
    for(int i=0;i<V;i++){
        edges[i]=new int[V];
        for(int j=0;j<V;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<E;i++){
        int x,y,w;
        cin >> x >> y >> w;
        edges[x][y]=w;
        edges[y][x]=w;
    }
    dijkstra(edges,V);
    
    return 0;
}
