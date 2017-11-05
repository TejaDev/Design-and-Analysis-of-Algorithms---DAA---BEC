#include<iostream>
#include<math.h>
using namespace std;
class X{
	public:
		int a[100];
		int i,j,min,max;
		
		void MaxMin(int i,int j){
			int max1,min1,mid;
		if(i<=j){
			if(i==j) min=max=a[i];

			else if(i==j-1){
				if(a[i]>a[j]){
					max=a[i];
					min=a[j];
				}
				else{
					max=a[j];
					min=a[i];
				}
			}
			else{
				mid=floor((i+j)/2);
				MaxMin(i,mid);
				min1=min;
				max1=max;
				MaxMin(mid+1,j);
	
				if(min>min1)
					min=min1;
				if(max<max1)
					max=max1;
			}
		}
		
	}
	
	public:void readnprint(int s){
		int i;		
		for(i=0;i<s;i++)
			cin>>a[i];
		MaxMin(0,s-1);

		cout<<"Min. value: "<<min<<"\nMax. Value: "<<max;
	}
	
};
int main(){
	X o;
	int x,k;
	cout<<"Enter the Size of the Array: ";
	cin>>x;
	
	cout<<"Enter the Elements of the Array: ";
	o.readnprint(x);

	
	
}

