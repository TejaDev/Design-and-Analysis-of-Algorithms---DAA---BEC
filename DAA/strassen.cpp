#include<iostream>
using namespace std;
class strassen
{
int r,c;
int mat[10][10];
public:
void read_mat();
void print_mat();
void multiply(strassen,strassen);
};
void strassen::read_mat()
{
int i,j;
cout<<"Enter the size of Matrix:\n";
cin>>r>>c;
cout<<"Enter the Elements of matrix:\n";
if(r==c)
for(i=0;i<r;i++)
for(j=0;j<c;j++)
cin>>mat[i][j];
}
void sub_matrix(int a[2][2],int b[2][2],int d[2][2])
{
int i,j;
for(i=0;i<2;i++)
for(j=0;j<2;j++)
d[i][j]=a[i][j]-b[i][j];
}
void add_matrix(int a[2][2],int b[2][2],int d[2][2])
{
int i,j;
for(i=0;i<2;i++)
for(j=0;j<2;j++)
d[i][j]=a[i][j]+b[i][j];
}
void mul_matrix(int a[2][2],int b[2][2],int d[2][2])
{
int i,j;
for(i=0;i<2;i++)
for(j=0;j<2;j++)
 {
 d[i][j]=0;
 for(int k=0;k<2;k++)
 d[i][j]=a[i][k]*b[k][j];
 }
}
void print_matrix(int d[2][2])
{
int i,j;
for(i=0;i<2;i++)
 {
 cout<<"\n";
 for(j=0;j<2;j++)
  cout<<d[i][j]<<"\t";
 }
}
void strassen::multiply(strassen a,strassen b)
{
  if(a.r==2)
   {
      int c[2][2];
      int p=(a.mat[0][0]+a.mat[1][1])*(b.mat[0][0]+b.mat[1][1]);
      int q=(a.mat[1][0]+a.mat[1][1])*(b.mat[0][0]);
      int r=(a.mat[0][0])*(b.mat[0][1]-b.mat[1][1]);
      int s=(a.mat[1][1])*(b.mat[1][0]-b.mat[0][0]);
      int t=(a.mat[0][0]+a.mat[0][1])*(b.mat[1][1]);
      int u=(a.mat[1][0]-a.mat[0][0])*(b.mat[0][0]+b.mat[0][1]);
      int v=(a.mat[0][1]-a.mat[1][1])*(b.mat[1][0]+b.mat[1][1]);
   c[0][0]=p+s-t+v;
   c[0][1]=r+t;
   c[1][0]=q+s;
   c[1][1]=p+r-q+u;
     print_matrix(c);
  }
  else if(a.r==4)
  {
	int a11[2][2],a12[2][2],a21[2][2],a22[2][2];
	int b11[2][2],b12[2][2],b21[2][2],b22[2][2];
	int i,j;
	for(i=0;i<2;i++)
	for(j=0;j<2;j++)
	{
		a11[i][j]=a.mat[i][j];
		b11[i][j]=b.mat[i][j];
	}
	for(i=0;i<2;i++)
        for(j=0;j<2;j++)
        {
                a12[i][j]=a.mat[i][j+2];
                b12[i][j]=b.mat[i][j+2];
        }
        for(i=0;i<2;i++)
        for(j=0;j<2;j++)
        {
                a21[i][j]=a.mat[i+2][j];
                b21[i][j]=b.mat[i+2][j];
        }
	for(i=0;i<2;i++)
        for(j=0;j<2;j++)
        {
                a22[i][j]=a.mat[i+2][j+2];
                b22[i][j]=b.mat[i+2][j+2];
        }
       int d[2][2],e[2][2],f[2][2],g[2][2],h[2][2],m[2][2];
        int p[2][2],temp1[2][2],temp2[2][2];
 		add_matrix(a11,a22,temp1);
		add_matrix(b11,b22,temp2);
		mul_matrix(temp1,temp2,d);
		cout<<"p matrix";
		print_matrix(d);

		add_matrix(a21,a22,temp1);
		mul_matrix(temp1,b11,e);
		cout<<"q matrix:";
		print_matrix(e);

		sub_matrix(b12,b22,temp2);
		mul_matrix(a11,temp2,f);
		cout<<"r matrix:";
		print_matrix(f);

		sub_matrix(b21,b11,temp2);
		mul_matrix(a22,temp2,g);
   		cout<<"s matrix:";
		print_matrix(g);

		add_matrix(a11,a12,temp1);
		mul_matrix(temp1,b22,h);
		cout<<"t matrix:";
		print_matrix(h);

		sub_matrix(a21,a11,temp1);
		add_matrix(b11,b12,temp2);
		mul_matrix(temp1,temp2,m);
		cout<<"u matrix:";
		print_matrix(m);

		sub_matrix(a12,a22,temp1);
		add_matrix(b21,b22,temp2);
		mul_matrix(temp1,temp2,p);
		cout<<"v matrix:";
		print_matrix(p);

	   int c11[2][2],c12[2][2],c21[2][2],c22[2][2];
		
		add_matrix(d,g,temp1);
		sub_matrix(p,h,temp2);
		add_matrix(temp1,temp2,c11);

		add_matrix(f,h,c12);
		add_matrix(e,g,c21);
		add_matrix(d,f,temp1);
		add_matrix(temp1,temp2,c22);

	cout<<"\n now c11 matrix:\n";
	print_matrix(c11);

	 cout<<"\n now c12 matrix:\n";
        print_matrix(c12);

	 cout<<"\n now c21 matrix:\n";
        print_matrix(c21);

       cout<<"\n now c22 matrix:\n";
        print_matrix(c22);

   }
}


int main()
{
   int i,j;
   strassen s,p,m;
   s.read_mat();
   p.read_mat();
   cout<<"after multiplication:\n";
   m.multiply(s,p);
}







