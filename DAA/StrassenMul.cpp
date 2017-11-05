#include<iostream>
#include<math.h>
using namespace std;
class X{

    public:
	int i,j,k,s1;
	int **a,**b,**c;

	void readnprint(){
		int size;
		cout<<"Enter Size of Array A: ";
		cin>>s1;
		//cout<<s1;
		size=s1;
		l:
		for(i=1;i<6;i++){
			if(s1==pow(2,i))
				goto x;
			if(i==5){
				s1++;
				goto l;
			}

		}


		x:
		cout<<"\n"<<size<<"\t"<<s1;
		a=new int*[s1];
		for(i=0;i<s1;i++)
			a[i]=new int[s1];
		//cout<<"Enter the Elements of the Array A: ";
		for(i=0;i<size;i++){
			for(j=0;j<size;j++)
				a[i][j]=10;
		}
		cout<<"Elements of Array A are set to 10";
		//cout<<"Enter Size of Array B: ";
		//cin>>s2;
		b=new int*[s1];
		for(i=0;i<s1;i++)
			b[i]=new int[s1];

		c=new int*[s1];
		for(i=0;i<s1;i++)
			c[i]=new int[s1];


		cout<<"Enter the Elements of the Array B: ";
		for(i=0;i<size;i++){
			for(j=0;j<size;j++)
				cin>>b[i][j];
		}
		//intitializing array elements to convert it into power of 2 order
		for(i=size;i<s1;i++){
			for(j=0;j<s1;j++)
				a[i][j]=0;
		}
		for(i=0;i<s1;i++){
			for(j=size;j<s1;j++)
				a[i][j]=0;
		}
		for(i=size;i<s1;i++){
			for(j=0;j<s1;j++)
				b[i][j]=0;
		}
		for(i=0;i<s1;i++){
			for(j=size;j<s1;j++)
				b[i][j]=0;
		}
		cout<<"\n";
		print(a,s1);
		print(b,s1);
		cout<<"\n\n\n\n";
		if(s1==2){
			Mul(a,b,c);
			print(c,s1);
		}
		else{MatMul(a,b,c,s1);}
		//print(c,s1);

	}
	void Mul(int **a,int **b,int **c){
		//int a11,a12,a21,a22;
		int p,q,r,s,t,u,v;
		p=(a[0][0] + a[1][1])*(b[0][0] + b[1][1]);
		q=(a[1][0] + a[1][1])*b[0][0];
		r=a[0][0]*(b[0][1] - b[1][1]);
		s=a[1][1]*(b[1][0] - b[0][0]);
		t=(a[0][0] + a[0][1])*b[1][1];
		u=(a[1][0] - a[0][0])*(b[0][0] + b[0][1]);
		v=(a[0][1] - a[1][1])*(b[1][0] + b[1][1]);


		c[0][0]=p+s-t+v;
		c[0][1]=r+t;
		c[1][0]=q+s;
		c[1][1]=p+r-q+u;


	}

	void addd(int **a,int **b,int **c,int g){
		for(i=0;i<g;i++){
			for(j=0;j<g;j++)
				c[i][j]=a[i][j]+b[i][j];
		}
	}
	void subb(int **a,int **b,int **c,int g){
		for(i=0;i<g;i++){
			for(j=0;j<g;j++)
				c[i][j]=a[i][j]-b[i][j];
		}
	}

	void print(int **c,int g){
		cout<<"\n";
		for(i=0;i<g;i++){
			for(j=0;j<g;j++)
				cout<<c[i][j]<<"\t";
			cout<<"\n";
		}
		cout<<"\n";
	}

