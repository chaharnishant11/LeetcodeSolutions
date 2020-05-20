class Solution {
public:
    
    int find( int*parent, int x)
    {
        if(parent[x]==x) return x;
        int px=find(parent,parent[x]);
        parent[x]=px; //path compression
        return px;
    }
    
    void unionn(int* parent, int x, int y)
    {
        int px=find(parent, x);
        int py=find(parent, y);
        
        parent[px]=py;
    }
    
    int regionsBySlashes(vector<string>& grid) {
        
        int n=grid.size();
        if(n==0) return 0;
        
        int p=(n+1)*(n+1);
        int* parent=new int[p];
        for(int i=0;i<p;i++) parent[i]=i; 
        
        //connecting boundary
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++) //nxn grid
            {
                if(i==0 || i==n || j==0 || j==n) parent[i*(n+1)+j]=0; 
            }
        }
        
        int ans=1; //number of regions=number of cylces+1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='/')
                {
                    int cell_top= i*(n+1)+j+1; //converting i,j to cell numbers
                    int cell_bottom=(i+1)*(n+1)+j;
                    
                    int pt=find(parent, cell_top);
                    int pb=find(parent,cell_bottom);
                    
                    if(pt==pb) ans++; //cycle formed on joining cell top and bottom using slash
                    else unionn(parent, pt, pb);
                }
                else if( grid[i][j]=='\\') 
                {
                    int cell_top= i*(n+1)+j;
                    int cell_bottom=(i+1)*(n+1)+j+1;
                    
                    int pt=find(parent, cell_top);
                    int pb=find(parent,cell_bottom);
                    
                    if(pt==pb) ans++; //cycle exists
                    else unionn(parent, pt, pb);
                }
            }
        }
        return ans;
    }
};