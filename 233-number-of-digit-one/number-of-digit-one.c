unsigned int power(int n, int pow)
{
    unsigned int m;
    
    m = n;
    if (pow == 0)
        return (1);
    if (pow == 1)
        return (m);
    if (pow == 2)
        return (m * m);
    if (pow % 2)
        return (m * power(power(m, pow / 2), 2));
    return (power(power(m, pow / 2), 2));
}

int factorial(int n)
{
    if (n <= 1)
        return (1);
    return (n * factorial(n - 1));
}

int C_k_n(int n, int k)
{
    return (factorial(n) / (factorial(k) * factorial(n - k)));
}

int count_9n(int n)
{
    int k;
    int result;
    
    result = 0;
    k = 0;
    while (k <= n)
    {
        result += (C_k_n(n, k) * (n - k) * power(9, k));
        k++;    
    }
    return (result);
}

int num_len(int n)
{
    int count;
    
    count = 0;
    while (n >= 1)
    {
        count++;
        n /= 10;
    }
    return (count);
}

void    fill_in_number(char *number, int nbr, int len)
{
    number[len] = 0;
    while (--len >= 0)
    {
        number[len] = nbr % 10 + '0';
        nbr /= 10;
    }
}

int count_1_before(char *number, int index)
{
    int count;
    
    count = 0;
    while (index >= 0)
        count += (number[index--] == '1');
    return (count);
}

int countDigitOne(int n){
    int     len;
    int     i;
    int     count;
    int     num9;
    char    *number;
    
    len = num_len(n);
    i = 0;
    num9 = 0;
    while (++i < len)
        num9 = num9 * 10 + 9;
    number = (char *)malloc(sizeof(char) * (len + 1));
    fill_in_number(number, n, len);
    i = 0;
    count = 0;
    while (i < len)
    {
        count += (number[i] >= '1');
        count += (number[i] - 48) * (count_1_before(number, i - 1) * (num9 + 1) + count_9n(len - 1 - i)) + num9 * (number[i] > '1');
        num9 /= 10;
        i++;
    }
    return (count);
}