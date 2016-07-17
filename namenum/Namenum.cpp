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

char map[256];
string serialize(string dict_name)
{
    string ret = "";
    for(int i = 0; i < dict_name.length(); i++) {
        if(dict_name[i] == 'Q' || dict_name[i] == 'Z')
            return "1";

        char c = map[dict_name[i]]; 
        ret += c;
    }

    return ret;


}
int main() {
map['A'] = map['B'] = map['C'] = '2';
map['D'] = map['E'] = map['F'] = '3';
map['G'] = map['H'] = map['I'] = '4';
map['J'] = map['K'] = map['L'] = '5';
map['M'] = map['N'] = map['O'] = '6';
map['P'] = map['R'] = map['S'] = '7';
map['T'] = map['U'] = map['V'] = '8';
map['W'] = map['X'] = map['Y'] = '9';

    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in"), fdin ("dict.txt");

    string brand;
    int nf = false;
    int bsize;
    fin>>brand;
    bsize = brand.size();

    // search name
    string dict_name;
    while(!fdin.eof()){
        fdin >> dict_name; 

        if(bsize == dict_name.length() && brand == serialize(dict_name)) {
            fout << dict_name << endl;
            nf = true;
        }
    }

    // no names found
    if(!nf) fout << "NONE" << endl;
}
