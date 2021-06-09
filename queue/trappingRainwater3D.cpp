//
// Created by Zeeshan Shaikh on 6/9/21.
//

#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int trapRainWater(int heightMap[3][6]) {
        r = 3; c = 6;
        vector<vector<bool>> seen(r, vector<bool>(c));
        for (int i = 0; i < r; i++) {
            pq.push({heightMap[i][0], i * c});
            pq.push({heightMap[i][c - 1], i * c + c - 1});
        }
        for (int j = 1; j < c - 1; j++) {
            pq.push({heightMap[0][j], j});
            pq.push({heightMap[r - 1][j], (r - 1) * c + j});
        }
        int res = 0;
        while (!pq.empty()) {
            auto p = pq.top(); pq.pop();
            dfs(p.second / c, p.second % c, p.first, heightMap, seen, res);
        }
        return res;
    }

private:
    int r, c;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    void dfs(int i, int j, int h, int heightMap[3][6], vector<vector<bool>>& seen, int& res) {
        seen[i][j] = true;
        if (heightMap[i][j] > h) {
            pq.push({heightMap[i][j], i * c + j});
            return;
        }
        res += h - heightMap[i][j];
        if (i > 0 && !seen[i - 1][j]) dfs(i - 1, j, h, heightMap, seen, res);
        if (i < r - 1 && !seen[i + 1][j]) dfs(i + 1, j, h, heightMap, seen, res);
        if (j > 0 && !seen[i][j - 1]) dfs(i, j - 1, h, heightMap, seen, res);
        if (j < c - 1 && !seen[i][j + 1]) dfs(i, j + 1, h, heightMap, seen, res);
    }
};

int main(){
    // Defining the array here
    int heightMap[3][6] = {1,4,3,1,3,2,3,2,1,3,2,4,2,3,3,2,3,1};

    Solution S;
    int output = S.trapRainWater(heightMap);

    cout << "The total amount of water possible to be trapped in this grid is: " << output << endl;
}