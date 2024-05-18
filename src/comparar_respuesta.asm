; no me gusta usar ensamblador realmente
; pero para este programa tendra que ser necesario su uso
; lo primero que tenemos que hacer es tomar las respuestas del usuario y las respuestas correctas
; requerimos de 3 cosas:
;   1) Un contador de aciertos que ira aumentando conforme vaya siendo igual la respuesta del usuario a la correcta
;   2) Comparar 2 array, moviendose entre uno y otro para ir comparando las respuestas
;           2.1) Al comparar dos array, si son iguales, el registro contador (rax) aumentara en 1
;           2.2) Aqui se utilizaran mensajes, tanto el mensaje de "Aprobado" si el numero de respuestas es >= 3 y reprobado si es <= 2
;           2.3) Una vez impresos los mensajes, deberia funcionar correctamente, eso espero.





section .text ;obligatorio iniciar con esto mismo
    global comprobante_resultados


comprobante_resultados:
    xor rax, rax
    xor rcx, rcx ;este mismo contador indicara el final de los elementos de la tabla.

verificación:
    cmp rcx, 5 ;aqui es donde verificamos si la cadena ha terminado
    je .termino ;saltamos a la parte final 
    ;aqui es donde compararemos tanto el array de preguntas y el de respuestas, primero inicializando el contador, se va a inicializar en 0 para ir sumando de forma adecuada.
    mov al, [rdi + rcx] ;almacena respuesta de usuario rdi[rcx] (como si fuese rdi[i o 0 pues])
    cmp al, [rsi + rcx] ;ahora la comparar con el elemento rsi[rcx] de las respuestas correctas
    je .incremento ;iremos a la linea donde se incrementa el rax
    inc rcx
    jmp verificación ;saltamos de nueva cuenta al verificador para poder seguir iterando

.incremento:
    inc rax ;aqui aumentamos en 1 el rax
    cmp rcx, 5 ;comparamos si ya termino rcx con todo el arreglo
    je .termino
    inc rcx ;el rcx se aumenta pues porque ocupamos que aumente realmente ya que si no pues nos quedamos que si respondes de forma incorrecta solo ahi avanzara
    jmp verificación


.termino:
    cmp rax, 0
    je .resultados_cero
    cmp rax, 3
    jae .resultados_aprobado
    cmp rax, 2
    jbe .resultados_reprobado

;Aquí es donde se envian los resultados e imprimen

.resultados_aprobado:
    mov rsi, msg1
    mov rdx, msg1_len
    jmp .resultados_total

.resultados_reprobado:
    mov rsi, msg2
    mov rdx, msg2_len
    jmp .resultados_total

.resultados_cero:
    mov rsi, msg3
    mov rdx, msg3_len
    jmp .resultados_total

.resultados_total:
    mov rax, 1
    mov rdi, 1
    syscall
    ret


section .rodata
    msg1: db "Aprobado, Felicidades!, tuviste un total de aciertos de: ", 10
    msg1_len equ $ - msg1

    msg2: db "Reprobado, no pasa nada!, tuviste un total de aciertos de: ", 10
    msg2_len equ $ - msg2

    msg3: db "Wow... Creo que toca estudiar un poco, tuviste cero aciertos...", 10
    msg3_len equ $ - msg3