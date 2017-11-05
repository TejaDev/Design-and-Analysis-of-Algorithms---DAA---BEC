#include<iostream>
using namespace std;

class X{
        public:
        int **edge,*visited,n,e,src;

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
                cout<<"Vertices are visited in the order: \n"<<src<<" ";
                DFS(src);
                

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
