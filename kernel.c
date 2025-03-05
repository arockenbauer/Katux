#include "keyboard.h"
#include "screen.h"
#include "lib.h"

void main() {
    clear_screen();
    print("Kernel started...\n");
    print("Welcome to Katux v0.4 Shell\n");
    print("Type 'help' for commands\n");

    while (1) {
        char cmd[64];
        print("\nKatux~# ");  // Affichage du prompt sur une nouvelle ligne
        read_line(cmd, 64);

        if (strcmp(cmd, "help") == 0) {
            print("Commands: help, hello, clear, shutdown\n");
        } else if (strcmp(cmd, "hello") == 0) {
            print("Hello Axel!\n");
        } else if (strcmp(cmd, "clear") == 0) {
            clear_screen();
        } else if (strcmp(cmd, "shutdown") == 0) {
            print("Shutting down Katux...\n");
            while (1) {
                asm volatile ("hlt");  // Arrêt du CPU
            }
        } else if (cmd[0] != '\0') {
            print("Unknown command\n");
        }
        // En mode idle, attendre la prochaine interruption pour éviter le busy-wait
        asm volatile ("hlt");
    }
}

