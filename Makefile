CC = g++
CFLAGS = -g -Wall
output = program

.PHONY: all 
all:  

# The files we depend on are the pre requisties
# trade: main ./Order/Order.cpp

trade: orderbook.o order.o
	${CC} main.cpp orderbook.o order.o -o ${output}.exe

orderbook.o: Orderbook/fifoBSTOrderbook.cpp
	${CC} -c Orderbook/fifoBSTOrderbook.cpp -o orderbook.o

order.o: Order/Order.cpp
	${CC} -c Order/Order.cpp -o order.o
debug: 
	${CC} -g main.cpp ./Order/Order.cpp -o ${output}Debug.exe

.PHONY: clean
clean: 
	rm -f *.exe *.o






