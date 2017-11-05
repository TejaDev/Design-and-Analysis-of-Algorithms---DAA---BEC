#include "kruskalsimp.cc"
int main()
{
	int n;
	kruskalsAlg k1;
	cout<<"enter the number of vertices\n";
	cin>>n;
	k1.read(n);
	k1.kruskals(n);
}
