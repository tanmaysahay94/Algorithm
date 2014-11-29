KERNEL_START equ 1		; Disk block where kernel starts
KERNEL_SIZE equ 1		; Kernel size in disk blocks
KERNEL_SEGMENT equ 1000h	; Segment where kernel will be loaded

;
; Load kernel
;
mov ax, 200h + KERNEL_SIZE
push word KERNEL_SEGMENT
pop es
xor bx, bx
mov cx, KERNEL_START + 1
mov dx, 0
int 13h
jnc ok
jmp $
ok:

;
; Jump to kernel
;
jmp KERNEL_SEGMENT:0

;
; Boot signature
;
times 510 - ($ - $$) db 0
db 55h
db 0aah
