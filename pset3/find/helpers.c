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
    
    binsearch(value, values, 0, n);
    /*
    int start = 0;
    int end = n - 1;
    // Return true if value is in values
    // Find middle of values
    
    int middle = n / 2;
        // Return true if middle == value
        if (values[middle] == value)
        {
            return true;
        // Check if value is smaller or larger than middle
        } else if (value < values[middle])
        // Search appropriate half
        {
            search(value, values)
        } else if (value > values[middle])
        // Search appropriate half
        {
            start = middle + 1;
            search(value, values, middle)
        }
    */
    // Return false if value is not in values.
    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    return;
}

bool binsearch(int value, int values[], int start, int end)
{
    // Calculate middle
    int mid = (start + end) / 2;
    // Return true if middle == value
    if (values[mid] == value)
    {
        return true;
    }
    
    // Change end to left of middle if value < middle
    if (value < values[mid]) {
        start = mid - 1;
        // Binary Search
        binsearch(value, values, start, end);
    }
        
        
    // Change start to right of middle if value > middle
        // Binary Search
    if (value > values[mid]) {
        end = mid + 1;
        // Binary Search
        binsearch(value, values, start, end);
    }
}