# to compile all files just type "make" without quotes in the terminal
#
# we could make it compile only files that have changed but that seems 
#unnecessary with a small project.
all:
	g++ Asgn.cpp Asgn.h Course.cpp Course.h Matrix.cpp -o Grade_Software
