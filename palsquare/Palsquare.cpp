/**
ID: muntean3
PROG: palsquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <list>

using namespace std;


list<int> convert(int sqN,int  b){

    int R = sqN / b;
    int rest = sqN % b;
    list <int> number;
    
    char rs;
    number.push_front(rest);
    int tm = R;
    while(R) {
        tm /= b;
        rest = R % b;
        R = tm;
        number.push_front(rest);
    }

return number;
}

bool isPal(list<int> number) {

    int nSize = number.size();
    int mid = nSize/2;

    for(int i = 0; i < mid; i++) {
        if(number.front() != number.back()) {
            return false; 
        } 
        number.pop_front();
        number.pop_back();
    }

    return true;

}
int main() {
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");
    int b;
    fin >> b;

    int N;
    int sqN;

    for(N = 1; N <= 300; N++){
        sqN = pow(N, 2); 

        list<int> number;
        list<int> nConverte;

        // loop through digits int 
        number = convert(sqN, b);
        nConverte = convert(N, b);

        int i;
        char iC;
        if(isPal(number)) {
            while(!nConverte.empty()){
                i = nConverte.front();
                // base > 10
                if(i > 9){
                    i += 55; 
                    iC = i;
                    fout << iC;
                } else {
                    fout << nConverte.front();
                }
                nConverte.erase(nConverte.begin());
            }

            fout << " ";
            while(!number.empty()){
                i = number.front();
                // base > 10
                if(i > 9){
                    i += 55; 
                    iC = i;
                    fout << iC;
                } else {
                    fout << number.front();
                }
                number.erase(number.begin());
            }
            fout << endl;
        }
    }

}
