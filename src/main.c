//el punto de este programa es hacer un juego de preguntas y respuestas, por ende al usuario se le haran distintas preguntas y se verficiaran mediante ensamblador que esten correctas las respuestas
/*No me gusta la idea de hacerlas complejas
Por ende, voy hacerla de capitales de America*/
/*Nota: Se requiere de almacenar cada respuesta para su posterior verificacion*/
//Nota 2: Se utilizara ncurses para temas de interfaz y preguntas

#include <stdio.h>
#include <ncurses.h>

extern int comprobante_resultados(char Usuelec[], char CorrectRes[]); //llamamos a la funciona global .asm

int main(){
    char CorrectRes[5] = {'a', 'b', 'a', 'd', 'c'}; //las respuestas correctas aqui yaceran, porque si no tendria que estarse utilizando mucho if y else que complicarian el codigo
    char Usuelec[5]; //para las respuestas que el usuario anote, tomando inspiracion del ejemplo puesto por el profe me parecio buena idea agregarlo
    float Puntaje;
    char op;

    initscr();
    echo();
    //sin embargo, lo que yo voy a hacer es con el usuRes el recibir las respuestas que se almacenaran en Usuelec.
    printw("\n()========================================()");
    printw("\n||                                        ||");
    printw("\n||                                        ||");
    printw("\n||        BIENVENIDO DESCONOCIDO!         ||");
    printw("\n||       (probablemente mi creador)       ||");
    printw("\n||                                        ||");
    printw("\n||        1) JUGAR       2) ADIOS         ||");
    printw("\n||                                        ||");
    printw("\n||                                        ||");
    printw("\n||             Preguntas sobre capitales  ||");
    printw("\n()========================================()\n");
    noecho();
    op = getch();
    refresh();

    clear(); //desaparecer menu para evitar estorbo

    while ( op != '2'){

    echo();
    printw("\n¿Cuál es la capital de México?\n");
    printw("\na) Ciudad de México   b) Baja California   c) Guadalajara   d) Acapulco\n");
    printw("\nRespuesta: ");
    scanw(" %c", &Usuelec[0]);
    clear(); //se utilizaran en cada pregunta para que pueda usarse del tamaño de una ventana normal y no se llene mucho de informacion la pantalla

    printw("\n¿Cuál es la capital de Estados Unidos?\n");
    printw("\na) Texas  b) Washington D.C   c) California   d) Florida\n");
    printw("\nRespuesta: ");
    scanw(" %c", &Usuelec[1]);
    clear();

    printw("\n¿Cuál es la capital de Argentina?\n");
    printw("\na) Buenos Aires   b) Rosario   c) Córdoba   d) Catamarca\n");
    printw("\nRespuesta: ");
    scanw(" %c", &Usuelec[2]);
    clear();

    printw("\n¿Cuál es la capital de Brazil?\n");
    printw("\na) Paraná   b) Sao Paulo   c) Rio de Janeiro   d) Brasilia\n");
    printw("\nRespuesta: ");
    scanw(" %c", &Usuelec[3]);
    clear();

    printw("\n¿Cuál es la capital de Canadá?\n");
    printw("\na) Nueva Escocia   b) Ontario   c) Ottawa   d) Quebec\n");
    printw("\nRespuesta: ");
    scanw(" %c", &Usuelec[4]);

    clear(); //desaparecer preguntas

    Puntaje = comprobante_resultados(Usuelec, CorrectRes); //Puntaje recibe el dato RAX de ensamblador que es la cantidad de aciertos

    //una vez hechas las preguntas, lo que ahora tenemos que hacer es irnos a ensamblador para las respuestas y mensajes.
    printw("\n\n\n");
    printw("                   *-*-*-*-*-*-*-*-*-*-*-*\n");
    printw("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");


    if (Puntaje >= 3){
        printw("                  Aprobado. FELICIDADES! \n                 Total de Aciertos: %1.0f / 5", Puntaje);
        printw("\n                    Porcentaje: %1.2f", (Puntaje/5)*100);         
    }

    else if (Puntaje == 0){
        printw("                Wow... Intentalo otra vez! \n                 Total de Aciertos: %1.0f / 5", Puntaje);
        printw("\n                    Porcentaje: %1.2f", (Puntaje/5)*100);        
    }

    else if (Puntaje <= 2){
        printw("                  Reprobado. Buen Intento! \n                 Total de Aciertos: %1.0f / 5", Puntaje);
        printw("\n                    Porcentaje: %1.2f", (Puntaje/5)*100);        
    }

    printw("\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printw("                   *-*-*-*-*-*-*-*-*-*-*-*\n");
    printw("\n\n");

    printw("\nEXCELENTE!... ahora solo presiona 2 para irte o 1 si es que quieres mejorar el puntaje.\n");
    refresh();
    noecho();
    op = getch();
    clear(); //por si se presiona un caracter distinto a 2, para que inicie de nuevo con pantalla limpia
    }

    printw("\n()========================================()");
    printw("\n||                                        ||");
    printw("\n||                                        ||");
    printw("\n||       HASTA PRONTO, DESCONOCIDO!       ||");
    printw("\n||       (probablemente mi creador)       ||");
    printw("\n||                                        ||");
    printw("\n||             PROYECTO NO.4              ||");
    printw("\n||                                        ||");
    printw("\n||                                        ||");
    printw("\n||            Presiona ENTER para cerrar  ||");
    printw("\n()========================================()\n");
    refresh();
    noecho();
    getch();

    endwin();
    return 0;
}