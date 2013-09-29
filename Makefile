all: sierpinski

sierpinski:
	gcc sierpinski.c -lbmp -o sierpinski

clean:
	rm sierpinski
