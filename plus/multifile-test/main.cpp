#include <iostream>
#include "hello.h"
#include "math.h"

int main ()
{
  int a = 5;
  int b = 7;

  int sum = Sum(a, b);

  std::cout << sum << std::endl;

  PRINT_F(12.3f);
  PRINT_I(12);
}