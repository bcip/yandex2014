#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int t[10000];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    sort(t, t + n);
    int result = -1;
    for (int i = 3; i < n; ++i) {
        if (t[i] < t[i - 1] + t[i - 2] + t[i - 3]) {
            result = max(result, t[i] + t[i - 1] + t[i - 2] + t[i - 3]);
        }
    }
    cout << result << endl;
}
