#include <stdio.h>

int nb_len(unsigned int x)
{
    int size;
    
    size = 0;
    while (x >= 10)
    {
        size++;
        x /= 10;
    }
    size++;
    return (size);
}

int test_valid(unsigned int x)
{
    int tab[] = {2,1,4,7,4,8,3,6,4,7};
    int i;
    int size;
    
    size = nb_len(x);
    if (size != 10)
        return (1);
    i = 0;
    while (i < 10)
    {
        if (tab[i] != x % 10)
        {
            if (tab[i] < x % 10)
                return (0);
            else
                return (1);
        }
        x /= 10;
        i++;
    }
    return (1);
}

int reverse(int x){
    int             number;
    int             sign;
    unsigned int    nb;
    
    number = 0;
    sign = 1;
    if (x < 0)
    {
        sign = -1;
        nb = (unsigned int)(-(x + 1));
        nb++;
    }
    else
        nb = x;
    if (!test_valid(nb))
        return (0);
    while (nb >= 10)
    {
        number *= 10;
        number += nb % 10;
        nb /= 10;
    }
    number *= 10;
    number += nb % 10;
    return (number * sign);
}