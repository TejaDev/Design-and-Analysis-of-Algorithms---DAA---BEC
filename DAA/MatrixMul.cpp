#include<iostream>
#include<math.h>
using namespace std;
class X{
   
    public:
	int i,j,k,sz;
	int a[10][10],b[10][10],c[10][10];
	void readnprint(int s){
		sz=s;
		cout<<"Enter the Elements of the Array A: ";
		for(i=0;i<s;i++){
			for(j=0;j<s;j++)
				cin>>a[i][j];
		}
		cout<<"Enter the Elements of the Array B: ";
		for(i=0;i<s;i++){
			for(j=0;j<s;j++)
				cin>>b[i][j];
		}
		StandardMul(s);
		for(i=0;i<s;i++){
			for(j=0;j<s;j++)
				cout<<c[i][j]<<"\t";
			cout<<"\n";
		}
			
	}
	void StandardMul(int s){
		for(i=0;i<s;i++){
			for(j=0;j<s;j++){
				c[i][j]=0;
				for(k=0;k<s;k++)
					c[i][j]=c[i][j]+ a[i][k]*b[k][j];
			}
		}
		
	}
	
	
	
	
	
};
int main(){
	X o;
	int x,k;
	cout<<"Enter the Size of the Array: ";
	cin>>x;
	o.readnprint(x);

	
	
}

