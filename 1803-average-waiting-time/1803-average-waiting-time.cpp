class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long end = 0;
        long long wait = 0;
        long long start = 0;

        for (int i = 0; i < customers.size(); i++) {
            int arrive = customers[i][0];
            int duration = customers[i][1];

            if (arrive > end) {
                end = arrive;
            }

            end += duration;
            wait += (end - arrive);
        }

        return static_cast<double>(wait) / customers.size();
    }
};
