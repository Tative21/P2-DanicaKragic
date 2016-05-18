/*
 * JoystickOptionsYAxis.h
 *
 *  Author: Martin  and Michael
 */ 


#ifndef JOYSTICKOPTIONSYAXIS_H_
#define JOYSTICKOPTIONSYAXIS_H_

void TaskPIDLeft(void *p);
float CalcSignal(float sampTime, float k_p, float k_i, float k_d, float currErr, float prevErr, int32_t sumErr);
void valuesforPWM(float finalU);
void SetPointLeftWheel(float setPoint,uint32_t theflagdriveleft);


#endif /* JOYSTICKOPTIONSYAXIS_H_ */