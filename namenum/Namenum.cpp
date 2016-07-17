/*
ID: muntean3
PROG: namenum
LANG: C++
*/

#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

char name[] = "";
string brand;
int bsize;
char tt[8][3] = { 
    {'A', 'B', 'C'}, 
    {'D', 'E', 'F'},
    {'G', 'H', 'I'},
    {'J', 'K', 'L'},
    {'M', 'N', 'O'},
    {'P', 'R', 'S'},
    {'T', 'U', 'V'},
    {'W', 'X', 'Y'} 
};

ofstream fout ("namenum.out");
ifstream fin ("namenum.in");

int nf = 0;

void translate (int a, int b);
void alternatives (int a, int b, int c);

void searchName(){

    ifstream fdin ("dict.txt");
    string nameStr(name);

    // search name
    string dict_name;
    while(!fdin.eof()){
        fdin >> dict_name; 

        if(nameStr == dict_name) {
            fout << name << endl;
            nf++;
        }
    }

}

void alternatives(int brandNum,int n, int numAlt) {


    if( numAlt >= 3) {return;}

        name[brandNum] = tt[n][numAlt];
        translate(brandNum+1, 0);
        alternatives(brandNum, n, numAlt+1);

}
void translate(int brandNum,int numAlt){

    if( brandNum < bsize) {
        int n = brand[brandNum] - '0';
        n -= 2;
        alternatives(brandNum, n, numAlt);

    } else {
        // search for name
        searchName();
    }
}

int main() {

    fin>>brand;
    bsize = brand.size();
    translate(0, 0);

    // no names found
    if(!nf) fout << "NONE" << endl;
}
