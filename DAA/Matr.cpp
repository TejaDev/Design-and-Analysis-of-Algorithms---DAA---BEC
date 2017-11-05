#include<iostream>
#include<math.h>
using namespace std;

class X{
public:
	void matmul(int *A, int *B, int *R, int n)
	{
		 if (n == 1)
		 {
			(*R) += (*A) * (*B);
		 }
		 else
		 {
			  matmul(A, B, R, n/4);
			  matmul(A, B+(n/4), R+(n/4), n/4);
			  matmul(A+2*(n/4), B, R+2*(n/4), n/4);
			  matmul(A+2*(n/4), B+(n/4), R+3*(n/4), n/4);
			  matmul(A+(n/4), B+2*(n/4), R, n/4);
			  matmul(A+(n/4), B+3*(n/4), R+(n/4), n/4);
			  matmul(A+3*(n/4), B+2*(n/4), R+2*(n/4), n/4);
			  matmul(A+3*(n/4), B+3*(n/4), R+3*(n/4), n/4);
		 }
	}
};
int main()
{
	X o;
	int a[100][100],b[100][100],r[100][100],n,i,j,*a1,*b1,*r1;
	cout<<"Enter order of matrix:";
	cin>>n;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	a[i][j]=1;
	*a1=a[1][1];
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	b[i][j]=1;
	*b1=b[1][1];
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	r[i][j]=0;
	*r1=r[1][1];
	cout<<"Matrix A:\n";
	for(i=1;i<=n;i++)
	{
			for(j=1;j<=n;j++)
			{
					cout<<"\t",a[i][j];
			}
			cout<<"\n";
	}
	cout<<"\nMatrix B:\n";
	for(i=1;i<=n;i++)
	{
			for(j=1;j<=n;j++)
			{
					cout<<"\t",b[i][j];
			}
			cout<<"\n";
	}
	o.matmul(a1,b1,r1,n);
	cout<<"\nResultant:\n";
	for(i=1;i<=n;i++)
	{
			for(j=1;j<=n;j++)
			{
				   cout<<"\t",r[i][j];
			}
			cout<<"\n";
	}
	
} 

