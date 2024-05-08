typedef struct {
    char* key;
    char* value;
} item;

typedef struct {
    int size;
    int count;
    item** items;
    
} hash_table;

// methods on the hash tables with the following API
void insert (hash_table* t, const char* key, const char* value);
char* search (hash_table* t, const char* key);
void table_delete (hash_table* t, const char* key);
