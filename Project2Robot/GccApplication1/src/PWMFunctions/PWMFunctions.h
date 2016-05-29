 /*
 * PWMFunctions.h
 *
 * Author: Martin och Michael. 
 */
 
#ifndef PWMFUNCTION_H_
#define PWMFUNCTION_H_

void PWMInit(void);
void InitPIN40(void);
void InitPIN38(void);
void LeftWheelPWM(uint32_t);
void RightWheelPWM(uint32_t);

#endif /* FuncPWM_H_ */