/*
ID: muntean3
PROG: milk
LANG: C++
*/
#include<iostream>
#include<fstream>
#include <algorithm>

using namespace std;

struct farmer {
    int price;
    int milkAmount;
};

bool priceCompare(farmer lhs, farmer rhs) { return lhs.price < rhs.price; }

int main() {
    ifstream fin("milk.in");
    ofstream fout("milk.out");
    int N,M,P,A;

    fin>>N;
    fin>>M;

    farmer * pointer = new farmer[M];

    // fill farmers data
    for(int i = 0; i < M; i++){
        fin>>P;
        pointer[i].price = P;
        fin>>A;
        pointer[i].milkAmount = A;
    }

    // sort by lowest price
    sort(pointer, pointer+M, priceCompare);

    int totMilk = 0;
    int minimumCost = 0;
    int i = 0;
    while(totMilk < N){
        int tempAmount = totMilk + pointer[i].milkAmount; 
        if(tempAmount > N) {
            int t = N - totMilk;
            tempAmount = totMilk + t;
            int cost = pointer[i].price * t;
            minimumCost += cost;
        } else {
            int cost = pointer[i].price * pointer[i].milkAmount;
            minimumCost += cost;
        }
        totMilk = tempAmount;
        i++;
    }

    fout << minimumCost << endl;

    return 0;
}
