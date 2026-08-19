class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> rows;

        // Store reserved seats for each row as a bitmask
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            rows[row] |= (1 << (col - 1));
        }

        int ans = (n - rows.size()) * 2;

        // Masks for:
        // Left  -> seats 2,3,4,5
        // Middle -> seats 4,5,6,7
        // Right -> seats 6,7,8,9
        int left   = 0b0000011110;
        int middle = 0b0001111000;
        int right  = 0b0111100000;

        for (auto &[row, reserved] : rows) {

            // Both left and right groups can fit
            if ((reserved & left) == 0 &&
                (reserved & right) == 0) {

                ans += 2;
            }

            // At least one of the three possible blocks can fit
            else if ((reserved & left) == 0 ||
                     (reserved & middle) == 0 ||
                     (reserved & right) == 0) {

                ans += 1;
            }
        }

        return ans;
    }
};
