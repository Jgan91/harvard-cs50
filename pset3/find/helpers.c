/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool binsearch(int value, int values[], int start, int end);
 
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    // Return false if n is non-positve.
    if (n < 0)
    {
        return false;
    }
    
    // linear search
    /*
    for (int i = 0; i < n; i++)
    {
        if (values[i] == value)
        {
            return true;
        }
    }
    */
    
    
    if (binsearch(value, values, 0, n))
    {
        return true;
    }

    // Return false if value is not in values.

    return false;
    
    
    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // set swap counter to non-zero value
    int swap = -1;
    // repeat until swap counter is zero:
    while (swap != 0)
    {
        // reset swap counter to 0
        swap = 0;
        // look at each adjacent pair
        for (int i = 0; i < n - 1; i++)
        {
            // if two adjacent elements are not in order, swap them and add 1 to swap counter
            if (values[i] > values[i + 1])
            {
                int temp = values[i];
                values[i] = values[i + 1];
                values[i + 1] = temp;
                swap += 1;
            }
        }
    }

    return;
}



bool binsearch(int value, int values[], int start, int end)
{
    // Calculate middle
    int mid;
    /* if (start == end)
    {
     mid = 0;
    } else
    {
    */
    if (start > end) {
        return false;
    }
        mid = (start + end) / 2;
    // }
    // Return true if middle == value
    if (start == end && values[mid] != value)
    {
        return false;
    } else if (values[mid] == value)
    {
        return true;
    }
    
    // Change end to left of middle if value < middle
    if (value < values[mid]) {
        end = mid - 1;
        // Binary Search
        return binsearch(value, values, start, end);
    } // Change start to right of middle if value > middle
    else if (value > values[mid]) {
        start = mid + 1;
        // Binary Search
        return binsearch(value, values, start, end);
    }
    
    return false;
}
