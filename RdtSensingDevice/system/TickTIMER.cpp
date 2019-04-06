/*
 * TickTIMER.cpp
 *
 * Created: 2019-04-06 11:28:57
 *  Author: kong
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "system/Util.h"
#include "system/ConsoleUART.h"
#include "system/BluetoothUART.h"
#include "system/TickTIMER.h"
#include "main.h"

ISR(TIMER0_COMP_vect) {
    x_tick.isr();
}

TickTIMER::TickTIMER() : m_millisec(0), m_sec(0)
{
}

TickTIMER::~TickTIMER()
{
    end();
}

void TickTIMER::begin(unsigned int interval)
{
    m_interval = interval;
    sbi(TCCR0, CS02);  // prescaler(64)
    sbi(TCCR0, WGM01); // ctc mode
    outb(TCNT0, 0);
    outb(OCR0, 249);   // 1ms
    sbi(TIMSK, OCIE0); // interrupt enable
}

void TickTIMER::end()
{
    cbi(TIMSK, OCIE0); // disable
}

unsigned long TickTIMER::getMillisec()
{
    return m_millisec;
}

unsigned long TickTIMER::getSec()
{
    return m_sec;
}

void TickTIMER::isr()
{
    m_millisec++;
    if (x_manual_mode) {
        return;
    }
    if (!(m_millisec % m_interval)) {
        if (x_showup) {
            x_console.write("T");
            x_bluetooth.write("T");
        }
    }
    if (!(m_millisec % 1000)) {
        m_sec++;
    }
}

TickTIMER x_tick;

/* EOF */