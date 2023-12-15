; Trabalho para a disciplina de Arquitetura de Computadores
; Objetivo foi imprimir uma matriz de asteriscos com base em input do usuario
; Autores: Marcos Kenji e Victor Puchalski


section .data
;======== VARIAVEIS A SEREM UTILIZADAS =========
    a: db 0
    b: db 0
    c: db 0
    d: db 0
;==============================================

    asterisk: db '*'
    newline: db 0xA ; quebra de linha
    message: db 'Por favor, insira um número de 1 a 9:', 0

section .text
    global _start

_start:

;======== IMPRIME A MENSAGEM =======
    mov   eax, 1
    mov   edi, 1
    mov   rsi, message
    mov   edx, 38
    syscall
    
;========== PEGA O INPUT DO USUARIO =====
    mov   eax, 0               ;   read do usuario
    mov   edi, 0               ;   entrada padra
    mov   rsi, b               ;   armazena em b
    mov   edx, 1               ;   tamanho 1 byte
    syscall

; ========= ATOI DE 1 DIGITO ==============

    sub byte [b], '0' ; subtrai o valor ascii -> ex. 5 (ascii 53) - 0 (ascii 48) resultado 5

    mov   bl, [b]             ; bl agora tem um valor numerico, não ascii
    mov   dl, [b]             ; 
    add   dl, 1               ;  adiciona 1
    mov   [c], dl             ;  armazena em dl

;Obs: para mais degitos, é preciso fazer um laco apra percorrer os algarismos
;  multiplicando por 10 e somando. Nao deu tempo de implementar

;========= LOOP DE IMPRESSAO =====

outer_loop:
    mov   al, [a]             ;   insere o 0 em al
    cmp   al, bl              ;   compara al (0) com a bl (usuario)
    jg    end                 ;   se a for maior , vai para end

    mov   cl, [c]             ;   move o c (usuario) para cl 
    cmp   cl, bl              ;   compara  cl com  bl
    jge   next_line           ;   se c for maior ou igual vai para proxima linha

;imprime os asteriscos

    mov   eax, 1
    mov   edi, 1
    mov   rsi, asterisk
    mov   edx, 1
    syscall

; incrementa o c volta no loop

    inc   byte [c]
    jmp   outer_loop
; insere nova linha 

next_line:
    mov   eax, 1
    mov   edi, 1
    mov   rsi, newline
    mov   edx, 1
    syscall

    inc   byte [a]
    mov   byte [c], 0
    jmp   outer_loop

;======== FINALIZA PROGRAMA ========
end:
    mov   eax, 60
    xor   edi, edi
    syscall
