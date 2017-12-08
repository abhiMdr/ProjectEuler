
#include <string>
#include <iostream>

// return the digit at position "pos"
// first digit after then decimal dot has pos = 1 (not zero !)
unsigned int getDigit(unsigned long long pos)
{
  // assume pos has one digit
  unsigned int       digits = 1;
  // then there are 9 other numbers
  unsigned long long range  = 9;
  // the smallest of them is 1
  unsigned long long first  = 1;

  // there are    9 numbers with 1 digit
  // there are   90 numbers with 2 digits
  // there are  900 numbers with 3 digits
  // there are 9000 numbers with 4 digits
  // ...
  // let's figure out the number of digits

  // skip numbers with too few digits
  unsigned long long skip = 0;
  while (skip + digits*range < pos)
  {
    skip += digits*range;
    // digits = 2 => range = 90 and
    // digits = 3 => range = 900
    // digits = 4 => range = 9000, etc.
    digits++;
    range *= 10;
    first *= 10;
  }

  // now that we know the number of digits
  // adjust "first" and "skip" such that the left-most/highest digit of pos and skip are identical
  // then continue with the next digit
  while (range > 9)
  {
    // could be replace by some modular arithmetic, but I'm too lazy for tough thinking ;-)
    while (skip + digits*range < pos)
    {
      skip  += digits*range;
      first += range;
    }

    // next lower digit
    range /= 10;
  }

  // right-most digit (basically same inner loop as above when range == 1)
  while (skip + digits < pos)
  {
    first++;
    skip += digits;
  }

  // skip all "skippable" digits
  pos -= skip;
  // strings are zero-based whereas input is one-based
  pos--;

  // create a string version of our number
  auto s = std::to_string(first);
  // extract digit and convert from ASCII to an integer
  return s[pos] - '0';
}

int main()
{
  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    unsigned int product = 1;
    // read 7 positions
    for (unsigned int i = 0; i < 7; i++)
    {
      unsigned long long pos;
      std::cin >> pos;

      // multiply all digits
      product *= getDigit(pos);
    }

    // print result
    std::cout << product << std::endl;
  }

  return 0;
}
