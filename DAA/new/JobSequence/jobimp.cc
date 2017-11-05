#include"job.h"
void job::read(){
	cout<<"Enter number of jobs:";
	cin>>n;
	p = new int[n+1];
	j = new int[n+1];
	d = new int[n+1];
	cout<<"Enter profits for jobs:";
	for(int i = 1; i<= n; i++){
		cin>>p[i];
	}
	cout<<"Enter dead lines for jobs:";
	for(int i = 1;i<= n;i++){
		cin>>d[i];
	}
}
void job::sort(){
	ord = new int(n+1);
	for(int i = 1; i <= n; i++)
		ord[i] = i;
	for(int i = 1;i<= n;i++)
		for(int k = i+1;k<= n;k++)
			if(p[k]>p[i]){
				int tmp;
				tmp = p[i];
				p[i] = p[k];
				p[k] = tmp;

				tmp = d[i];
				d[i] = d[k];
				d[k] = tmp;

				tmp =  ord[i];
				ord[i] = ord[k];
				ord[k] = tmp;
			}
}		
int job::js(){	
	d[0] = j[0] = 0;
	j[1] = 1;
	int k = 1;
	for(int i = 2;i<= n;i++){
		int r = k;
		while((d[j[r]]>d[i])&&(d[j[r]]!= r))
			r = r-1;
		if((d[j[r]]<= d[i]) && (d[i]>r))
		{
			for(int q = k; q>= r+1; q--)
				j[q+1] = j[q];
			j[r+1] = i;
			k = k+1;
		}
	}
	return k;
}
void job::print(int k){
	int t = 0;
	cout << "JOB\t" << "PROFIT\t" << "DEADLINE\n";
	for(int i = 1;i<= k;i++){
		
		cout << ord[j[i]] << "\t" << p[j[i]] << "\t" << d[j[i]] << "\n";
		t = t + p[j[i]];	
	}
	cout<<"total profit = "<<t<<"\n";
}	
