#include <stdio.h>
#include <string.h>

#define EMPTY -1
#define MAX 1000

int table[MAX];
int m;

// Insert using quadratic probing
void insert(int key) {
    int hk = key % m;

    for (int i = 0; i < m; i++) {
        int idx = (hk + i * i) % m;

        if (table[idx] == EMPTY) {
            table[idx] = key;
            return;
        }
    }
    // Table full (optional handling)
}

// Search using quadratic probing
int search(int key) {
    int hk = key % m;

    for (int i = 0; i < m; i++) {
        int idx = (hk + i * i) % m;

        if (table[idx] == EMPTY)
            return 0;  // Not found

        if (table[idx] == key)
            return 1;  // Found
    }
    return 0;
}

int main() {
    int q;
    scanf("%d", &m);
    scanf("%d", &q);

    // Initialize table
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}
