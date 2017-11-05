#include<iostream>
using namespace std;
class X{

	int i;
	public:void fibonacci(int n){
		int f[100];
		int i;
		f[0]=0;
		f[1]=1;	
		for(i=2;i<n;i++)
			f[i]=f[i-1]+f[i-2];
		for(i=0;i<n;i++)
			cout<<f[i]<<" ";
		cout<<"\n";
	}
	
	public: int fib(int n){
				
		if(n==0)return 0;
		if(n==1)return 1;
		
		else{
			return fib(n-1)+fib(n-2);
		}	
	}
		
};
int main(){
	X o;
	int i,g;
	cout<<"Enter the index of the Fibonacci series u want to print:\t";
	cin>>i;	
	o.fibonacci(i);
	for(g=0;g<i;g++)
		cout<<o.fib(g)<<" ";
}
