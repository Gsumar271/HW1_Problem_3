/*
By Yevgeniy Sumaryev
3/20/21
*/
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;

//function which swaps 2 pointers
void swap(int *xp, int *yp){
    
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//this notation allows us to pass
//2D array into a function
template <size_t rows, size_t cols>
void insertionSort2D(int (&arr)[rows][cols]){

    cout <<"insertionSort2D is called \n";

    //declare variables
    int startRow;
    int startCol;
    int total = rows*cols;
    int i, j;

    int insertKey;
    bool insert;

     //sort the matrix
     //by starting at second position
     //all the way to the last position
    for (int t = 1; t < total; t++)
    {  
        //tells us at which row to start
        startRow = t / cols;
        //tells at which column to start
        startCol = t % cols;

        //start at this row
        i = startRow;
        insert = true;

        // assign the starting position in array
        //to the variable insertkey
        insertKey = arr[startRow][startCol];

        //traverse array checking each element
        while(i >= 0 && insert)
        {
            //check these 3 cases:
            //1.we are on first row, i == 0
            //2.we are at starting row, i == startRow
            //3.we are at neither
            //case 1:
            //we are at the first row
            if (i == 0)
            {   
                //if we are also at 
                //the starting row
               if(i == startRow)
                   j = startCol;
                else 
                    j = cols-1;
                
                //if first row, traverse as in regular insertion sort
                while(j > 0 && arr[i][j-1] > insertKey){
                    arr[i][j] = arr[i][j-1];
                    j--;
                }
 
                 //this is the last row to traverse
                 //so we are done
                 break;
            }
            
            //if we are not in the first row
            else 
            {
                //case 2:
                //make j= startCol if our row is
                //startRow
                if (i == startRow)
                    j = startCol;
                //case 3:
                //make j=last column otherwise 
                else
                    j = cols - 1;
               
               //keep traversing row j while insert = true
               //and we havent reached first column
                while (j >= 0 && i > 0 && insert)
                {
                    //if we reached 1st element
                    //of this row, compare it
                    //with last element of previous row
                    if(j == 0){
                        if(arr[i-1][cols-1] > insertKey){
                            arr[i][j] = arr[i-1][cols-1];
                            //j = cols - 1;
                            j--;
                            i--;
                        }
                        //if insertkey is no longer smaller
                        //than left element, stop traversing array
                        else{
                            insert = false;
                        }
                    }
                    //if we didnt reach 1st element of current row
                    //traverse the row as normal
                    else{
                        if(arr[i][j-1] > insertKey){
                            arr[i][j] = arr[i][j-1];
                            j--;
                        }
                        //if insertKey is larger than
                        //left element, stop traversing
                        else{
                            insert = false;
                        }
                    }
                }
                
            }     
        }
        //after i loop
        //insert key into proper spot
        arr[i][j] = insertKey; 

    } 
}

//this notation allows us to pass
//2D array into a function
template <size_t rows, size_t cols>
void selectionSort2D(int (&arr)[rows][cols]){
    
    cout <<"selectionSort2D is called \n";
    int remainderRow, remainderCol;
    int startRow, startCol;
    int total = rows*cols;

    //Use a variable named min
    //that keeps track of minimum value
    //in each 2D array iteration 
    int min;

     //sort the matrix
    for (int t = 0; t < total - 1; t++)
    {  
        //tells us at which row 
        //to start checking
        startRow = t / cols;
        
        //tells us at which col
        //to start checking
        startCol = t % cols;

        //designate first element as min
        min = arr[startRow][startCol];
        for (int i = startRow; i < rows; i++)
        {
            //if this is a starting row
            //start at where startingCol is
            if (i == startRow){
                for (int j = startCol; j < cols; j++)
                {
                    //if current value is less than minimum
                    //swap values
                    if (arr[i][j] < min) {
                        min = arr[i][j];
                        swap(arr[i][j], arr[startRow][startCol]); 
                    }
                }
            }
            //else traverse row as normal
            else {
                for (int j = 0; j < cols; j++)
                { 
                    //if current value is less than minimum
                    //swap values
                    if (arr[i][j] < min) {
                        min = arr[i][j];
                        swap(arr[i][j], arr[startRow][startCol]); 
                    }                   
                  //  cout <<  arr[i][j] << " ";
                }
            }  
        }     
    }   

}

//this notation allows us to pass
//2D array into a function
template <size_t rows, size_t cols>
void bubbleSort2d(int (&arr)[rows][cols]){
    cout <<"bubblesort2D is called \n";

    int remainderRow;
    int remainderCol;
    int total = rows*cols;

    //declare a pointer 
    //to keep track of 2 adjacent elements
    //need when traversing array
    //since 2D matrix structure may not be contigious
    int* curr;
    int* prev;

     //sort the matrix
    for (int t = total-1; t > 0; t--)
    {  
        //tells us how much rows left
        remainderRow = t / cols;
        //tells us how much columns left
        remainderCol = t % cols;

        for (int i = 0; i < remainderRow + 1; i++)
        {
            //if last row
            if (i == remainderRow)
            {
                //traverse the last remaining columns
                for (int j = 1; j <= remainderCol; j++)
                {   
                    prev = &arr[i][j-1];
                    curr = &arr[i][j];
                    //if current value is less than previous value
                    //swap values
                    if (*curr < *prev)
                        swap(curr, prev);
                 //   cout <<  arr[i][j] << " ";
                }
              //  cout << endl;
              //  cout << endl;
            }
            //traverse the columns
            else
            {
                for (int j = 1; j <= cols+1; j++)
                {   
                    prev = &arr[i][j-1];
                    //if the last column is reached
                    //move the curr pointer to next row
                    //since this is not the last row 
                    //it's ok to move ptr
                    if(j == cols+1)
                        curr = &arr[i+1][0];
                    else
                        curr = &arr[i][j];
                    
                    //if current value is less than previous value
                    //swap values
                    if (*curr < *prev)
                     swap(curr, prev);
                  //  cout <<  arr[i][j] << " ";
                }
               // cout << endl;
                
            }  
           // cout << endl;
        }
        
    }
    
}




int main() {

    int row = 4;
    int col = 4;

    int arr[4][4];
    int total = row*col;
    int totalNums= 90; 

    int remainderRow;
    int remainderCol;

    //declare a pointer 
    //to keep track of 2 adjacent elements
    //need when traversing array
    //if 2D matrix structure may not be contigious
    int* curr;
    int* prev;

    //build the matrix 
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = rand() % 100 + 1;
           // arr[i][j] = totalNums--;
        }

    //print the matrix 
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
        {
           cout <<  arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    selectionSort2D(arr);

    //print the matrix 
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
        {
           cout <<  arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    //randomize the matrix again
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = rand() % 100 + 1;
           // arr[i][j] = totalNums--;
        }
   
   
    bubbleSort2d(arr);
    
    //print the matrix 
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
        {
           cout <<  arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    //randomize the matrix 
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = rand() % 100 + 1;
           // arr[i][j] = totalNums--;
        }
    
    insertionSort2D(arr);

    //print the matrix 
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
        {
           cout <<  arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}

