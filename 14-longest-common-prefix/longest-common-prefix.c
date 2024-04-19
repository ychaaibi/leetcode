

char * longestCommonPrefix(char ** strs, int strsSize){
    int i;
    int j;
    
    if (strsSize == 1)
        return (strs[0]);
    i = 0;
    j = 0;
    while (strs[0][j])
    {
        i = 0;
        while (i < strsSize - 1)
        {
            if (strs[i][j] ^ strs[i + 1][j])
            {
                strs[0][j] = 0;
                return (strs[0]);
            }
            i++;
        }
        j++;
    }
    strs[i][j] = 0;
    return (strs[i]);
}