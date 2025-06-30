section .data
    hello db 'Hello, World!',0
    hello_len equ $ - hello

section .text
    global _start

_start:
    ; Appel système write (sys_write)
    mov eax, 4         ; Code de la fonction write
    mov ebx, 1         ; Descripteur de fichier (1 = sortie standard)
    mov ecx, hello     ; Pointeur vers la chaîne à afficher
    mov edx, hello_len ; Longueur de la chaîne
    int 0x80           ; Interruption pour appeler le noyau

    ; Appel système exit (sys_exit)
    mov eax, 1         ; Code de la fonction exit
    xor ebx, ebx       ; Code de retour (0 = succès)
    int 0x80           ; Interruption pour appeler le noyau
