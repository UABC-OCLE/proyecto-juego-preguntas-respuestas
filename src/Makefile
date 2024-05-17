
release: juego_preguntas

# Compila el programa final enlazando los archivos objeto de C y ASM
juego_preguntas: main.o comparar_respuesta.o
	gcc -o juego_preguntas main.o comparar_respuesta.o -no-pie

# Compila el archivo fuente de C en un archivo objeto
main.o: main.c
	gcc -c main.c -o main.o

# Compila el archivo fuente de ASM en un archivo objeto
comparar_respuesta.o: comparar_respuesta.asm
	nasm -f elf64 comparar_respuesta.asm -o comparar_respuesta.o

# Limpiar los archivos compilados y el ejecutable
clean:
	rm -f *.o juego_preguntas

run:
	./juego_preguntas