CC = g++
CFLAGS = -g -Wall 
output = program

.PHONY: all 
all: trade 

# The files we depend on are the pre requisties
# trade: main ./Order/Order.cpp
trade: 
	${CC} main.cpp ./Order/Order.cpp -o ${output}.exe
	./${output}.exe



debug: 
	${CC} -g main.cpp ./Order/Order.cpp -o ${output}Debug.exe

.PHONY: clean
clean: 
	rm -f *.exe