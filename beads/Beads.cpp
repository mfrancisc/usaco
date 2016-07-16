/*
ID: muntean3
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main () {

    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

    int N;

    fin>>N;
    char necklace[N];
    fin>>necklace;

    int max = 0;

    for(int a = 0; a < N; a++) {

        char color = 'w';
        int cur = 0;
        bool switched = false;
        for(int i = 0; i < N; i++) {
            char cur_c = necklace[(i + a) % N];

            if(cur_c != 'w'){
                if(color == 'w'){
                    // first non white
                    color = cur_c;
                }else
                    if(cur_c != color) {
                        if(switched) {break;}
                        else {
                            color = cur_c;
                            switched = true; 
                        }
                    }
            }
            cur++;
        }

        if( max < cur) max = cur; 

        }
        fout << max << endl;

        return 0;
    }

