#include <stdio.h>
#include <stdlib.h>

extern int calcular_puntuacion(char *respuestas_correctas, char *respuestas_usuario, int num_preguntas);

void historiaMundial();
void geografia();
void biologia();

int main() {
    int opcionMenuPrincipal;
    char c;

    do {
        printf("\n*** Menú Principal ***\n");
        printf("1. Jugar Historia\n");
        printf("2. Jugar Geografía\n");
        printf("3. Jugar Biología\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcionMenuPrincipal);
        
        switch(opcionMenuPrincipal) {
            case 1:
                historiaMundial();
                break;
            case 2:
                geografia();
                break;
            case 3:
                biologia();
                break;
            case 4:
                printf("¡Gracias por jugar!\n");
                break;
            default:
                printf("Opción no válida. Por favor, seleccione nuevamente.\n");
        }

        // Limpiar el búfer del teclado
        while ((c = getchar()) != '\n' && c != EOF);

    } while(opcionMenuPrincipal != 4);
    
    return 0;
}

void historiaMundial() {
    printf("Tema 1: Historia Mundial\n");

    char respuestas[] = {'a', 'b', 'a', 'a', 'c', 'a', 'b', 'c', 'a', 'd'};
    char respuestas_usuario[10];
    int puntuacion = 0;

    for(int i = 0; i < 10; i++) {
        printf("%d. ", i+1); // Imprimir el número de la pregunta
        switch(i) {
            case 0:
                printf("¿En qué año comenzó la Primera Guerra Mundial?\n");
                printf("a) 1914\nb) 1916\nc) 1918\nd) 1920\nRespuesta: ");
                break;
            case 1:
                printf("¿Quién fue el primer presidente de los Estados Unidos?\n");
                printf("a) Thomas Jefferson\nb) George Washington\nc) Abraham Lincoln\nd) John Adams\nRespuesta: ");
                break;
            case 2:
                printf("¿Cuál fue la capital del Imperio Romano?\n");
                printf("a) Roma\nb) Atenas\nc) Cartago\nd) Constantinopla\nRespuesta: ");
                break;
            case 3:
                printf("¿Quién fue el líder de la Revolución Rusa en 1917?\n");
                printf("a) Lenin\nb) Stalin\nc) Trotsky\nd) Rasputín\nRespuesta: ");
                break;
            case 4:
                printf("¿Qué evento histórico ocurrió el 20 de julio de 1969?\n");
                printf("a) Caída del Muro de Berlín\nb) Desembarco en Normandía\nc) Llegada del hombre a la luna\nd) Asesinato de John F. Kennedy\nRespuesta: ");
                break;
            case 5:
                printf("¿Quién fue el líder del movimiento por los derechos civiles en Estados Unidos durante la década de 1960?\n");
                printf("a) Martin Luther King Jr.\nb) Malcolm X\nc) Rosa Parks\nd) Barack Obama\nRespuesta: ");
                break;
            case 6:
                printf("¿En qué año cayó el Muro de Berlín?\n");
                printf("a) 1985\nb) 1989\nc) 1991\nd) 1993\nRespuesta: ");
                break;
            case 7:
                printf("¿Cuál fue la causa principal de la Revolución Francesa?\n");
                printf("a) Escasez de alimentos\nb) Monarquía absoluta\nc) Influencia de la Ilustración\nd) Aumento de impuestos\nRespuesta: ");
                break;
            case 8:
                printf("¿Quién fue el líder principal de la Revolución Cubana en 1959?\n");
                printf("a) Fidel Castro\nb) Che Guevara\nc) Fulgencio Batista\nd) Raúl Castro\nRespuesta: ");
                break;
            case 9:
                printf("¿Qué tratado puso fin a la Segunda Guerra Mundial en Europa?\n");
                printf("a) Tratado de Versalles\nb) Tratado de Múnich\nc) Tratado de Roma\nd) Tratado de París\nRespuesta: ");
                break;
        }

        char respuesta;
        scanf(" %c", &respuesta);
        respuestas_usuario[i] = respuesta;
    }

    puntuacion = calcular_puntuacion(respuestas, respuestas_usuario, 10);

    printf("Puntuación: %d/10\n", puntuacion);
}

void geografia() {
    printf("Tema 2: Geografía\n");

    char respuestas[] = {'a', 'c', 'a', 'c', 'b', 'b', 'b', 'a', 'c', 'a'};
    char respuestas_usuario[10];
    int puntuacion = 0;

    for(int i = 0; i < 10; i++) {
        printf("%d. ", i+1); // Imprimir el número de la pregunta
        switch(i) {
            case 0:
                printf("¿Cuál es el río más largo del mundo?\n");
                printf("a) Amazonas\nb) Nilo\nc) Yangtsé\nd) Mississippi\nRespuesta: ");
                break;
            case 1:
                printf("¿Cuál es la montaña más alta del mundo?\n");
                printf("a) Mont Blanc\nb) Kilimanjaro\nc) Everest\nd) Aconcagua\nRespuesta: ");
                break;
            case 2:
                printf("¿Cuál es el país más grande por área terrestre?\n");
                printf("a) Rusia\nb) Estados Unidos\nc) Canadá\nd) China\nRespuesta: ");
                break;
            case 3:
                printf("¿Cuál es el océano más grande del mundo?\n");
                printf("a) Océano Atlántico\nb) Océano Índico\nc) Océano Pacífico\nd) Océano Antártico\nRespuesta: ");
                break;
            case 4:
                printf("¿Cuál es el país más poblado del mundo?\n");
                printf("a) India\nb) China\nc) Estados Unidos\nd) Indonesia\nRespuesta: ");
                break;
            case 5:
                printf("¿Cuál es la capital de Australia?\n");
                printf("a) Sydney\nb) Canberra\nc) Melbourne\nd) Brisbane\nRespuesta: ");
                break;
            case 6:
                printf("¿Cuál es la ciudad más poblada de África?\n");
                printf("a) El Cairo\nb) Lagos\nc) Johannesburgo\nd) Kinshasa\nRespuesta: ");
                break;
            case 7:
                printf("¿Cuál es el desierto más grande del mundo?\n");
                printf("a) Sahara\nb) Gobi\nc) Kalahari\nd) Atacama\nRespuesta: ");
                break;
            case 8:
                printf("¿Cuál es el país más pequeño del mundo por área terrestre?\n");
                printf("a) Mónaco\nb) San Marino\nc) Vaticano\nd) Nauru\nRespuesta: ");
                break;
            case 9:
                printf("¿Cuál es el canal artificial más largo del mundo?\n");
                printf("a) Canal de Suez\nb) Canal de Panamá\nc) Canal de Kiel\nd) Canal de Nicaragua\nRespuesta: ");
                break;
        }

        char respuesta;
        scanf(" %c", &respuesta);
        respuestas_usuario[i] = respuesta;
    }

    puntuacion = calcular_puntuacion(respuestas, respuestas_usuario, 10);

    printf("Puntuación: %d/10\n", puntuacion);
}

void biologia() {
     printf("Tema 3: Biología\n");

    char respuestas[] = {'b', 'd', 'd', 'a', 'c', 'b', 'a', 'a', 'c', 'b'};
    char respuestas_usuario[10];
    int puntuacion = 0;

    for(int i = 0; i < 10; i++) {
        printf("%d. ", i+1); // Imprimir el número de la pregunta
        switch(i) {
            case 0:
                printf("¿Qué órgano es responsable de bombear sangre por todo el cuerpo?\n");
                printf("a) Riñón\nb) Corazón\nc) Hígado\nd) Pulmón\nRespuesta: ");
                break;
            case 1:
                printf("¿Cuál es la función principal del sistema nervioso central?\n");
                printf("a) Controlar el movimiento voluntario\nb) Regular el metabolismo\nc) Producir hormonas\nd) Procesar información y coordinar respuestas\nRespuesta: ");
                break;
            case 2:
                printf("¿Qué tipo de célula es responsable de la producción de energía en el cuerpo?\n");
                printf("a) Neurona\nb) Glóbulo blanco\nc) Glóbulo rojo\nd) Célula muscular\nRespuesta: ");
                break;
            case 3:
                printf("¿Cuál es el proceso mediante el cual las plantas convierten la luz solar en energía química?\n");
                printf("a) Fotosíntesis\nb) Respiración celular\nc) Fermentación\nd) Transpiración\nRespuesta: ");
                break;
            case 4:
                printf("¿Cuál de las siguientes estructuras es parte del sistema respiratorio humano?\n");
                printf("a) Vesícula biliar\nb) Riñón\nc) Tráquea\nd) Estómago\nRespuesta: ");
                break;
            case 5:
                printf("¿Qué tipo de tejido cubre la superficie externa del cuerpo y las cavidades corporales internas?\n");
                printf("a) Tejido muscular\nb) Tejido epitelial\nc) Tejido conectivo\nd) Tejido nervioso\nRespuesta: ");
                break;
            case 6:
                printf("¿Cuál es la molécula responsable de transportar oxígeno en la sangre?\n");
                printf("a) Hemoglobina\nb) Glucosa\nc) Insulina\nd) Adrenalina\nRespuesta: ");
                break;
            case 7:
                printf("¿Qué parte del sistema digestivo es responsable de absorber los nutrientes de los alimentos?\n");
                printf("a) Intestino delgado\nb) Estómago\nc) Intestino grueso\nd) Esófago\nRespuesta: ");
                break;
            case 8:
                printf("¿Cuál de las siguientes enfermedades es causada por un virus?\n");
                printf("a) Tuberculosis\nb) Malaria\nc) SIDA\nd) Diabetes\nRespuesta: ");
                break;
            case 9:
                printf("¿Cuál es la función principal de los glóbulos blancos en el sistema inmunológico?\n");
                printf("a) Transportar oxígeno\nb) Eliminar bacterias y virus\nc) Regular el metabolismo\nd) Coagular la sangre\nRespuesta: ");
                break;
        }

        char respuesta;
        scanf(" %c", &respuesta);
        respuestas_usuario[i] = respuesta;
    }

    puntuacion = calcular_puntuacion(respuestas, respuestas_usuario, 10);

    printf("Puntuación: %d/10\n", puntuacion);
}