# Lab Week 3: Linked Lists

Name: Maksym Tymchyshyn  
Lab: Lab Week 3: Linked Lists

## Solution Description

1. **LinkedList Class**: Implementation based on provided base code with Node structure where last node points to itself. Uses root pointer and nodeAddresses vector for pointer jumping operations.

2. **Delete ith Node**: Function `deleteNodeNumber(int i)` removes node at 0-indexed position i. Maintains last node self-reference property. Handles edge cases (empty list, single node, middle nodes).

3. **Copy Constructor**: Deep copy implementation that creates independent duplicate preserving self-referencing last node structure. Original and copy remain isolated after modifications.

4. **Prefix Sum Checker**: Function `checkPrefixSum()` traverses list computing running sum until reaching self-referencing last node. Returns 1 if all prefix sums positive, -1 if all negative, 0 if mixed.

5. **Pointer Jumping**: Uses `nodeAddresses` vector to store original node addresses. Function `performPointerJumping()` applies iterative doubling algorithm where each node jumps forward, eventually pointing all nodes to the last element (O(n log n) complexity).

6. **Algorithm Combination**: Prefix sum checking (O(n)) and pointer jumping (O(n log n)) can be performed on same structure sequentially. The nodeAddresses vector preserves original pointers, allowing operations without copying the list (total O(n log n) complexity).

## System Architecture

```
┌─────────────────────────────────────────────┐
│          LinkedList Class                   │
├─────────────────────────────────────────────┤
│ Private:                                    │
│  - Node* root                              │  ← Points to first node
│  - vector<void*> nodeAddresses             │  ← Stores node pointers
├─────────────────────────────────────────────┤
│ Public Methods:                             │
│  + LinkedList()                            │
│  + ~LinkedList()                           │
│  + LinkedList(const LinkedList&)           │  ← Copy Constructor
│  + insertAtBeginning(int val)              │
│  + insertAtEnd(int val)                    │
│  + deleteNodeNumber(int i)                 │  ← Delete ith Node
│  + getValueAt(int i) -> int                │
│  + getSize() -> int                        │
│  + getFirstElement() -> Node*              │
│  + getLastElement() -> Node*               │
│  + copyAllNodesAddresses()                 │
│  + runPointerJumps()                       │
│  + operator<< (friend)                     │
└──────────────┬──────────────────────────────┘
               │
               │ uses
               ▼
    ┌─────────────────────┐
    │  Node Struct        │
    ├─────────────────────┤
    │  + int data         │
    │  + Node* next       │  ← Last node: next points to itself
    │                     │
    │  Node(int val):     │
    │    next(this) {}    │  ← Constructor sets self-reference
    └─────────────────────┘

┌─────────────────────────────────────────────┐
│      Standalone Algorithm Functions         │
├─────────────────────────────────────────────┤
│  • checkPrefixSum(const LinkedList&)        │
│    → Returns: 1 / -1 / 0                    │
│                                             │
│  • performPointerJumping(LinkedList&)       │
│    → Uses nodeAddresses vector              │
│    → Makes all nodes point to last          │
└─────────────────────────────────────────────┘
```

## Use Flow Diagram

```
Start
  │
  ▼
[Create LinkedList with root=nullptr]
  │
  ├──────────────────┬──────────────────┬──────────────────┐
  │                  │                  │                  │
  ▼                  ▼                  ▼                  ▼
[insertAtEnd]  [deleteNodeNumber] [Copy Constructor] [checkPrefixSum]
  │                  │                  │                  │
  │                  │                  │                  ▼
  │                  │                  │            [Compute running sum]
  │                  │                  │            [Stop at self-reference]
  │                  ▼                  ▼                  │
  │            [Remove ith node]  [Deep copy with         ▼
  │            [Update links]     self-referencing]  [All positive?] → Yes → Return 1
  │            [Maintain last->   [last node]             │
  │             next = last]           │                 No
  │                  │                  │                  │
  └──────────────────┴──────────────────┘                  ▼
               │                                    [All negative?] → Yes → Return -1
               │                                           │
               ▼                                          No
[copyAllNodesAddresses() stores nodes in vector]           │
  │                                                        ▼
  ▼                                                   Return 0 (mixed)
[performPointerJumping calls runPointerJumps()]
  │
  ▼
[Iteration 1: Each node jumps to next->next]
  │
  ▼
[Iteration 2: Each node jumps over 4 nodes]
  │
  ▼
[Continue until all point to last (O(log n) iterations)]
  │
  ▼
[All nodes now point to self-referencing last node]
  │
  ▼
End
```
