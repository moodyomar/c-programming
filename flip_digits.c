#include <stdio.h>
#include <string.h>

int flip_digits(int n);

int main ()
{
    printf("%d \n",flip_digits(123));
}

int flip_digits(int n)
{
    // char n_to_str[10];
    // // printing integer to the string defined above.
    // sprintf(n_to_str,"%d",n);
    // int len = strlen(n_to_str);
    // // flipped string will be saved here
    // for (int i = 0, j = len; j >= 0;j--)
    // {
    //     if(n_to_str[j] == '0')
    //         continue;
    //     printf("%c",n_to_str[j]);
    //     i++;
    // }
    // return 0;

int reverse = 0, remainder;

while( n != 0)
{
    remainder = n % 10;
    reverse = reverse * 10 + remainder;
    n /= 10;
}
  return reverse;
}