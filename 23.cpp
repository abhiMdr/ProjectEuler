
#include <iostream>
#include <set>

// constant according to problem statement
const unsigned int EverythingsASumFromHere = 28124;

// will contain all abundant numbers
std::set<unsigned int> abundant;

// generate sum of all divisor's of x
unsigned int getSum(unsigned int x)
{
  // note: code very similar to problem 21

  // find all factors:
  // look only for the "smaller" divisors <= sqrt(x)
  // and they have a "bigger" brother x / divisor

  // 1 is always a divisor, but not the number x itself
  unsigned int divisorSum = 1;
  // therefore start at 2
  for (unsigned int divisor = 2; divisor * divisor <= x; divisor++)
    if (x % divisor == 0)
    {
      divisorSum += divisor;

      // add the "bigger brother"
      unsigned int otherDivisor = x / divisor;
      // except square numbers
      if (otherDivisor != divisor)
        divisorSum += otherDivisor;
    }

  return divisorSum;
}

// return true if parameter can be written as the sum of two abundant numbers
bool isAbundantSum(unsigned int x)
{
  // big numbers are always an abundant sum
  if (x >= EverythingsASumFromHere)
    return true;

  // look at all small abundant numbers in ascending order
  for (auto i : abundant)
  {
    // abort if there is no sum possible
    if (i >= x) // or even faster: if (i > x/2)
      return false;

    // is its partner abundant, too ?
    unsigned int other = x - i;
    if (abundant.count(other) == 0)
      continue;

    // yes, we found a valid combination
    return true;
  }

  // nope
  return false;
}

int main()
{
  // precomputation step:
  // find all abundant numbers <= 28123
  for (unsigned int i = 1; i < EverythingsASumFromHere; i++) // actually, we could start at 12
    // divisor's sum bigger than the number itself ?
    if (getSum(i) > i)
      abundant.insert(i);

//#define ORIGINAL
#ifdef ORIGINAL
  unsigned long long sum = 0;
  for (unsigned int i = 0; i < EverythingsASumFromHere; i++)
  {
    // sum of all numbers which cannot be written as an abundant sum
    if (!isAbundantSum(i))
      sum += i;
  }
  std::cout << sum << std::endl;

#else

  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    // find out whether a certain number can be written as an abundant sum
    unsigned int x;
    std::cin >> x;
    std::cout << (isAbundantSum(x) ? "YES" : "NO") << std::endl;
  }
#endif
  return 0;
}
