# Push_swap

*This project has been created as part of the 42 curriculum by ayamhija.*

## Description

**Push_swap** is a sorting algorithm project that challenges you to sort data on a stack using a limited set of instructions while aiming for the lowest possible number of operations. The project involves implementing an efficient sorting algorithm that works with two stacks (A and B) and a specific set of operations.

### Project Goals
- Sort a stack of integers in ascending order (smallest on top)
- Minimize the number of operations used
- Implement an algorithm that scales efficiently (handles 100-500 numbers)
- Understand algorithm complexity and optimization techniques

### Key Features
- **Sorting algorithm**: Implements the Turk Algorithm (greedy approach) for large datasets
- **Optimized small sorts**: Hardcoded solutions for 2-5 elements
- **Bonus checker program**: Validates sorting operations
- **Error handling**: Robust input validation (duplicates, non-integers, out-of-range values)

### Performance Benchmarks
- **3 numbers**: ≤ 3 operations
- **5 numbers**: ≤ 12 operations
- **100 numbers**: < 700 operations (average: ~560-600)
- **500 numbers**: < 5500 operations (average: ~5000-5300)

---

## Instructions

### Compilation

```bash
# Compile push_swap
make

# Compile bonus checker
make bonus

# Clean object files
make clean

# Clean all compiled files
make fclean

# Recompile everything
make re
```

### Uage

#### Push_swap Program

```bash
# Basic usage
./push_swap 4 67 3 87 23

# With quoted string
./push_swap "4 67 3 87 23"

# Mixed format
./push_swap "4 67" 3 "87 23"

# Already sorted (no output)
./push_swap 1 2 3 4 5

# Error cases
./push_swap 1 2 3 2        # Error: duplicate
./push_swap 1 2 abc        # Error: non-integer
./push_swap 2147483648     # Error: out of range
```

#### Checker Program (Bonus)

```bash
# Verify push_swap output
./push_swap 3 2 1 | ./checker 3 2 1

# Manual input (type operations, then Ctrl+D)
./checker 3 2 1
sa
pb
pa
# Press Ctrl+D

# With echo
echo -e "sa\npb\npa" | ./checker 3 2 1

# Test from file
cat operations.txt | ./checker 3 2 1
```

### Availabe Operations

| Operation | Description                            |
| --------- | -------------------------------------- |
| sa        | Swap first 2 elements of stack A       |
| sb        | Swap first 2 elements of stack B       |
| ss        | sa and sb simultaneously               |
| pa        | Push top element from B to A           |
| pb        | Push top element from A to B           |
| ra        | Rotate stack A up (first becomes last) |
| rb        | Rotate stack B up                      |
| rr        | ra and rb simultaneously               |
| rra       | Reverse rotate A (last becomes first)  |
| rrb       | Reverse rotate B                       |
| rrr       | rra and rrb simultaneously             |


### Testing

```bash
# Test with random numbers
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l

# Test with checker
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG

# Count operations for different sizes
for i in {1..10}; do ARG=$(seq 1 100 | shuf | tr '\n' ' '); echo "Test $i: $(./push_swap $ARG | wc -l) operations"; done
```

### Algorithm Explanation

#### Turk Algorithm (Greedy Approach)

The project uses the Turk Algorithm, a greedy sorting algorithm optimized for the push_swap constraints:

1. **Phase 1: Push to B** - Push all elements except 3 from stack A to stack B
2. **Phase 2: Sort Three** - Sort the remaining 3 elements in stack A (easy with hardcoded patterns)
3. **Phase 3: Smart Push Back** - For each element in B:
    - Calculate the "cost" (number of operations) to push it to its correct position in A
    - Choose the element with the lowest cost
    - Execute the move
    - Repeat until B is empty
4. **Phase 4: Final Rotation** - Rotate stack A to ensure the minimum element is at the top

#### Cost Calculation

The algorithm calculates the cost by:
    - Finding the target position in stack A for each element in stack B
    - Calculating rotation costs for both stacks
    - Optimizing by using combined operations (rr, rrr) when both stacks rotate in the same direction
    - Always choosing the move with the minimum total cost

#### Small Number Optimization

For 2-5 elements, the algorithm uses optimized hardcoded solutions:
    - **2 numbers:** Single swap if needed
    - **3 numbers:** Maximum 2-3 operations using pattern matching
    - **4-5 numbers:** Push smallest to B, sort 3, push back

## Resources

### Tutorials & Articles
- [42 Cursus Push_swap Guide](https://42-cursus.gitbook.io/guide/2-rank-02/push_swap) - Comprehensive guide on push_swap strategies
- [Push_swap Tutorial (YouTube)](https://www.youtube.com/watch?v=wRvipSG4Mmk) - Visual explanation of sorting algorithms

### AI Usage

AI tools (Perplexity AI) were used for researching sorting algorithms and understanding the Turk Algorithm concept, exploring cost calculation strategies and greedy optimization approaches, and generating comprehensive test cases for validation. All information gathered was verified through multiple sources and tested extensively to ensure correctness and compliance with project requirements.
