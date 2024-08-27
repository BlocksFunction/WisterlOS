intr%1main:
    %2
    push ds
    push es
    push fs
    push gs
    pushad
    mov al, 0x20
    out 0xa0, al
    out 0x20, al
    push %1
    call [idtTable + %1 * 4]
    jmp intrExit