#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int t, m, rest_length=1000000;
    cin >> t;
    if(t==0){
        cout << 0;
        return 0;
    }
    vector <vector<int>> tests;
    vector <int> buf;
    vector <vector <int>> subanswer;
    int current_value;
    for(int i=0;i<t;i++){
        tests.push_back(buf);
    }
    for(int i=0;i<t;i++){
        cin >> m;
        for(int j=0; j<m; j++){
            cin >> current_value;
            tests[i].push_back(current_value);
        }
    }
    cout << "прога" << endl;
    for(auto el : tests){
        cout << "тестик" << endl;
        if(el.size()==0){
            cout << 0 << endl << 0 << endl;
            buf.clear();
            continue;
        }
        if(el.size()==1){
            cout << 1 << endl << 1 << endl;
            buf.clear();
            continue;
        }
        buf.clear();
        for(int i=0; i<el.size(); i++){
            if(rest_length<1){
                subanswer.push_back(buf);
                buf.clear();
                rest_length = 1000;
            }
    
            if(buf.size()==0){
                buf.push_back(el[i]);
                rest_length = el[i]-1;
                continue;
            }
            
            if(el[i]>buf.size() ){
                buf.push_back(el[i]);
                rest_length = min(rest_length-1, int(el[i]-buf.size()));
            }
            else{
                subanswer.push_back(buf);
                buf.clear();
                buf.push_back(el[i]);
                rest_length = el[i]-1;
            }
        }
        if(buf.size()!=0){
            subanswer.push_back(buf);
            buf.clear();
        }
        cout << subanswer.size() << endl;
        for(auto sub : subanswer){
            cout << sub.size() << " ";
        }
        cout << endl;
        subanswer.clear();
        buf.clear();
        rest_length = 1000000;
    }
    return 0;
}