	void MatMul(int **a,int **b,int **c,int n){
		if(n==2){
			Mul(a,b,c);
		}
		else{
			int **a00,**a01,**a10,**a11,**b00,**b01,**b10,**b11,**c00,**c01,**c10,**c11;
			int ns=n/2;
			a00=new int*[ns];
			a01=new int*[ns];
			a10=new int*[ns];
			a11=new int*[ns];
			b00=new int*[ns];
			b01=new int*[ns];
			b10=new int*[ns];
			b11=new int*[ns];
			c00=new int*[ns];
			c01=new int*[ns];
			c10=new int*[ns];
			c11=new int*[ns];
			   


			for(i=0;i<n/2;i++){
				for(j=0;j<n/2;j++){
					a00[i][j]=a[i][j];	b00[i][j]=b[i][j];}
			}
			int w,z;
			for(i=0;i<n/2;i++){
				for(j=n/2;j<n;j++){
			    		if(j==n/2){ z=0;}
						a01[i][z]=a[i][j];	b01[i][z]=b[i][j];
			    z++;
			}

			}
			for(i=n/2;i<n;i++){
				for(j=0;j<n/2;j++){
                    			if(i==n/2){ w=0;}
					a10[w][j]=a[i][j];	b10[w][j]=b[i][j];
				}
				w++;
			}
			for(i=n/2;i<n;i++){
				for(j=n/2;j<n;j++){
                    			if(i==n/2){ w=0;}
					if(j==n/2){z=0;}
					a11[w][z]=a[i][j];	b11[w][z]=b[i][j];
					z++;
				}
				w++;
			}
            /*
			print(a00,n/2);
			print(a01,n/2);
			print(a10,n/2);
			print(a11,n/2);
			print(b00,n/2);
			print(b01,n/2);
			print(b10,n/2);
			print(b11,n/2);*/
			int **p,**q,**r,**s,**t,**u,**v,**t1,**t2,**t3;

			p=new int*[ns];
			q=new int*[ns];
			r=new int*[ns];
			s=new int*[ns];
			t=new int*[ns];
			u=new int*[ns];
			v=new int*[ns];
			t1=new int*[ns];
			t2=new int*[ns];

			for(i=0;i<ns;i++){
				p[i]=new int[ns];
				q[i]=new int[ns];
				r[i]=new int[ns];
				s[i]=new int[ns];
				t[i]=new int[ns];
				u[i]=new int[ns];
				v[i]=new int[ns];
				t1[i]=new int[ns];
				t2[i]=new int[ns];
			}


			addd(a00,a11,t1,n/2);
			addd(b00,b11,t2,n/2);
			MatMul(t1,t2,p,n/2);
			cout<<"Matrix p:";
            print(p,n/2);

			addd(a10,a11,t1,n/2);
			MatMul(t1,b00,q,n/2);
			cout<<"Matrix q:";
            print(q,n/2);

			subb(b01,b11,t1,n/2);
			MatMul(a00,t1,r,n/2);
			cout<<"Matrix r:";
            print(r,n/2);

			subb(b10,b00,t1,n/2);
			MatMul(a11,t1,s,n/2);
			cout<<"Matrix s:";
		print(s,n/2);

			addd(a00,a01,t1,n/2);
			MatMul(t1,b11,t,n/2);
			cout<<"Matrix t:";
		print(t,n/2);

			subb(a10,a00,t1,n/2);
			addd(b00,b01,t2,n/2);
			MatMul(t1,t2,u,n/2);
			cout<<"Matrix u:";
		print(u,n/2);

			subb(a01,a11,t1,n/2);
			addd(b10,b11,t2,n/2);
			MatMul(t1,t2,v,n/2);
			cout<<"Matrix v:";
		print(v,n/2);

			addd(s,v,t1,n/2);
			addd(p,t1,t2,n/2);
			subb(t2,t,c00,n/2);
			cout<<"Matrix c00:";
		print(c00,n/2);

			addd(r,t,c01,n/2);
			cout<<"Matrix c01:";
		print(c01,n/2);

			addd(q,s,c10,n/2);
			cout<<"Matrix c10:";
		print(c10,n/2);


			addd(p,r,t1,n/2);
			addd(u,t1,t2,n/2);
			subb(t2,q,c11,n/2);
			cout<<"Matrix c11   :";
            print(c11,n/2);

		}

	}


};
int main(){
	X o;
	int x,k;
	o.readnprint();
	//int a[10];
	//cout<<sizeof(a)/4;
}

