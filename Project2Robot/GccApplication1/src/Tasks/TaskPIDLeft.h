/*
 * TaskPIDLeft.h
 *
 *  Author: Martin  and Michael
 */ 


#ifndef JOYSTICKOPTIONSYAXIS_H_
#define JOYSTICKOPTIONSYAXIS_H_

void TaskPIDLeft(void *p);
float CalcSignal(float sampTime, float k_p, float k_i, float k_d, float currErr, float prevErr, float sumErr);
void valuesforPWM(float finalU);
void setDesiredValueLeft(float tempdesirevalue);
float getDesiredValueLeft(void);


#endif /* JOYSTICKOPTIONSYAXIS_H_ */