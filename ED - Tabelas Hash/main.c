#include <stdio.h>
#include <stdlib.h>

typedef struct entry Entry;
typedef struct hash_map HashMap;

struct entry //par chave-valor, representado como um nó, que tem ponteiro que aponta para o próx
    {
        int key;
        int value;
        Entry *prox;
    };

struct hash_map
    {
        Entry **entries;
        int length;
        // void (*hashFunction)(int key) // ponteiro para funções
    };

int hash1x1(int x)
    {
        return x;
    }

int hash1xn(int x)
    {
        
    }

    HashMap *criarHashMap(int tableSize) // representa a criação do modelo de lista encadeada
    {
        HashMap *map = malloc(sizeof(HashMap));
        if(map)
            {
                map->entries = calloc(sizeof(Entry*), tableSize);
                map->length = 0;
            }
    }