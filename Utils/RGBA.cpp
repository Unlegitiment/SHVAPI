#include "../utils.h"
#include <stdlib.h>

RGBA_t rgb_Create(float r, float g, float b, float a) {
	return RGBA_t{ r,g,b,a };
}
/* @return TRUE = 1 FALSE = 0 */
BOOL_t rgb_Equal(RGBA_t rgb1, RGBA_t rgb2) {
	if (rgb1.a == rgb2.a && rgb1.b == rgb2.b && rgb1.g == rgb2.g && rgb1.r == rgb2.r) { return TRUE_; }
	else return FALSE_;
}
void rgb_Destroy(RGBA_t* rgb) {
	rgb->a = 0;
	rgb->b = 0;
	rgb->g = 0;
	rgb->r = 0;
	free(rgb);
	return;
}