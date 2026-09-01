class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        // Number of rows
        int m = classroom.size();

        // Number of columns
        int n = classroom[0].size();

        // STEP 1: Find the starting position 'S'
        //         and assign an index to every litter 'L'
        int startRow = 0;
        int startCol = 0;

        // litterId[i][j] tells us which bit belongs
        // to a litter cell.
        //
        // Example:
        //
        // L1 -> bit 0
        // L2 -> bit 1
        // L3 -> bit 2
        //
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        int litterCount = 0;


        // Traverse the complete classroom
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                // Find starting point
                if (classroom[i][j] == 'S') {

                    startRow = i;
                    startCol = j;
                }

                // Give every litter a unique number
                else if (classroom[i][j] == 'L') {

                    litterId[i][j] = litterCount;

                    litterCount++;
                }
            }
        }
        // STEP 2: If there is no litter, answer is already 0
        if (litterCount == 0) {
            return 0;
        }
        // STEP 3: Bitmask for collected litter       
        // Suppose there are 3 litter cells.
        //
        // We use:
        //
        // bit 0 -> litter 0 collected?
        // bit 1 -> litter 1 collected?
        // bit 2 -> litter 2 collected?
        //
        // Example:
        //
        // mask = 000  -> collected nothing
        // mask = 001  -> collected litter 0
        // mask = 101  -> collected litter 0 and 2
        // mask = 111  -> collected everything
        //
        // Therefore:
        //
        // allCollectedMask = (1 << litterCount) - 1
        //

        int allCollectedMask = (1 << litterCount) - 1;
        // STEP 4: Define our BFS state        
        // A state must contain:
        //
        // row
        // column
        // remaining energy
        // litter mask
        //
        // We cannot simply store row and column.
        //
        // Why?
        //
        // Reaching the same cell with:
        //
        // energy = 5
        //
        // is different from:
        //
        // energy = 1
        //
        // Also:
        //
        // reaching the same cell after collecting different litter
        // is also a different state.


        // State format:
        //
        // {row, col, remainingEnergy, mask}

        queue<array<int, 4>> q;


        // Starting state:
        //
        // position = S
        // energy   = full energy
        // mask     = 0 because nothing is collected yet

        q.push({
            startRow,
            startCol,
            energy,
            0
        });
        // STEP 5: Visited states     
        // visited[row][col][energy][mask]
        //
        // Prevents us from processing the exact same state again.

        vector<
            vector<
                vector<
                    vector<bool>
                >
            >
        > visited(
            m,
            vector<
                vector<
                    vector<bool>
                >
            >(
                n,
                vector<
                    vector<bool>
                >(
                    energy + 1,
                    vector<bool>(
                        1 << litterCount,
                        false
                    )
                )
            )
        );


        // Mark starting state as visited

        visited[startRow][startCol][energy][0] = true;
        // STEP 6: Directions
        // Up, Down, Left, Right

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};


        // Number of moves taken so far
        int moves = 0;


        // STEP 7: BFS


        while (!q.empty()) {

            // All states currently inside the queue
            // belong to this BFS level.
            //
            // One BFS level = one move.

            int levelSize = q.size();


            // Process every state reachable in "moves" moves
            while (levelSize--) {

                // Take current state
                auto state = q.front();
                q.pop();


                int row = state[0];
                int col = state[1];

                int currentEnergy = state[2];

                int mask = state[3];
                // STEP 8: Have we collected all litter?

                if (mask == allCollectedMask) {

                    // Because this is BFS,
                    // this is guaranteed to be minimum moves.

                    return moves;
                }
                // STEP 9: If energy is 0, we cannot move
                //
                // Note:
                //
                // If we reached an R cell, we restore the energy
                // immediately while creating that state.
                //
                // Therefore a state with energy == 0 here
                // cannot continue.

                if (currentEnergy == 0) {
                    continue;
                }
                // STEP 10: Try moving in 4 directions

                for (int d = 0; d < 4; d++) {

                    int newRow = row + dr[d];
                    int newCol = col + dc[d];
                    // Check classroom boundaries
                    if (
                        newRow < 0 ||
                        newRow >= m ||
                        newCol < 0 ||
                        newCol >= n
                    ) {
                        continue;
                    }
                    // Cannot enter obstacle

                    if (classroom[newRow][newCol] == 'X') {
                        continue;
                    }
                    // STEP 11: Moving costs 1 energy

                    int newEnergy = currentEnergy - 1;
                    // STEP 12: If we reach reset cell 'R'
                    // restore energy completely

                    if (classroom[newRow][newCol] == 'R') {

                        newEnergy = energy;
                    }


                    // Copy current collected-litter mask
                    int newMask = mask;
                    // STEP 13: If this cell contains litter
                    // collect it using bitmask

                    if (classroom[newRow][newCol] == 'L') {

                        // Find which bit belongs to this litter
                        int id = litterId[newRow][newCol];


                        // Set that bit to 1
                        //
                        // Example:
                        //
                        // mask      = 001
                        // id        = 2
                        //
                        // 1 << 2    = 100
                        //
                        // OR:
                        //
                        // 001
                        // 100
                        // ---
                        // 101

                        newMask = newMask | (1 << id);
                    }
                    // STEP 14: If this exact state was already seen
                    // don't process it again

                    if (
                        visited[newRow]
                               [newCol]
                               [newEnergy]
                               [newMask]
                    ) {

                        continue;
                    }


                    // Mark new state visited

                    visited[newRow]
                           [newCol]
                           [newEnergy]
                           [newMask] = true;


                    // Add state to BFS queue

                    q.push({
                        newRow,
                        newCol,
                        newEnergy,
                        newMask
                    });
                }
            }
            // Finished one complete BFS level,
            // therefore one move has been performed.

            moves++;
        }
        // STEP 15:
        // If BFS ends and all litter was never collected,
        // completing the task is impossible.

        return -1;
    }
};