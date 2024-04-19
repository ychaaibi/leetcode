int find_nb(char *s, char c)
{
    int i;
    
    i = 0;
    while (s[i])
    {
        if (s[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

int special_cases(char c1, char c2)
{
    if ((c1 == 'I' && (c2 == 'V' || c2 == 'X'))
       || (c1 == 'X' && (c2 == 'L' || c2 == 'C'))
       || (c1 == 'C' && (c2 == 'D' || c2 == 'M')))
        return (1);
    return (0);
}

int romanToInt(char * s){
    int     i;
    int     romanToInt[7] = {1, 5, 10, 50, 100, 500, 1000};
    int     number;
    char    *romanBase = "IVXLCDM";
    
    number = 0;
    i = 0;
    while (s[i])
    {
        if (s[i + 1] && special_cases(s[i], s[i + 1]))
        {
            number += (romanToInt[find_nb(romanBase, s[i + 1])] - romanToInt[find_nb(romanBase, s[i])]);
            i++;
        }
        else
        {
            number += romanToInt[find_nb(romanBase, s[i])];
        }
        i++;
    }
    return (number);
}