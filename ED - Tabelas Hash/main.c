#include <stdio.h>
#include <stdlib.h>

typedef struct entry Entry;
typedef struct list List;
typedef struct hash_map HashMap;

struct entry {
  int key;
  int value;
  Entry *prox;
};

struct list {
  Entry *start;
  int length;
};

struct hash_map {
  List *lists;
  int length;
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
    map->lists = calloc(sizeof(List), tableSize);
    if(!map->lists) {
      free(map);
      return NULL;
    }
  }
  return map;
}
// 
void insertLinkedMap1x1(HashMap *map, Entry *e) {
  if(!map || !e) return;
  if(map->lists[hash1x1(e->value)].length == 0) {
    map->lists[hash1x1(e->value)].start = e;
    map->lists[hash1x1(e->value)].length++;
  } else { // inserção ordenada
    
  }
}