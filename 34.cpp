
#include <iostream>

int main()
{
  // precompute factorials of all possible digits 0!..9!
  const unsigned int factorials[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

  // no more than 7*9! = 2540160 for the original problem
  unsigned int limit;
  std::cin >> limit;

  // result (differs for Hackerrank modified problem !)
  unsigned int result = 0;

  for (unsigned int i = 10; i < limit; i++)
  {
    unsigned int sum = 0;

    // split i into its digits
    unsigned int x = i;
    while (x > 0)
    {
      // add factorial of the right-most digit
      sum += factorials[x % 10];
      // remove that digit
      x /= 10;
    }

#define ORIGINAL
#ifdef ORIGINAL
    // equal ?
    if (sum == i)
      result += i;
#else
    // divisible ?
    if (sum % i == 0)
      result += i;
#endif
  }

  std::cout << result << std::endl;
  return 0;
}
