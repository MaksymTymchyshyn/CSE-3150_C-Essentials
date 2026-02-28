#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linked_list.h"

TEST_CASE("LinkedList - Basic Operations") {
    LinkedList list;
    CHECK(list.getSize() == 0);
    
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    CHECK(list.getSize() == 3);
    CHECK(list.getValueAt(0) == 1);
    CHECK(list.getValueAt(1) == 2);
    CHECK(list.getValueAt(2) == 3);
    
    LinkedList list2;
    list2.insertAtBeginning(1);
    list2.insertAtBeginning(2);
    CHECK(list2.getValueAt(0) == 2);
    CHECK(list2.getValueAt(1) == 1);
}

TEST_CASE("LinkedList - Copy Constructor") {
    LinkedList list1;
    list1.insertAtEnd(-1);
    list1.insertAtEnd(1);
    list1.insertAtEnd(1);
    
    LinkedList list2(list1);
    CHECK(list2.getSize() == 3);
    CHECK(list2.getValueAt(0) == -1);
    CHECK(list2.getValueAt(1) == 1);
    CHECK(list2.getValueAt(2) == 1);
    
    list1.insertAtEnd(99);
    CHECK(list1.getSize() == 4);
    CHECK(list2.getSize() == 3);
}

TEST_CASE("LinkedList - Delete Node") {
    LinkedList list;
    list.insertAtEnd(-1);
    list.insertAtEnd(1);
    list.insertAtEnd(1);
    list.insertAtEnd(-1);
    list.insertAtEnd(0);
    
    list.deleteNodeNumber(0);
    CHECK(list.getSize() == 4);
    CHECK(list.getValueAt(0) == 1);
    
    list.deleteNodeNumber(2);
    CHECK(list.getSize() == 3);
    CHECK(list.getValueAt(0) == 1);
    CHECK(list.getValueAt(1) == 1);
    CHECK(list.getValueAt(2) == 0);
}

TEST_CASE("LinkedList - Last Node Points to Itself") {
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    
    Node* last = list.getLastElement();
    CHECK(last->next == last);
    CHECK(last->data == 3);
}

TEST_CASE("Prefix Sum - Positive") {
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    CHECK(checkPrefixSum(list) == 1);
}

TEST_CASE("Prefix Sum - Negative") {
    LinkedList list;
    list.insertAtEnd(-1);
    list.insertAtEnd(-2);
    list.insertAtEnd(-3);
    CHECK(checkPrefixSum(list) == -1);
}

TEST_CASE("Prefix Sum - Mixed") {
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(-2);
    list.insertAtEnd(1);
    CHECK(checkPrefixSum(list) == 0);
}

TEST_CASE("Prefix Sum - Edge Cases") {
    LinkedList empty;
    CHECK(checkPrefixSum(empty) == 0);
    
    LinkedList single;
    single.insertAtEnd(5);
    CHECK(checkPrefixSum(single) == 1);
    
    LinkedList singleNeg;
    singleNeg.insertAtEnd(-5);
    CHECK(checkPrefixSum(singleNeg) == -1);
}

TEST_CASE("Pointer Jumping - Basic") {
    LinkedList list;
    list.insertAtEnd(-1);
    list.insertAtEnd(1);
    list.insertAtEnd(1);
    list.insertAtEnd(-1);
    list.insertAtEnd(0);
    
    list.copyAllNodesAddresses();
    Node* first = list.getFirstElement();
    Node* last = list.getLastElement();
    
    CHECK(first->data == -1);
    CHECK(last->data == 0);
    CHECK(last->next == last);
}

TEST_CASE("Pointer Jumping - All Point to Last") {
    LinkedList list;
    for (int i = 0; i < 5; i++) {
        list.insertAtEnd(i);
    }
    
    Node* last = list.getLastElement();
    CHECK(last->data == 4);
    CHECK(last->next == last);
    
    performPointerJumping(list);
    
    Node* first = list.getFirstElement();
    CHECK(first->next == last);
}

TEST_CASE("Pointer Jumping - runPointerJumps Method") {
    LinkedList list;
    list.insertAtEnd(0);
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    
    list.copyAllNodesAddresses();
    Node* last = list.getLastElement();
    
    for (int i = 0; i < 3; i++) {
        list.runPointerJumps();
    }
    
    Node* first = list.getFirstElement();
    CHECK(first->next == last);
}

TEST_CASE("Integration - Prefix Sum with Pointer Jumping") {
    LinkedList list;
    list.insertAtEnd(-1);
    list.insertAtEnd(1);
    list.insertAtEnd(1);
    list.insertAtEnd(-1);
    list.insertAtEnd(2);
    
    int prefixResult = checkPrefixSum(list);
    CHECK(prefixResult == 0);
    
    performPointerJumping(list);
    
    Node* first = list.getFirstElement();
    Node* last = list.getLastElement();
    CHECK(first->next == last);
    CHECK(last->data == 2);
}
