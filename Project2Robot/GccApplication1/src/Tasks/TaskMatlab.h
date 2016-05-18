/*
 * TaskMatlab.h
 *
 *  Author: Martin and Michael
 */ 


#ifndef TASKMATLAB_H_
#define TASKMATLAB_H_

void TaskMatLab(void *p);
void SendControlSignalLeftPID(uint32_t signal, float desiredValue,float error,uint32_t average);



#endif /* TASKMATLAB_H_ */