#include <iostream>
#include <vector>

using namespace std;

class FenwickCube{

public:
    FenwickCube(int size) : n(size){
        fenwikus.resize(n + 1, vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0)));
    }

    void update(int x, int y, int z, long long delta){
        for (int i = x + 1; i <= n; i += i & -i){
            for (int j = y + 1; j <= n; j += j & -j){
                for (int k = z + 1; k <= n; k += k & -k){
                    fenwikus[i][j][k] += delta;
                }
            }
        }
    }

    long long getStars(int x1, int y1, int z1, int x2, int y2, int z2){
        return sum(x2, y2, z2) - sum(x1 - 1, y2, z2) - sum(x2, y1 - 1, z2) - sum(x2, y2, z1 - 1) + sum(x1 - 1, y1 - 1, z2) + sum(x1 - 1, y2, z1 - 1) + sum(x2, y1 - 1, z1 - 1) - sum(x1 - 1, y1 - 1, z1 - 1);
    }

protected:
    int n;
    vector<vector<vector<long long>>> fenwikus;
    long long sum(int x, int y, int z) {
        long long result = 0;
        for (int i = x + 1; i > 0; i -= i & -i) {
            for (int j = y + 1; j > 0; j -= j & -j) {
                for (int k = z + 1; k > 0; k -= k & -k) {
                    result += fenwikus[i][j][k];
                }
            }
        }
        return result;
    }

};

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    FenwickCube fenwikus(n);
    while (m != 3){
        if(m == 1){
            int x, y, z, k;
            cin >> x >> y >> z >> k;
            fenwikus.update(x, y, z, k);
        } 
        else if(m == 2){
            int x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            cout << fenwikus.getStars(x1, y1, z1, x2, y2, z2) << endl;
            continue;
        } 
        else{
            break;
        }
        cin >> m;
    }
    return 0;
}


