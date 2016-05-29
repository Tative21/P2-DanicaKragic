/*
* TaskPIDRight.h
*
*
*  Author: Michael och Martin
*/

#ifndef TASKPIDRIGHT_H_
#define TASKPIDRIGHT_H_

void TaskPIDRight(void *p);
float CalcSignalRight(float sampTime, float k_p, float k_i, float k_d, float currErr, float prevErr, float sumErr);
void valuesforPWMRight(float finalULeft);
void setDesiredValueRight(float tempdesire);
float getDesiredValueRight(void);


#endif /* TASKPIDRIGHT_H_ */