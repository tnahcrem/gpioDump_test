/*
 ============================================================================
 Name        : gpioDump_test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "gpioDump.h"

int main(void) {
	uint8_t* buf = (uint8_t*)malloc(64);
	memset((void*)buf,0x55,64);
	gpioDump_init(0);
	gpioDump_showMem(buf,64);

	return EXIT_SUCCESS;
}
