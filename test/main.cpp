#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<char>> grid = {{'1', '0', '1', '1', '1'},{'1', '0', '1', '0', '1'}, {'1', '1', '1', '0', '1'}};
    //vector<vector<char>> grid = {{"1","0","1","1","1"},{"1","0","1","0","1"},{"1","1","1","0","1"}};

    int res = 0;

    int row = grid.size();
    int col = grid[0].size();

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == '1') {
                res++;
                vector<vector<int>> v_cur; // Discovery the first leading '1'
                v_cur.push_back({i, j});
                grid[i][j] = '0';
                while (1) {
                    cout << "#" << endl;
                    vector<vector<int>> v_new; // Store 4 directions' coordinates
                    for (int k = 0; k < v_cur.size(); k++) {
                        int x = v_cur[k][0];
                        int y = v_cur[k][1];

                        // 4 directions
                        if (x - 1 >= 0) { // UP
                            if (grid[x - 1][y] == '1') {
                                v_new.push_back({x - 1, y});
                                grid[x - 1][y] = '0';
                            }
                        }
                        if (x + 1 < row) { // DOWN
                            if (grid[x + 1][y] == '1') {
                                v_new.push_back({x + 1, y});
                                grid[x + 1][y] = '0';
                            }
                        }
                        if (y - 1 >= 0) { // LEFT
                            if (grid[x][y - 1] == '1') {
                                v_new.push_back({x, y - 1});
                                grid[x][y - 1] = '0';
                            }
                        }
                        if (y + 1 < col) { // RIGHT
                            if (grid[x][y + 1] == '1') {
                                v_new.push_back({x, y + 1});
                                grid[x][y + 1] = '0';
                            }
                        }

                        for (int p = 0; p < row; p ++) {
                            for (int q = 0; q < col; q ++) {
                                cout << grid[p][q];
                            }
                            cout << endl;
                        }
                        cout << endl;

                    }

                    if (v_new.size() == 0) {
                        break;
                    }
                    v_cur.erase(v_cur.begin(), v_cur.end());
                    v_cur = v_new;
                }
            }
        }
     }
     cout << res << endl;

    return 0;
}
