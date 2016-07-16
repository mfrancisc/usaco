/*
ID: muntean3
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {

	ofstream fout ("ride.out");
	ifstream fin ("ride.in");

	char comet[8];
	char group[8];

	fin >> comet >> group;

	int clen = strlen(comet);
	int totc = tolower(comet[0]) - 96;
	for(int i = 1; i < clen; i++) {
		char ca = tolower(comet[i]);
		int c = ca - 96;
		totc *= c;
	}

	int glen = strlen(group);
	int totg = tolower(group[0]) - 96;
	for(int i = 1; i < glen; i++) {
		char ga = tolower(group[i]);
		int g = ga - 96;
		totg *= g;
	}



	int rc = totc % 47;
	int rg = totg % 47;


	if(rc == rg) {
		fout << "GO" << endl;
	} else {
		fout << "STAY" << endl;
	}

	return 0;
}
