so:
	gcc -c -fpic -o add.o add.c
	gcc -shared -o libadd.so add.o
main: main.c
	gcc -o main main.c -L./ -I./inc -Wl,-rpath=./ -ladd -Wl,-M=main.map
clean:
	rm lib* main