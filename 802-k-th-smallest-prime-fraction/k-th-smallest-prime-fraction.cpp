class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double,pair<int,int>>>  v;

        for ( int i=0; i<arr.size(); i++ )
            for ( int j=i+1; j<arr.size(); j++ )
                v.push_back( make_pair((double)arr[i] / arr[j], make_pair(arr[i], arr[j])));

        sort(v.begin(), v.end());

        vector<int> ans(2);

        ans[0] = v[k - 1].second.first, ans[1] = v[k - 1].second.second;

        return ( ans );
    }
};