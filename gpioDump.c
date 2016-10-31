/*
 * gpioDump.c
 *
 *  Created on: Oct 30, 2016
 *      Author: hmerchan
 */


#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "gpioDump.h"

// GLOBALS
int  gpioDump_gpio;
uint32_t gpioDump_loopCnt;


// system specific functions
#define GPIO_SET_DIRECION(gpioNum,dir)
#define GPIO_SET(gpioNum,val)
#define DELAY_US(usVal)
#define LOCK_CONTEXT
#define UNLOCK_CONTEXT
#define GPIO_DIRECTION_OUTPUT 1
#define GPIODUMP_STARTBIT  0
#define GPIODUMP_STOPBIT   1

/*****************************************************************************
*    Function: void gpioDump_init(int  gpioNum)
*
*    Abstract: gpio dump init function
*
*               type : what type of gpio to use
*    Return:
*
 *****************************************************************************/
void gpioDump_init(int  gpioNum)
{
	gpioDump_gpio = gpioNum;
	gpioDump_loopCnt = 120;
    // set direction as output
	GPIO_SET_DIRECION(gpioDump_gpio, GPIO_DIRECTION_OUTPUT);

    // set it to zero
	GPIO_SET( gpioDump_gpio, GPIODUMP_STOPBIT);
    DELAY_US(10);
}

/*****************************************************************************
*    Function: void gpioDump_showByte(uint8_t byte)
*
*    Abstract: This function is used to dump one byte by bit banging a GPIO
*
*    Return:
*
 *****************************************************************************/
void gpioDump_showByte(uint8_t byte)
{
    uint8_t  bits[10];
    uint8_t  i, j;

    bits[0] = GPIODUMP_STARTBIT; // start bit
    for(i = 1; i < 9; i ++)
    {
        bits[i] = byte & 0x01;
        byte >>= 1;
    }
    bits[i] = GPIODUMP_STOPBIT;  // stop bit


    // lock context to ensure timing
    LOCK_CONTEXT;

    for(j = 0; j < 10; j ++)
    {
    	GPIO_SET( gpioDump_gpio,  bits[j]);
        for(i = 0; i < gpioDump_loopCnt; i ++)
        {
        }
    }
    UNLOCK_CONTEXT;

	DELAY_US(50);
}

/*****************************************************************************
*    Function: void gpioDump_showMem(uint8_t* adr,uint32_t len)
*
*    Abstract: This function is used to dump a section of memory
*
*    Return:
*
 *****************************************************************************/
void gpioDump_showMem(uint8_t* adr,uint32_t len)
{
	uint32_t i;
    for(i = 0; i < len; i++)
    {
        gpioDump_showByte(adr[i]);
    }
}
