#include <stdio.h>

double ten_power(double n);

int main(void){

printf("\n %lf \n",ten_power(-3));

return 0;
}

double ten_power(double n)
{
    float x = 10, p=1;
    if (n < 0)
    {
        n *= -1;
        x = 1.0 / x;
    }
    for (int i = 0; i < n; i++)
    {
        p *= x; 
    }
    return p;
}
