#include<iostream>
using namespace std;

class X{
	public:
	void asd(){
		int g,a,b,r;
		char d;
		char *c1,*c2,*c;
		cout<<"Enter no: of characters:";
		cin>>g;
		c1=new char[g];
		c2=new char[g];
		c2=new char[g];	
		cout<<"\nString1";
		cin>>c1;
		
		//cout<<c1;
		cout<<"\nString2";		
		cin>>c2;
		
		if(sizeof(c1)==sizeof(c2)){
			for(int x=0;x<g;x++){
				a=(int)c1[x];
				//cout<<a<<"\n";
				int b=(int)c2[x];
				//cout<<b<<"\n";
				a-=96;
				b-=96;
				int r=(a+b)%26;
				//cout<<r;
				r+=96;
				char d=(char)r;
				cout<<d;
				c[x]=d;
				
			}		
			for(int q=g-1;q>=0;q--)
				cout<<c[q];		
		}
		else
			cout<<"Please enter the strings with exactly "<<g<<"Characters"; 
	}
};
int main(){
	X o;
	o.asd();
}
