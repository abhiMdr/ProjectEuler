#include<cstdlib>
#include<string>
#include<iostream>
#include<sstream>

using namespace std;

int main() {

    unsigned int max = 0;

    for(unsigned int i = 999; i != 99; --i)
        for(unsigned int j = 999; j != 99; --j) {

            int mul = i*j;
            stringstream str;
            str << mul;
            string string = str.str();
            int length = string.length();
            bool state = true;
            for(unsigned int ui = 0; ui < length/2.0; ++ui)
                if(string[ui] != string[(length-ui)-1]) {

                    state = false;
                    break;

                }

            if(max <= mul && state)
                max = mul;

        }

    cout << max << endl;

    return 0;

}