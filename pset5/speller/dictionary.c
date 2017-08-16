/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"


// create linked list
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

node *head;
node *ptr;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // 
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(ptr->word, word) == 0)
        {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
    {
    head = malloc(sizeof(node));

    FILE* fptr = fopen(dictionary, "r");
    
    char* word = malloc(LENGTH + 1);
    
    // iterate through dictionary
    while (fscanf(fptr, "%s", word) != EOF)
    {
        // insert word into linked list
        // create new node
        node* new_node = malloc(sizeof(node));
        
        //check for NULL
        if (new_node == NULL)
        {
            unload();
            return false;
        }
        
        // point new node to head
        strcpy(new_node->word, word);
        new_node->next = head;
        
        // point head to new node
        head = new_node;
    }
    
    return true;
    
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
