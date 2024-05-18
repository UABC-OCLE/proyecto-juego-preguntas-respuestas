//el punto de este programa es hacer un juego de preguntas y respuestas, por ende al usuario se le haran distintas preguntas y se verficiaran mediante ensamblador que esten correctas las respuestas
/*No me gusta la idea de hacerlas complejas
Por ende, voy hacerla de capitales de America*/

/*Nota: Se requiere de almacenar cada respuesta para su posterior verificacion*/


#include <stdio.h>

extern void comprobante_resultados(char Usuelec[], char CorrectRes[]);

int main(){
    char CorrectRes[5] = {'a', 'b', 'a', 'd', 'c'}; //las respuestas correctas aqui yaceran, porque si no tendria que estarse utilizando mucho if y else que complicarian el codigo
    char Usuelec[5]; //para las respuestas que el usuario anote, tomando inspiracion del ejemplo puesto por el profe me parecio buena idea agregarlo
    //sin embargo, lo que yo voy a hacer es con el usuRes el recibir las respuestas que se almacenaran en Usuelec.

    printf("\n¿Cuál es la capital de México?\n");
    printf("\na) Ciudad de México   b) Baja California   c) Guadalajara   d) Acapulco\n");
    printf("\nRespuesta: ");
    scanf(" %c", &Usuelec[0]);

    printf("\n¿Cuál es la capital de Estados Unidos?\n");
    printf("\na) Texas  b) Washington D.C   c) California   d) Florida\n");
    printf("\nRespuesta: ");
    scanf(" %c", &Usuelec[1]);

    printf("\n¿Cuál es la capital de Argentina?\n");
    printf("\na) Buenos Aires   b) Rosario   c) Córdoba   d) Catamarca\n");
    printf("\nRespuesta: ");
    scanf(" %c", &Usuelec[2]);

    printf("\n¿Cuál es la capital de Brazil?\n");
    printf("\na) Paraná   b) Sao Paulo   c) Rio de Janeiro   d) Brasilia\n");
    printf("\nRespuesta: ");
    scanf(" %c", &Usuelec[3]);

    printf("\n¿Cuál es la capital de Canadá?\n");
    printf("\na) Nueva Escocia   b) Ontario   c) Ottawa   d) Quebec\n");
    printf("\nRespuesta: ");
    scanf(" %c", &Usuelec[4]);

    //una vez hechas las preguntas, lo que ahora tenemos que hacer es irnos a ensamblador para las respuestas y mensajes.

    printf("\n\n");

    comprobante_resultados(Usuelec, CorrectRes);

    printf("\n\n");

    return 0;
}