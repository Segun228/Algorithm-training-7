#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    if (n <= 2) {
        for (int i = 0; i < n; ++i) cout << "0 ";
        cout << endl;
        return 0;
    }

    vector<int> res(n, 0);
    vector<bool> alive(n, true);
    vector<int> left(n), right(n);
    for (int i = 0; i < n; ++i) {
        left[i] = (i - 1 + n) % n;
        right[i] = (i + 1) % n;
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        int l = left[i], r = right[i];
        if (a[i] < a[l] && a[i] < a[r]) {
            res[i] = 1;
            q.push(i);
        }
    }

    int remaining = n;
    int current_round = 1;

    while (!q.empty()) {
        int sz = q.size();
        vector<int> next_round;

        for (int t = 0; t < sz; ++t) {
            int i = q.front(); q.pop();
            if (!alive[i]) continue;

            alive[i] = false;
            --remaining;

            int l = left[i], r = right[i];
            if (alive[l]) right[l] = r;
            if (alive[r]) left[r] = l;

            // Проверка левого соседа
            if (alive[l] && res[l] == 0) {
                int ll = left[l], rr = right[l];
                if (alive[ll] && alive[rr] && a[l] < a[ll] && a[l] < a[rr]) {
                    res[l] = current_round + 1;
                    next_round.push_back(l);
                }
            }

            // Проверка правого соседа
            if (alive[r] && res[r] == 0) {
                int ll = left[r], rr = right[r];
                if (alive[ll] && alive[rr] && a[r] < a[ll] && a[r] < a[rr]) {
                    res[r] = current_round + 1;
                    next_round.push_back(r);
                }
            }
        }

        if (remaining <= 2 || next_round.empty()) break;

        for (int x : next_round) q.push(x);
        current_round++;
    }

    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}