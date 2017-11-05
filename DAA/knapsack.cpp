#include<iostream>
#include<math.h>
using namespace std;
class X{
	public:
	float *w,*x,*p,*uc,*in;

	int i,u,tp,n,m;
	

	void read(){
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
		/*int jj=0;
		for(i=n-1;i>=0;i--){
			in[jj]=i;
			jj++;
		}*/
		knapsack(n,m);
		print();
		sort();
		print();
		knapsack(n,m);
		print();
		sort2();
		print();
	}
	void knapsack(int n,int m){
		
	
	/*	u=m;
		for(i=0;i<n;i++){
			x[i]=0;
		}	
		for(i=0;i<n;i++){
			if(u>=w[i]){
				
				x[i]=1;
				u=u-w[i];
			}
		
		}
	*/
		
	//Fractional Knapsack 
	/*	
		u=m;
		for(i=0;i<n;i++)
			x[i]=0;
			
		for(i=0;i<n;i++){
			if(u<w[i])
				break;
			x[i]=1;
			u=u-w[i];
		}
		IF(i<n)
			x[i]=u/w[i];

		for(i=0;i<n;i++)
			cout<<x[i]<<"\t"<<w[i]<<"\n";
	*/		
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

	void print(){
		tp=0;
		for(i=0;i<n;i++){
			cout<<x[i]<<"\t"<<w[i]<<"\t"<<uc[i]<<"\t"<<in[i]<<"\n";
			tp+=x[i]*p[i];		
		}
		cout<<"Total Profit: "<<tp<<"\n";
	}
	
	void sort(){
		int i,j,r,n;
		n=sizeof(uc)/2;
		
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(uc[i]<uc[j]){
					sss();
				}
			}
		}/*
		float *b,*z,*x,*v;
		b=new float[n];
		z=new float[n];
		x=new float[n];
		v=new float[n];
		j=n-1;
		for(i=0;i<n;i++){		
			b[i]=uc[j];
			z[i]=p[j];
			x[i]=w[j];
			j--;
		}
			
		for(i=0;i<n;i++){		
			uc[i]=b[i];
			p[i]=z[i];
			w[i]=x[i];
		}
		*/

	}
	void sort2(){
        	int i,j,r,n;
        	n=sizeof(in)/2;
	
	        for(i=0;i<n;i++){
	                for(j=i+1;j<n;j++){
        	                if(in[i]>in[j]){
                	                sss();
                        	}
			}
		}
	}	
	
	void sss(){
		r=uc[i];
		uc[i]=uc[j];
		uc[j]=r;

		r = p[i];
		p[i] = p[j];
		p[j] = r;

		r = w[i];
		w[i] = w[j];
		w[j] = r;
	
		r=x[i];
		x[i]=x[j];
		x[j]=r;
		
		r=in[i];
		in[i]=in[j];
		in[j]=r;
	}
	
};
int main(){
	X o;
	o.read();
	
	

	
	
}

