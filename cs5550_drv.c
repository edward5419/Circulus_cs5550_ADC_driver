#include "cs5550_DRV.h"



void delay_us(unsigned int us)
{
    while (us--)
    {
        _nop_();
        _nop_();
        _nop_();
        _nop_();
    }
}


void CS5550_InitDRV(void)
{
    CS = 0;
    CS = 1;
    delay_us(50);
    CS = 0;
    delay_us(50);
    delay_us(50);
    SDI = 0;
    SDO = 1;
    SCLK = 0;
    //command for start conversation
    TransferByteDRV(0x80);//
    TransferByteDRV(0xe8);//11101000
}


unsigned long CS5550_ReadRegisterDRV()
{
    unsigned long ADC_long = 0;
    uint8_t i;

    SCLK = 0;
    CS = 0;
    TransferByteDRV(0xe); // ADC value 

    // Read data (24 bits)
    for (i = 0; i < 24; i++)
    {
        ADC_long <<= 1;
        if (SDO)
            ADC_long |= 0x01;

        SCLK = 1;
        SCLK = 0;

        // Set SDI for every 8th bit
        SDI = ((i + 1) % 8 == 0) ? 0 : 1;
    }

    SCLK = 0;
    CS = 1;

    return ADC_long;
}

void TransferByteDRV(unsigned char dat)
{
    unsigned char i;
    SCLK = 0;
    CS = 0;
    //delay_us(50);
    for (i = 0; i < 8; i++)
    {
        if ((dat & 0x80) == 0)
        {
            SDI = 0;
        }
        else
        {
            SDI = 1;
        }

        SCLK = 1;
        //delay_us(50);
        SCLK = 0;
        dat <<= 1;
    }
}

unsigned long CombineBytesToLongDRV(unsigned char* bytes)
{
    unsigned long result = 0;
    result = (unsigned long)bytes[0] << 16 |
        (unsigned long)bytes[1] << 8 |
        (unsigned long)bytes[2];
    return result;
}