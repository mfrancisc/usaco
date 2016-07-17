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

string serialize(string dict_name)
{
    string ret = "";
    for(int i = 0; i < dict_name.length(); i++) {
        if(dict_name[i] == 'Q' || dict_name[i] == 'Z'){
            return "1";
        } else if( dict_name[i] < 'Q') {
            ret += ((dict_name[i] - 'A') / 3) + '2'; 
        } else {
            ret += ((dict_name[i] - 'Q') / 3) + '7'; 
        }
    }

    return ret;


}
int main() {

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
