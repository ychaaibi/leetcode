class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int p1 = 0, p2 = people.size() - 1;
        int ans = 0;
        int curr_weight = 0;

        sort(people.begin(), people.end());

        while ( p1 < p2 )
        {
            if ( people[p1] + people[p2] <= limit )
                ans++, p1++, p2--;
            else
                ans++, p2--;
        }
        return ( ans + (p1 == p2));
    }
};
