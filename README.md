*This project has been created as part of the 42 curriculum by \<jneris-d\>.*

## Description

The **push_swap** project consists of sorting a stack of integers using a limited set of operations and an auxiliary stack.  
The goal is not only to sort the numbers correctly, but also to **optimize the number of operations** used during the process.

The allowed operations are:

- **Swap**  
  Swaps the first two elements of a stack.

- **Push**  
  Takes the first element of one stack and pushes it onto the other stack.

- **Rotate**  
  Shifts all elements of a stack up by one position, moving the first element to the bottom.

- **Reverse rotate**  
  Shifts all elements of a stack down by one position, moving the last element to the top.

This project focuses heavily on algorithmic efficiency, especially for larger input sizes, where choosing the right sorting strategy is essential.

## Instructions

To compile the project, run make.
After compilation, execute the program by passing a list of integers as arguments:
./push_swap "5 8 2 6 0"

If all arguments are valid, the program will print the sequence of operations used to sort the stack. To count the total number of operations, you can pipe the output to wc -l

## Resources

To complete this project, I studied and applied several computer science concepts:
- Stack-based sorting algorithms and constrained-operation problem solving.
- Radix Sort and its adaptation for sorting using two stacks.
- Indexing and normalization techniques to optimize comparisons.
- Algorithmic optimization focused on minimizing the number of operations.

These topics were explored through:
- Educational tutorials and explanations available on YouTube.

Additionally, AI assistance was used as a learning and debugging tool to:
- Clarify algorithmic concepts.
- Improve code structure.
- Discuss optimization strategies and memory management.