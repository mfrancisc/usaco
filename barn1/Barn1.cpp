/*
ID: muntean3
PROG: barn1
LANG: C++
*/
#include<iostream>
#include<fstream>
#include <algorithm>

using namespace std;

int main() {

   ifstream fin("barn1.in");
   ofstream fout("barn1.out");

   int max_boards_purchased;
   int tot_stalls;
   int cows_in_stalls;
   int stall_num;

   // initialize stalls with 0

   fin>>max_boards_purchased;
   fin>>tot_stalls;
   fin>>cows_in_stalls;
   int stallList[cows_in_stalls];

   // list of occupied stalls
   for(int i = 0; i < cows_in_stalls; i++) {
        fin>>stall_num; 
        stallList[i] = stall_num;
   }

   sort(stallList, stallList+cows_in_stalls);

   int min_boards=0;
   for(int a = 1; a < cows_in_stalls; a++){
       cout << stallList[a] << endl;
       cout <<  stallList[a-1] << endl;
       cout << " *** " << endl;
        min_boards += stallList[a] - stallList[a-1]; 
   }

   fout << min_boards << endl;






}
