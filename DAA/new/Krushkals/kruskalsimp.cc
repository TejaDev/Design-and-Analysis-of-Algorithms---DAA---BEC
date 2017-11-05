#include"kruskals.h"
void kruskalsAlg::read(int num)
{
	mc = 10000;
	for(int i=0;i<=num;i++)
		for(int j=0;j<=num;j++)
			cost[i][j]=10000;
	cout<<"enter number of edges in the graph\n";
	cin>>ne;
	if(ne<=(((num-1)*(num))/2)){
			cout<<"two vertices cannot be equal or vertices should be <"<<num<<" and >0\n";
	f:
	cout<< "enter details of edges\n";
	int k,l,w;	
	for(int i=0;i<ne;i++){
		cout<<"enter first vertex of edge:";
		cin>>k;
		cout<<"enter second vertex of edge:";
		cin>>l;
		cout<<"enter cost vertex of edge:";
		cin>>w;
		if(k!=l&&k<=num&&l<=num&&k>0&&l>0){			
		p[i][0]=k;p[i][1]=l;p[i][2]=w;
		if (mc > w)
			mc = w;
			cout<<"two vertices cannot be equal or vertices should be <"<<num<<" and >0\n";
		}
		else{
			cout<<"two vertices cannot be equal or vertices should be <"<<num<<" and >0\n";
			i--;
		}
	}
	cout<<"given edges and their cost\n";
	
		for(int j=1;j<=num;j++)
			cout<<p[i-1][0]<<","<<p[i-1][1]<<"\t"<<p[i-1][2]<<"\n";	
			
	
}
	else{
		cout<<"number of edges cannot be grater than"<<(((num-1)*(num)/2));
		goto f;	
	}
	
	
}

int kruskalsAlg::kruskals(int n)
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
	for (i=1; i<=n; i++){
		if(cost[i][l] < cost[i][k])
			near[i] = l;
		else
			near[i] = k;
	}
	
	near[k] = near[l] = 0;

	for(i=2; i <= n-1; i++)
	{
			
		for(int k=1; k<=n; k++)
			if( near[k] != 0 && (cost[k][near[k]] < p) )
			{
				p = cost[k][near[k]];
				j = k; 
				
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

		
		
	}
	cout << "\n\nT matrix:\n";
	for (i=1; i<n; i++)
	{
		
		cout << "\t" << t[i][1] << " \t" << t[i][2] << endl;
	}
	return mc;

}
