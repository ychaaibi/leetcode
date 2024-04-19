int ft_strlen(char *s)
{
    int size;
    
    size = 0;
    while (s[size])
        size++;
    return (size);
}

int valid_palindrome(char *s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
            return (0);
        end--;
        start++;
    }
    return (1);
}

char    *palindrome(char *s, int start, int end)
{
    char    *palind;
    int     i;
    
    i = start;
    palind = (char *)malloc(sizeof(char) * (end - start + 2));
    while (start <= end)
    {
        palind[start - i] = s[start];
        start++;
    }
    palind[start - i] = 0;
    return (palind);
}

char * longestPalindrome(char * s){
    int     i;
    int     start;
    int     end;
    int     end_iter;
    char    *palindrom;
    char    *temp_palind;
    
    start = 0;
    end = ft_strlen(s) - 1;
    palindrom = "";
    while (start <= end)
    {
        end_iter = end;
        while (end_iter >= start)
        {
            if (valid_palindrome(s, start, end_iter))
            {
                temp_palind = palindrome(s, start, end_iter);
                palindrom = ft_strlen(palindrom) > ft_strlen(temp_palind) ? palindrom : temp_palind;
                break ;
            }
            end_iter--;
        }
        start++;
    }
    return (palindrom);
}