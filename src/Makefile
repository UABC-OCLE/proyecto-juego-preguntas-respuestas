release: juego_preguntas_respuestas.bin

juego_preguntas_respuestas.bin: main.o preguntas_respuestas.o
	gcc -g -o juego_preguntas_respuestas.bin main.o preguntas_respuestas.o -no-pie

main.o: main.c
	gcc -c main.c -o main.o

preguntas_respuestas.o: preguntas_respuestas.asm
	nasm -f elf64 preguntas_respuestas.asm -o preguntas_respuestas.o

clean:
	rm main.o preguntas_respuestas.o juego_preguntas_respuestas.bin

run:
	./juego_preguntas_respuestas.bin

gdb:
	gdb ./juego_preguntas_respuestas.bin