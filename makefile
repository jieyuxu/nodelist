strtest: linkedlist.c
	gcc linkedlist.c -o linkedlist
clean:
	rm *~
run: linkedlist
	./linkedlist


