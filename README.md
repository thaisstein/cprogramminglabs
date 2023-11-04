# C Programming Labs

## Info
Laboratories related to the Unix and C Programming Class (Telecom SudParis - Institut Polytechnique de Paris) made in the first school semester of 2022.

## Content
- Comparison of slow and fast sorting algorithms (Lab 01 and 02)
- Linked lists (Lab 03)
- Binary trees (Lab 04)

## Reports
For the first and second labs we were asked to provide reports to compare the results of the sorting algorithms used, as seen below:

### Lab 01: 
- I coded two commonly taught slow sorting algorithms:** Bubble Sort, Insertion Sort and Selection Sort**. The analysis involved sorting random and reverse-ordered arrays of different sizes (10, 100, 1000, 10000, 100000) in five trials for each case, and the results were graphically presented for better understanding.
- In the first case, Bubble Sort is notably slower due to its high number of operations.
- Insertion Sort performs better than Selection Sort. In the second case with a reverse-ordered array, Insertion Sort's efficiency drops significantly, making it slower than both Bubble and Selection Sort, while Bubble Sort remains the slowest in both cases.
![Screen Shot 2023-11-04 at 5 12 47 PM](https://github.com/thaisstein/cprogramminglabs/assets/52481495/134ab4d5-cf0c-4988-aec2-a3add6c9289d)

### Lab 02:
- I coded two commonly taught _fast_ sorting algorithms: **Quick Sort and Heap Sort** with the same cases as before.
- In the first case, Heap Sort outperforms Quick Sort on average, especially for larger arrays. Both algorithms show similar performance for smaller arrays.
- In the second case with a reverse-ordered array, both algorithms take more time and have steeper slopes, with Quick Sort suffering from a poor pivot selection. Nevertheless, Heap Sort remains more efficient.
- Comparing these lab-coded algorithms to those from a previous lab, the "fast algorithms" outperform the previous ones, with a significant difference in slope, notably faster than the slowest algorithm, Bubble Sort.
- In the fourth graph, Selection Sort surpasses Insertion Sort, but all algorithms show increased slopes, indicating slower overall performance.

![Screen Shot 2023-11-04 at 5 16 08 PM](https://github.com/thaisstein/cprogramminglabs/assets/52481495/e2576181-330b-48da-9a3e-01ef4e32a7b3)

  
![Screen Shot 2023-11-04 at 5 16 14 PM](https://github.com/thaisstein/cprogramminglabs/assets/52481495/6e12df20-14fc-48e7-8350-646f69b6e9e2)

