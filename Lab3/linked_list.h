#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <vector>

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(this) {}
    
    friend std::ostream& operator<<(std::ostream& os, const Node& node) {
        os << node.data;
        return os;
    }
};

class LinkedList {
    friend std::ostream& operator<<(std::ostream& os, const LinkedList& linkedList);
    Node* root;
    std::vector<void*> nodeAddresses;

public:
    LinkedList();
    LinkedList(const LinkedList& fromLL);
    ~LinkedList();
    
    void insertAtBeginning(int val);
    void insertAtEnd(int val);
    void deleteNodeNumber(int nodeNumber);
    int getValueAt(int position) const;
    int getSize() const;
    Node* getFirstElement() const;
    Node* getLastElement() const;
    void* getAddressFromArray(int i);
    void printAllNodeAddresses();
    void printTableNodesNextValue();
    void copyAllNodesAddresses();
    void pointerJump(Node* head);
    void runPointerJumps();
};

int checkPrefixSum(const LinkedList& list);
void performPointerJumping(LinkedList& list);

#endif
