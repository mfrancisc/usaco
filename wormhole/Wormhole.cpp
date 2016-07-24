/*
 ID: muntean3
 PROG: wormhole
 LANG: C++11
 */

#include<iostream>
#include<fstream>

using namespace std;


int N;
int X[13];
int Y[13];
int next_to_right[13];
int partner[13];

bool cycle_exists(){
    
    for(int start = 1; start <= N; start++){
        int pos = start;
        for(int j = 1; j <= N; j++){
            pos = next_to_right[partner[pos]];
        }
        if(pos !=  0) return true;
    }
    
    return false;
}

int solve(){
    int total = 0, i;
    
    for(i = 1; i <= N; i++)
        if(partner[i] == 0) // unpaired
            break;
    
    // if everyone paired
    if ( i > N){
        if(cycle_exists()) return 1;
        else return 0;
    }
    
    // find next unpaired
    for(int j = i+1; j <= N; j++) {
        if(partner[j] == 0) {// unpaired
            partner[j] = i;
            partner[i] = j;
            total += solve();
            partner[i] = partner[j] = 0;
        }
    }
    
    return total;
}

int main() {
    ifstream fin("wormhole.in");
    fin>>N;
    //cin>>N;
    
    int x, y;
    for(int i = 1; i <= N; i++) {
        fin>>x>>y;
        //cin>>x>>y;
        X[i] = x;
        Y[i] = y;
    }
    fin.close();
    
    // set next to right
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            // if is next on x but same y
            if(X[j] > X[i] && Y[j] == Y[i])
                if(next_to_right[i] == 0 ||
                   X[j] - X[i] < X[next_to_right[i]] - X[i]){
                    next_to_right[i] = j;
                }
        }
    }
    
    ofstream fout("wormhole.out");
    fout << solve() << endl;
    fout.close();
//    cout << solve() << endl;
}

