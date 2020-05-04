/*
 * Trivial implementation of converter function.
 * You may override this file or create your own.
 */
#include "converter.h"
#include <stdlib.h>

// super naive implementation 
quote_t super_naive_convert(char* lines)
{
  quote_t val = 0;
  while (*lines != 0)
  {
    switch(*lines)
    {
      case '0' :
        val *= 10;
        break;
      case '1' :
        val = val * 10 + 1;
        break;
      case '2' :
        val = val * 10 + 2;
        break;
      case '3' :
        val = val * 10 + 3;
        break;
      case '4' :
        val = val * 10 + 4;
        break;
      case '5' :
        val = val * 10 + 5;
        break;
      case '6' :
        val = val * 10 + 6;
        break;
      case '7' :
        val = val * 10 + 7;
        break;
      case '8' :
        val = val * 10 + 8;
        break;
      case '9' :
        val = val * 10 + 9;
        break;
    }
    ++lines;
  }
  return val;
}

// baseline naive implementation
quote_t naive_convert(char* lines)
{
  quote_t val = 0;
  while (*lines != 0)
  {
    val = (val * 10) + (*lines - '0');
    ++lines;
  }
  return val;
}

// optimized implementation
inline quote_t advanced_convert(const char* lines)
{
  quote_t val = *lines - '0';
  while (*(++lines) != 0)
  {
    val = val * 10 + (*lines - '0');
  }
  return val;
}

void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
  for (unsigned i = 0; i < nlines; i++) {
    nums[i] = advanced_convert(lines[i]);
  }
}
