
#include <set>
#include <iostream>

int main()
{
  const unsigned int MaxPrime = 500000;
  // find all primes up to 500000
  std::set<unsigned int> primes;
  primes.insert(2);
  for (unsigned int i = 3; i < MaxPrime; i += 2)
  {
    bool isPrime = true;
    // test against all prime numbers we have so far (in ascending order)
    for (auto p : primes)
    {
      // next prime is too large to be a divisor
      if (p*p > i)
          break;

      // divisible => not prime
      if (i % p == 0)
      {
        isPrime = false;
        break;
      }
    }

    // yes, we have a prime number
    if (isPrime)
      primes.insert(i);
  }

//#define ORIGINAL
#ifdef ORIGINAL
  // start at 9 (smallest odd number which is not prime)
  for (unsigned int i = 9; i <= MaxPrime; i += 2)
  {
    // only composite numbers
    if (primes.count(i) != 0)
      continue;

    bool refuteConjecture = true;
    // try all squares
    for (unsigned int j = 1; 2*j*j < i; j++)
    {
      auto check = i - 2*j*j;
      // found a combination, conjecture is still valid
      if (primes.count(check) != 0)
      {
        refuteConjecture = false;
        break;
      }
    }

    // conjecture refuted !
    if (refuteConjecture)
    {
      std::cout << i << std::endl;
      break;
    }
  }

#else

  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    unsigned int i;
    std::cin >> i;

    // try all squares
    unsigned int solutions = 0;
    for (unsigned int j = 1; 2*j*j < i; j++)
    {
      // check whether i - j^2 is prime
      unsigned int check = i - 2*j*j;
      // yes, found another combination
      if (primes.count(check) != 0)
        solutions++;
    }

    std::cout << solutions << std::endl;
  }
#endif

  return 0;
}
