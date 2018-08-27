typedef struct pixels{
  char r;
  char g;
  char b;
} pixels;

typedef struct imag{
  char magic_number[3];
  int width;
  int height;
  char max_number;
  pixels **pix;
} image;
