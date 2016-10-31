/*
 * gpioDump.h
 *
 *  Created on: Oct 30, 2016
 *      Author: hmerchan
 */

#ifndef GPIODUMP_H_
#define GPIODUMP_H_


void gpioDump_init(int  gpioNum);
void gpioDump_showByte(uint8_t byte);
void gpioDump_showMem(uint8_t* adr,uint32_t len);


#endif /* GPIODUMP_H_ */
