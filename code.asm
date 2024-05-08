section .text
    global calcular_puntuacion

calcular_puntuacion:
    ; Entradas:
    ;   RDI: dirección del array de respuestas correctas
    ;   RSI: dirección del array de respuestas del usuario
    ;   RDX: número total de preguntas
    ; Salidas:
    ;   RAX: puntuación

    xor rax, rax        ; Inicializar la puntuación en 0
    xor rcx, rcx        ; Inicializar el contador en 0

calcular_puntuacion_loop:
    cmp rcx, rdx        ; Comprobar si hemos alcanzado el final del array
    je calcular_puntuacion_fin   ; Si sí, salir del bucle

    mov al, [rdi + rcx]         ; Cargar la respuesta correcta en AL
    cmp al, [rsi + rcx]         ; Comparar con la respuesta del usuario
    jne respuesta_incorrecta    ; Si no son iguales, ir a etiqueta respuesta_incorrecta

respuesta_correcta:
    inc rax              ; Aumentar la puntuación en 1
    jmp calcular_puntuacion_continuar   ; Saltar a calcular_puntuacion_continuar

respuesta_incorrecta:
    jmp calcular_puntuacion_continuar   ; Saltar a calcular_puntuacion_continuar sin aumentar la puntuación

calcular_puntuacion_continuar:
    inc rcx              ; Incrementar el contador
    jmp calcular_puntuacion_loop       ; Volver al inicio del bucle

calcular_puntuacion_fin:
    ret                  ; Devolver la puntuación en RAX
