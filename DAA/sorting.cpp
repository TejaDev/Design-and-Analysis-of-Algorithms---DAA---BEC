#include<iostream>
using namespace std;

class X{
	int a[5],n,i;
	public :void read(int s){
		n=s;
		cout<<"Enter the Elements";
		for(i=0;i<n;i++)
			cin>>a[i];
	}	
	public: void display(){
		cout<<"Sorted array is: \n";		
		for(i=0;i<n;i++){
			cout<<a[i];
			cout<<" ";
		}
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
	o.read(5);
	o.sort();
	o.display();
}
