
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main()
{
  // read highest digit
  unsigned int maxDigit;
  std::cin >> maxDigit;

  // all digits from 1..9
  std::vector<unsigned int> digits = { 1,2,3,4,5,6,7,8,9 };
  // remove higher numbers so there is only 1..n left
  digits.resize(maxDigit);

  // all pandigital products
  std::set<unsigned int> valid;

  // create all permutations
  do
  {
    // let's say a * b = c
    // each variable contains at least one digit
    // the sum of their digits is limited by n (which should be 9)
    // try all combinations of lengths with the current permutation of digits
    for (unsigned int lenA = 1; lenA < maxDigit; lenA++)
      for (unsigned int lenB = 1; lenB < maxDigit - lenA; lenB++)
      {
        unsigned int lenC = maxDigit - lenA - lenB;

        // a*b=c => c>=a && c>=b => c has at least as many digits as a or b
        if (lenC < lenA || lenC < lenB)
          break;

        // pos contains the currently used position in "digits"
        unsigned int pos = 0;

        // build "a" out of the first digits
        unsigned int a = 0;
        for (unsigned int i = 1; i <= lenA; i++)
        {
          a *= 10;
          a += digits[pos++];
        }

        // next digits represent "b"
        unsigned int b = 0;
        for (unsigned int i = 1; i <= lenB; i++)
        {
          b *= 10;
          b += digits[pos++];
        }

        // and the same for "c"
        unsigned int c = 0;
        for (unsigned int i = 1; i <= lenC; i++)
        {
          c *= 10;
          c += digits[pos++];
        }

        // is a*b = c ?
        if (a*b == c)
          valid.insert(c);
      }
  } while (std::next_permutation(digits.begin(), digits.end()));

  // find sum
  unsigned int sum = 0;
  for (auto x : valid)
    sum += x;
  std::cout << sum << std::endl;

  return 0;
}
