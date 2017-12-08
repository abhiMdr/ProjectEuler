#include <iostream>


using namespace std;

int main() {

	unsigned int sqSum = 0;
	unsigned int sumSq = 0;

	for(unsigned int i = 1; i < 101; ++i) {

		sumSq += i*i;
		sqSum += i;

		}

	cout << sqSum*sqSum - sumSq << endl;

	return 0 ;

	}