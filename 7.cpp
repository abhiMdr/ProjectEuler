#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {

	unsigned long int i = 2;

	double limit = 0;

	while(limit <= 10001) {

		limit = double(i)/log(i);
		++i;

		}

	vector <unsigned long int> sieve;

	for(unsigned long int j = 0; j <= i; ++j)
		sieve.push_back(j);


	int count = 0;

	unsigned long int j;

	for(j = 2; j <= i; ++j) {
		if(sieve[j] != 0) {
			++count;
			if(count == 10001)
				break;
			for(unsigned long int k = 2; k*sieve[j] <= i; ++k)
				sieve[k*sieve[j]] = 0;
			sieve[j] = 0;
			}

		}

	cout << j << endl;

	return 0;

	}