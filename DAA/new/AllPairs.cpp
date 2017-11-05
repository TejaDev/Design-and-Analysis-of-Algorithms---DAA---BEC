#include<iostream>
using namespace std;

class AllPairs
{
	int **cost, **a;
	public:
		void read(int);
		int allPairs(int);

};

void AllPairs::read(int size)
{
	int e, v1, v2, w;
	
	cout << "Enter number of edges:" ;
	cin >> e;
	
	cost = new int *[size];
	   a = new int *[size];
	
	for(int i=1; i<=size; i++)
	{
		cost[i] = new int[size];
		a[i] = new int[size];
	}

	for(int i=1; i<=size; i++)
		for(int j=1; j<=size; j++)
			 cost[i][j] = 10000;
	for(int i=1; i<=size; i++)
		cost[i][i] = 0;

	for(int i=1; i<=e; i++)
	{
		cout << "\nEnter two vertices and edge  weight between them :";
		cin >> v1;
		cin >> v2;
		cin >> w;
		cost[v1][v2]=w;	
	}
	
	
	cout << "Adjacency Matrix:\n";
	for(int i=1; i<=size; i++){
		for(int j=1; j<=size; j++)
			cout << cost[i][j] <<"\t";
		cout << "\n";
	}
	cout << "\n";
}

int AllPairs::allPairs(int n)
{
	int sum;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			a[i][j] = cost[i][j];
	
	for(int k=1; k<=n; k++)
	{
		for(int i=1; i<=n; i++)
			for(int j=0; j<=n; j++)
				if( (sum = (a[i][k] + a[k][j])) < a[i][j] )
					a[i][j] = sum;
		cout<< "\na[" << k <<"]\n";
		for(int e=1; e<=n; e++){
			for(int r=1; r<=n; r++)
				cout << a[e][r] <<"\t";
			cout << "\n";
		}
		cout << "\n\n";
	}

	
	
}
int main()
{	
	int q;
	AllPairs ob;
	cout << "Enter the number of vertices:";
	cin >> q;
	ob.read(q);
	ob.allPairs(q);
   	return 0;
}

