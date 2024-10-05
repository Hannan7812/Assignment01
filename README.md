# Approach
## Task 1
The task was to simulate a process scheduling algorithm using linked lists. The specific data structure I chose was a circular Linked List. The circular linked list was chosen because the last process in the list can point to the first process in the list. This allows for a continuous loop of processes. The circular linked list is also useful because it is easy to add and remove nodes from the list. This is important for a process scheduling algorithm because processes are constantly being added and removed from the list. The circular linked list is also useful because it is easy to traverse the list. This is important for a process scheduling algorithm because processes need to be traversed in order to determine which process to run next. Overall, the circular linked list is a good data structure for a process scheduling algorithm because it is easy to add and remove nodes, easy to traverse, and allows for a continuous loop of processes. In order to manage adding processes and executing the loop, a seperate driver function was created.
## Task 2
The task was to check the primality of 1024 bit numbers. 1024 bit numbers are unusually long. For this task not only did I have to figure out a way to store that number but I also had to define the basic arithmetic operations myself (+, -, *, /, %, ^). The primality test used was the [Miller Rabin primality test](https://www.google.com/url?sa=t&source=web&rct=j&opi=89978449&url=https://en.wikipedia.org/wiki/Miller%25E2%2580%2593Rabin_primality_test&ved=2ahUKEwjHiZrr-PWIAxUWzwIHHRUhF5wQFnoECAsQAQ&usg=AOvVaw16qHuNnir2cDsFqhy19CwP). I decided to define the arithmetic operations as we do by hand i.e long multiplication and long division. This resulted in exponential time complexity of the code such that when multiple divisions and multiplications had to be done, which is often the case in Miller Rabin primality test, the algorithm took more and more time to complete. Although this may seem like a disadvantage but for me this was the right choice to make because this way I know the complete working of the algorithm and have complete faith in its correctness. All the arithmetic operations were tested on multiple test cases and cross checked and all of them stood this test.

# Assumptions
## Task 1
- The processes are added to the list in the order they are created.
- The calling entity has access to the driver function.
- There is no priority of one process over the other. All the processes are inserted sequentially.

## Task 2
- It is assumed that the input will be a positive integer.
- There is no restriction on the length of the input number i.e it can be any length and the algorithm accomodates numbers which even exceed 1024 bits.
- It is not strictly necessary to store 64 bit numbers in each node. The node can hold 32 bit numbers as well.
- It is also assumed that there is no time restriction for the algorithm since very large numbers can take alot of time.

# Challenges
## Task 1
- How to manage the removal of a process from the list once it has completed its execution time.

## Task 2
- How to store 1024 bit numbers.
- The zeroes in the middle of the number such that they are occur at the start of their respective node were difficult to account for since the 'int' data type ignores leading zeroes.
- How to define the basic arithmetic operations for 1024 bit numbers.
- How to prevent overflow in the arithmetic operations.
- How to define comparisons for 1024 bit numbers.
- How to do exception handling for the arithmetic operations.
- How to implement the Miller Rabin primality test using the custom arithmetic operations.

## GitHub Link
[Github Repository](https://github.com/Hannan7812/Assignment01)

