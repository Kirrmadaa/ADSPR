#include <iostream>
#include <vector>
#include <climits> 
using namespace std;

class OBST {
    int n;
    vector<int> keys, freq;
    vector<vector<int>> cost, root;

public:
    OBST(int size, vector<int> k, vector<int> f) : n(size), keys(k), freq(f), cost(size + 1, vector<int>(size + 1, 0)), root(size + 1, vector<int>(size + 1, 0)) {}

    void build() {
        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + freq[i - 1];

        for (int i = 0; i < n; i++) {
            cost[i][i] = freq[i];
            root[i][i] = i;
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                cost[i][j] = INT_MAX;

                for (int r = i; r <= j; r++) {
                    int c = (r > i ? cost[i][r - 1] : 0) + (r < j ? cost[r + 1][j] : 0) + (sum[j + 1] - sum[i]);
                    if (c < cost[i][j]) {
                        cost[i][j] = c;
                        root[i][j] = r;
                    }
                }
            }
        }
    }

    void print() {
        cout << "Minimum cost: " << cost[0][n - 1] << endl;
        cout << "Root of the OBST: " << keys[root[0][n - 1]] << endl;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> keys(n), freq(n);
    for (int i = 0; i < n; i++) cin >> keys[i];
    for (int i = 0; i < n; i++) cin >> freq[i];

    OBST obst(n, keys, freq);
    obst.build();
    obst.print();
    return 0;
}
