class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string>          ans(score.size(), "");
        vector<pair<int,int>>   placem;

        placem.reserve( score.size() );

        for ( int i=0; i<score.size(); i++ )
            placem.push_back( make_pair(score[i], i ) );
        
        sort(placem.begin(), placem.end(), greater<pair<int,int>>());

        if ( score.size() >= 1 )
            ans[placem[0].second] = "Gold Medal";
        if ( score.size() >= 2 )
            ans[placem[1].second] = "Silver Medal";
        if ( score.size() >= 3 )
            ans[placem[2].second] = "Bronze Medal";

        for ( int i=3; i<score.size(); i++ )
            ans[placem[i].second] = to_string(i + 1);

        return ( ans );
    }
};