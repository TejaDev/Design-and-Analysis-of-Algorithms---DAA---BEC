#include<iostream>
using namespace std;

class kruskalsAlg
{
	int cost[20][20], mc, t[20][3], near[20],ne,q[20][3];

	public:
		void read(int);
		int kruskals(int);

};	
