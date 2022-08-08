#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining all functions
void swap(int *, int *);
void display(int *, int);
void insert(int *, int, int, int);
void delete (int *, int, int);
void reverse(int *, int);
void shift_left(int *, int);
void shift_right(int *, int);
void search(int *, int, int);
void sort(int *, int);
void merge(int *, int *, int, int);
void rm_duplicate(int *, int);
void scnd_largest(int *, int);
int freq(int *, int, int);

// main function
int main()
{
    int length = 6;
    int ar[6] = {1, 3, 3, 3, 5};
    // print the array
    printf("Array before any operation: ");
    display(ar, length);
    printf("\n");
    // insert new element
    printf("After inserting a new element: ");
    insert(ar, length, 9, 2);
    display(ar, length);
    printf("\n");
    // delete an element
    printf("After deleting an element: ");
    delete (ar, length, 4);
    display(ar, length);
    printf("\n");
    // reverse the array
    printf("After reversing the array: ");
    reverse(ar, length);
    display(ar, length);
    printf("\n");
    // left shift the array
    printf("After shifting the array left: ");
    shift_left(ar, length);
    display(ar, length);
    printf("\n");
    // left right the array
    printf("After shifting the array right: ");
    shift_right(ar, length);
    display(ar, length);
    printf("\n");
    // search element in un-sorted array(linear search)
    int elem = 3;
    printf("Search %d in array: ", elem);
    search(ar, length, elem);
    printf("\n");
    // sort an array
    printf("Sorted array: ");
    sort(ar, length);
    display(ar, length);
    printf("\n");
    // merge two sorted array
    printf("\n");
    printf("Merged array: ");
    int ar1[] = {1, 2, 3, 45, 45}; // declared one more array to merge with existing array
    merge(ar, ar1, length, 5);
    printf("\n");
    // find second largest
    scnd_largest(ar, length);
    printf("\n");
    // find frequency of an element
    printf("Frequency of %d is %d", elem, freq(ar, length, elem));
    printf("\n");
    // return :)
    return 0;
}

// swap two variable
void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

// prints the array
void display(int *ar, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", ar[i]);
    }
}

// insert a new element in array
void insert(int *ar, int length, int elem, int pos)
{
    // shift array to right starting form pos
    // put new element in pos.
    for (int i = length - 1; i > pos; i--)
    {
        ar[i] = ar[i - 1];
    }
    ar[pos] = elem;
    // display(ar, length);
}

// delete an element from array
void delete (int *ar, int length, int pos)
{
    int i;
    // shift array to left overlapping deleting element position
    // this will remove the element
    for (i = pos - 1; i < length - 1; i++)
    {
        ar[i] = ar[i + 1];
    }
    // assign 0 to the last empty space
    ar[i] = 0;
    // display(ar, length);
}

// reverse the array
void reverse(int *ar, int length)
{
    int temp, right = length - 1;
    // swap right and left side element
    for (int left = 0; left < length / 2; left++, right--)
    {
        // swap first and last element
        temp = ar[left];
        ar[left] = ar[right];
        ar[right] = temp;
    }
}

// shift elements by one element in left side
void shift_left(int *ar, int length)
{
    // store left mose element inside a variable
    int temp = ar[0];
    // shift array to left side (which will remove first element)
    for (int i = 0; i < length - 1; i++)
    {
        ar[i] = ar[i + 1];
    }
    // assign first element value at last
    ar[length - 1] = temp;
    // 1 2 3 4
    // 2 3 4 1
}

// shift elements by one element in right side
void shift_right(int *ar, int length)
{
    // store rightmost value inside temp
    int temp = ar[length - 1];
    // shift the array right side
    for (int i = length - 1; i >= 0; i--)
    {
        ar[i] = ar[i - 1];
    }
    // assign the first place with rightmost element value
    ar[0] = temp;
    // 1 2 3 4
    // 4 1 2 3
}

// search in unsorted array(linear search)
void search(int *ar, int length, int elem)
{
    for (int i = 0; i < length; i++)
    {
        if (ar[i] == elem)
        {
            printf("%d is in %dth position", elem, i);
            return;
        }
    }
    printf("%d doesn't exist in this array", elem);
}

// sort an array(bubble sort)
void sort(int *ar, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (ar[j] > ar[j + 1])
            {
                swap(ar + j, ar + j + 1);
            }
        }
    }
    // 1 3 2 4
    // 1 2 3 4
}

// merge two sorted array
void merge(int *ar1, int *ar2, int len1, int len2)
{
    int length = len1 + len2;
    int ar_merge[length];
    // outer loop will go on for len1+len2
    for (int i = 0, j = 0, k = 0; i < length; i++)
    {
        // if element of ar1 < ar2 we will put ar1 in new array
        if (ar1[j] < ar2[k])
        {
            ar_merge[i] = ar1[j++];
            // if ar1 has no more element left (ar1 reaches the end)
            if (j >= len1)
            {
                // perform another loop to put all elements of ar2 in new array
                for (i++; k < len2; i++, k++)
                {
                    ar_merge[i] = ar2[k];
                }
            }
        }
        // if ar1 element is not smaller than ar2
        else
        {
            // assign ar2 element value inside new loop
            ar_merge[i] = ar2[k++];
            // if ar2 reaches the end of array
            if (k >= len2)
            {
                // perform another for loop to put all elements from ar1 inside new array
                for (i++; j < len1; i++, j++)
                {
                    ar_merge[i] = ar1[j];
                }
            }
        }
    }
    // 1 3 5 7 || 2 4 6 8
    // 1 2 3 4 5 6 7 8
    // at last print our new array :)
    display(ar_merge, length);
    printf("\n");
    // remove all duplicates from merged array
    printf("Distinctive merged array: ");
    rm_duplicate(ar_merge, length);
    printf("\n");
    // done bro that's all :)
}

// remove duplicate element from array
// assuming array is sorted
void rm_duplicate(int *ar, int length)
{
    int temp[length], j = 0;
    // put unique elements inside new array temp[]
    for (int i = 0; i < length - 1; i++)
    {
        if (ar[i] != ar[i + 1])
        {
            temp[j++] = ar[i];
        }
    }
    // put the last element inside
    temp[j++] = ar[length - 1];
    // now assign unique elements from temp [] to ar[]
    for (int i = 0; i < j; i++)
    {
        ar[i] = temp[i];
    }
    // assign new length after removing duplicates from array
    length = j;
    display(ar, length);
    // 1 1 2 3
    // 1 2 3
}

// find the second largest element from array
void scnd_largest(int *ar, int length)
{
    int largest = ar[0], scnd;
    for (int i = 0; i < length; i++)
    {
        if (ar[i] > largest)
        {
            scnd = largest;
            largest = ar[i];
        }
    }
    printf("Second largest element: %d", scnd);
    // 1 2 3 4
    // 3
}

// frequency of a number
int freq(int *ar, int length, int elem)
{
    // count will count the number of times a certain element in present in an array
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (ar[i] == elem)
        {
            count++;
        }
    }
    return count;
}