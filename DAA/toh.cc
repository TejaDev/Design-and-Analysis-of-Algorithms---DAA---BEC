#include<iostream>
using namespace std;

class X{
	
	public:int toh(int n,char x, char y,char z){
		int p;	
		if(n==0)
			return 0;
		p=n;	
		toh(n-1,x,z,y);
		cout<<"Move disk "<<p<<" from tower "<<x<<" to tower "<<y<<"\n";
		toh(n-1,z,y,x);	
	}
};
int main(){
	X o;
	int nod;
	cout<<"Enter no: of Disks";
	cin>>nod;
	o.toh(nod,'A','B','C');
}

