;En este codigo implementaremos:
;           1) Contador rbx para los aciertos
;           2) Contador rcx para recorrer arreglos
;           3) Mensajes para situaciones:
;                   a) Cuando se tiene un >=3 en aciertos [APROBADO]
;                   b) Cuando se tiene un <= 2 en aciertos [REPROBADO]
;                   c) Cuando se tienen 0 aciertos [CERO]
;           4) Imprimiremos la cantidad de aciertos

section .text
    global comprobante_resultados ;Iniciador

comprobante_resultados:
    xor rax, rax ;limpiar rax
    xor rbx, rbx ;limpiar rbx
    xor rcx, rcx ;limpiar rcx

verificador:
    cmp rcx, 5 ;comparar rcx con 5 por si termino la cadena
    je .fin ;saltamos a la etiqueta .fin si y solo si termino
    mov al, [rdi + rcx] ;movemos el caracter almacenado en rdi[rcx] dentro de al
    cmp al, [rsi + rcx] ;comparamos rdi[rcx] con rsi[rcx]
    je .incrementa ;saltamos a la etiqueta .incrementa si la respuesta es correcta
    inc rcx ;incrementamos rcx para rdi y rsi
    jmp verificador ;devolverse al verificador para seguir

;Aqui se incrementara el contador de aciertos, al igual que se verificara si se termino o no el contador
.incrementa:
    inc rbx
    cmp rcx, 5
    je .fin
    inc rcx
    jmp verificador


;Aqui es donde se iniciara la compracion de resultados
.fin:
    cmp rbx, 3
    jae .aprobado ;Sí la respuesta es >= 3 [APROBADO]
    cmp rbx, 0
    je .cero    ;Sí la respuesta es 0 [CERO]
    cmp rbx, 2
    jbe .reprobado ;Sí la respuesta es <= 2 [REPROBADO]

;Saltamos a cada situacion dependiendo los aciertos

.aprobado:
    mov rsi, msg1
    mov rdx, msg1_len
    jmp .resultados
;                           rsi msgX = Almacenamos el mensaje correspondiente dentro de la variable rsi
;                           rdx msgX_len = Almacenamos el largo del mensaje para que lo imprima todo
.reprobado:
    mov rsi, msg2
    mov rdx, msg2_len
    jmp .resultados

.cero:
    mov rsi, msg3
    mov rdx, msg3_len
    jmp .resultados

.resultados:
    mov rax, 1
    mov rdi, 1
    syscall
    ret

;Aqui se escribiran los mensajes correspondientes a cada puntaje
section .data
    msg1: db "Aprobado. Felicidades! Total de aciertos: ", 10
    msg1_len equ $ - msg1
    msg2: db "Reprobado. Buen Intento! Total de aciertos: ", 10
    msg2_len equ $ - msg2
    msg3: db "Wow... Cero aciertos", 10
    msg3_len equ $ - msg3