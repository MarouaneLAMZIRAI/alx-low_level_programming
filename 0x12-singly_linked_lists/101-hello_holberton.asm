section .data
    hello db "Hello, Holberton", 10  ; The 10 is the newline character '\n'
    hello_len equ $ - hello           ; Calculate the length of the string

section .text
    global _start

_start:
    ; Prepare arguments for printf
    mov rdi, 1                       ; File descriptor 1 (stdout)
    mov rsi, hello                   ; Pointer to the string
    mov rdx, hello_len               ; Length of the string
    mov rax, 1                       ; syscall: write
    syscall

    ; Exit the program
    mov rax, 60                      ; syscall: exit
    xor rdi, rdi                     ; status: 0
    syscall
