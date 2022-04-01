# SortingAlgorithms

## How to run:

1. Clone this repository 
2. Go to the directory that you want this program in and type "git clone " followed by the "HTTPS" link you can find from the "Code" button
3. Enter the "SortingAlgorithms" folder using ```cd SortingAlgorithms```
4. Compile using this command: ```g++ main.cpp iSortr.cpp iSorti.cpp myQuickSort.cpp -o Sorting.exe```
5. In terminal, type: ```./Sorting.exe``` to run

### Alternatively:
1. Download the files of this repository by zipping it, and then open that folder through file explorer
2. If you are on a linux based shell: ```g++ -o Sorting iSortr.cpp isorti.cpp myQuickSort.cpp main.cpp``` should compile and ```./Sorting``` should run it
3. If you are on windows: ```gcc iSortr.cpp isorti.cpp myQuickSort.cpp main.cpp -o Sorting.exe``` should compile and ```Sorting.exe```

## How it works:

I have 4 key components to this program:
1. Insertion Sort - Iterative Implementation
2. Insertion Sort - Recursive Implementation
3. Binary Search
4. Quicksort 

* Given a menu where you choose which sorting algorithm you would like to run
* Asked how many terms you want to make a list out of, and then based on the input a random list of integers is created
  - If you said less than 100, the list is printed out, if it is more, to not crowd command prompt it isn't printed out
* Time to sort is also printed out
Important note:
* My quicksort takes in a void pointer for the list, meaning that it can handle any type of data, whether it be ints, doubles, or even custom structs
  - This dnyamic technique mimics the in-built quicksort function and helped me understand how the C++ native function was made
  - Even when 1000000 elements are made, it still takes an extremely small amount of time to run, showing how efficient it is
