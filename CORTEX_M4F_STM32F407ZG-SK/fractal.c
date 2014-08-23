#include "main.h"
#include <math.h>
#include "fractal.h"
#define WIDTH 240
#define HEIGHT 320
#define _sq(x) ((x)*(x))
unsigned char GR(uint16_t, uint16_t);
unsigned char BL(uint16_t, uint16_t);
unsigned char RD(uint16_t i, uint16_t j){
	return (char)(_sq(cos(atan2(j-160, i-120)/2))*255);
}

unsigned char GR(uint16_t i, uint16_t j){
	return (char)(_sq(cos(atan2(j-160, i-120)/2-2*acos(-1)/3))*255);
}

unsigned char BL(uint16_t i, uint16_t j){
	return (char)(_sq(cos(atan2(j-160, i-120)/2+2*acos(-1)/3))*255);
}

void Background_Update(){
	uint16_t i, j;
	for( j = 0; j < HEIGHT; j++){
		for( i = 0; i < WIDTH; i++){
			Background_Render(i, j);
		}
	}
}


void Background_Render(uint16_t i, uint16_t j){
	static unsigned char color[3];
	
	color[0] = RD(i, j)&255;
	color[1] = GR(i, j)&255;
	color[2] = BL(i, j)&255;
	LCD_SetTextColor(ASSEMBLE_RGB(color[0], color[1], color[2]));
	LCD_DrawFullRect(i, j, 1, 1);
}
