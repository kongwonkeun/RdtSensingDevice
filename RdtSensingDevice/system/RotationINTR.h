/*
 * RotationINTR.h
 *
 * Created: 2019-04-06 11:34:52
 *  Author: kong
 */


#ifndef ROTATIONINTR_H_
#define ROTATIONINTR_H_

#define WHEEL_SIZE 34.56 // 11cm * pi --> 34.56 cm

class RotationINTR
{
public:
    RotationINTR();
    ~RotationINTR();
    int  begin();
    unsigned int getVelocity();
    void isr();
private:
    unsigned long m_rotation;
    unsigned long m_msec;
public:
    unsigned int  m_cmeter_per_sec;
    unsigned int  m_last_cmeter_per_sec;
};

extern RotationINTR x_rotation;

#endif /* ROTATIONINTR_H_ */