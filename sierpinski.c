#include <stdio.h>
#include <stdlib.h>
#include <bmpfile.h>

const rgb_pixel_t white = {0xFF,0xFF,0xFF,0xFF};
const rgb_pixel_t black = {0x0,0x0,0x0,0x0};

rgb_pixel_t sierpinski(int x, int y) {
	while (x > 0 && y > 0) {
		if ((x%3 == 1) && (y%3 == 1)) {
			// return 1;
			return white;
		}
		x /= 3;
		y /= 3;
	}
	// return 0;
	return black;
}

int main(int argc, char *argv[]){
	if (argc != 2) return 0;
	int depth = atoi(argv[1]);
	int dimension = 1;
	int x,y;
	while (depth--) {
		dimension *= 3;
	}
	/*
	char* im = malloc(dimension*(dimension>>3));
	char* pt = im;
	*/
	int bit = 0;
	bmpfile_t *bmp = bmp_create(dimension, dimension, 1);
	for (y = 0; y < dimension; y++) {
		for (x = 0; x < dimension; x++) {
			/*
			if (!bit) {
				*pt = 0;
			} else if (bit == 7) {
				pt++;
				bit = 0;
			}
			*pt |= (sierpinski(x,y) << (7-bit));
			bit--;
			*/
			bmp_set_pixel(bmp, x, y, sierpinski(x,y));
		}
	}
	bmp_save(bmp, "output.bmp");
	bmp_destroy(bmp);
	/*
	*(pt+1) = '\0';
	FILE *fout = fopen("output.bmp", "w");
	fwrite(im, sizeof(char), dimension*dimension, fout);
	fclose(fout);
	*/
	return 0;
}