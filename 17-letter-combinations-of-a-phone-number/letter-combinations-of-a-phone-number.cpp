class Solution {
public:
    void    solve(vector<string> Letters, vector<string> &Solutions, string Num, string comb, int index)
    {
        if (index >= Num.length())
        {
            Solutions.push_back(comb.substr(0, comb.length() - 1));
            return ;
        }
        for (int i=0; i<Letters[Num[index] - 50].length(); i++)
        {
            comb[comb.length() - 1] = Letters[Num[index] - 50][i];
            solve(Letters, Solutions, Num, comb + "?", index + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>      Letters = {string("abc"), string("def"), string("ghi"), string("jkl"),
                                       string("mno"), string("pqrs"), string("tuv"), string("wxyz")};   
        vector<string>      Solutions;
        
        if (digits.length())
            solve(Letters, Solutions, digits, string("?"), 0);
        return (Solutions);
    }
};