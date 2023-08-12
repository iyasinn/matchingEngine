CC = g++
CFLAGS = -g -Wall
output = program

.PHONY: all 
all:  

# The files we depend on are the pre requisties
# trade: main ./Order/Order.cpp

run: ${output}.exe
	./${output}.exe

trade: orderbook.o order.o
	${CC} main.cpp orderbook.o order.o -o ${output}.exe -lcurl
	./${output}.exe

debug: orderbook.o order.o
	${CC} -g main.cpp orderbook.o order.o -o ${output}Debug.exe -lcurl

orderbook.o: Orderbook/fifoBSTOrderbook.cpp
	${CC} -g -c Orderbook/fifoBSTOrderbook.cpp -o orderbook.o

order.o: Order/Order.cpp
	${CC} -g -c Order/Order.cpp -o order.o
	
.PHONY: clean
clean: 
	rm -f *.exe *.o






