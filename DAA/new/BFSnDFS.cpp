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
		
		while(1){
			int opt;
			cout<<"Choose the mode of Search:\n1.BFS\n2.DFS\n";
			cin>>opt;
			switch(opt){
				case 1:
					cout<<"Vertices are visited in the order: \n"<<src<<" ";
					BFS(src);
					for(int i=1;i<=n;i++)
						visited[i]=0;
					break;
				case 2:
					cout<<"Vertices are visited in the order: \n"<<src<<" ";
					DFS(src);
					for(int i=1;i<=n;i++)
						visited[i]=0;
					break;
				default:cout<<"Choose a Valid Option\n";
			}
		}
		
	}

	void BFS(int v){
		int k=1,j;
		visited[v]=1;
		int front=1,rare=1;

		
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
	void DFS(int v){
                visited[v]=1;
                for(int i=1;i<=n;i++){
                        if(edge[v][i]==1){
                                if(visited[i]==0){
					cout<<i<<" ";
                                        DFS(i);
                                        
                                }
                        }
                }

        }
		
};
int main(){
	X o;
	o.read();
}
