int ft_len(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
        i++;
    return (i);
}

char * convert(char * s, int numRows){
    char    *Return;
    int     len;
    int     step_1;
    int     step_2;
    int     start; 
    int     k;
    int     step;
    int     begin;

    if (numRows == 1)
        return (s);
    len = ft_len(s);
    step_1 = (numRows - 1) * 2;
    step_2 = 0;
    Return = (char *)malloc(sizeof(char) * (len + 1));
    start = 0;
    k = 0;
    begin = 0;
    while (k < len)
    {
        Return[k++]= s[begin];
        start = begin;
        step = step_1;
        while (start + step < len)
        {
            start += step;
            if (step != 0)
                Return[k++] = s[start];
            if (step == step_1)
                step = step_2;
            else
                step = step_1;
        }
        step_1 -= 2;
        step_2 += 2;
        begin++;
    }
    Return[len] = 0;
    return (Return);
}