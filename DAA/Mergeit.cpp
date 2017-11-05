#include "Merge.h"


int i,j,h,k,t;
int *a,b[100];


void X::readnprint(int s){
	a=new int[s];
	for(i=0;i<s;i++)
		cin>>a[i];
	if(s>16)
		MSort(0,s-1);
	else
		InsertionSort(s);
	for(i=0;i<s;i++)
		cout<<a[i]<<"\t";
}
void X::MSort(int low,int high){
	int mid;		
	if(low<high){
		mid=floor((low+high)/2);
		MSort(low,mid);
		MSort(mid+1,high);
		Merge(low,mid,high);
	}
}
void X::Merge(int low,int mid,int high){
			
	i=low;
	h=low;
	j=mid+1;
	while(h<=mid && j<=high){
		if(a[h]<a[j]){
			b[i]=a[h];
			h++;
		}
		else{
			b[i]=a[j];
			j++;
		}
		i++;
	}
	if(h>mid){
		for(k=j;k<=high;k++){
			b[i]=a[k];
			i++;
		}
	}
	else{
		for(k=h;k<=mid;k++){
			b[i]=a[k];
			i++;
		}
	}
	for(k=low;k<=high;k++)
		a[k]=b[k];
}
void X::InsertionSort(int s){
	for(j=1;j<s;j++){
		i=j-1;
		t=a[j];
		while(i>=0 && t<a[i]){
			a[i+1]=a[i];
			i--;
		}
		i++;
		a[i]=t;
	}
	
	
}
