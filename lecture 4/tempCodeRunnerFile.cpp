#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node{
    int val;
    int num;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node(int v = 0, int n = 0) : val(v), num(n), next(nullptr), prev(nullptr) {}
};



int main(){
    int n, buf;
    bool flag = true;
    cin >> n;
    if (n <= 0) {
        return 0;
    }
    else if(n==1){
        cout <<"0"<<endl;
        return 0;
    }
    else if(n==2){
        cout <<"0 0" <<endl;
        return 0;
    }
    vector<int> places(n+1, 0);
    vector<Node* > onRemove;
    Node* base = new Node;
    base->num = 0;
    cin >> base->val;
    Node* current;
    Node* prev = base;
    for(int i=1; i<n; i++){
        cin >> buf;
        current = new Node;
        current->val = buf;
        current->prev = prev;
        current->num = i;
        prev->next = current;
        prev = current;
    }
    current->next = base;
    base->prev = current;
    bool wasDeletion = false;
    for(int i=0; i<n-2; i++){
        onRemove.clear();
        current = base;
        while(current->next != base){
            if(current->val < current->next->val && current->val < current->prev->val){
                wasDeletion = true;
                onRemove.push_back(current);
            }
            current = current->next;
        }
        if(current->val < current->next->val && current->val < current->prev->val){
            onRemove.push_back(current);
        }
        if(onRemove.size()==0){
            break;
        }
        else{
            for(auto el : onRemove){
                if(el==base){
                    base=base->next;
                }
                el->next->prev = el->prev;
                el->prev->next = el->next;
                places[el->num] = i+1;
                delete el;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << places[i] << " ";
    }
    return 0;
}