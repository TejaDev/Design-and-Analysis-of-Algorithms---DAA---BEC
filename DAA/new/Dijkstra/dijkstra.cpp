#include<iostream>
using namespace std;

class X{
	public:
	int *s,*d,*m,**cost,n,t;
	void Dijkstra(int v){
		int u;
		for(int i=1;i<=n;i++)
		{	
			if(i!=v){
				s[i]=0;
				if(cost[v][i]!=10000)
					d[i]=cost[v][i];
				else
					d[i]=10000;
				cout<<i<<"\t"<<d[i]<<"\n";
			}		
		}
		s[v]=1;
		d[v]=0;
		
		for(int k=2;k<=n-1;k++){
			t=0;
			for(int j=1;j<=n;j++){
				if(s[j]==0){
					m[t++]=d[j];
				}	
			}
			for(int j=t;j<=n;j++)
				m[j]=0;
			u=min(m);
			s[u]=1;                                  
			
				
			//for(int i=1;i<=n;i++)
			//	cout<<i<<"\t"<<s[i]<<"\t"<<d[i]<<"\n";
			for(int i=1;i<=n;i++){
				if(i!=u && d[u]!=0 && s[i]==0){
					if(d[i]>d[u]+cost[u][i])
						d[i]=d[u]+cost[u][i];
				}
			}
			cout<<"\n"<<k<<"\t"<<u<<"\n";					
			//for(int i=1;i<=n;i++)
			//	cout<<i<<"\t"<<s[i]<<"\t"<<d[i]<<"\n";	
		}

		for(int i=1;i<=n;i++)
				cout<<i<<"\t"<<s[i]<<"\t"<<d[i]<<"\n";

	}

	int min(int *a){
		int i,j,r,g;
		
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				if(a[i]>a[j]){
					r=a[i];
					a[i]=a[j];
					a[j]=r;
				}
			}
		}
		for(i=1;i<=n;i++){
			if(a[i]!=0){
				g=a[i];
				goto h;
			}
		}
		h:
		for(i=1;i<=n;i++){
			if(d[i]==g)
				return i;
		}
		
	}
	void read(){
		int i1,i2,i3,src;
		cout<<"Enter no: of Vertices: ";
		cin>>n;
		s=new int[n];
		d=new int[n];
		m=new int[n];
		cost=new int*[n];
		for(int i=1;i<=n;i++)
			cost[i]=new int[n];
		while(1){
			cout<<"Enter the vertices which have an edge and its cost:";
			cin>>i1>>i2>>i3;
			if(i1==-1)
				goto x;
			
			cost[i1][i2]=i3;
			cost[i2][i1]=i3;
		}
		x:
		cout<<"Adjacency Matrix:\n";

		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					if(cost[i][j]==0)
						cost[i][j]=10000;
				}	
				cout<<cost[i][j]<<"\t";
				
			}
			cout<<endl;
			
		}

		cout<<"Enter Source Vertex: ";
		cin>>src;
		Dijkstra(src);
	}
};
int main(){
	X o;

	o.read();
}

