#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m, buf1, buf2;
    int curr_class = 0;
    cin>>n>>m;
    vector <pair <int, int>> groupList; 
    vector <pair <int, int>> classList; 

    for (int i=0; i<n; ++i){
        cin>>buf1;
        groupList.push_back({buf1, i+1});
    }

    for (auto i=0; i<m; ++i) {
        cin >> buf1;
        classList.push_back({buf1, i+1});
    }

    sort(groupList.begin(), groupList.end());
    sort(classList.begin(), classList.end());

    vector <int> result(n+2, 0); 
    int readyGrops=0;
    for (auto i=0; i<n; i++){
        
        while (curr_class<m && classList[curr_class].first<=groupList[i].first)
            curr_class++ ;
        if (m>curr_class) {
            result[groupList[i].second]=classList[curr_class].second;
            readyGrops+=1;
            curr_class+=1; 
        }
    }
    cout<<readyGrops<<endl;
    for (auto el : result){
        cout<<el<<" ";
    } 
    return 0;
}