typedef struct LRUCache{
    int key;
    int val;
    struct LRUCache* prev;
    struct LRUCache* next;
} LRUCache;

LRUCache* head;
LRUCache* tail;
LRUCache** map;
int capa;
int curr;
int mask;

LRUCache* lRUCacheCreate(int capacity) {
    mask = 2 * capacity;
    curr = 0;
    capa = capacity;
    map = malloc(sizeof(LRUCache*)*3*capa);
    for (int i = 0; i < 3*capa; i++){
        map[i] = malloc(sizeof(LRUCache));
        map[i]->val = -1;
        map[i]->key = -1;
    }
    return head;
}

void lRUCacheHit(LRUCache* curr){
    if (curr == tail) return;
    if (curr == head){
        head = head->next;
        tail->next = curr;
        curr->prev = tail;
        tail = curr;
    } else if (curr != tail) {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        tail->next = curr;
        curr->prev = tail;
        tail = curr;
    }
}

int lRUCacheGet(LRUCache* obj, int key) {
    int key_mask = key % mask;
    while (map[key_mask]->val != -1){
        if (map[key_mask]->key == key) {
            lRUCacheHit(map[key_mask]);
            return map[key_mask]->val;
        }
        key_mask++;
    }
    return -1;
}

void lRUCacheRemove(){
    head->key = -1;
    head->val = -1;
    head = head->next;
}

void lRUCacheAdd(LRUCache* curr){
    if (!head){
        curr->next = NULL;
        curr->prev = NULL;
        head = curr;
        tail = curr;
    } else {
        tail->next = curr;
        curr->prev = tail;
        tail = curr;
    }
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    int key_mask = key % mask;
    while (map[key_mask]->val != -1) {
        if (map[key_mask]->key == key) {
            map[key_mask]->val = value;
            lRUCacheHit(map[key_mask]);
            return;
        }
        key_mask++;
    }

    if (curr == capa){
        lRUCacheRemove();
        curr--;
    }

    map[key_mask]->key = key;
    map[key_mask]->val = value;
    lRUCacheAdd(map[key_mask]);
    curr++;
}

void lRUCacheFree(LRUCache* obj) {
    for(int i = 0; i < 3 * capa; i++){
        free(map[i]);
    }
    free(map);
    head = NULL;
    tail = NULL;
}