;
; Set up segment registers
;
mov sp, STACK_SEGMENT
mov ss, sp
mov sp, STACK_SIZE
push cs
pop ds
push word SCREEN_SEGMENT
pop es

; Blank screen
call clearScreen

; Say hello
push word welcomeMessage_size
push word welcomeMessage
call printString
call newline

; Hang
jmp $

;;;;;;;;;;;;;
; Functions ;
;;;;;;;;;;;;;

clearScreen:
; Clear screen and reset cursor position
; In: none
; Out: none
; Global:
;	color		The color to use
;	es		The screen segment
;	cursor_pos	Cursor position (modified)
mov ah, [color]
mov al, 0
mov cx, SCREEN_COLS * SCREEN_ROWS
xor di, di
rep stosw	; Write ax to to screen and decrement cx, until cx equals 0
mov [cursor_pos], word 0
ret

printString:
; Print string
; In:
; 	String offset (word)
;	String length (word)
; Out:
;	none
; Global:
;	color		The color to use
;	es		The screen segment
;	cursor_pos	The cursor position (modified)
mov ah, [color]
pop cx
pop si
mov di, [cursor_pos]
.loop0:
lodsb	; load byte from string
stosw	; store byte and color on screen
loop .loop0	; decrement cx, jump to .loop0 if cx > 0
mov [cursor_pos], di
ret

newline:
; Advance cursor to beginning of next line
; In: none
; Out: none
; Global:
;	cursor_pos	Cursor position (modified)

; Divide the cursor position by the number of bytes per row,
; add 1, then multiply by bytes per row
mov ax, [cursor_pos]
xor dx, dx
mov cx, SCREEN_COLS * 2
div cx
inc ax
mul cx
mov [cursor_pos], ax
ret

;;;;;;;;
; Data ;
;;;;;;;;

welcomeMessage db "Simple Kernel"
welcomeMessage_size EQU $ - welcomeMessage
color db 7	; White on black
cursor_pos dw 0

;;;;;;;;;;;;;
; Constants ;
;;;;;;;;;;;;;

STACK_SEGMENT EQU 09000h	; Top of conventional memory
STACK_SIZE EQU 0ffffh		; 64K - 1 bytes of stack
SCREEN_SEGMENT EQU 0b800h
SCREEN_COLS EQU 80
SCREEN_ROWS EQU 25
