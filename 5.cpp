#include <iostream>

long gcd(long a, long b) {
    while (b) {
        int prevB = b;
        b = a % b;
        a = prevB;
    }
    return a;
}

long lcm(long a, long b) {
    return a * (b / gcd(a, b));
}

int main() {
    long result = 20;
    for (long number = result - 1; number > 1; --number) {
        result = lcm(result, number);
    }
    std::cout << result << '\n';
}