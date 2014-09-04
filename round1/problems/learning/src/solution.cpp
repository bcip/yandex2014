#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <vector>

using namespace std;

int n;
bool got[1000005];
bool ngot[1000005];

int main() {
    cin >> n;
    got[0] = true;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        for (int j = 0; j <= 1000000; ++j) {
            if (got[j]) {
                int z = j + a;
                vector<int> d;
                while (z) {
                    d.push_back(z % 10);
                    z /= 10;
                }
                sort(d.begin(), d.end());
                do {
                    int c = 0;
                    for (int j = 0; j < (int) d.size(); ++j) {
                        c = 10 * c + d[j];
                    }
                    assert(c <= 1000000);
                    ngot[c] = true;
                } while (next_permutation(d.begin(), d.end()));
            }
        }
        memcpy(got, ngot, sizeof(ngot));
        memset(ngot, 0, sizeof(ngot));
    }
    int result = 1000000;
    while (!got[result]) {
        --result;
    }
    cout << result << endl;
}
