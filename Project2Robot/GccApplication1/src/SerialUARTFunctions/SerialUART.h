/*
* SerialUART.h
*
* Author: Martin och Michael.
*/

#ifndef SerialUART_H_
#define SerialUART_H_

void setupUART(void);
void setupSTDIO(void);
uint8_t readByte(void);
uint32_t isRXReady(void);
uint32_t waitRXReady(void);
double readDouble(void);

#endif /* SerialUART_H_ */