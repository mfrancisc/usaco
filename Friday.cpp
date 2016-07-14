/*
ID: muntean3
PROG: friday
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

bool leap(int y){
    return (y % 100 == 0 && y % 400 == 0 || y % 100 != 0 && y % 4 == 0);
}

int main() {

    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

    int N;

    fin>>N;


    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days[7] = {0, 0, 0, 0, 0, 0, 0}; 

    // 1 jan 1900 is monday
    int day = 2;

    // years loop
    for(int y = 1900; y < 1900 + N; y++) {

        // months lopp
        for(int m = 0; m < 12; m++) {

            int daysInMonth =months[m];
            if(m == 1 && leap(y)) daysInMonth++;

            for(int d = 1; d <= daysInMonth; d++){
                if(d == 13) {days[day]++;}
                day = (day + 1) % 7;
            }
        }
    }

    for(int i = 0; i < 7; i++){
        fout << (i ? " " : "") << days[i];
    }
    fout << endl;

    return 0;
}
