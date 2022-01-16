
scheduler: scheduler.o io.o
	gcc -o scheduler scheduler.o io.o -g
scheduler.o: scheduler.c
	gcc -c scheduler.c
io.o: io.c
	gcc -c io.c
clean:
	rm -f *.o scheduler
