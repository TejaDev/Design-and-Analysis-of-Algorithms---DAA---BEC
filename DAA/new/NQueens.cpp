#include<iostream>
#include<stdlib.h> 
#include<math.h>                               
using namespace std;

class X
{
	public:

	int *x,n,count;
	void read(){
		cout<<"Enter the no: of Queens:";
		cin>>n;
		x=new int[n];
		count=0;
		NQueen(1,n);
	}
	void NQueen(int k, int n){
		for(int i=1; i<=n; i++)
		{
			if(place(k, i))
			{
				x[k] = i;
				if(k == n){
					for(int i=1; i<=n; i++){
						count++;
						cout << x[i] << "\t";
					}
					cout << "\n";
					
				}
				else
					NQueen(k+1, n);
			}
			
		}
	}

	bool place(int k, int i){
		for(int j=1; j<=k-1; j++)
			if( (x[j] == i) || (abs(x[j]-i) == abs(j - k)) )
				return false;
		return true;
	}


};



int main()
{
	X o;
	o.read();
	cout<<"No: of Possible solutions are:"<<o.count/o.n;
} 
