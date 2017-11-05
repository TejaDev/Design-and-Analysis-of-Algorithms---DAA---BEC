#include<iostream>
#include<math.h>
using namespace std;
class X{
	public:int a[100];
	public:int x;	
	int mid;
	
	public: int BSearch(int low,int high){
		
		if(low==high){
			if(x==a[low]) return low;
			else	return -1;
		}
		else{
			mid=floor((low+high)/2);
			if(x==a[mid])	return mid;
			else if (x>a[mid])	return BSearch(mid+1,high);
			else	return BSearch(low,mid-1);
		}
		
	}
	
	public:void readArray(int s){
		int i;		
		for(i=0;i<s;i++)
			cin>>a[i];
	}
	public:void readKey(int l){
		x=l;
	}
};
int main(){
	X o;
	int x,k;
	cout<<"Enter the Size of the Array: ";
	cin>>x;
	
	cout<<"Enter the Elements of the Array: ";
	o.readArray(x);

	cout<<"Enter the Element to Search: ";
	cin>>k;
	o.readKey(k);
	

	k=o.BSearch(0,x-1);	
	if(k==-1)
		cout<<"Element not Found";
	else{
		cout<<"The Element found at index: ";
		cout<<k;
	}
}
