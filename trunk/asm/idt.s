[GLOBAL idt_load]    ; Allows the C code to call idt_load().

idt_load:
    mov eax, [esp+4]  ; Get the pointer to the IDT, passed as a parameter. 
    lidt [eax]        ; Load the IDT pointer.
    ret
