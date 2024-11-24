#if !defined(CS5550_DRV_H)
#define CS5550_DRV_H
#include "commons.h"
unsigned long CS5550_ReadRegisterDRV();
unsigned long CombineBytesToLongDRV(unsigned char* bytes);
void delay_us(unsigned int us);
void CS5550_InitDRV(void);
void TransferByteDRV(unsigned char dat);
void cs5550_startConversationDRV();


#endif // CS5550_DRV_H
