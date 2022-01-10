/**
 * @file util.h holds utility functions to be used in various parts of the main code.
 * @author Santiago Pinzon
 * 
 */

#ifndef UTIL
#define UTIL

#include "constants.h"
#include <Arduino.h>


//Macro used to convert individual RBG values to one hex value
#define RGB(r, g, b) (((r) << 16) | ((g) << 8) | (b))

/**
 * Used to calculate the relationship between x and y matrix coordinates and linear values according to the Octo Library. 
 * The board is numbered with 0,0 being the top left corner.
 * @param x unsigned int representing the horizontal coordinate
 * @param y unsigned int representing the vertical coordinate
 * @return the corresponding LED number according to the octo library.
 * 
 */
unsigned int xy(unsigned int x, unsigned int y)
{
	int rowsDeep = y % 16;
	int xOffset = x % 32;
	int cycles = rowsDeep / 2;
	cycles *= num_panels_horiz * num_panels_vert;

	int x_panel = floor(x / 32);
	int y_panel = floor(y / 16);

	if (y % 2 == 0)
	{
		return 64 * cycles + 64 * ((num_panels_vert - y_panel - 1) * num_panels_horiz + x_panel) + xOffset;
	}
	else
	{
		return 64 * cycles + 64 * ((num_panels_vert - y_panel - 1) * num_panels_horiz + x_panel) + 63 - xOffset;
	}
}

/**
 * Used in makeColor.
 */
unsigned int h2rgb(unsigned int v1, unsigned int v2, unsigned int hue)
{
	if (hue < 60)
		return v1 * 60 + (v2 - v1) * hue;
	if (hue < 180)
		return v2 * 60;
	if (hue < 240)
		return v1 * 60 + (v2 - v1) * (240 - hue);
	return v1 * 60;
}

/**
 * Used to convert color values between HSL and RGB. S is defaulted to 98.
 * @param hue the H value for the desired color.
 * @param lightness the L value for the desired color.
 * @return the corresponding color represented in RGB
 */
int makeColor(unsigned int hue, unsigned int lightness)
{
	unsigned int red, green, blue;
	unsigned int var1, var2;
	unsigned int saturation = 98;

	if (hue > 359)
		hue = hue % 360;
	if (saturation > 100)
		saturation = 100;
	if (lightness > 100)
		lightness = 100;

	// algorithm from: http://www.easyrgb.com/index.php?X=MATH&H=19#text19
	if (saturation == 0)
	{
		red = green = blue = lightness * 255 / 100;
	}
	else
	{
		if (lightness < 50)
		{
			var2 = lightness * (100 + saturation);
		}
		else
		{
			var2 = ((lightness + saturation) * 100) - (saturation * lightness);
		}
		var1 = lightness * 200 - var2;
		red = h2rgb(var1, var2, (hue < 240) ? hue + 120 : hue - 240) * 255 / 600000;
		green = h2rgb(var1, var2, hue) * 255 / 600000;
		blue = h2rgb(var1, var2, (hue >= 120) ? hue - 120 : hue + 240) * 255 / 600000;
	}
	return (red << 16) | (green << 8) | blue;
}

/**
 * @brief Calculates the corresponding 1 dimensional array from 2d coordinates
 * @param x the desired x index
 * @param y the desired y index
 * @return the corresponding 1d index
 */
int arrayIndex(int x, int y) {
	return (x * height) + y;
}

/**
 * Used to precalculate an array storing the results of running xy() on every led on the board.
 * @param coords an array representing the board.
 */
void coordCalc(unsigned int* coords) {
	for(int i = 0; i < width; i ++) {
		for(int j = 0; j < height; j ++) {
			if(num_panels_vert == 2 && j < 16) {
				coords[arrayIndex(i, j)] = xy(width - 1 - i,  15 - j );
			}
			else {
				coords[arrayIndex(i , j)] = xy(i, j);
			}
		}
	}
}






#endif /* UTIL */