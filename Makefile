workbench: main.o workbench.o
	gcc -Wall -Werror -o workbench main.o workbench.o


main.o: main.c
	gcc -Wall -Werror -c main.c


workbench.o: workbench.c
	gcc -Wall -Werror -c workbench.c


clean:
	rm *.o
