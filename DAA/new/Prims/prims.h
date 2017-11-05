#include<iostream>
using namespace std;

class PrimsAlg
{
	int cost[20][20], mc, t[20][3], near[20],ne;

	public:
		void read(int);
		int prims(int);

};
