#include <cstdio> // Include for printf
#include "Map.h"

int main() {
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto it = m.begin(); it != m.end(); ++it) {
        int key = it->key;
        const char* value = it->value;
        int index = it->index;
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    for (auto it = m.begin(); it != m.end(); ++it) {
        int key = it->key;
        const char* value = it->value;
        int index = it->index;
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    return 0;
}
