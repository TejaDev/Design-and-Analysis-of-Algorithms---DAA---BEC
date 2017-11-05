#include<iostream>
#include<math.h>
using namespace std;
class X{
	public:int a[100];
	public:int x;	
	int mid,low,high;
	
	
	public: int BSearch(int s){
		low=0;
		high=s-1;
		while(low<=high){
			mid=floor((low+high)/2);
			if(x==a[mid])	return mid;
			else if(x>a[mid])	low=mid+1;
			else	high=mid-1;
		}
		return -1;
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
	

	k=o.BSearch(x);	
	if(k==-1)
	cout<<"Element not Found";
	else{
	cout<<"The Element found at index: ";
	cout<<k;
	}
}
