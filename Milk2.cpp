/*
ID: muntean3
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

struct Milking {
    int from;
    int to;
};


int milkcmp(const void *va, const void *vb) {
    Milking *a, *b;

    a = (Milking*)va;
    b = (Milking*)vb;

    if(a->from > b->from)
        return 1;
    if(a->from < b->from)
        return -1;
    return 0;
}
int main() {

	ofstream fout("milk2.out");
	ifstream fin("milk2.in");

	int N;

	fin>>N;

    Milking milking[5000];

	int from, to;
	for(int i = 0; i < N; i++) {
		fin>>from;
		fin>>to;

		milking[i].from = from;
		milking[i].to  = to;
	}

    // sort by from time
    qsort(milking, N, sizeof(Milking), milkcmp);

	int maxT = milking[0].to - milking[0].from;
	int maxI = 0;

	int max = 0;
    Milking cur = milking[0];
	for(int i = 1; i < N; i++) {
        if(milking[i].from > cur.to)
        {
                max = milking[i].from - cur.to;
                if(maxI < max) maxI = max;

                max = cur.to - cur.from;
                if(maxT < max) maxT = max;

                cur = milking[i];
        } else {
            if(milking[i].to > cur.to ) {
                cur.to = milking[i].to;
            }
        }
	}

    // final milking 
    max = cur.to - cur.from;
    if(maxT < max) maxT = max;

	fout << maxT << " " << maxI << endl;
}
