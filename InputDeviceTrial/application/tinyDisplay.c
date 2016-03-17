/*
 * tinyDisplay.c
 *
 * Created: 2016-03-05 3:02:00 AM
 *  Author: take-iwiw
 */ 

#include <avr/io.h>
#include "../myCommon.h"
#include <util/delay.h>
#include "../myLibraries/myStdio.h"
#include "../myLibraries/myTimer.h"
#include "../myLibraries/myVideo.h"
#include "../color/colorRGB.h"

/*** Internal Const Values ***/
#define WIDTH 128
#define HEIGHT 80

/*** Internal Static Variables ***/
/*** Internal Function Declarations ***/

/*** External Function Defines ***/
void tinyDisplayInit()
{
	printPos("Tiny Display", 0, 0);
}

void tinyDisplayLoop()
{
	static uint8_t s_cnt = 0;

	printDecPos(s_cnt++, 0, 1);
	setVideoArea(0, 30, WIDTH, HEIGHT);
	startFrame();
	for(uint8_t y = 0; y < HEIGHT; y++){
		for(uint8_t x = 0; x < WIDTH; x++){
			uint8_t dataHigh = getchar();
			uint8_t dataLow = getchar();
			drawPixel(dataHigh, dataLow);
		}
	}
	uint16_t time = stopFrame();
	//printDecPos(time, 0, 0);
	//printPos("msec", 4, 0);
}

/*** Internal Function Definitions ***/
