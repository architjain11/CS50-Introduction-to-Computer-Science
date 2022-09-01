// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 186019 ;

// Hash table
node *table[N];

// Number of word added to the table
unsigned int now=0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *cursor;
    cursor = table[hash(word)];
    printf("%i\n", hash(word));

    char *w=malloc(strlen(word)+1);
    strcpy(w, word);

    for(int i=0; w[i]!='\0'; i++)
        w[i]=tolower(w[i]);

    while(cursor!=NULL)
    {
        if(strcmp(w, cursor->word)==0)
        {
            free(w);
            return true;
        }
        printf("%s\n", cursor->word);
        cursor=cursor->next;
    }
    free(w);
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long h = 0;
    for ( ; *word; ++word)  // s is a zero terminated string, hence the loops exits
        h = 5*h + *word;   //  when the terminating zero byte is reached, *s == NULL

    return h%N;

}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if(file==NULL)
        return false;

    for(int i=0; i<N; i++)
        table[i]=NULL;

    char *w = malloc(LENGTH + 1);
    if(w==NULL)
        return false;

    while(fscanf(file, "%s", w)!=EOF)
    {
        node *n = malloc(sizeof(node));
        if(n==NULL)
            return false;

        strcpy(n->word, w);

        int j=hash(w);
        n->next=table[j];
        table[j]=n;

        now++;
    }

    fclose(file);
    free(w);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return now;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *cursor;
    node *tmp;
    for(int i=0; i<N; i++)
    {
        cursor=table[i];
        while(cursor!=NULL)
        {
            tmp=cursor;
            cursor=cursor->next;
            free(tmp);
        }
    }
    return true;
}
  