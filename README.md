# HW1_Problem_3
In this problem we had to implement insertionSort, selectionSort and bubbleSort for a 2D matrix, 
which was challenging since we had to take into account the array wasn’t linear and we needed to manipulate and 
traverse the array along the 2d structure and keep track of the location as to not go beyond limits of the array. 
Since all 3 of these sorts are quadratic for a linear array as they required 2 for loops, 
we would need a third for loop for 2d matrix. In order to traverse entire grid 
all the sorts required row*column steps to begin with. (I’ve retraced steps for each sort on a normal array 
and then tried to see how to recreate such steps on 2D matrix). 
Each sort for the matrix required 2 variables, one for the row and one for the column.
Depending on the sort we needed to calculate the position from which to start the traversal, and in order to calculate the row
we would need to take the first for loop counter and divide it by number of columns and in order to get the column number 
we would need to take that counter and mod it by the number of columns. Using this calculation I used it in this way:

for bubbleSort:
I used 2 pointers to keep track of adjacent elements, since it made it easier to swap these elements when 
they were not in proper positions and it also looked cleaner than using double brackets. 
The things to watch for was keeping track whenever we reached the edge of particular row and needed to compare two elements 
which were on different rows. I set up a few if statements to check for such cases.

for selectionSort:
 We traverse array from left to right and from top to bottom by setting the first element as a minimum 
 and swapping whenever we find a smaller element. Here we had to calculate starting position at each new iteration 
 and make sure we stay within the limits of the grid
 
for insertionSort
 I think this was the trickiest sort for 2D matrix since it requires us to move all the elements bigger than particular element
 to the right and it required some arithmetic to calculate position in the array where to move each element. 
 In addition there were few cases to account for in order to traverse properly, such as when we are at a starting row, 
 or the first row of the matrix or any other row. In order to properly move each element we had to calculate row and column
 and make sure we don’t go over the borders of the matrix. 


