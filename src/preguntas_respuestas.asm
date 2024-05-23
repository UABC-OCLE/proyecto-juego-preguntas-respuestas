;En este codigo implementaremos:
;           1) Contador rax para los aciertos
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
    xor rcx, rcx ;limpiar rcx

verificador:
    cmp rcx, 5 ;comparar rcx con 5 por si termino la cadena
    je .fin ;saltamos a la etiqueta .fin si y solo si termino
    mov bl, [rdi + rcx] ;movemos el caracter almacenado en rdi[rcx] dentro de al
    cmp bl, [rsi + rcx] ;comparamos rdi[rcx] con rsi[rcx]
    je .incrementa ;saltamos a la etiqueta .incrementa si la respuesta es correcta
    inc rcx ;incrementamos rcx para rdi y rsi
    jmp verificador ;devolverse al verificador para seguir

;Aqui se incrementara el contador de aciertos, al igual que se verificara si se termino o no el contador
.incrementa:
    inc rax
    cmp rcx, 5
    je .fin
    inc rcx
    jmp verificador


;Final del programa, donde ret devolvera los resultados almacenados en RAX para el codigo C
.fin:
    ret