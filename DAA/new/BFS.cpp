#include<iostream>
using namespace std;

class X{
	public:
	int **edge,*visited,*queue,n,e,src,*q;	

	void read(){
		int i1,i2;
		cout<<"Enter no: of Vertices:";
		cin>>n;
		cout<<"Enter no: of Edges: ";
		cin>>e;
		edge=new int*[n];
		for(int i=1;i<=n;i++)
			edge[i]=new int[n];
		queue=new int[n];
		q=new int[n];
		visited=new int[n];

		
		for(int g=1;g<=e;g++){
			cout<<"Enter the vertices of Edge"<<g<<":";
			cin>>i1>>i2;
			
			edge[i1][i2]=1;
			edge[i2][i1]=1;

		}

		cout<<"Adjacency Matrix:\n";

		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				cout<<edge[i][j]<<"\t";
			cout<<endl;
			
		}
		cout<<"Enter Source Vertex:";
		cin>>src;
		BFS(src);

	}

	void BFS(int v){
		int k=1,j;
		visited[v]=1;
		int front=1,rare=1;

		cout<<"Vertices are visited in the order: \n"<<v<<" ";
		while(k<n)
		{
			for(j=1;j<=n;j++)
				if(edge[v][j]!=0 && visited[j]!=1 )
				{
					queue[rare++]=j;
					visited[j]=1;
					cout<<j << " ";
					
				}
			
			v=queue[front++];
			
			k++;
			
		}
				
	
	}
		
};
int main(){
	X o;
	o.read();
}
