release: juego_preguntas.bin

# Compila el programa final enlazando los archivos objeto de C y ASM
juego_preguntas.bin: main.o prac.o
	gcc -g -o juego_preguntas.bin main.o prac.o -no-pie

# Compila el archivo fuente de C en un archivo objeto
main.o: main.c
	gcc -c main.c -o main.o

# Compila el archivo fuente de ASM en un archivo objeto
prac.o: prac.asm
	nasm -f elf64 prac.asm -o prac.o

# Limpiar los archivos compilados y el ejecutable
clean:
	rm prac.o main.o juego_preguntas.bin

#correr programa
run:
	./juego_preguntas.bin

gdb:
	gdb ./juego_preguntas.bin