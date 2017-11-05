#include"primsimp.cc"
int main()
{	
	int q;
	PrimsAlg ob;
	cout<<"enter no of vertices in graph\n";
	cin>>q;
	ob.read(q);
	cout << "Minimum cost: " << ob.prims(q);
	
   	return 0;
}
