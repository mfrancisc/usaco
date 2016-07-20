/*
ID: muntean3
PROG: combo
LANG: C++11
*/

#include <iostream>
#include <fstream>

using namespace std;

int N,a,b,c,d,e,f;
int cnt;

bool check(int a, int b){
    if(abs(a - b) <= 2) return true;
    if(abs(a - b) >= N - 2) return true;

    return false;
}
bool check_combo(int a1, int b1, int c1){

    return (check(a1, a) && check(b1, b) && check(c1, c)) || (check(a1, d) && check(b1, e) && check(c1, f));
}

int main() {

	ifstream fin("combo.in");
	ofstream fout("combo.out");


	fin>>N;
    fin>>a>>b>>c>>d>>e>>f;

    for(int a1 = 1; a1 <= N; a1++){
        for(int b1 = 1; b1 <= N; b1++){
            for(int c1 = 1; c1 <= N; c1++){
                if(check_combo(a1, b1, c1)) cnt++;
            }
        }
    }

	fout << cnt << endl;

}
