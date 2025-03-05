#include "keyboard.h"
#include "screen.h"

char get_key() {
    char key;
    asm volatile (
        "xor %%ah, %%ah\n\t"  // Fonction 0 : lecture d'un caractère
        "int $0x16\n\t"
        : "=al" (key)
        :
        : "ax"
    );
    return key;
}

void read_line(char *buffer, int max_length) {
    int i = 0;
    while (i < max_length - 1) {
        char c = get_key();
        // Si la touche Entrée (retour chariot ou saut de ligne) est pressée
        if (c == '\r' || c == '\n') {
            buffer[i] = '\0';
            print("\n");  // Saut de ligne après validation
            return;
        }
        // Gestion du Retour arrière
        else if (c == '\b') {
            if (i > 0) {
                i--;
                print("\b \b");  // Efface le dernier caractère affiché
            }
        }
        // Caractère imprimable
        else if (c >= 32 && c <= 126) {
            buffer[i++] = c;
            print_char(c);
        }
    }
    buffer[i] = '\0';
}

