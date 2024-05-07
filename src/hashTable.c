#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"

// new_item() initializes a new hash table item
static item* new_item (const char* k, const char* v) {
    item* i = malloc(sizeof(item));
    i->key = strdup(k);
    i->value = strdup(v);
    return i;
}

// new() initializesa new hash table
hash_table* new() {
    hash_table* t = malloc(sizeof(hash_table));
    t->size = 64;
    t->count = 0;
    t->items = calloc((size_t)t->size, sizeof(item*))
}

// delete_item() delets and frees the memory allocated to an item
static void delete_item (item* i) {
    free(i->key);
    free(i->value);
    free(i);
}

// delete_hash_table() delets and frees the memory allocated to a hash table
void delete_hash_table (hash_table* t) {
    int i;
    for (i = 0; i < t->size; i++) {
	item* it = t->items[i];
	if (it != NULL)
	    delete_item(it);
    }
    free(t->items);
    free(t);
}
