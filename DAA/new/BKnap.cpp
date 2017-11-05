#include<iostream>
using namespace std;

class X{
	public:
	int *x,*y,*p,*w,cp,cw,fp,fw,n,m;
	void read(){
		cout<<"Enter no: items: ";
		cin>>n;
		x=new int[n];
		y=new int[n];
		p=new int[n];
		w=new int[n];
		cout<<"Enter the capacity of Knapsack: ";
		cin>>m;
		cout<<"Enter the profits of items:";
		for(int i=1;i<=n;i++)
			cin>>p[i];

		cout<<"Enter the weights of items:";
		for(int i=1;i<=n;i++)
			cin>>w[i];

		cp=cw=fp=fw=0;
	
		BKnap(1,0,0);

		for(int i=1;i<=n;i++)
			cout<<x[i]<<"\t";
		
	}

	void BKnap(int k,int cp,int cw){
		if(cw+w[k]<=m){
			y[k]=1;
			if(k<n)
				BKnap(k+1,cp+p[k],cw+w[k]);
			if((cp+p[k]>fp) && k==n){
				fp=cp+p[k];
				fw=cw+w[k];
				for(int j=1;j<=k;j++)
					x[j]=y[j];
			}
		}
		
		if(Bound(cp,cw,k)>fp){
			y[k]=0;
			if(k<n)
				BKnap(k+1,cp,cw);
			if(cp>fp && k==n){
				fp=cp;
				fw=cw;
				for(int j=1;j<=k;j++)
					x[j]=y[j];
			}
		}
	}


	int Bound(int cp,int cw,int k){
		int b=cp,c=cw;
		for(int i=k+1;i<=n;i++){
			c+=w[i];
			if(c<m)
				b+=p[i];
			else
				return b+(1-(c-m)/w[i])*p[i];
		}
		return b;
	}

};
int main(){
	X o;
	o.read();
}
