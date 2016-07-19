/*
ID: muntean3
PROG: barn1
LANG: C++
*/
#include<iostream>
#include<fstream>
#include <algorithm>
#include <vector>

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

   vector<int>gaps;
   // calc gaps
   for(int i = 1; i < cows_in_stalls; i++){

	   if(stallList[i] - stallList[i-1] > 1) {
		   gaps.push_back(stallList[i] - stallList[i-1] - 1);
	   }

   }


   // sort gaps
   sort(gaps.begin(), gaps.end() );


   int boards = gaps.size() + 1;
   int min_boards=cows_in_stalls;
   while(boards > max_boards_purchased){
	int b = gaps.front();
	gaps.erase(gaps.begin());
	min_boards += b;
	boards--;
   }

   fout << min_boards << endl;






}
