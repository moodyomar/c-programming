
#include <stdio.h>

float power(float x, float y);

int main()
{
    printf("%f\n", power(2, 3));
    printf("%f\n", power(3, 4));
    printf("%f\n", power(-2, 3));
    printf("%f\n", power(2, -3));
    printf("%f\n", power(2, 0));
    printf("%f\n", power(-1, 2));
    return 0;
}

float power(float x, float y)
{
    float power = 1;
    if (y < 0)
    {
        y *= -1;
        x = 1 / x;
    }
    for (int i = 0; i < y; i++)
    {
        power *= x;
    }
    return power;
}
