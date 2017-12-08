
#include <iostream>
#include <string>
#include <map>
#include <set>

//#define ORIGINAL

// read a single name from STDIN, syntax: "abc","def","xyz"
std::string readName()
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
  // note: an std::set is always sorted
  std::set<std::string> names;

#ifdef ORIGINAL

  while (true)
  {
    // read a single name, abort when empty
    auto name = readName();
    if (name.empty())
      break;
    names.insert(name);
  }

#else

  unsigned int numNames;
  std::cin >> numNames;
  while (numNames--)
  {
    // Hackerrank's names are separated by a space
    std::string name;
    std::cin >> name;
    // add to our set
    names.insert(name);
  }
#endif

  // walk through all names in alphabetic order, keep track of their position
  // store both information as [name] => [pos]
  std::map<std::string, unsigned int> sorted;
  unsigned int pos = 1;
  for (auto name : names)
    sorted[name] = pos++;

#ifdef ORIGINAL
  // original problem
  unsigned int sum = 0;
  for (auto name : sorted)
  {
    unsigned int value = 0;
    // 'A' = 1, 'B' = 2, ..., 'Z' = 26
    for (auto c : name.first)
      value += c - 'A' + 1;
    // multiply by position
    sum += value * name.second;
  }
  std::cout << sum << std::endl;

#else

  unsigned int queries;
  std::cin >> queries;
  while (queries--)
  {
    std::string name;
    std::cin >> name;

    unsigned int value = 0;
    // 'A' = 1, 'B' = 2, ..., 'Z' = 26
    for (auto c : name)
      value += c - 'A' + 1;
    // multiply by position
    value *= sorted[name];

    std::cout << value << std::endl;
  }
#endif

  return 0;
}
