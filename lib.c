#include "lib.h"

int strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

int strlen(const char *s) {
    int len = 0;
    while (s[len]) len++;
    return len;
}

void memcpy(char *dest, const char *src, int count) {
    for (int i = 0; i < count; i++) {
        dest[i] = src[i];
    }
}

