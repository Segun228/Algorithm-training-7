#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

struct triplet{
    double price;
    double volume;
    double koef;
};

void printTriplet(const triplet& t) {
    cout << fixed << setprecision(2);
    cout << "[Price: " << setw(4) << t.price
        << ", Volume: " << setw(4) << t.volume
        << ", Koef: " << setw(6) << t.koef << "]" << endl;
}

bool comparator( triplet set1, triplet set2){
    if(set1.koef <= set2.koef){
        return true;
    }
    return false;
}

int main(){
    int m, buf;
    int current_value = 0;
    int current_cost = 0;
    int current_tar = 0;
    cin >> m;
    vector <triplet> pricelist;
    triplet buf_triplet;
    for(int i = 0; i<10; i++){
        cin >> buf;
        buf_triplet.price = pow(2, i);
        buf_triplet.volume = buf;
        buf_triplet.koef = buf_triplet.price / buf_triplet.volume;
        pricelist.push_back(buf_triplet);
    }

    sort(pricelist.begin(), pricelist.end(), comparator);
    for(int i = 0; i<10; i++){
        printTriplet(pricelist[i]);
    }

    while(current_value<m){
        if(m-current_value<pricelist[current_tar].volume)
    }

}
