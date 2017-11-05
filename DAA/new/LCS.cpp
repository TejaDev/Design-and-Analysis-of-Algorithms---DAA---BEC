#include<iostream>
#include<stdlib.h> 
#include<math.h>                               
using namespace std;

class X
{
	public:

	int **c,m,n;
	char *x,*y,**b;
	
	int read(){
		cout<<"Enter no of characters in String1:";
		cin>>m;
		cout<<"Enter no of characters in String2:";
		cin>>n;
		x=new char[m];
		y=new char[n];

		cout<<"Enter String1:";
		for(int i=1;i<=m;i++)
	    		cin>>x[i];
		cout<<"Enter String2:";
		for(int i=1;i<=n;i++)
	    		cin>>y[i];


		
		c=new int*[m+1];
		for(int i=0;i<=m;i++)
			c[i]=new int[n+1];
		
		b=new char*[m+1];
		for(int i=0;i<=m;i++)
			b[i]=new char[n+1];
		for(int i=0;i<=m;i++){
			for(int j=0;j<=n;j++)
				c[i][j]=0;
			
		}


		for(int i=0;i<=m;i++)
			b[i][0]='X';
		for(int i=0;i<=n;i++)
			b[0][i]='Y';

		
		getLCS();
		//char *gl=getLCS();
		//cout<<"\n";
		//for(int i=0;i<=m;i++)
		//	cout<<gl[i]<<"\t";
		//cout<<"\nzzzz\n";
	}
	
	char* getLCS(){
		char *LCS;
		int mm,ccc;

		mm=LCSCount();		
		
		LCS=new char[mm];
		ccc=0;
		int i,j;
		i=m;
		j=n;
		
		while(i!=0 && j!=0){
			switch(b[i][j]){
				case 'A':
					LCS[ccc++]=y[j];
					i--;
					j--;
					break;
				case 'X':
					i--;
					break;
				case 'Y':
					j--;
					break;

			}
		}
		

		cout<<"\n";
		for(int i=mm;i>=0;i--)
			cout<<LCS[i]<<"\t";
		cout<<"\n";	
		return LCS;
	}
	
	int LCSCount(){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(x[i]==y[j]){
					c[i][j]=c[i-1][j-1]+1;
					b[i][j]='A';
				}
				else if(c[i-1][j]>=c[i][j-1]){
					c[i][j]=c[i-1][j];
					b[i][j]='X';
				}
				else{
					c[i][j]=c[i][j-1];
					b[i][j]='Y';
				}
			}
		}
		
		for(int i=0;i<=m;i++){
			for(int j=0;j<=n;j++)
				cout<<c[i][j]<<"\t";
			cout<<"\n";
		}
		return c[m][n];
	}
	

};



int main()
{
	X o;
	o.read();
} 
