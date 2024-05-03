class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p1=0, p2=0, last=0;

        while ( p1 < version1.length() or p2 < version2.length() )
        {
            int n1 = 0, n2 = 0;

            if ( p1 < version1.length() )
            {
                size_t  find = version1.find('.', p1);

                find    = min( find, version1.length() );
                n1      = stoi( version1.substr(p1, find - p1) );
                p1      = find + 1;
            }

            if ( p2 < version2.length() )
            {
                size_t  find = version2.find('.', p2);

                find    = min( find, version2.length() );
                n2      = stoi( version2.substr(p2, find - p2 ) );
                p2      = find + 1;
            }
            
            if ( n1 > n2 )
                return ( 1 );
            else if ( n1 < n2 )
                return ( -1 );
        }

        return (0);
    }
};