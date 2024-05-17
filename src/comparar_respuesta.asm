; Código en ASM
section .text
global comparar_respuesta

; Función para comparar respuestas
; Argumentos:
;   rdi: puntero a la respuesta del usuario
;   rsi: puntero a la respuesta correcta
comparar_respuesta:
    mov rax, 0        ; Establecer rax en 0 (respuesta incorrecta)
    cmp rdi, rsi      ; Comparar las respuestas
    je respuesta_correcta  ; Si son iguales, salta a respuesta_correcta
    ret              ; Retornar si la respuesta es incorrecta

respuesta_correcta:
    mov rax, 1        ; Establecer rax en 1 (respuesta correcta)
    ret              ; Retornar
