#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int


int main() {
    string s;
    getline(cin,s);
    ull max=0;
    for(int i=0;i<s.length();i++)
    {
        ull prod=1;
        for(int j=i; j< 13+ i; j++)
            prod*=(s[j]-'0');
        if(prod >= max)
            max = prod;
    }
    cout<<max;
    return 0;
}