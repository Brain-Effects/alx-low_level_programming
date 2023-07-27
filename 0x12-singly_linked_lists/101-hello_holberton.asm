; 64-bit program in assembly that prints "Hello, Holberton" followed by a new line

        global  main
        extern  printf

        section .data
msg:    db      'Hello, Holberton', 0

        section .text
main:
        ; Call printf to print the message
        mov     rdi, msg
        xor     rax, rax
        call    printf

        ; Exit the program
        xor     rax, rax
        ret
