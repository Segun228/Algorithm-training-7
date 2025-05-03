#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node{
    string name = "";
    Node* next = nullptr;
    Node* prev = nullptr;
};

void trim(string& str){
    while(str[0] == ' ') str.erase(str.begin());
    while(str[str.size() - 1] == ' ') str.pop_back();
}

Node* addTab(Node* head, string name){
    if(head==nullptr){
        head = new Node;
        head -> next = head;
        head -> prev = head;
        head -> name = name;
        cout<<head->name<<endl;
        return head;
    }
    Node* buf = new Node;
    buf -> name = name;
    buf -> prev = head;
    buf -> next = head->next;
    head->next->prev = buf;
    head -> next = buf;
    head = buf;
    cout << head->name << endl;
    return head;
}



Node* backTab(Node* head, int k) {
    if (head == nullptr) {
        cout << "Error: no tabs" << endl;
        return nullptr;
    }
    int tabCount = 1;
    Node* temp = head->next;
    while (temp != head) {
        tabCount++;
        temp = temp->next;
    }

    k = k % tabCount;
    Node* current = head;
    for (int i = 0; i < k; i++) {
        current = current->prev;
    }
    
    if (current != head) {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        
        current->next = head->next;
        current->prev = head;
        head->next->prev = current;
        head->next = current;
    }
    cout << current->name << endl;
    return current;
}


int main(){
    Node* head = nullptr;
    string command;
    string tabName;
    int n;
    int counter = 0;
    cin >> n;
    cin.ignore();
    for(int i=0; i<n; i++){
        cin >> command;
        counter = 0;
        if(command=="Run"){
            getline(cin, tabName);
            trim(tabName);
            head = addTab(head, tabName);
        }
        else{
            for(int j=0; j<command.length(); j++){
                if(command[j]=='+'){
                    counter++;
                }
            }
            if(counter==0){
                continue;
            }
            head = backTab(head, counter);
        }
    }
    return 0;
}