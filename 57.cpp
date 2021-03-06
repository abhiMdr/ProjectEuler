/

#include <vector>
#include <iostream>

// store single digits with lowest digits first
// e.g. 1024 is stored as { 4,2,0,1 }
// only non-negative numbers supported
struct BigNum : public std::vector<unsigned int>
{
  // must be 10 for this problem: a single "cell" store one digit 0 <= digit < 10
  static const unsigned int MaxDigit = 10;

  // store a non-negative number
  BigNum(unsigned long long x = 0)
  {
    do
    {
      push_back(x % MaxDigit);
      x /= MaxDigit;
    } while (x > 0);
  }

  // add two big numbers
  BigNum operator+(const BigNum& other) const
  {
    auto result = *this;
    // add in-place, make sure it's big enough
    if (result.size() < other.size())
      result.resize(other.size(), 0);

    unsigned int carry = 0;
    for (size_t i = 0; i < result.size(); i++)
    {
      carry += result[i];
      if (i < other.size())
        carry += other[i];
      else
        if (carry == 0)
          return result;

      if (carry < MaxDigit)
      {
        // no overflow
        result[i] = carry;
        carry     = 0;
      }
      else
      {
        // yes, we have an overflow
        result[i] = carry - MaxDigit;
        carry = 1;
      }
    }

    if (carry > 0)
      result.push_back(carry);

    return result;
  }
};

#define ORIGINAL

int main()
{
  unsigned int iterations = 1000;
  std::cin >> iterations;

  // both values have one digit initialized with 1
  BigNum a = 1;
  BigNum b = 1;

  unsigned int count = 0;
  for (unsigned int i = 0; i <= iterations; i++)
  {
    // different number of digits ?
    if (a.size() > b.size())
    {
#ifdef ORIGINAL
      count++;
#else
      std::cout << i << std::endl;
#endif
    }

    // a(n+1) = 2*b(n) + a(n)
    // b(n+1) =   b(n) + a(n)
    auto twoB  = b + b;
    auto nextA = a + twoB;
    auto nextB = b + a;

    a = std::move(nextA);
    b = std::move(nextB);
  }

#ifdef ORIGINAL
  std::cout << count << std::endl;
#endif

  return 0;
}
