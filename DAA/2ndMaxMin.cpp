#include<iostream>
using namespace std;

class X{
	int a[5],i,n;
	public :void read(int s){
		n=s;
		cout<<"Enter the Elements";
		for(i=0;i<n;i++)
			cin>>a[i];
		sort();
		cout<<"2nd Min Element is: "<<a[1]<<"\n2nd Max Element is: "<<a[s-2];
	}	
	
	public:void sort(){
		int i,j,r;
		
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(a[i]>a[j]){
					r=a[i];
					a[i]=a[j];
					a[j]=r;
				}
			}
		}
		
		
	}
};
int main(){
	X o;
	int a;
	cout<<"Enter the Size of the Array:";
	cin>>a;
	o.read(a);
	
}
