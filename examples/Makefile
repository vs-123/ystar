CFLAGS	= -Wall -Wextra -Wpedantic -Werror
SRC	= $(wildcard *.c)
PROGRAM	= example-ystar
INCLUDE	= -Iinclude/

b:
	@echo "BUILDING..."
	@mkdir -p build/
	$(CC) $(CFLAGS) $(INCLUDE) -o ./build/$(PROGRAM) $(SRC)

r: b
	@echo "RUNNING..."
	./build/$(PROGRAM)

c:
	@echo "CLEANING..."
	rm -rf build/
