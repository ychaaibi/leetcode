class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>>  wpq( quality.size() );
        
        for ( int i=0; i<quality.size(); i++ )
            wpq[i]  = make_pair(((double)wage[i] / quality[i]), i);

        sort(wpq.begin(), wpq.end());

        priority_queue<int> pq;

        int sum = 0;

        for ( int i=0; i<k; i++ )
        {
            pq.push( quality[wpq[i].second] );
            sum += quality[wpq[i].second];
        }

        double ans = sum * wpq[k - 1].first;

        for ( int i=k; i<quality.size(); i++ )
        {
            sum = sum - pq.top() + quality[wpq[i].second];
            pq.pop();

            ans = min(ans, sum * wpq[i].first );
            pq.push( quality[wpq[i].second] );
        }

        return ( ans );
    }
};

// 7,  6, 2.5
// 10, 5, 20

// 5   10  20
// 30  70  50


// 3, 1, 10, 10, 1
// 4, 8,  2,  2, 7

// 1.3 ,8, 0.2, 0.2, 7

// 1.3, 0.2, 0.2

// 

// 0.2 0.2 1.3 7 8

