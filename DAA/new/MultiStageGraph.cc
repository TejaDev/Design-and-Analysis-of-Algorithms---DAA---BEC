#include<iostream>
                          
using namespace std;

class MultiStageGraph
{
	int n, s, *cost, *p, *b, **sv, **cst, *ns, k;
		
	public:
		
		MultiStageGraph()
		{
			  int w;
			  cout << "Enter number of vertices:";
			  cin>>n;
			  cout << "Enter number of stages:";
			  cin >> s;
			  cost=new int[n];
			  p=new int[s];
			  b=new int [n];
			  for(int i=1;i<=n;i++)
			  {
				cost[i]=0;
				b[i]=0;
			  }
			
			ns=new int[s];
			sv=new int*[s];
			for(int i=1;i<=s;i++)
			{
			    p[i]=0;
			    if(i==1 || i==s)
			    {
			      ns[1]=ns[s]=1;
			      sv[i]=new int[1];
			    }
			    else
			    {
				cout<<"Enter number of vertices in stage "<< i <<" : ";
				cin >> w;
				ns[i] = w;
				sv[i] = new int[w];
			    }
			}
			cst=new int*[n];
			  for(int i=1;i<=n;i++)
			      cst[i]=new int[n];
			  for(int i=1;i<=n;i++)
			  {
			      for(int j=1;j<=n;j++)
			      {
				  cst[i][j]=10000;
			      }
			  }
				    
		}
		
		void read();
		void forward();
		int val(int*,int);
};

void MultiStageGraph::read()
{
      int x=1; 
      for(int i=1;i<=s;i++){
         for(int j=1;j<=ns[i];j++){
               sv[i][j]=x;
               x=x+1;
         }
      }
       int v,c,d;
	cout<<"If no edge exists enter 10000 value"<<endl;
	for(int f=1; f<s; f++)
	{
	  for(int i=1; i<=ns[f]; i++)
	  {
	    for(int q=1; q<=ns[f+1]; q++)
	    {
               cout<<"Enter cost of edge from "<<sv[f][i]<<"  To  "<<sv[f+1][q]<<":";
               cin>>c;
               v=sv[f+1][q];
               d=sv[f][i];
               cst[d][v]=c;
	   }
	 }
       }
}

void MultiStageGraph::forward()
{
      cost[n]=0;
      for(int j=s-1;j>=1;j--)
      {
         int *a,f;
         f=ns[j+1];
         a=new int[f];
         for(int i=1;i<=ns[j];i++)
	 {
                 int v=sv[j][i];
                 for(int h=1;h<=ns[j+1];h++)
		 {
                        int u=sv[j+1][h];
                        a[h]=cst[v][u]+cost[u];
                 }
                 cost[v]=val(a,f);
                 b[v]=sv[j+1][k];
         }
      }
      p[1]=1;
      p[s]=n;
      for(int j=2;j<=s-1;j++)
            p[j]=b[p[j-1]];
      cout << "minimum cost is:" << cost[1] << endl;
      cout << "Path is:"<< endl;
      cout<<p[1];
      for(int i=2;i<=s;i++) 
          cout << " --> " << p[i];
      cout<<endl;
}

int MultiStageGraph::val(int *a, int l)
{
    int m=a[1];k=1;
    for(int i=1;i<=l;i++){
         if(a[i]<m){
             m=a[i];
             k=i;
         }
    }
    return m;
}

int main()
{
	MultiStageGraph m;
	m.read();
	m.forward();
	return 0;
}
