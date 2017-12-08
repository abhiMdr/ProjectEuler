
#include <iostream>

// I generate a "fingerprint" for each number:
// e.g. a fingerprint of 40231 means that the parameter had
// 1 zero
// 3 ones
// 2 threes
// no fours
// 4 fives
// and no sixes, sevens, ...
unsigned long long fingerprint(unsigned int x)
{
  unsigned long long result = 0;

  while (x > 0)
  {
    // extract right-most digit
    auto digit = x % 10;
    x /= 10;

    // add 10^digit
    unsigned long long pos = 1;
    for (unsigned int i = 1; i <= digit; i++)
      pos *= 10;
    result += pos;
  }

  return result;
}

int main()
{
  // the result can be found with 1000000 6
  unsigned int maxNumber   = 1000000;
  unsigned int maxMultiple = 6;;
  std::cin >> maxNumber >> maxMultiple;

  // look at all numbers
  for (unsigned int i = 1; i <= maxNumber; i++)
  {
    // initial fingerprint
    auto id = fingerprint(i);

    bool found = true;
    for (unsigned int multiple = 2; multiple <= maxMultiple; multiple++)
      // mismatch ? => abort
      if (id != fingerprint(i * multiple))
      {
        found = false;
        break;
      }

    // print result
    if (found)
    {
//#define ORIGINAL
#ifdef ORIGINAL
      std::cout << i << std::endl;
      return 0;
#endif

      for (unsigned int multiple = 1; multiple <= maxMultiple; multiple++)
        std::cout << (i * multiple) << " ";
      std::cout << std::endl;
    }
  }

  return 0;
}
