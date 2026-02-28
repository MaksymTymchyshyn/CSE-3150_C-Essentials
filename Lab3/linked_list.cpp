#include "linked_list.h"
using namespace std;

LinkedList::LinkedList() : root(nullptr) {}

LinkedList::LinkedList(const LinkedList& fromLL) {
    if (nullptr == fromLL.root) {
        root = nullptr;
        return;
    }
    root = new Node(fromLL.root->data);
    Node* currentOld = fromLL.root;
    Node* newList = root;
    while (currentOld != currentOld->next) {
        newList->next = new Node(currentOld->next->data);
        currentOld = currentOld->next;
        newList = newList->next;
    }
    newList->next = newList;
}

LinkedList::~LinkedList() {
    Node* current = root;
    if (nullptr != root) {
        while (current != current->next) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        delete current;
    }
    root = nullptr;
}

void LinkedList::insertAtBeginning(int val) {
    if (nullptr == root) {
        root = new Node(val);
    } else {
        Node* newNode = new Node(val);
        newNode->next = root;
        root = newNode;
    }
}

void LinkedList::insertAtEnd(int val) {
    Node* newNode = new Node(val);
    if (!root) {
        root = newNode;
        return;
    }
    Node* current = root;
    while (current != current->next) {
        current = current->next;
    }
    current->next = newNode;
}

void LinkedList::deleteNodeNumber(int nodeNumber) {
    if (!root) return;
    if (0 == nodeNumber) {
        Node* temp = root;
        if (root == root->next) {
            root = nullptr;
        } else {
            root = root->next;
        }
        delete temp;
        return;
    }
    int count = 1;
    Node* lag = root;
    Node* current = root->next;
    while (current != current->next && count != nodeNumber) {
        count++;
        current = current->next;
        lag = lag->next;
    }
    if (count == nodeNumber) {
        lag->next = current->next;
        delete current;
    }
}

int LinkedList::getValueAt(int position) const {
    if (!root) return -1;
    if (0 == position) return root->data;
    
    int count = 0;
    Node* current = root;
    while (current != current->next && count < position) {
        count++;
        current = current->next;
    }
    return current->data;
}

int LinkedList::getSize() const {
    if (!root) return 0;
    if (root == root->next) return 1;
    
    int size = 1;
    Node* current = root;
    while (current != current->next) {
        size++;
        current = current->next;
    }
    return size;
}

Node* LinkedList::getFirstElement() const {
    return root;
}

Node* LinkedList::getLastElement() const {
    if (!root) return nullptr;
    Node* current = root;
    while (current != current->next) {
        current = current->next;
    }
    return current;
}

void* LinkedList::getAddressFromArray(int i) {
    return static_cast<void*>(nodeAddresses[i]);
}

void LinkedList::printAllNodeAddresses() {
    for (auto address : nodeAddresses) {
        cout << static_cast<void*>(address) << " ";
    }
    cout << endl;
}

void LinkedList::printTableNodesNextValue() {
    cout << " Node address         next-ptr             data" << endl;
    for (auto address : nodeAddresses) {
        cout << static_cast<Node*>(address) << " ";
        cout << static_cast<Node*>(address)->next << " ";
        cout << static_cast<Node*>(address)->data << endl;
    }
}

void LinkedList::copyAllNodesAddresses() {
    nodeAddresses.clear();
    if (getSize() > 0) {
        Node* current = root;
        while (current != current->next) {
            nodeAddresses.push_back(static_cast<void*>(current));
            current = current->next;
        }
        nodeAddresses.push_back(static_cast<void*>(current));
    }
}

void LinkedList::pointerJump(Node* head) {
    if (head && head->next && head != head->next) {
        head->next = head->next->next;
    }
}

void LinkedList::runPointerJumps() {
    for (auto address : nodeAddresses) {
        pointerJump(static_cast<Node*>(address));
    }
}

ostream& operator<<(ostream& os, const LinkedList& linkedList) {
    Node* current = linkedList.root;
    if (nullptr == linkedList.root) return os;
    
    while (current != current->next) {
        os << *current << " -> ";
        current = current->next;
    }
    os << *current;
    return os;
}

int checkPrefixSum(const LinkedList& list) {
    if (list.getSize() == 0) return 0;
    
    int prefixSum = 0;
    bool allPositive = true;
    bool allNegative = true;
    
    for (int i = 0; i < list.getSize(); i++) {
        prefixSum += list.getValueAt(i);
        if (prefixSum <= 0) allPositive = false;
        if (prefixSum >= 0) allNegative = false;
    }
    
    if (allPositive) return 1;
    else if (allNegative) return -1;
    else return 0;
}

void performPointerJumping(LinkedList& list) {
    list.copyAllNodesAddresses();
    int size = list.getSize();
    if (size <= 1) return;
    
    for (int round = 0; round < 32; round++) {
        bool changed = false;
        for (int i = 0; i < size; i++) {
            Node* current = static_cast<Node*>(list.getAddressFromArray(i));
            if (current && current->next && current != current->next) {
                Node* target = current->next;
                if (target->next != target) {
                    current->next = target->next;
                    changed = true;
                }
            }
        }
        if (!changed) break;
    }
}
