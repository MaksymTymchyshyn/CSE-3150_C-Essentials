# Lab Week 2: Balanced Lists

Name: Maksym Tymchyshyn 
Lab: Lab Week 2: Balanced Lists

## Solution Description

1. **Generate sequences** of n +1s and n -1s (e.g., representing opening/closing parentheses)

2. **Shuffle randomly** using Fisher-Yates algorithm implemented with `std::rand()`

3. **Validate** by computing prefix sums and checking all are non-negative (well-balanced)

4. **Count ratio** of well-balanced sequences to total generated over many trials

5. **Verify convergence** to theoretical Catalan number ratio: 1/(n+1)

## System Architecture

```
┌─────────────────────────────────────────┐
│         Main Experiment Runner          │
│  (Runs trials, collects statistics)     │
└──────────────┬──────────────────────────┘
               │
               ▼
┌─────────────────────────────────────────┐
│        Core Algorithm Module            │
├─────────────────────────────────────────┤
│  • generateSequence(n)                  │
│    → [1,1,...,1,-1,-1,...,-1]          │
│                                         │
│  • fisherYatesShuffle(sequence)         │
│    → Randomly permuted sequence         │
│                                         │
│  • hasNonNegativePrefixSums(sequence)   │
│    → true/false (well-balanced?)        │
└─────────────────────────────────────────┘
```

## Use Flow Diagram

```
Start
  │
  ▼
[Generate sequence: n ones, n negative ones]
  │
  ▼
[Apply Fisher-Yates shuffle]
  │
  ▼
[Compute prefix sums: s₀=0, sᵢ=sᵢ₋₁+aᵢ]
  │
  ├──► [Any sᵢ < 0?] ──Yes──► [Reject: Not well-balanced]
  │                              │
  No                             │
  │                              │
  ▼                              │
[Accept: Well-balanced]          │
  │                              │
  └──────────────┬───────────────┘
                 │
                 ▼
          [Record result]
                 │
                 ▼
        [More trials?] ──Yes──► [Repeat]
                 │
                 No
                 │
                 ▼
  [Calculate ratio and compare to 1/(n+1)]
                 │
                 ▼
               End
```
