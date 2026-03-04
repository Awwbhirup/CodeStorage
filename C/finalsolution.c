/*
Accept a spaced collection of numbers, the numbers are either SMALL, MEDIUM, or LARGE
SMALL - <10
MEDIUM - 10 to 49 (inclusive)
LARGE - >=50
Find the sum of these categories and replace numbers in each category with their sum.
The entered numbers are >0 and <1000
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
 
int main()
{
    int n[50], in = 0, sums = 0, summ = 0, suml = 0;
    char line[256];
    if (fgets(line, sizeof(line), stdin) != NULL)
    {
        int num = 0;
        for (int i = 0; line[i] != '\0'; i++)
        {
            if (isdigit(line[i]))
            {
                num = num * 10 + (line[i] - '0');
            }
            else if (isspace(line[i]) && num > 0)
            {
                n[in++] = num;
                if (num < 10)
                {
                    sums += num;
                }
                else if (num <= 49)
                {
                    summ += num;
                }
                else
                {
                    suml += num;
                }
                num = 0;
            }
        }
        if (num > 0)
        {
            n[in++] = num;
            if (num < 10)
            {
                sums += num;
            }
            else if (num <= 49)
            {
                summ += num;
            }
            else
            {
                suml += num;
            }
        }
    }
    for (int i = 0; i < in; i++)
    {
        if (n[i] < 10)
        {
            n[i] = sums;
        }
        else if (n[i] <= 49)
        {
            n[i] = summ;
        }
        else
        {
            n[i] = suml;
        }
    }
    printf("The array is: ");
    for (int i = 0; i < in; i++)
    {
        printf("%d ", n[i]);
    }
    return 0;
}
