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
void insertLinkedMap1x1(HashMap *map, Entry *e) {
  // validação da entrada
  if(!map || !e) return;
  // validação do índice na tabela
  int hash = hash1x1(e->key);
  if(hash < 0 && hash >= map->tableSize) return;
  // lista vazia
  if(map->lists[hash].length == 0) {
    map->lists[hash].start = e;
    map->lists[hash].length++;
  } else { // inserção ordenada
    // inserção no início
    if(e->key < map->lists[hash].start->key) {
      e->next = map->lists[hash].start;
      map->lists[hash].start = e;
    } else { // inserção entre nós ou ao final
      Entry *aux = map->lists[hash].start;
      while(aux->next != NULL && e->key >= aux->next->key)
        aux = aux->next;
      e->next = aux->next;
      aux->next = e;
    }
  }
}

void insertLinkedMap1xN(HashMap *map, Entry *e) {
  // validação da entrada
  if(!map || !e) return;
  // validação do índice na tabela
  int hash = hash1xN(e->key);
  if(hash < 0 && hash >= map->tableSize) return;
  // lista vazia
  if(map->lists[hash].length == 0) {
    map->lists[hash].start = e;
    map->lists[hash].length++;
  } else { // inserção ordenada
    // inserção no início
    if(e->key < map->lists[hash].start->key) {
      e->next = map->lists[hash].start;
      map->lists[hash].start = e;
    } else { // inserção entre nós ou ao final
      Entry *aux = map->lists[hash].start;
      while(aux->next != NULL && e->key >= aux->next->key)
        aux = aux->next;
      e->next = aux->next;
      aux->next = e;
    }
  }
}

void insertLinkedMap(HashMap *map, Entry *e, int (*hashFunction)(int key)) {
  // validação da entrada
  if(!map || !e) return;
  // validação do índice na tabela
  int hash = hashFunction(e->key);
  if(hash < 0 && hash >= map->tableSize) return;
  // lista vazia
  if(map->lists[hash].length == 0) {
    map->lists[hash].start = e;
    map->lists[hash].length++;
  } else { // inserção ordenada
    // inserção no início
    if(e->key < map->lists[hash].start->key) {
      e->next = map->lists[hash].start;
      map->lists[hash].start = e;
    } else { // inserção entre nós ou ao final
      Entry *aux = map->lists[hash].start;
      while(aux->next != NULL && e->key >= aux->next->key)
        aux = aux->next;
      e->next = aux->next;
      aux->next = e;
    }
  }
}

// 0000 0000 | 0000 0000 | 0000 0000 | 0000 0000
// 0111 1111 | 1111 1111 | 1111 1111 | 1111 1111
//    7    F      F    F      F    F      F    F
#define MAX_INT 0x7FFFFFFF;
  
int getValue1x1(HashMap *map, int key) {
  if(!map) return MAX_INT;
  int hash = hash1x1(key);
  if(hash < 0 && hash >= map->tableSize) return MAX_INT;
  List list = map->lists[hash];
  if(list.length == 0) return MAX_INT;
  Entry *aux = list.start;
  while(aux != NULL) {
    if(aux->key == key) return aux->value;
  }
  return MAX_INT;
}

int getValue(HashMap *map, int key, int (*hashFunction)(int key)) {
  if(!map) return MAX_INT;
  int hash = hashFunction(key);
  if(hash < 0 && hash >= map->tableSize) return MAX_INT;
  List list = map->lists[hash];
  if(list.length == 0) return MAX_INT;
  Entry *aux = list.start;
  while(aux != NULL) {
    if(aux->key == key) return aux->value;
  }
  return MAX_INT;
}

int main() {
  HashMap *map = newHashMap(10);
  insertLinkedMap(map, newEntry( 16, 1), hash1xN);
  insertLinkedMap(map, newEntry( 12, 2), hash1xN);
  insertLinkedMap(map, newEntry( 25, 3), hash1xN);
  insertLinkedMap(map, newEntry( 39, 4), hash1xN);
  insertLinkedMap(map, newEntry(  6, 5), hash1xN);
  insertLinkedMap(map, newEntry(122, 6), hash1xN);
  insertLinkedMap(map, newEntry(  5, 7), hash1xN);
  insertLinkedMap(map, newEntry( 68, 8), hash1xN);
  int value = getValue(map, 6, hash1xN);
  printf("chave: 16, valor: %d\n", value);

  value = getValue(map, 9, hash1xN);
  printf("chave: 9, valor: %d\n", value);
  return 0;
}