#include <iostream>
#include <vector>
#include <limits>

using namespace std;
int main(){
    int m, buf;
    int current_value = 0;
    int current_cost = 0;
    int current_tar = 0;
    cin >> m;
    if(m == 0){
        cout << 0;
        return 0;
    }
    vector<int> pricelist;
    for(int i = 0; i < 30; i++){
        cin >> buf;
        pricelist.push_back(buf);
    }
    bool flag = false;
    for(auto el : pricelist){
        if(el != 0){
            flag = true;
            break;
        }
    }
    if(!flag){
        cout << 0;
        return 0;
    }
    vector<int> times(m * 2 + 1, -1);
    times[0] = 0;
    for(int i = 0; i < 30; i++){
        int volume = pricelist[i];
        int cost = 1 << i;
        if(volume <= 0) continue;
        for(int j = 0; j <= m * 2; j++){
            if(times[j] != -1 && j + volume <= m * 2){
                int new_cost = times[j] + cost;
                if(times[j + volume] == -1 || times[j + volume] > new_cost){
                    times[j + volume] = new_cost;
                }
            }
        }
    }
    int mini = numeric_limits<int>::max();
    for(int i = m; i <= m * 2; i++){
        if(times[i] != -1 && times[i] < mini){
            mini = times[i];
        }
    }
    cout << (mini == numeric_limits<int>::max() ? 0 : mini);
    return 0;
}