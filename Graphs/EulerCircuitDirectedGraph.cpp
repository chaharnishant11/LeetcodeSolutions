// { Driver Code Starts
#include<bits/stdc++.h>
#include <list>
#define CHARS 26
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
    int *in;
public:
    Graph(int V);
    ~Graph()   { delete [] adj; delete [] in; }
    void addEdge(int v, int w) { adj[v].push_back(w);  (in[w])++; }
    bool isEulerianCycle();
    bool isSC();
    void DFSUtil(int v, bool visited[]);
 
    Graph getTranspose();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    in = new int[V];
    for (int i = 0; i < V; i++)
       in[i] = 0;
}
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
int main()
{
    int t;
	cin>>t;
	while(t--){
		int V,E;
		cin>>V>>E;
		Graph g(V);
		for(int i=0;i<E;i++){
			int a,b;
			cin>>a>>b;
			g.addEdge(a,b);
		}
		if (g.isEulerianCycle())
		   cout << "1\n";
		else
		   cout << "0\n";
	}
    return 0;
}// } Driver Code Ends


/*Complete the function below*/
bool Graph::isEulerianCycle(){
//add code here.
    vector<int> ind(V,0);
    vector<int> out(V,0);
    for(int i=0;i<V;i++){
        for(auto j:adj[i]){
            ind[j]++;
            out[i]++;
        }
    }
    for(int i=0;i<V;i++){
        ind[i]-=out[i];
    }
    for(int i=0;i<V;i++){
        if(ind[i]!=0) return false;
    }
    return true;
}