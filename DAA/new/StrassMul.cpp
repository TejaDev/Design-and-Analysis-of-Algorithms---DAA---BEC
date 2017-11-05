#include<iostream>
#include<math.h>
using namespace std;
class X{

    public:
	int i,j,k,s1;
	int **a,**b,**c;

	void readnprint(){
		int s1,s11,s2,s21,s3,s31,s4,s41,m1,m2,m;
		cout<<"Enter no: of Rows in Matrix A: ";
		cin>>s1;
		s11=s1;
		
		cout<<"Enter no: of Columns in Matrix A: ";
		cin>>s2;
		s21=s2;

		if(s1<s2)
			m1=s2;
		else
			m1=s1;
		
		

		//converting Matrix B
		cout<<"\nEnter no: of Rows in Matrix B: ";
		cin>>s3;
		s31=s3;
		
		cout<<"Enter no: of Columns in Matrix B: ";
		cin>>s4;
		s41=s4;

		if(s3<s4)
			m2=s4;
		else
			m2=s3;
		
		if(m1<m2)
			m=m2;
		else 
			m=m1;
		l:
		for(i=1;i<6;i++){
			if(m==pow(2,i))
				goto x;
			if(i==5){
				m++;
				goto l;
			}

		}
		x:
		cout<<"\nThe Array A of size "<<s1<<"x"<<s2<<" is converted to "<<m<<"x"<<m;
		cout<<"\nThe Array B of size "<<s3<<"x"<<s4<<" is converted to "<<m<<"x"<<m;
		if(s2==s3){
			a=new int*[m];
			for(i=0;i<m;i++)
				a[i]=new int[m];
			cout<<"\nEnter the Elements of the Matrix A: ";
			for(i=0;i<s11;i++){
				for(j=0;j<s21;j++)
					cin>>a[i][j];
			}
			
			b=new int*[m];
			for(i=0;i<m;i++)
				b[i]=new int[m];

			c=new int*[m];
			for(i=0;i<m;i++)
				c[i]=new int[m];


			cout<<"\nEnter the Elements of the Matrix B: ";
			for(i=0;i<s31;i++){
				for(j=0;j<s41;j++)
					cin>>b[i][j];
			}
			//intitializing array elements to convert it into power of 2 order
			for(i=s11;i<s1;i++){
				for(j=0;j<s2;j++)
					a[i][j]=0;
			}
			for(i=0;i<s1;i++){
				for(j=s21;j<s2;j++)
					a[i][j]=0;
			}
			for(i=s31;i<s3;i++){
				for(j=0;j<s4;j++)
					b[i][j]=0;
			}
			for(i=0;i<s3;i++){
				for(j=s41;j<s4;j++)
					b[i][j]=0;
			}
			cout<<"\n";
			print(a,s11,s21);
			print(b,s31,s41);
			cout<<"\n\n\n\n";
			if(s1==2){
				Mul(a,b,c);
				cout<<"The Resultant Matrix is:\n";
				print(c,s11,s41);
			}
			else{
				MatMul(a,b,c,m);
				cout<<"The Resultant Matrix is:\n";
				print(c,s11,s41);
			}
			
		}

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

	void print(int **c,int g,int h){
		cout<<"\n";
		for(i=0;i<g;i++){
			for(j=0;j<h;j++)
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
		    for(i=0;i<ns;i++){
			a00[i]=new int[ns];
			a01[i]=new int[ns];
			a10[i]=new int[ns];
			a11[i]=new int[ns];
			b00[i]=new int[ns];
			b01[i]=new int[ns];
			b10[i]=new int[ns];
			b11[i]=new int[ns];
			c00[i]=new int[ns];
			c01[i]=new int[ns];
			c10[i]=new int[ns];
			c11[i]=new int[ns];
		    }



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
            print(p,n/2,n/2);

			addd(a10,a11,t1,n/2);
			MatMul(t1,b00,q,n/2);
			cout<<"Matrix q:";
            print(q,n/2,n/2);

			subb(b01,b11,t1,n/2);
			MatMul(a00,t1,r,n/2);
			cout<<"Matrix r:";
            print(r,n/2,n/2);

			subb(b10,b00,t1,n/2);
			MatMul(a11,t1,s,n/2);
			cout<<"Matrix s:";
			print(s,n/2,n/2);

			addd(a00,a01,t1,n/2);
			MatMul(t1,b11,t,n/2);
			cout<<"Matrix t:";
			print(t,n/2,n/2);

			subb(a10,a00,t1,n/2);
			addd(b00,b01,t2,n/2);
			MatMul(t1,t2,u,n/2);
			cout<<"Matrix u:";
			print(u,n/2,n/2);

			subb(a01,a11,t1,n/2);
			addd(b10,b11,t2,n/2);
			MatMul(t1,t2,v,n/2);
			cout<<"Matrix v:";
			print(v,n/2,n/2);

			addd(s,v,t1,n/2);
			addd(p,t1,t2,n/2);
			subb(t2,t,c00,n/2);
			cout<<"Matrix c00:";
		print(c00,n/2,n/2);

			addd(r,t,c01,n/2);
			cout<<"Matrix c01:";
			print(c01,n/2,n/2);

			addd(q,s,c10,n/2);
			cout<<"Matrix c10:";
			print(c10,n/2,n/2);


			addd(p,r,t1,n/2);
			addd(u,t1,t2,n/2);
			subb(t2,q,c11,n/2);
			cout<<"Matrix c11   :";
            	print(c11,n/2,n/2);

			for(i=0;i<n/2;i++){
				for(j=0;j<n/2;j++){
					c[i][j]=c00[i][j];	
				}
			}
			
			for(i=0;i<n/2;i++){
				for(j=n/2;j<n;j++){
                   			 if(j==n/2){ z=0;}
					 c[i][j]=c01[i][z];
					 z++;
				}

			}
			for(i=n/2;i<n;i++){
				for(j=0;j<n/2;j++){
				    if(i==n/2){ w=0;}
					c[i][j]=c10[w][j];
				}
				w++;
			}
			for(i=n/2;i<n;i++){
				for(j=n/2;j<n;j++){
				        if(i==n/2){ w=0;}
					if(j==n/2){z=0;}
					c[i][j]=c11[w][z];
					z++;
				}
                		w++;
			}

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

