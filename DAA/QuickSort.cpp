#include<iostream>
#include<math.h>
using namespace std;
class X{
   
    public:
	int i,j,h,k,t;
	int *a;
	X(int s){
		h=s;
		a=new int[s];
	}
	void readnprint(int s){
		for(i=0;i<s;i++)
			cin>>a[i];
	
		QSort(0,s-1);
		
		for(i=0;i<s;i++)
			cout<<a[i]<<"\t";
	}
	void QSort(int low,int high){
		int j;		
		if(low<high){
			j=Partition(low,high+1);
			QSort(low,j-1);
			QSort(j+1,high);
			
		}
	}
	int Partition(int m,int p){
		for(i=0;i<h;i++)
			cout<<a[i]<<"\t";
			cout<<"\n";		
		int v=a[m];
		int i, j;
		i=m;j=p;
		do{
			do{
				i++;
			}while(a[i]<v);
			do{
				j--;
			}while(a[j]>v);
			if(i<j)
				swapp(i,j);
		}while(i<j);
		a[m]=a[j];
		a[j]=v;
		
		return j;
	
	}
	void swapp(int i,int j){
		int t;
		t=a[i];
		a[i]=a[j];
		a[j]=t;
	}
	
	
	
};
int main(){
	
	int x,k;
	cout<<"Enter the Size of the Array: ";
	cin>>x;
	X o(x);
	cout<<"Enter the Elements of the Array: ";
	o.readnprint(x);

	
	
}

