/*
ID: muntean3
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
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
    ifstream fin ("dualpal.in");
    ofstream fout ("dualpal.out");

    int N;
    int S;
    fin>>N;
    fin>>S;

   int n = 0;
   int baseP;
   int baseC;

   int bases[] = {2,3,4,5,6,7,8,9,10};
   int baseSize = 9;

    int num = S+1;
  while(n < N) {
    baseP =0; 
    baseC =0; 
    while(baseP < 2 && baseC < baseSize){
        
       list <int> number= convert(num, bases[baseC]); 
       if(isPal(number)) {baseP++;}
       baseC++;

    }
    // add palindrome number
    if(baseP >= 2) {
        n++;
        fout << num << endl;
    }
        num++;
  } 


    return 0;
}
