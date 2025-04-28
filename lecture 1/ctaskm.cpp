#include <iostream>
#include <vector>

using namespace std;

int main(){
    int m = -1, buf, ans = -1;
    cin >> m;

    vector<int> pricelist(31);

    for (auto i = 0; i < 31; i++) {
        cin >> buf;
        pricelist[i] = (i == 0) ? buf : max(buf, pricelist[i - 1] * 2);
        if (pricelist[i]>= m) {
            if (ans== -1){
                ans = i;
            }
            else {
                ans = min(ans, i);
            }
        }
    }
    int j = ans - 1;
    ans = 1 << ans;
    int now_time = pricelist[j];
    int currPrice = 1 << j;

    for (auto i=j-1; i>=0; i--){
        if(m <= now_time+pricelist[i]){
            ans=min(ans, currPrice+(1<<i));
        } 
        else{
            now_time+=pricelist[i];
            currPrice+=(1 << i);
        }
    }
    cout << ans;
    return 0;
}