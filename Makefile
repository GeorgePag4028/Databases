all: array linkedList stack queue hashTable

array : array.cpp
	g++ -o array array.cpp 

linkedList : linkedList.cpp
	g++ -o linkedList linkedList.cpp 

stack : stack.cpp
	g++ -o stack stack.cpp 

queue : queue.cpp
	g++ -o queue queue.cpp 

hashTable : hashTable.cpp
	g++ -o hashTable hashTable.cpp 
