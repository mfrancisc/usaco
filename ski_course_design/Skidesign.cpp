/*
ID: muntean3
PROG: skidesign
LANG: C++11
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
	int N;
	ifstream fin("skidesign.in");
	fin>>N;

	int hills[N];
	for(int i = 0; i < N; i++)
		fin>>hills[i];
	fin.close();
		
	int cost;
	int mincost = 999999999;	
	for(int i = 0; i < 83; i++){

		cost = 0;
		int p;
		for(int  j = 0; j < N; j++){
			p = 0;
			int a = i + 17;
			if(hills[j] < i) {
				p = (i - hills[j]) * (i - hills[j]);	
			} else if( a < hills[j] ) {
				p = (hills[j] - a) * (hills[j] - a);

			}
		cost += p;

		}

		mincost = min(cost,mincost);
	}

	ofstream fout("skidesign.out");
	fout << mincost << endl;
	fout.close();

	return 0;
}
