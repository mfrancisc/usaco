/*
ID: muntean3
PROG: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {

	ofstream fout ("milk2.out");
	ifstream fin ("milk2.in");

	int N;

	fin>>N;

	int arr[500][2];

	int from, to;
	for(int i = 0; i < N; i++) {
		fin>>from;
		fin>>to;

		arr[i][0] = from;
		arr[i][1] = to;
	}

	int maxT = arr[0][1] - arr[0][0];
	int maxI = 0;

	int max = 0;
	for(int i = 1; i < N; i++) {
		int max = arr[i][1] - arr[i][0];
		if(maxT < max) maxT = max;

		if((arr[i-1][0] <= arr[i][0]) && (arr[i][0] <= arr[i-1][1])) {
			max = arr[i][1] - arr[i-1][0];
			if(maxT < max) {maxT = max;}
		} else {
			max = arr[i][0] - arr[i-1][1];
			if(maxI < max) {maxI = max;}
		}
	}

	fout << maxT << " " << maxI << endl;
}
