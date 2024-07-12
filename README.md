<p align="center">
<img src="https://github.com/daviduartecf/push_swap/blob/main/swap.png" style="width: 12%;">
</p>
<h1 align="center">PUSH SWAP</h1>

<p align="center"> <strong>push_swap</strong> is a project from the 42 school designed to sort a stack of integers using a predefined set of operations. The main objective is to sort the stack with the fewest number of operations.</p>

<p align="center">
  <a href="https://github.com/daviduartecf/push_swap/blob/main/en.subject.pdf">
    <img src="https://emojicdn.elk.sh/📖" width="20" alt="Book emoji">
    <br>
    Read the subject
  </a>
</p>

## Benchmark

To validate this project, the program must perform efficient sorts within specific operation limits:
- For sorting **100 random numbers**: fewer than **700 operations**.
- For sorting **500 random numbers**: fewer than **5500 operations**.

<br>

<p align="center">
  <img src="push_swap.gif" alt="Example GIF">
</p>

## Algorithm

The algorithm used in this project can be described as an enhanced insertion sort adapted for two stacks. The sorting process involves moving elements between two stacks (`a` and `b`) and reinserting them in a sorted manner. Key steps include:

1. **Moving Elements to Stack B**: Elements are moved from stack `a` to stack `b` until only three elements remain in stack `a`. The function `cheapest` is used to determine the element in stack `a` that can be moved to stack `b` with the least cost (number of operations), and `move_elem` performs the move.

2. **Sorting the Remaining Elements in Stack A**: The three remaining elements in stack `a` are sorted using the `sort_three` function.

3. **Reinserting Elements from Stack B to Stack A**: The elements in stack `b` are then reinserted into stack `a` in their correct positions. The function `cheapest_a` helps find the optimal position in stack `a` to insert each element from stack `b`, minimizing the number of operations. The actual insertion is done by `insert_elem`.

4. **Final Adjustment**: After reinserting all elements, the algorithm ensures stack `a` is fully sorted by performing necessary rotations (`ra` or `rra`).

This algorithm involves careful calculation of the most **cost-effective operations** to minimize the total number of moves, making it an **optimized approach** for sorting using the allowed operations.

## Installation and Usage intructions
1. Clone the repository:
    ```sh
    git clone https://github.com/daviduartecf/push_swap.git
    ```
2. Compile the project:
    ```sh
    make
    ```
3. Run the executable:
    ```sh
    ./push_swap "<random list of numbers>"
    ```
4. Visualizer (optional)
   <br>
   For better understanding and visualization of the sorting process, you can use a visualizer tool. Clone the repository of a fellow student who created a visualizer:
     ```sh
    git clone https://github.com/o-reo/push_swap_visualizer
    ```
    Follow the instructions in the visualizer's README to set it up and use it with your push_swap program.
