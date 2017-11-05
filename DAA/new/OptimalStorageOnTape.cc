#include<iostream>
using namespace std;

class Optimalstoragetape
{
	int *t, *o;	
	
	public:
		void read(int);
		void print(int);
		void tapeStorage(int, int);

};

void Optimalstoragetape::read(int size)
{
	t=new int[size];
	o=new int[size];
	cout << "Enter lengths of " << size << " programs:";
	for(int i=0; i<size; i++)
	{
		cin >> t[i];
		o[i] =  i;
	}
	for(int m=0; m<size; m++)
	{	
		int temp;
		for(int n=m+1; n<size; n++)
			if(t[m] > t[n])
			{
				temp = t[m];
				t[m] = t[n];
				t[n] = temp;

				temp = o[m];
				o[m] = o[n];
				o[n] = temp;	

				
			}	
	}
	
}

/*void Optimalstoragetape::print(int size)
{	cout << "TAP\tSTORAGE"<<endl;
	for(int i=0; i<size; i++)
		cout << "t" << o[i] <<"\t" << t[i] <<endl;
	cout <<"\n\n\n\n";
}*/

void Optimalstoragetape::tapeStorage(int n, int m)
{	
	int j=0;
	for(int i=0; i<n; i++)
	{
		cout << "append program "<<o[i]+1<<" to permutation for tape "<<j+1<<endl;
		j = (j+1) % m;
	}
    	
}

int main()
{	
	int q,w;
	Optimalstoragetape ob;
	cout << "Enter number of programs:";
	cin >> q;
	cout << "Enter number of tapes:";
	cin >> w;
	ob.read(q);
     	ob.tapeStorage(q,w);
	return 0;
}

