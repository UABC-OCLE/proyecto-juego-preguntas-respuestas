#include <stdio.h>
#include <stdlib.h>

// Declara el array globalmente para que pueda ser accedido por módulos externos
char user_answers[10];

void displayMenu() {
    printf("\n==== Quiz de Películas de Disney ====\n");
    printf("1. Empezar a jugar\n");
    printf("2. Salir\n");
    printf("==========================\n");
    printf("Ingrese una opción: ");
}

// Declara la función externa en ensamblador
extern int calculate_score();

int main() {
    int correct_answers = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Preguntas del cuestionario
                for (int i = 0; i < 10; i++) {
                    printf("\nPregunta %d:\n", i + 1);
                    switch (i) {
                        case 0:
                            printf("¿Qué princesa de Disney se enamora de un príncipe que ha sido convertido en una bestia en la película 'La Bella y la Bestia'?\n");
                            printf("a) Blancanieves\nb) Cenicienta\nc) Ariel\nd) Bella\n");
                            break;
                        case 1:
                            printf("¿En qué película de Disney aparece el personaje Aladdín?\n");
                            printf("a) 'El Rey León'\nb) 'La Sirenita'\nc) 'Aladdín'\nd) 'Mulán'\n");
                            break;
                        case 2:
                            printf("¿Cuál es el nombre de la hermana de Elsa en la película 'Frozen'?\n");
                            printf("a) Anna\nb) Moana\nc) Rapunzel\nd) Mérida\n");
                            break;
                        case 3:
                            printf("¿Qué película de Disney presenta a una joven llamada Moana que se aventura en el océano en busca de una isla mítica?\n");
                            printf("a) 'Enredados'\nb) 'Moana'\nc) 'Valiente'\nd) 'Coco'\n");
                            break;
                        case 4:
                            printf("¿Quién es el villano en 'El Rey León'?\n");
                            printf("a) Scar\nb) Jafar\nc) Úrsula\nd) Maléfica\n");
                            break;
                        case 5:
                            printf("¿Cuál es el título de la película en la que una joven se disfraza de hombre para unirse al ejército chino y proteger a su padre?\n");
                            printf("a) 'Mulán'\nb) 'Pocahontas'\nc) 'Mérida'\nd) 'Rapunzel'\n");
                            break;
                        case 6:
                            printf("¿Qué película de Disney presenta al personaje Simba?\n");
                            printf("a) 'La Sirenita'\nb) 'El Rey León'\nc) 'Frozen'\nd) 'Aladdín'\n");
                            break;
                        case 7:
                            printf("¿Cuál es el nombre del cangrejo amigo de Ariel en 'La Sirenita'?\n");
                            printf("a) Sebastián\nb) Flounder\nc) Scuttle\nd) Tritón\n");
                            break;
                        case 8:
                            printf("¿Qué princesa de Disney tiene una rana como amiga en su película?\n");
                            printf("a) Aurora\nb) Blancanieves\nc) Tiana\nd) Rapunzel\n");
                            break;
                        case 9:
                            printf("¿Qué película de Disney presenta a un joven llamado Miguel que emprende un viaje a la tierra de los muertos?\n");
                            printf("a) 'Encanto'\nb) 'Coco'\nc) 'Frozen II'\nd) 'Moana'\n");
                            break;
                    }
                    printf("Respuesta: ");
                    scanf(" %c", &user_answers[i]);
                }

                // Llama a la función en ensamblador para calcular la puntuación
                correct_answers = calculate_score();
                
                // Imprime o utiliza la puntuación según sea necesario
                printf("Tu puntuación es: %d\n", correct_answers);

                break;
            case 2:
                printf("Saliendo...\n");
                break;
            default:
                printf("Elección inválida. Por favor ingrese 1 o 2.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}
