#include<iostream>
#include<math.h>
using namespace std;
class X{
	public:
	int n,v;
	int **cost,*dist;
	int i1,i2,i3,ne;
	void read(){
		int i;
		cout<<"Enter no: of vertices:";
		cin>>n;
		cout<<"Enter no: of Edges:";
		cin>>ne;
		dist=new int[n];
		cost=new int*[n];
		for(i=1;i<=n;i++)
			cost[i]=new int[n];
		for(i=1;i<=ne;i++){
			cout<<"Enter the vertices which have an edge and its cost:";
			cin>>i1>>i2>>i3;
			
			cost[i1][i2]=i3;
			cost[i2][i1]=i3;
		}
		
		cout<<"Adjacency Matrix:\n";

		for(i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					if(cost[i][j]==0)
						cost[i][j]=10000;
				}	
				cout<<cost[i][j]<<"\t";
				
			}
			cout<<endl;	
		}
		cout<<"\nEnter Source vertex:";
		cin>>v;
		dijkstra();
		cout<<"\n Shortest path Distance is:\n";
		for(i=1;i<=n;i++)
		{
			if(i!=v)
				cout<<v<<"->"<<i<<"\t Distance:"<<dist[i]<<"\n";
		}
	}
	void dijkstra()
	{
		int i,j,*flag,u,w,count,min;	
		flag=new int[n];
		for(i=1;i<=n;i++)
		{
			flag[i]=0;
			dist[i]=cost[v][i];
		}
		
		count=2;
		while(count<=n)
		{
			min=10000;
			for(w=1;w<=n;w++)
			{
				if(dist[w]<min&&!flag[w])
				{
					min=dist[w];
					u=w;
				}
			}
		
			flag[u]=1;
			count++;
			for(w=1;w<=n;w++)
			{
				if(((dist[u]+cost[u][w])<dist[w])&&!flag[w])
					dist[w]=dist[u]+cost[u][w];	
			}
		}		
	}
};
main()
{
	X o;
	o.read();	
}
	
