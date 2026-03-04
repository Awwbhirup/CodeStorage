/*
Accept a spaced collection of numbers, the numbers are either SMALL MEDUIM OR LARGE
SMALL - <10
MEDUIM - 10> AND <=49
LARGE - >=50
Find the sum of these categories of numbers and replace the sum of the categories
in place of the numbers that fall in that category
The entered numbers are >0 and <1000
*/

#include <stdio.h>

int main()
{
 int n[50];
 int in=0;
 int v=1;
 while(v!=0)
 {
   scanf("%d",&v);
   n[in]=v;
   in++;
 }

 int sums=0,summ=0,suml=0;
 for(int i=0;i<in;i++)
  {
    if(n[i]<10)
    {
        sums+=n[i];
    }
    else if(n[i]>10 && n[i]<=49)
    {
        summ+=n[i];
    }
    else if(n[i]>=50)
    {
        suml+=n[i];
    }
  }

 for(int i=0;i<in;i++)
 {
    if(n[i]<10)
     {
            n[i]=sums;
        }
    else if(n[i]>10 && n[i]<=49)
        {
            n[i]=summ;
        }
    else if(n[i]>=50)
        {
            n[i]=suml;
        }
 }

 printf("The array is: ");
 for(int i=0;i<in;i++)
  {
    printf("%d ",n[i]);
  }



  
 




}