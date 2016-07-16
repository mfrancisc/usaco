/*
ID: muntean3
PROG: gift1
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<map>
#include<vector>

using namespace std;

int main() {

    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int NP;
    fin >> NP;

    map<string, int> persons;

    // initialize names map
    string name;
    vector <string> namesList;
    for(int i = 0; i < NP; i++) {
        fin>> name;
        persons[name] = 0;
        namesList.push_back(name);
    }

    int total1;
    int gifts;
    // start calc
    while(!fin.eof()){
        fin >> name;
        fin >> total1;
        fin >> gifts;

        if(gifts == 0) continue;

        int parts = total1 / gifts;
        persons[name] -= parts * gifts;
        for(int n = 0; n < gifts; n++) {
            fin >> name;
            persons[name] += parts;
        }

    }

    while(!namesList.empty())
    {
        string n = namesList.front();
        fout << n << " " << persons[n] << endl;
        namesList.erase(namesList.begin());
    }

    return 0;
}
