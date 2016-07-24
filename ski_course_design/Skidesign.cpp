/**
ID: muntean3
PROG: skidesign
LANG: C++11
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<math.h>

using namespace std;

int N;
int main(void){

    ifstream fin("skidesign.in");
    fin>>N;
    int hillsHeight[N];

    int h;
    for(int i = 0; i < N; i++) {
        fin>> h;
        hillsHeight[i] = h;
    }

    // sort heigths
    sort(hillsHeight, hillsHeight+N);

    int newMaxDiff = hillsHeight[N-1] - hillsHeight[0];
    int cost = 0;
    int costMax;
    int costMin;
    while(17 < newMaxDiff){
        costMax = 0;
        costMin = 0;
        int minHill = hillsHeight[0];
        int hMin = 0;
        int hMax = 0;
        int maxHill = hillsHeight[N-1];
        int maxDiff = newMaxDiff;

        while(17 < maxDiff ){

            // add to min hill
            minHill++;
            hMin++;
            costMin = pow(hMin, 2);

            // test if we have required max limit
            maxDiff = maxHill - minHill;
            if(maxDiff <= 17) break;

            // subract from max hill
            maxHill--;
            hMax++;
            costMax = pow(hMax, 2);
            maxDiff = maxHill - minHill;
        }

        cost += costMin + costMax;
        hillsHeight[0] = minHill;
        hillsHeight[N-1] = maxHill;
        sort(hillsHeight, hillsHeight+N);
        newMaxDiff = hillsHeight[N-1] - hillsHeight[0];
    }

    // calc total cost
    ofstream fout("skidesign.out");
    fout << cost << endl;
    fout.close();

    return 0;
}
