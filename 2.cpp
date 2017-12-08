#include <iostream>

using namespace std;


int main() {
    int num1 = 1;
    int num2 = 1;
    int sol;
    int sum = 0;

    while(num2 <= 4000000) {

        if(num2 % 2 == 0) {
            sum += num2;
        }

        sol=num2;
        num2 += num1;
        num1=sol;

    }

    cout << sum << endl;

    return 0;

}