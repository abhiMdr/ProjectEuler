
#include <string>
#include <iostream>
#include <cmath>

const int NoTriangle = 0;
// return triangle index or -1 if not a triangle number
int getTriangle(unsigned long long x)
{
  unsigned long long n = sqrt(2*x);

  // if n it truely the right answer then t(n) = x
  unsigned long long check = n * (n + 1) / 2;
  if (x == check)
    return n;
  else
    return NoTriangle;
}

// read a single word from STDIN, syntax: "abc","def","xyz"
std::string readWord()
{
  std::string result;
  while (true)
  {
    // read one character
    char c = std::cin.get();
    // no more input ?
    if (!std::cin)
      break;

    // ignore quotes
    if (c == '"')
      continue;
    // finish when a comma appears
    if (c == ',')
      break;

    // nope, just an ordinary letter (no further checks whether c in 'A'..'Z')
    result += c;
  }
  return result;
}

int main()
{
//#define ORIGINAL
#ifdef ORIGINAL

  unsigned int triangleWords = 0;
  while (true)
  {
    // read next word
    auto word = readWord();
    if (word.empty())
      break;

    unsigned int sum = 0;
    // A = 1, B = 2, ...
    for (auto c : word)
      sum += c - 'A' + 1; // all words contain only uppercase letters without spaces or other characters

    // another "triangle word" ?
    if (getTriangle(sum) != NoTriangle)
      triangleWords++;
  }
  std::cout << triangleWords << std::endl;

#else

  unsigned int tests;
  std::cin >> tests;
  while (tests--)
  {
    // all work is done in getTriangle()
    unsigned long long x;
    std::cin >> x;
    std::cout << getTriangle(x) << std::endl;
  }
#endif

  return 0;
}
