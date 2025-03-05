#include "screen.h"

void print_char(char c) {
    asm volatile (
        "mov $0x0E, %%ah\n\t"
        "mov %0, %%al\n\t"
        "int $0x10\n\t"
        : : "r"(c) : "ax"
    );
}

void print(const char *str) {
    while (*str) {
        print_char(*str++);
    }
}

void clear_screen() {
    asm volatile (
        "mov $0x0600, %%ax\n\t"
        "mov $0x0000, %%cx\n\t"
        "mov $0x184F, %%dx\n\t"
        "mov $0x07, %%bh\n\t"
        "int $0x10\n\t"
        : : : "ax", "bx", "cx", "dx"
    );
}

