# to compile all files just type "make" without quotes in the terminal
#
# we could make it compile only files that have changed but that seems 
#unnecessary with a small project.
all:
	g++ Course.cpp -o Grade_Software
	
clean:
	rm -rf
