section .data
    extern respuestas_usuario   ; Declarar el array externo
    ; Definir el array de respuestas correctas
    correct_answers db 'dcabaabacb', 0  ; Respuestas correctas

section .text
    global calculate_score

calculate_score:
    ; Prólogo de la función
    push rbp
    mov rbp, rsp

    ; Inicializar contador de puntuación
    mov rax, 0

    ; Recorrer las respuestas del usuario
    mov ecx, 0  ; Contador para el bucle
    lea rsi, [respuestas_usuario]  ; Cargar la dirección del array de respuestas del usuario

answer_loop:
    cmp ecx, 9  ; Verificar si el contador del bucle alcanza 9 (10 preguntas - 1)
    jge end_loop  ; Si es así, salir del bucle
    movzx rdx, byte [rsi + rcx]  ; Cargar la respuesta del usuario en rdx

    ; Comparar la respuesta del usuario con la respuesta correcta para cada pregunta
    cmp ecx, 0  ; Pregunta 1: La Bella y la Bestia (respuesta correcta: d)
    je check_answer
    cmp ecx, 1  ; Pregunta 2: Aladdín (respuesta correcta: c)
    je check_answer
    cmp ecx, 2  ; Pregunta 3: Frozen (respuesta correcta: a)
    je check_answer
    cmp ecx, 3  ; Pregunta 4: Moana (respuesta correcta: b)
    je check_answer
    cmp ecx, 4  ; Pregunta 5: El Rey León (respuesta correcta: a)
    je check_answer
    cmp ecx, 5  ; Pregunta 6: Mulán (respuesta correcta: a)
    je check_answer
    cmp ecx, 6  ; Pregunta 7: El Rey León (respuesta correcta: b)
    je check_answer
    cmp ecx, 7  ; Pregunta 8: La Sirenita (respuesta correcta: a)
    je check_answer
    cmp ecx, 8  ; Pregunta 9: Tiana y el Sapo (respuesta correcta: c)
    je check_answer
    cmp ecx, 9  ; Pregunta 10: Coco (respuesta correcta: b)
    je check_answer

    ; Saltar a la siguiente pregunta si la respuesta del usuario fue incorrecta
    jmp next_question

check_answer:
    cmp dl, [correct_answers + rcx]  ; Comparar la respuesta del usuario con la respuesta correcta
    je correct_answer  ; Si coinciden, saltar a la etiqueta correct_answer

next_question:
    inc ecx  ; Pasar a la siguiente pregunta
    jmp answer_loop  ; Repetir el bucle para la siguiente pregunta

correct_answer:
    inc rax  ; Incrementar la puntuación si la respuesta es correcta
    jmp next_question  ; Pasar a la siguiente pregunta

end_loop:
    ; Epílogo de la función
    pop rbp
    ret
