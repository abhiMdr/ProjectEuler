
#include <iostream>
#include <string>
#include <algorithm>

int main()
{
//#define ORIGINAL
#ifdef ORIGINAL
  unsigned int numPermutation = 1000000;
  std::string current = "0123456789";
  while (--numPermutation)
    std::next_permutation(current.begin(), current.end());
  std::cout << current << std::endl;

#else

  const std::string abc = "abcdefghijklm";
  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    // to find the permutation we treat the input number as something written
    // in a "factorial" system:
    // x = pos0 * 12! + pos1 * 11! + pos2 * 10! + ... + pos12 * 1!
    // (we have 13 letters, therefore the position of the first letter is in 12! radix)

    // precomputed 0! .. 12!
    const unsigned long long factorials[13+1] =
    { 1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800 };

    // 13! which exceed 32 bits
    unsigned long long x;
    std::cin >> x;

    // reduce to a single cycle (repeats after 13! iterations)
    x %= factorials[abc.size()];

    // that factorial system is zero-based ...
    x--;

    // strip off single letters (until empty)
    auto remain = abc;
    // our wanted permutation
    std::string result;
    while (!remain.empty())
    {
      // get next digit in that strange number system :-)
      auto currentFactorial = factorials[remain.size() - 1];
      auto pos = x / currentFactorial;

      // store the associated letter
      result += remain[pos];
      // and remove it from the still unprocessed data
      remain.erase(pos, 1);

      // eliminate the processed digit
      x %= currentFactorial;
    }

    std::cout << result << std::endl;
  }
#endif
  return 0;
}
