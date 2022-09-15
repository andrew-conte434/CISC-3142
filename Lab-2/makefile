#targets
lab2: ex1_5.txt ex1_11.txt

#Compiles and runs program for Exercise 1.5
ex1_5.txt: ex1_11.txt
	echo "Running program exercise 1.5"
	g++ exercise1_5.cc -o exercise1_5 && ./exercise1_5 > ex1_5.txt

#Compiles and runs program for Exercise 1.11
ex1_11.txt:
	echo "Running program exercise 1.11"
	g++ exercise1_11.cc -o exercise1_11 && ./exercise1_11 > ex1_11.txt

clean:
	rm exercise1_5 exercise1_11 ex1_5.txt ex1_11.txt
