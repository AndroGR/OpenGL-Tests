CC=clang++ # Our compiler for C++
CFLAGS=-O3 -lglfw -lGLEW -lGL -lm -lX11 # The compiler flags
OUTFILE=triangle # Output file

SOURCES=Triangle.cpp # Our source files

default: $(SOURCES)
	@$(CC) -o $(OUTFILE) $(SOURCES) $(CFLAGS)
	@echo "Done"

cleanup:
	@rm ./$(OUTFILE)
	@echo "Done"
