#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = 0, sc = 0;
        int litterCount = 0;

        // litterId[r][c] = index of litter at this cell, otherwise -1
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                }

                if (classroom[r][c] == 'L') {
                    litterId[r][c] = litterCount++;
                }
            }
        }

        // No litter
        if (litterCount == 0)
            return 0;

        int totalMasks = 1 << litterCount;
        int fullMask = totalMasks - 1;

        /*
            best[r][c][mask] = maximum energy with which
            we have reached (r,c) after collecting 'mask'.

            Since energy <= 50, int8_t is enough.
            -1 means never visited.
        */
        vector<int8_t> best(
            m * n * totalMasks,
            -1
        );

        auto index = [&](int r, int c, int mask) {
            return ((r * n + c) * totalMasks + mask);
        };

        struct State {
            int r;
            int c;
            int mask;
            int energy;
        };

        queue<State> q;

        best[index(sr, sc, 0)] = energy;
        q.push({sr, sc, 0, energy});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            // Process one BFS level
            while (sz--) {

                State cur = q.front();
                q.pop();

                int r = cur.r;
                int c = cur.c;
                int mask = cur.mask;
                int e = cur.energy;

                if (mask == fullMask)
                    return moves;

                // Cannot move with zero energy
                if (e == 0)
                    continue;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    // Obstacle
                    if (classroom[nr][nc] == 'X')
                        continue;

                    // Spend 1 energy
                    int ne = e - 1;

                    int nmask = mask;

                    // Collect litter
                    if (litterId[nr][nc] != -1) {
                        nmask |= (1 << litterId[nr][nc]);
                    }

                    // Reset energy
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    int idx = index(nr, nc, nmask);

                    /*
                        Dominance optimization:

                        If we've already reached this exact
                        (position + mask) with >= energy,
                        this state is useless.
                    */
                    if (best[idx] >= ne)
                        continue;

                    best[idx] = ne;

                    q.push({
                        nr,
                        nc,
                        nmask,
                        ne
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};