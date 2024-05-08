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

// get_hash() is used in handling collisions using open addressing with double hashing
static int get_hash (const char* str, const int n_buckets, const int attemp) {
    const int a = hash(str, PRIME_1, n_buckets);
    const int b = hash(str, PRIME_2, n_buckets);
    return (a + (attempt * (b + 1))) % n_buckets;
}

// insert() iterates through indexes until we find an empty buket, then inserts the item into the bucket and increments count
void insert (hash_table* t, const char* key, const char* value) {
    item* it = new_item(key, value);
    int index = get_hash(it->key, h->size, 0);
    item* current_it = h->items[index];
    int f = 1;
    while(current_item != NULL && current_item != &DELETED_ITEM) {
	index = get_hash(it->key, h->size, f);
	current_item = h->items[index];
	f++;
    }
    h->items[index] = it;
    h->count++;
}

// search() at the iteration checks if the key matches key we are looking for, and if so returns the value
char* search (hash_table* t, const char* key) {
    int index = get_hash(key, h->size, 0);
    item* it = h->items[index];
    int f = 1;
    while (it != NULL) {
	if (it != &DELETED_ITEM) {
	    if (strcmp(it->key, key) == 0)
		return it->value;
	}
	index = get_hash(key, h->size, f);
	it = h->items[index];
	f++;
    }
    return NULL;
}

// table_delete() deletes from an open addressed hash table
static item DELETED_ITEM = {
    NULL,
    NULL
};

void table_delete (hash_table* t, const char* key) {
    int index = get_hash (key, t->size, 0);
    item* it = h->items[index];
    int f = 1;
    while (it != NULL) {
	if (it != &DELETED_ITEM) {
	    if (strcmp(it->key, key) == 0) {
		delete_item(it);
		h->items[index] = &DELETED_ITEM;
	    }
	}
	index = get_hash (key, h->size, f);
	it = h->items[index];
	f++;
    }
    h->count--;
}
