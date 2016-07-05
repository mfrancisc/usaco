/*
ID: muntean3
PROG: friday
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

    int N;

    fin>>N;

    int startYear = 1900;
    int lastYear = startYear + N - 1;

    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int days[7] = {0, 0, 0, 0, 0, 0, 0}; // from saturday to friday

    // 1 jan 1900 is monday
    int d = 0;

    // years loop
    for(int y = startYear; y <= lastYear; y++) {
        // leap year febrary 29
        if(y % 4 == 0 && y % 100 != 0) {months[1] = 29; } 
        else if( y % 100 == 0 && y % 400 == 0) {months[1] = 29;} 

        // months lopp
        for(int m = 0; m < 12; m++) {
            // month days lopp


        }

        fout << days[5] << " " << days[6] << " " << days[0] << " " << days[1] << " " << days[2] << " " << days[3] << " " << days[4] << " "; 
    }

    return 0;
}
