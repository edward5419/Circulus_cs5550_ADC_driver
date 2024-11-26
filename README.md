# CS5550 ADC module driver code

Driver code for CS5550 ADC module

## functions


- void CS5550_InitDRV(void);
initiate CS5550 module. register is controlled as explained in datasheet.

- void TransferByteDRV(unsigned char dat);
transfer a byte data to CS5550, everytime transfer a bit, you need to set SCLK high and low.

- unsigned long CS5550_ReadRegisterDRV();
CORE FUNCTION! read 24bit ADC value from CS5550.

these three function if enough to use CS5550, and other function is legacy.
but please notice that the pins such as SCLK, CS, SDO, SDI, you need to set your own pin according to your board.
