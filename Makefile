 CC=gcc
    CFLAGS=-I.
    mp1: main.o downloader.o json.o
            $(CC) -o mp1 main.o downloader.o json.o -I.
    .PHONY : clean
    clean :
           -rm *.o $(objects)