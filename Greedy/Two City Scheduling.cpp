class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // The idea is to sort the costs array based on the amount of savings if we choose to send the current person to city A instead of city B, so those N people who have max savings in going to cityA will be sent to city A and the left out N people who have least savings in going to city B will be then send to city B
        sort(costs.begin(), costs.end(), [](vector<int> &p1, vector<int> &p2) {
            return (p1[1] - p1[0]) > (p2[1] - p2[0]); // return true for that person who has more savings 
        });
        int min_cost = 0;
        // Step2: Now add first N person's cityA cost to ans and the next N person's cityB cost
        for (int person= 0; person < costs.size(); person++) {
            if (person < costs.size()/2) min_cost += costs[person][0]; // adding cost to cityA
            else min_cost += costs[person][1]; // adding cost ro cityB
        }
        return min_cost;
    }
};
