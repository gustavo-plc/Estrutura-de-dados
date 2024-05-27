#include <stdio.h>
#include <stdlib.h>

typedef struct entry Entry;
typedef struct list List;
typedef struct hash_map HashMap;

struct entry {
  int key;
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
  // void (*hashFunction)(int key); // ponteiro para função
};

int hash1x1(int x) {
  return x;
}

int hash1xN(int x) {
  return x % 10;
}

Entry *newEntry(int key, int value) {
  Entry *entry = malloc(sizeof(Entry));
  if(entry) {
    entry->key = key;
    entry->value = value;
  }
  return entry;
}

HashMap *newHashMap(int tableSize) {
  HashMap *map = malloc(sizeof(HashMap));
  if(map) { // inicializar o map
    map->length = 0;
    map->tableSize = tableSize;
    map->lists = calloc(sizeof(List), tableSize);
    if(!map->lists) {
      free(map);
      return NULL;
    }
  }
  return map;
}
// 
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

Entry *getValue1x1(HashMap *map, int key) {
    if(!map)
        return NULL;
    int hash = hash1x1(key);
    if (hash < 0 && hash >= map->tableSize)
        return NULL;
    List list = map->lists[hash]; // busca sequencial
    while (map->lists->start->next != NULL) {
        if (map->lists->start->value == key)
            return map->lists->start->value;
        map->lists->start = map->lists->start->next;
    }
    return map->lists->start->value;
}