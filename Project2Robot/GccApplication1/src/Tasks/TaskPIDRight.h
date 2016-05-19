/*
 * TaskPIDRight.h
 *
 * Created: 2016-05-12 17:04:04
 *  Author: Spellabbet
 */ 


#ifndef TASKPIDRIGHT_H_
#define TASKPIDRIGHT_H_

void TaskPIDRight(void *p);
float CalcSignalRight(float sampTime, float k_p, float k_i, float k_d, float currErr, float prevErr, int32_t sumErr);
void valuesforPWMRight(float finalULeft);
void SetPointRightWheel(float setPoint);


#endif /* TASKPIDRIGHT_H_ */