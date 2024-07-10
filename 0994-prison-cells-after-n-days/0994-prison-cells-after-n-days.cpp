class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int> next(cells.size(), 0);
        n=(n-1)% 14 + 1;
        for (int day = 0; day < n; ++day) {

            for (int i = 1; i < cells.size() - 1; ++i) {
                if (cells[i - 1] == cells[i + 1]) {
                    next[i] = 1;
                } else {
                    next[i] = 0;
                }
            }

            cells = next;

            fill(next.begin(), next.end(), 0);
        }

        return cells;
    }
};
