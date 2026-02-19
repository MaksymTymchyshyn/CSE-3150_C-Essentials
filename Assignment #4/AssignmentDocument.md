# Assignment #4: Python Style Integers

Name: Maksym Tymchyshyn 
Assignment: Assignment #4: Python Style Integers

## Solution Description

1. **Default Constructor** - Initializes PyLongObject to value 0

2. **Parameterized Constructors** - Create integers from `int` or `long long` values

3. **Copy Constructor** - Deep copy with independent memory allocation for digit arrays

4. **Destructor** - Deallocates dynamically allocated `digitsBase30` array to prevent memory leaks

5. **Addition Operator** - Implements `operator+` handling all sign combinations (positive+positive, positive+negative, negative+negative)

6. **Base-2^30 Representation** - Uses digit array structure for arbitrary precision (currently optimized for `long long` range)

## System Architecture

```
┌───────────────────────────────────────────────┐
│            PyLongObject Class               │
├───────────────────────────────────────────────┤
│  Private Members:                           │
│    • int sign          (+1 or -1)           │
│    • int numDigits     (base-2^30 count)    │
│    • bool fitsInLongLong  (optimization)    │
│    • long long iValue  (direct storage)     │
│    • unsigned* digitsBase30  (digit array)  │
├───────────────────────────────────────────────┤
│  Public Interface:                          │
│    • PyLongObject()              [default]  │
│    • PyLongObject(int/long long) [convert]  │
│    • PyLongObject(const &)       [copy]     │
│    • ~PyLongObject()             [destruct] │
│    • operator=(const &)          [assign]   │
│    • operator+(const &)          [add]      │
│    • operator==/!=               [compare]  │
└───────────────────────────────────────────────┘
         │
         │ uses
         ▼
┌───────────────────────────────────────────────┐
│         Memory Management Helpers           │
├───────────────────────────────────────────────┤
│  • allocateDigits(size)                     │
│  • deallocateDigits()                       │
│  • copyFrom(const PyLongObject&)            │
└───────────────────────────────────────────────┘
```

## Use Flow Diagram

```
┌─────────────────────────────────┐
│  Create PyLongObject Instance   │
└────────┬────────────────────────┘
         │
         ▼
   [Constructor Called]
         │
         ├──► Default: Set iValue=0, sign=1
         │
         ├──► From int/long: Store in iValue
         │
         └──► Copy: Deep copy all members
                    └─► Allocate new digitsBase30
                        Copy digit values
         │
         ▼
┌─────────────────────────────────┐
│   Perform Operations (e.g., +)  │
└────────┬────────────────────────┘
         │
         ▼
   [Addition Algorithm]
         │
         ├──► Same sign? Add magnitudes
         │
         └──► Diff sign? Subtract magnitudes
         │
         ▼
   [Create result object]
         │
         ▼
┌─────────────────────────────────┐
│    Object Goes Out of Scope     │
└────────┬────────────────────────┘
         │
         ▼
   [Destructor Called]
         │
         └──► deallocateDigits()
                └─► if (digitsBase30) delete[]
         │
         ▼
       [End]
```
