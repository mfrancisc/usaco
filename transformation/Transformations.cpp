/**
ID: muntean3
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N;

void rotate90(vector<vector<char> > arr, vector<vector<char> >& res) {

    for(int i =0; i < N; i++) {
        for(int j =0; j < N; j++) {
            res[j][N - i - 1] = arr[i][j];
        }
    }
}

void reflect (vector<vector<char> >arr, vector<vector<char> >& res) {

    for(int i =0; i < N; i++) {
        for(int j =0; j < N; j++) {
            res[i][j] = arr[i][N - j - 1];
        }
    }
}

bool areEqual(vector<vector<char> >arr, vector<vector<char> >trs) {

    for(int a = 0; a < N; a++) {
        for(int b = 0; b < N; b++) {
            if(arr[a][b] != trs[a][b]) return false; 
        }
    }

    return true;
}

int main() {


    ofstream fout ("transform.out");
    ifstream fin ("transform.in");

    fin>>N;
    vector<vector<char> > arr;
    arr.resize(N);

    vector<vector<char> > res;
    res.resize(N);

    vector<vector<char> > trs;
    trs.resize(N);

    char x;
    for(int a=0; a < N; a++) {
        arr[a].resize(N);
        trs[a].resize(N);
        res[a].resize(N);
        for(int b=0; b < N; b++) {
            fin>>x;
            arr[a][b] = x;
        }
    }

    char y;
    for(int a=0; a < N; a++) {
        for(int b=0; b < N; b++) {
            fin>>x;
            trs[a][b] = x;
        }
    }

    // verify 90° degrees
    rotate90(arr, res);
    bool same = areEqual(res, trs);
    if(same) {fout << "1" << endl; return 0;}

    // verify 180° degrees
    rotate90(res, res);
    same = areEqual(res, trs);
    if(same) {fout << "2" << endl; return 0;}

    // verify 270° degrees
    rotate90(res, res);
    same = areEqual(res, trs);
    if(same) {fout << "3" << endl; return 0;}

    // verify reflection 
    reflect(arr, res);
    same = areEqual(res, trs);
    if(same) {fout << "4" << endl; return 0;}

    // verify combination after reflection
    rotate90(res, res);
    same = areEqual(res, trs);
    if(same) {fout << "5" << endl; return 0;}

    rotate90(res, res);
    same = areEqual(res, trs);
    if(same) {fout << "5" << endl; return 0;}

    rotate90(res, res);
    same = areEqual(res, trs);
    if(same) {fout << "5" << endl; return 0;}

    // no changes
    same = areEqual(arr, trs);
    if(same) {fout << "6" << endl; return 0;}

    // invalid transformation
    fout << "7" << endl; return 0;
}
