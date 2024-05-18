#include <stdio.h>
#include <string.h>

// Prototipo de la función en ASM
extern void comparar_respuesta(char respuestaUsuario, char respuestaCorrecta);

int main() {
    // Preguntas y respuestas
    char preguntas[10][256] = {
        "¿Quién pinto la Mona Lisa?",
        "¿Cuál es el país más grande del mundo por área territoria?",
        "¿Cuál es el metal más ligero que se conoce?",
        "¿cuál es el océano más grande del mundo?",
        "¿En qué año terminó la segunda guerra mundial?",
        "¿Cuál es el país con más ganadores del premio nobel en la historia?",
        "¿Cuál es el símbolo químico del oro?",
        "¿Cuál es el idioma más hablado del mundo?",
        "¿Cuál es la montaña más alta del mundo?",
        "¿Cuál es el único metal líquido a temperatura ambiente?"
    };
    char respuestas[10][4][256] = {
        {"a) Leonardo DiCaprio", "b) Leonardo Favio", "c) Leonardo Da Vinci", "d) Leonardo Casio"},
        {"a) México", "b) Rusia", "c) China", "d) Antártida"},
        {"a) Titanio", "b) Aluminio", "c) Magnesio", "d) Litio"},
        {"a) Oceáno Antártico", "b) Oceáno Atlántico", "c) Oceáno Indico", "d) Oceáno Pacifico"},
        {"a) 1945", "b) 1950", "c) 1955", "d) 1943"},
        {"a) USA", "b) Rusia", "c) China", "d) Alemania"},
        {"a) Ca", "b) Au", "c) Bv", "d) Si"},
        {"a) Español", "b) Ingles", "c) Chino", "d) Árabe"},
        {"a) Cervino", "b) K2", "c) Everest", "d) Denali"},
        {"a) Mercurio", "b) Litio", "c) Aluminio", "d) Titanio"}
    };
    char respuestasCorrectas[10] = {'c', 'b', 'd', 'd', 'a', 'a', 'b', 'c', 'c', 'a'};

    int aciertos = 0;
    int total_preguntas = sizeof(preguntas) / sizeof(preguntas[0]);

    // Iterar a través de todas las preguntas
    for (int i = 0; i < total_preguntas; i++) {
        char respuestaUsuario;
        printf("%s\n", preguntas[i]);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", respuestas[i][j]);
        }
        printf("Tu respuesta (a/b/c/d): ");
        scanf(" %c", &respuestaUsuario); // Usamos un espacio antes del %c para ignorar los saltos de línea
        getchar(); // Limpiamos el buffer de entrada

        // Llamar a la función en ASM para comparar respuestas
        comparar_respuesta(respuestaUsuario, respuestasCorrectas[i]);

        // Verificar si la respuesta es correcta e incrementar los aciertos
        // (la función en ASM no retornará si la respuesta es incorrecta)
        if (respuestaUsuario == respuestasCorrectas[i]) {
            aciertos++;
        }
    }

    // Imprimir el número de aciertos y si fallaste
    if (aciertos == total_preguntas) {
        printf("¡Felicidades! Has respondido todas las preguntas correctamente.\n");
    } else {
        printf("Fallaste. Has respondido correctamente %d preguntas de %d.\n", aciertos, total_preguntas);
    }

    return 0;
}
