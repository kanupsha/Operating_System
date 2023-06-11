computer.exe: cpu.o memory.o load.o shell.o computer.o
	gcc cpu.o memory.o load.o shell.o computer.o -o computer.exe
cpu.o: cpu.c
	gcc -c cpu.c
memory.o: memory.c
	gcc -c memory.c
load.o: load.c
	gcc -c load.c
shell.o: shell.c
	gcc -c shell.c
computer.o: computer.c
	gcc -c computer.c



