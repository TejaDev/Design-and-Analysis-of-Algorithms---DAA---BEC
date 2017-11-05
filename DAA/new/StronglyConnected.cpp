#include<iostream>
using namespace std;

class X{
	public:
	int **edge,**trans,*visited,*found,n,e,src,cnt,tmp,*foundx,qwe;	

	void read(){
		int i1,i2;
		cout<<"Enter no: of Vertices:";
		cin>>n;
		cout<<"Enter no: of Edges: ";
		cin>>e;
		edge=new int*[n];
		for(int i=1;i<=n;i++)
			edge[i]=new int[n];
		
		trans=new int*[n];
		for(int i=1;i<=n;i++)
			trans[i]=new int[n];

		visited=new int[n];
		found=new int[n];
		foundx=new int[n];
		for(int g=1;g<=e;g++){
			cout<<"Enter the vertices of Edge"<<g<<":";
			cin>>i1>>i2;
			
			edge[i1][i2]=1;
			trans[i2][i1]=1;

		}

		cout<<"Adjacency Matrix:\n";

		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				cout<<edge[i][j]<<"\t";
			cout<<endl;
			
		}
		
		
		cnt=1;
		qwe=n;
		for(int h=1;h<=n;h++){
			for(int i=1;i<=n;i++){
				visited[i]=0;
				found[i]=0;
			}
			DFSFinished(h);

			tmp=0;

			for(int f=1;f<=n;f++){
				for(int d=1;d<=n;d++){
					if(found[f]==d)
						tmp++;
				}
			}
			if(qwe>tmp)	qwe=tmp;
		}
		if(qwe==n)
			cout<<"The Graph is Strongly Connected.";
		else{
			cout<<"The Graph is not Strongly Connected.\n";
			asd();
		}

	}


	void DFS(int v){
		
		visited[v]=1;
		
		for(int i=1;i<=n;i++){
			if(trans[v][i]==1){
				if(visited[i]==0){
					found[++cnt]=i;	
					cout<<i<<"\t";				
					DFS(i);					
				}
			}
		}
		
		
	}

	void DFSFinished(int v){
		
		visited[v]=1;
		for(int i=1;i<=n;i++){
			if(edge[v][i]==1){
				if(visited[i]==0){
					DFSFinished(i);							
					foundx[cnt++]=i;								
				}
			}
		}
		
	}
	
	void asd(){
		for(int i=1;i<=n;i++){
			visited[i]=0;
			found[i]=0;
		}
		cnt=1;
		
		DFSFinished(1);
		foundx[cnt]=1;
		cout<<"\nVertices are finished in order:\n";
		for(int i=n;i>=1;i--)
			cout<<foundx[i]<<"\t";
		
		DFT();
	}
	
	void DFT(){
		cout<<"\nTranspose Matrix:\n";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				cout<<trans[i][j]<<"\t";
			cout<<"\n";
		}
		for(int i=1;i<=n;i++)
			visited[i]=0;
		cout<<"\nStrongly Connected Components are:\n";
		for(int i=n;i>=1;i--){
			if(visited[foundx[i]]==0){
				cnt=1;
				
				cout<<foundx[i]<<"\t";				
				DFS(foundx[i]);
				cout<<"\n";
			}
			
		}
	}
};
int main(){
	X o;
	o.read();
}
