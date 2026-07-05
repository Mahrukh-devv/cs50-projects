// Implements a dictionary's functionality

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1000;

// Hash table
unsigned int word_count = 0;
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    char lower[LENGTH + 1];
int i;
for (i = 0; word[i] != '\0'; i++)
{
    lower[i] = tolower(word[i]);
}
lower[i] = '\0';

unsigned int index = hash(lower);
node *cursor = table[index];
while (cursor != NULL)
{
    if (strcmp(cursor->word, lower) == 0)
    {
        return true;
    }
    cursor = cursor->next;
}
return false;
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int h = 0;
for (int i = 0; word[i] != '\0'; i++)
{
    h = (h * 31 + tolower(word[i])) % N;
}
return h;
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
if (file == NULL)
{
    return false;
}
char word[LENGTH + 1];
while (fscanf(file, "%s", word) != EOF)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        fclose(file);
        return false;
    }
    strcpy(n->word, word);
    unsigned int index = hash(word);
    n->next = table[index];
    table[index] = n;
    word_count++;
}
fclose(file);
return true;

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
return word_count;
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
{
    node *cursor = table[i];
    while (cursor != NULL)
    {
        node *tmp = cursor;
        cursor = cursor->next;
        free(tmp);
    }
}
return true;
    return false;
}
