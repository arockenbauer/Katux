[org 0x7c00]
; Passe en mode texte 80x25
mov ax, 0x0003
int 0x10

; Affiche le message de chargement une seule fois
mov si, kernel_msg
call print_string

; Charger le kernel depuis le disque
mov ax, 0x0100       ; Destination segment = 0x0100 (0x0100*16 = 0x1000)
mov es, ax
mov bx, 0x0000       ; Offset de destination = 0
mov ah, 0x02         ; Fonction BIOS : lire des secteurs
mov al, 100          ; Nombre de secteurs à lire (10 secteurs = 5120 octets)
mov ch, 0            ; Cylindre 0
mov cl, 2            ; Lire à partir du secteur 2 (le secteur 1 est le bootloader)
mov dh, 0            ; Tête 0
mov dl, 0x80         ; Disque de boot (premier disque)
int 0x13
jc disk_error        ; Si une erreur survient, afficher le message d'erreur

; Configurer les segments pour le kernel
mov ax, 0x0100
mov ds, ax
mov es, ax
mov ss, ax

; Far jump vers le kernel (démarre à l’adresse 0x1000)
jmp 0x0100:0x0000

; Routine d'affichage d'une chaîne via BIOS
print_string:
    mov ah, 0x0E
.print_loop:
    lodsb
    cmp al, 0
    je .done
    int 0x10
    jmp .print_loop
.done:
    ret

disk_error:
    mov si, disk_err_msg
    call print_string
    cli
    hlt

kernel_msg    db "Loading Katux Kernel...", 0
disk_err_msg  db "Disk read error!", 0

times 510 - ($-$$) db 0
dw 0xAA55

