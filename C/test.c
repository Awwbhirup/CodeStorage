#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

  int a =5;
  int b=10;

  int c;
  c=a;
  &a=&b;
  &b=&c;


  printf("%d %d",a,b);
}