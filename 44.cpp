
#include <iostream>
#include <cmath>

bool isPentagonal(unsigned long long x)
{
  // see explanation above
  unsigned long long n = (1 + sqrt(24*x + 1)) / 6;

  // if x was indeed a pentagonal number then our assumption P(n) = x must be true
  auto p_n = n * (3 * n - 1) / 2;
  return p_n == x;
}

int main()
{
//#define ORIGINAL
#ifdef ORIGINAL

  const unsigned int HugeNumber = 999999999;
  unsigned int best = HugeNumber;
  unsigned int n    = 2; // start with P(2)
  unsigned int last = 1; // P(1)

  while (best == HugeNumber)
  {
    // next pentagonal number
    auto p_n  = n * (3 * n - 1) / 2;
    // difference to closest pentagonal number larger than our best result ?
    if (p_n - last > best)
      break;

    // check all pairs P(n) and P(n - distance) where 1 <= distance < n
    for (unsigned int distance = 1; distance < n; distance++)
    {
      // compute P(n - distance) pentagonal number
      auto x   = n - distance;
      auto p_x = x * (3 * x - 1) / 2;

      // their sum and difference
      auto sum        = p_n + p_x;
      auto difference = p_n - p_x;

      // too far away ?
      if (difference > best)
        break;

      // yes, found something
      if (isPentagonal(sum) && isPentagonal(difference))
        best = difference;
    }

    // check next pentagonal number
    last = p_n;
    n++;
  }
  std::cout << best << std::endl;

#else

  unsigned int maxIndex;
  unsigned int distance;
  std::cin >> maxIndex >> distance;

  // iterate over all pairs at a given distance
  for (unsigned long long n = distance + 1; n <= maxIndex; n++)
  {
    auto p_n = n * (3 * n - 1) / 2;

    auto x   = n - distance;
    auto p_x = x * (3 * x - 1) / 2;

    // check sum and difference
    auto sum        = p_n + p_x;
    auto difference = p_n - p_x;

    // yes, found something
    if (isPentagonal(sum) || isPentagonal(difference))
      std::cout << p_n << std::endl;
  }
#endif

  return 0;
}
