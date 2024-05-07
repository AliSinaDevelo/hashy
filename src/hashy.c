#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hashy.h"

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

// delete() delets and frees the memory allocated to a hash table
void delete (hash_table* t) {
    int i;
    for (i = 0; i < t->size; i++) {
	item* it = t->items[i];
	if (it != NULL)
	    delete_item(it);
    }
    free(t->items);
    free(t);
}

// hash() function takes a string as an input and returns a number in our bucket array length
static int hash (const char* str, const int a, const int z) {
    long hash = 0;
    const int len_str = strlen(str);
    for (int i = 0; i < len_str; i++) {
	hash += (long) pow(a, len_str - (i + 1)) * s[i];
	hash = hash % m;
    }
    return (int) hash;
}
