#include<iostream>
using namespace std;

class PrimsAlg
{
	int **cost, mc, **t, *near;

	public:
		void read(int);
		int prims(int);

};

void PrimsAlg::read(int size)
{
	mc = 10000;
	int v1, v2, w, i, j, e;
	
	cout << "Enter number of edges:" ;
	cin >> e;
	near = new int[size];
	cost = new int *[size];
	   t = new int *[size];
	
	for(i=1; i<=size; i++){
		cost[i] = new int[size];
		   t[i] = new int[2];	
	}

	for(i=1; i<=size; i++)
		for(int j=1; j<=size; j++)
			 cost[i][j] = 10000;
	for(i=1; i<=e; i++)
	{
		cout << "\nEnter two vertice and edge  weight between them :";
		cin >> v1;
		cin >> v2;
		cin >> w;
		cost[v1][v2]=w;
		cost[v2][v1]=w;
		
		if (mc > w)
			mc = w;

	}
	
	
	cout << "Adjacency Matrix:\n";
	for(i=1; i<=size; i++){
		for(j=1; j<=size; j++)
			cout << cost[i][j] <<"\t";
		cout << "\n";
	}
	
}

int PrimsAlg::prims(int n)
{
	int k, l, i, p=10000, j, cnt=0;
	for(i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if( cost[i][j] == mc )
			{
				k = j;
				l = i;		
			}	

	cout << "minimum cost edge: " << k << "\t" << l << endl;
	t[1][1] = k;
	t[1][2] = l;
	for (i=1; i<=n; i++)
		if(cost[i][l] < cost[i][k])
			near[i] = l;
		else
			near[i] = k;
	
	near[k] = near[l] = 0;

	/*cout << "near matrix:\n";
	for(i=1; i<=n; i++)
		cout << near[i] << "\t";
	cout <<"\n";*/

	for(i=2; i <= n-1; i++)
	{
		
		
		for(int k=1; k<=n; k++)
			if( near[k] != 0 && (cost[k][near[k]] < p) )
			{
				p = cost[k][near[k]];
				j = k; 
				/*cout <<"\n" << k <<"\n";*/
				cnt++;
			}
		if(cnt > 0)
		{
			mc += cost[j][near[j]]; 
			t[i][1] = j;
			t[i][2] = near[j];
			near[j] = 0;
		}
		cnt = 0;
		p = 10000;
		for (int k=1; k<=n; k++)
			if( (near[k] != 0) && (cost[k][near[k]] > cost[k][j]) )
				near[k] = j;

		/*cout << "\n\nnear matrix:\n";
		for(int z=1; z<=n; z++)
			cout << near[z] << "\t";
		cout << "\nn=" << n << "\n";*/
		
		
	}
	cout << "\n\nT matrix:\n";
	for (i=1; i<n; i++)
	{
		
		cout << "\t" << t[i][1] << " \t" << t[i][2] << endl;
	}
	return mc;

}
int main()
{	
	int q;
	PrimsAlg ob;
	cout << "Enter size of an vertices:";
	cin >> q;
	ob.read(q);
	cout << "Minimum cost: " << ob.prims(q);
	
   	return 0;
}

