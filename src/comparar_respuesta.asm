; no me gusta usar ensamblador realmente
; pero para este programa tendra que ser necesario su uso
; lo primero que tenemos que hacer es tomar las respuestas del usuario y las respuestas correctas
; requerimos de 3 cosas:
;   1) Un contador de aciertos que ira aumentando conforme vaya siendo igual la respuesta del usuario a la correcta
;   2) Comparar 2 array, moviendose entre uno y otro para ir comparando las respuestas
;           2.1) Al comparar dos array, si son iguales, el registro contador (rax) aumentara en 1
;           2.2) Aqui se utilizaran mensajes, tanto el mensaje de "Aprobado" si el numero de respuestas es >= 3 y reprobado si es <= 2
;           2.3) Una vez impresos los mensajes, deberia funcionar correctamente, eso espero.


section .data
    msg1 db 'Aprobado. De 5 preguntas tuviste un total de aciertos igual a: ', 0
    msg2 db 'Reprobado. De 5 preguntas tuviste un total de aciertos igual a: ', 0
    msg3 db 'Wow. Creo que toca estudiar un poco, tuviste 0 aciertos...', 0



section .text ;obligatorio iniciar con esto mismo

global verificador


contador:
    mov rax, 0
    mov rcx, 5 ;este mismo contador indicara el final de los elementos de la tabla.

verificador:
    ;aqui es donde compararemos tanto el array de preguntas y el de respuestas, primero inicializando el contador, se va a inicializar en 0 para ir sumando de forma adecuada.
    cmp rdi, rsi ;rdi es el de las respuestas del usuario, rsi el de las respuestas correctas.
    je incremento ;iremos a la linea donde se incrementa el rax
    inc rsi
    inc rdi
    cmp rax, rcx ;aqui es donde verificamos si la cadena ha terminado
    je termino ;saltamos a la parte final 
    jmp verificador ;saltamos de nueva cuenta al verificador para poder seguir iterando


incremento:
    inc rax ;aqui aumentamos en 1 el rax
    jmp verificador


termino:
    cmp rax, 0
    je cero
    cmp rax, 3
    jae Aprobado
    cmp rax, 2
    jbe Reprobado


;Aquí es donde se envian los resultados
Aprobado:
    mov rdi, msg1
    ret

Reprobado:
    mov rdi, msg2
    ret

cero:
    mov rdi, msg3
    ret