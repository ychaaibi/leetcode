typedef struct  s_base
{
    int     intg;
    char    roman;
}               t_base;

void    fill_in_roman_base(t_base *base)
{
    char    *base_roman = "IVXLCDM";
    int     i;
    
    base[0].intg = 1;
    base[0].roman = 'I';
    i = 1;
    while (base_roman[i])
    {
        base[i].roman = base_roman[i];
        base[i].intg = base[i - 1].intg * 5;
        base[i + 1].roman = base_roman[i + 1];
        base[i + 1].intg = base[i].intg * 2;
        i += 2;
    }
}

int   stock_n_time(int n, char c, int k, char *number)
{
    while (n--)
        number[k++] = c;
    return (k);
}

char * intToRoman(int num){
    int     i;
    t_base  *base;
    char    *number;
    int     k;
    
    k = 0;
    number = (char *)malloc(sizeof(char) * 20);
    base = (t_base *)malloc(sizeof(t_base) * 7);
    fill_in_roman_base(base);
    while (num > 0)
    {
        i = 6;
        while (num < base[i].intg)
            i--;
        if (i % 2)
        {
            if (num >= base[i + 1].intg - base[i - 1].intg)
            {
                number[k++] = base[i - 1].roman;
                number[k++] = base[i + 1].roman;
                //printf("%c%c", base[i - 1].roman, base[i + 1].roman);
                num -= (base[i + 1].intg - base[i - 1].intg);
            }
            else
            {
                k = stock_n_time(num / base[i].intg, base[i].roman, k, number);
                num -= (num / base[i].intg) * base[i].intg;
            }
        }
        else
        {
            if (i == 6)
            {
                k = stock_n_time(num / base[i].intg, base[i].roman, k, number);
                num -= (num / base[i].intg) * base[i].intg;
            }
            else
            {
                if (num >= base[i + 1].intg - base[i].intg)
                {
                    number[k++] = base[i].roman;
                    number[k++] = base[i + 1].roman;
                    //printf("%c%c", base[i], base[i + 1]);
                    num -= (base[i + 1].intg - base[i].intg);
                }
                else
                {
                    k = stock_n_time(num / base[i].intg, base[i].roman, k, number);
                    num -= (num / base[i].intg) * base[i].intg;
                }
            }
        }
    }
    number[k] = 0;
    return (number);
}