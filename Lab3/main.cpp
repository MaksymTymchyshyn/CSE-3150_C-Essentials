#include <iostream>
#include "linked_list.h"

using namespace std;

int main() {
    cout << "\nLab Week 3 - Linked List Demonstrations\n" << endl;
    
    // 1. Basic operations
    cout << "1. Basic Operations:" << endl;
    LinkedList list;
    list.insertAtEnd(-1);
    list.insertAtEnd(1);
    list.insertAtEnd(1);
    cout << "   Created list: " << list << endl;
    cout << "   Size: " << list.getSize() << endl;
    
    // 2. Copy constructor
    cout << "\n2. Copy Constructor:" << endl;
    LinkedList copy(list);
    list.insertAtEnd(99);
    cout << "   Original: " << list << endl;
    cout << "   Copy:     " << copy << endl;
    
    // 3. Delete node
    cout << "\n3. Delete Node:" << endl;
    LinkedList delList;
    delList.insertAtEnd(-1);
    delList.insertAtEnd(1);
    delList.insertAtEnd(1);
    delList.insertAtEnd(-1);
    delList.insertAtEnd(0);
    cout << "   Before: " << delList << endl;
    delList.deleteNodeNumber(0);
    cout << "   After deleting node 0: " << delList << endl;
    
    // 4. Prefix sum
    cout << "\n4. Prefix Sum Checker:" << endl;
    LinkedList pos;
    pos.insertAtEnd(1);
    pos.insertAtEnd(2);
    pos.insertAtEnd(3);
    cout << "   List " << pos << " -> Result: " << checkPrefixSum(pos) << " (1=positive)" << endl;
    
    LinkedList neg;
    neg.insertAtEnd(-1);
    neg.insertAtEnd(-2);
    neg.insertAtEnd(-3);
    cout << "   List " << neg << " -> Result: " << checkPrefixSum(neg) << " (-1=negative)" << endl;
    
    LinkedList mix;
    mix.insertAtEnd(1);
    mix.insertAtEnd(-2);
    mix.insertAtEnd(1);
    cout << "   List " << mix << " -> Result: " << checkPrefixSum(mix) << " (0=mixed)" << endl;
    
    // 5. Pointer jumping
    cout << "\n5. Pointer Jumping:" << endl;
    LinkedList ptrList;
    for (int i = 0; i < 5; i++) {
        ptrList.insertAtEnd(i);
    }
    
    cout << "   Before: " << ptrList << endl;
    cout << "   Last node points to itself: " << (ptrList.getLastElement()->next == ptrList.getLastElement() ? "Yes" : "No") << endl;
    
    performPointerJumping(ptrList);
    
    cout << "   After pointer jumping:" << endl;
    cout << "   First node now points to last node: " << (ptrList.getFirstElement()->next == ptrList.getLastElement() ? "Yes" : "No") << endl;
    
    // 6. Answer to Question 7
    cout << "\n6. Question 7 - Combining Algorithms:" << endl;
    cout << "   We can check prefix sums in O(n) time first, then perform" << endl;
    cout << "   pointer jumping in O(n log n) time on the same structure." << endl;
    cout << "   The nodeAddresses vector preserves original addresses," << endl;
    cout << "   allowing pointer jumping without copying the list." << endl;
    cout << "   Total complexity: O(n log n)." << endl;
    
    cout << "\n✓ All demonstrations complete. Run ./test_linked_list for tests.\n" << endl;
    
    return 0;
}
