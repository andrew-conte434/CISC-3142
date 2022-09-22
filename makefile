#targets
hello:
	echo "Running helloWorld program"
	g++ hello.cc -o hello
	./hello

clean:
	rm hello
