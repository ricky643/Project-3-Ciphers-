
#Ricardo Varona
#CPSC 1071
#4/3/2023

#Compiles needed files and include flag to run proper version of c++ for assingment 
compile:
	g++ Cipher.cpp Queue.cpp Project3.cpp -o Project3.out -Wall
#Driver contains the main and needs .out respectively
run:
	./Project3.out
#clean included to clear terminal when needed
clean:
	rm *.out
