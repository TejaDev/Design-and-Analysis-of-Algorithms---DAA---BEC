#include<iostream>
using namespace std;
class X{
	
	public: void MagicSquare(int n){
		int i,j,q,w,z,x,num;
		int s[99][99];		
		if(n%2!=0){
			for(i=0;i<n;i++){
				for(j=0;j<n;j++)
					s[i][j]=0;
			}
			
			s[0][(n-1)/2]=1;
			i=0;
			j=(n-1)/2;
			for(num=2;num<=(n*n);num++){
					
				if(i==0)
					q=n-1;
				else
					q=i-1;
				if(j==0)
					w=n-1;
				else
					w=j-1;
				if(s[q][w]>=1){
					i=(i+1)%n;
				}
				else
				{	
					i=q;
					j=w;	
				}
				s[i][j]=num;
				
			}
		}

		for(i=0;i<n;i++){
			cout<<"|";
			for(j=0;j<n;j++){
				cout<<s[i][j]<<"\t|";
				
			}cout<<"\n";
			for(j=0;j<n;j++)
				cout<<"-------";
			cout<<"\n";
		}
	}
};
int main(){
	X o;
	int p;
	cout<<"Enter the dimension of the square: ";
	cin>>p;
	o.MagicSquare(p);
	
}	
			
