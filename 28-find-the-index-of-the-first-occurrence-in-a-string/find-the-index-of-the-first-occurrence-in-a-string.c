int strStr(char * haystack , char * needle)
{
    int i =  0 , j , Valid = 1;
    if (needle[0]=='\0')
        return 0;
    while(haystack[i]!='\0')
    {
        j = 0;
        if(haystack[i]==needle[j])
        {
            while(needle[j]!='\0')
            {
                if (needle[j]!=haystack[i])
                    {
                        Valid = 0;
                        i-=j;
                        break;
                    }
                i++;
                j++;
            }
            if(Valid)
                return i-j;
        }
        i++;
        Valid = 1;
    }
    return -1;
}