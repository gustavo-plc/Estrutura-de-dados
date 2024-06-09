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

int main() {

int hash(char c) //função de mapeamento dos caracteres em índices da tabela ASCII - função de Hash
{
    return (int)c;
}

// Resolução de colisões utilizando lista encadeada

// Com base na tabela ASCII de 128 índices

HashMap *newHashMap(int tableSize, int (*hashFunction)(char)) {
    HashMap *map = malloc(sizeof(HashMap));
    if (map) {
        map->length = 0;
        map->tableSize = tableSize;
        map->lists = calloc(tableSize, sizeof(List));
        map->hashFunction = hash;
        if (!map->lists) {
            free(map);
            return NULL;
        }
    }
    return map;
}

    // Inicialização da tabela hash
    int tableSize = 128;
    HashMap *myMap = newHashMap(tableSize, hash);


Entry *newEntry(char key, int value) {
    Entry *entry = malloc(sizeof(Entry));
    if (entry) {
        entry->key = key;
        entry->value = value;
        entry->next = NULL;
    }
    return entry;
}


char key = "A"; //escreva aqui a chave que deseja mapear
Entry *e = newEntry(key, myMap->hashFunction(key));


void insertLinkedMap(HashMap *map, Entry *e, int (*hashFunction)(char key)) { //resolução de conflitos por encadeamento, usando 1:1
  // validação da entrada
  if(!map || !e) return;
  // validação do índice na tabela
  int hashValue = myMap->hashFunction(e->key);
  if(hashValue < 0 || hashValue >= map->tableSize) return; // caso de índice inválido
  if(map->lists[hashValue].length == 0) { // se a lista existente naquele índice da tabela hash for zero, é pq se trata do primeiro elemento do índice.
    map->lists[hashValue].start = e;  // atribui essa entrada ao ponteiro de início da lista
    map->lists[hashValue].length++; //incrementa valor da lista existente naquele índice
  } else {  //se não for zero, já tem elementos nessa lista, pelo menos 1.
    if(e->key < map->lists[hashValue].start->key) { // inserção ordenada no início: se o valor que estou tentando inserir é menor que o primeiro valor, torna ele o primeiro e o já existente vira o segundo.
        e->next = map->lists[hashValue].start; //aponta o ponteiro próximo da entrada atual para o já existente
        map->lists[hashValue].start = e; //redefine o início para apontar para a entrada atual.
        map->lists[hashValue].length++; //incrementa lista daquele índice
    } else { //se ele for maior que o primeiro nó, terá de ser inserido depois dele
        Entry *aux = map->lists[hashValue].start; //criação de um nó auxiliar que recebe o início da lista
        while(aux->next != NULL && e->key >= aux->next->key) { //inserção no meio ou ao final: enquanto o nó atual não apontar para NULL e o valor da entrada for maior que o nó atual
            aux = aux->next; //atualiza o nó atual para ser o próximo nó. Caminha para o próximo nó
        }
        e->next = aux->next; //faz a entrada apontar para o nó subsequente ao atual
        aux->next = e; //atualiza
        map->lists[hashValue].length++; //incrementa lista daquele índice
    }  
  }
}


    // Inserção da entrada na tabela hash
    insertLinkedMap(myMap, e);

    // Impressão dos resultados
    if (myMap->lists[hash('A')].length > 0) {
        printf("Valor mapeado para 'A': %d\n", myMap->lists[hash('A')].start->value);
    }

    return 0;
}