#include <stdio.h>
#include <stdlib.h>

typedef struct entry Entry;
typedef struct list List;
typedef struct hash_map HashMap;

struct entry { //recriada para tabela ASCII 
  char key;
  int value;
  Entry *next;
};

struct list {
  Entry *start;
  int length;
};

struct hash_map {
  List *lists;
  int length;
  int tableSize;
  int (*hashFunction)(int key); // ponteiro para função
};



// Resolução de colisões utilizando lista encadeada

// Com base na tabela ASCII de 128 índices
int tableSize = 128;

HashMap *newHashMap(int tableSize) {
  HashMap *map = malloc(sizeof(HashMap));
  if(map) { // inicializar o map
    map->length = 0;
    map->tableSize = tableSize;
    map->lists = calloc(sizeof(List), tableSize);
    map->hashFunction = hash;
    if(!map->lists) {
      free(map);
      return NULL;
    }
  }
  return map;
}

myMap = newHashMap(tableSize);
int key = "A";
int hashValue = myMap->hashFunction(key);

int hash(char c) //função de mapeamento dos caracteres em índices da tabela ASCII - função de Hash
{
    
}

insertLinkedMap(HashMap *map, Entry *e, int (*hashFunction)(int key))
{

}


void insertLinkedMap1x1(HashMap *map, Entry *e) { //resolução de conflitos por encadeamento, usando 1:1
  // validação da entrada
  if(!map || !e) return;
  // validação do índice na tabela
  int hash = hash1x1(e->key);
  if(hash < 0 && hash >= map->tableSize) return; // caso de índice inválido
  
  if(map->lists[hash].length == 0) {
    map->lists[hash].start = e;
    map->lists[hash].length++;
  } else { 
    if(e->key < map->lists[hash].start->key) { // inserção ordenada no início
        e->next = map->lists[hash].start;
        map->lists[hash].start = e;
    } else {
        Entry *aux = map->lists[hash].start;
        while(aux->next != NULL && e->key >= aux->next->key) { //inserção no meio ou ao final
            aux = aux->next;
        }
        e->next = aux->next;
        aux->next = e;
    }
    
  }
}