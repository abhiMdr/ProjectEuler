#include <iostream>
#include <vector>

// store single digits in an array, lowest digit come first
typedef std::vector<unsigned int> Digits;

// return factorial
Digits factorial(unsigned int maxFactor)
{
  // 1! = 1
  Digits result = { 1 };

  // avoid further memory allocations
  result.reserve(2568); // 1000! has 2568 digits

  // go through all factors
  for (unsigned int factor = 2; factor <= maxFactor; factor++)
  {
    // multiply each digit with current factor
    // might overflow into next digit => carry
    unsigned int carry = 0;
    for (auto& digit : result)
    {
      digit = digit * factor + carry;

      // overflow ?
      if (digit >= 10)
      {
        carry  = digit / 10;
        digit %= 10;
      }
      else
        carry  = 0;
    }

    // add remaining carry
    while (carry != 0)
    {
      result.push_back(carry % 10);
      carry /= 10;
    }
  }
  return result;
}

int main()
{
  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    unsigned int number;
    std::cin >> number;

    // add all digits of the factorial
    unsigned int sum = 0;
    for (auto i : factorial(number))
      sum += i;
    std::cout << sum << std::endl;
  }
  return 0;
}
