/*
 * main.h
 *
 * Created: 2019-04-06 11:56:30
 *  Author: kong
 */

#ifndef MAIN_H_
#define MAIN_H_

//#define F_CPU 16000000UL // move to compile option

#define BAUDRATE_CONSOLE 115200UL
#define BAUDRATE_BLUETOOTH 115200UL
#define TICK_INTERVAL 30 // 30 millisec

extern bool x_showup;
extern bool x_manual_mode;

#endif /* MAIN_H_ */