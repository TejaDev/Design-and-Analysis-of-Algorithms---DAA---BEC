#include<iostream>
#include<math.h>
using namespace std;
class Knapsack{
	float *w,*x,*p,*uc,*in;
	int i,u,tp,n,m;
	public:
	void read();
	void knapsack(int n,int m);
	void print();
	void sort();
	void xchange(float*,int,int);
};
void Knapsack::read(){
		cout<<"\nEnter the No of the Items: ";
		cin>>n;
		cout<<"Enter the Capacity of the Knapsack: ";
		cin>>m;
		w=new float[m];
		x=new float[n];
		p=new float[n];
		uc=new float[n];
		in=new float[n];
		cout<<"Enter the weights of Items:";
		for(i=0;i<n;i++)
			cin>>w[i];
		cout<<"Enter the profits of Items:";
		for(i=0;i<n;i++)
			cin>>p[i]; 
		
		for(i=0;i<n;i++){
			x[i]=0;
			uc[i]=p[i]/w[i];
			in[i]=i;
		}
		sort();
		knapsack(n,m);
		print();
}
void Knapsack::knapsack(int n,int m){
		u=m;
		cout<<"\n";
		for(i=0;i<n;i++){
			if(u<w[i])
				break;
			x[i]=1;
			u=u-w[i];
		}
		if(i<n)
			x[i]=u/w[i];
}
void Knapsack::print(){
		tp=0;
		cout<<"\nGiven weights are:";
		for(i=0;i<n;i++)
			for(int j=0;j<n;j++)
			if(in[j]==i)
			cout<<w[j]<<"\t";
		cout<<"\nGiven profits are:";
		for(i=0;i<n;i++)
			for(int j=0;j<n;j++)
			if(in[j]==i)
			cout<<p[j]<<"\t";
		cout<<"\nFraction of items taken into knapsack:";
		for(i=0;i<n;i++)
			for(int j=0;j<n;j++)
			if(in[j]==i)
			cout<<x[j]<<"\t";
		cout<<"\nunit cost of items :";
		for(i=0;i<n;i++)
			for(int j=0;j<n;j++)
			if(in[j]==i)
			cout<<uc[j]<<"\t";
		for(i=0;i<n;i++){
			tp+=x[i]*p[i];		
		}
		cout<<"\nTotal Profit: "<<tp<<"\n";
}
void Knapsack::sort(){
	int i,j,r;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(uc[i]<uc[j]){
				xchange(uc,i,j);
				xchange(p,i,j);
				xchange(w,i,j);
				xchange(x,i,j);
				xchange(in,i,j);				
			}
		}
	}
}
void Knapsack::xchange(float* a,int i,int j){
	float t;
	t=a[i];
	a[i]=a[j];
	a[j]=t;
}
int main(){
	Knapsack o;
	o.read();
}

