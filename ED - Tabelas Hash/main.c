#include <stdio.h>
#include <stdlib.h>

typedef struct entry Entry;
typedef struct hash_map HashMap;

struct entry //par chave-valor, representado como um nó, que tem ponteiro que aponta para o próx
    {
        int key;
        int value;
        Entry *prox;
    } 

struct hash_map
    {
        Entry *entry;
        int length;
        void (*hashFunction)(int key) // ponteiro para funções
    }

    