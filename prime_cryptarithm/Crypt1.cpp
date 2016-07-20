/*
ID: muntean3
PROG: crypt1
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> nums;
int cnt = 0;

bool valid(int d) {


	bool valid = true;
	while(d){
		int di = d%10;
		d/=10;
		vector<int>::iterator it;
		it =  find(nums.begin(), nums.end(), di);
		if(it == nums.end()) {
			valid = false;
			break;

		}

	}


	// valid if found till end of vector
	return valid;
	
}

int digit_len(int n) {
	unsigned int number_of_digits = 0;

	do {
		++number_of_digits; 
		n /= 10;
	} while (n);

	return number_of_digits;

}

void products ( int first, int second) {
	// validate digits int first number
	if(!valid(first)) return;	

	// validate digits in second number
	if(!valid(second)) return;	


	// validate digits in partial products
	int p1 = (second%10) * first;
	if(digit_len(p1) > 3) return;
	if(!valid(p1)) return;	

	int p2 = ((second/10)%10) * first;
	if(digit_len(p2) > 3) return;
	if(!valid(p2)) return;	

	// validate final product
	int p = second * first;
	if(digit_len(p) > 4) return;
	if(!valid(p)) return;	


	cnt++;

}

int main() {

	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");

	int N;

	fin>>N;
	nums.resize(N);
	
	int a;
	for(int i = 0; i < N; i++) {
		fin>>a;
		nums[i] = a;
	}
	
	for(int first = 100; first < 1000; first++){
		for(int second = 10; second < 100; second++){
			products(first, second);
		}

	}

	fout << cnt << endl;

}
