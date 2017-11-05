#include<iostream>
using namespace std;

class X{
	public:
	int **edge,*visited,*found,n,e,src,cnt,tmp,*queue;	

	void read(){
		int i1,i2;
		cout<<"Enter no: of Vertices:";
		cin>>n;
		cout<<"Enter no: of Edges: ";
		cin>>e;
		edge=new int*[n];
		for(int i=1;i<=n;i++)
			edge[i]=new int[n];

		visited=new int[n];
		found=new int[n];
		queue=new int[n];
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
		
		found[n]=1;
		cnt=1;

		DFS(1);

		tmp=0;

		for(int f=1;f<=n;f++){
			for(int d=1;d<=n;d++){
				if(found[f]==d)
					tmp++;
			}
		}
		if(tmp==n)
			cout<<"The Graph is Connected.";
		else{
			cout<<"The Graph is not Connected.\n";
			BFT();
		}

	}
	
	void DFS(int v){
		visited[v]=1;
		for(int i=1;i<=n;i++){
			if(edge[v][i]==1){
				if(visited[i]==0){
					DFS(i);
					
					found[cnt++]=i;
				}
			}
		}
		
	}
	void BFS(int v){
		int k=1,j;
		visited[v]=1;
		int front=1,rare=1;

		cout<<v<<" ";
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
			if(v==0)
				goto x;
			
		}
		x:
		cout<<"\n";
				
	
	}

	void BFT(){
		for(int i=1;i<=n;i++)
			visited[i]=0;
		cout<<"Connected Components are:\n";
		for(int i=1;i<=n;i++){
			if(visited[i]==0)				
				BFS(i);
	
		}
		
	}

};
int main(){
	X o;
	o.read();
}
