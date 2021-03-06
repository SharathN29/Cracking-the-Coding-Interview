/*
* Cracking the coding interview Chapter 2 Problem 1
* Remove Dups: Write code to remove duplicates from an unsorted linked list.
* Approach 1: Naive approach of iterating and removing all further duplicates of current node 
*             Time: O(n^2), Space: O(1)
* Approach 2: Use a hash table, Time: O(n), space: O(n)
* Author : Sharath Nagendra
*/

#include<iostream>
#include<unordered_map>
#include<random>

struct Node {
    int data = 0;
    Node * next = nullptr;
};

void insert(Node * &head, int data){
    Node * newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void printList(Node * head){
    while (head){
        std::cout<<head->data<<"-->";
        head = head->next;
    }
    std::cout<<"nullptr"<<std::endl;
}

static inline int random_range(const int min, const int max){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(mt);
}

void removeDuplicates(Node * head){
    if(head == nullptr || (head &&(head->next == nullptr))){
        return;
    }

    Node * curr = head;
    while(curr){
        Node * runner = curr;
        while(runner->next != nullptr){
            if(runner->next->data == curr->data){
                runner->next = runner->next->next;
            } else {
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
}

void removeDuplicates1(Node * head){
    if(head == nullptr || (head && (head->next == nullptr))){
        return;
    }

    std::unordered_map<int, int> node_map;
    Node * prev = head;
    Node * curr = head->next;
    node_map[head->data] = 1;
    while (curr != nullptr){
        while (curr && node_map.find(curr->data) != node_map.end()){
            curr = curr->next;
        }
        prev->next = curr;
        prev = curr;
        if(curr){
            node_map[curr->data] = 1;
            curr = curr->next;
        }
    }
}

int main(){
    std::cout<<"Method 1: \n";
    Node * head = nullptr;
    for (int i = 0; i < 10; ++i) {
        insert(head, random_range(1,7));
    }
    printList(head);
    removeDuplicates(head);
    printList(head);

    std::cout<<"Method 2: \n";
    Node * head1 = nullptr;
    for (int i = 0; i < 10; ++i) {
        insert(head1, random_range(1,7));
    }
    printList(head1);
    removeDuplicates1(head1);
    printList(head1);

    return 0;
}

