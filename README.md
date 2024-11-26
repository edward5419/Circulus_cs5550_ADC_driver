# CS5550 ADC Module Driver Code

Driver code for CS5550 ADC module.

## Functions

- **`void CS5550_InitDRV(void);`**  
  Initiates the CS5550 module. The register is controlled as explained in the datasheet.

- **`void TransferByteDRV(unsigned char dat);`**  
  Transfers a byte of data to the CS5550. Each time a bit is transferred, you need to set SCLK high and low.

- **`unsigned long CS5550_ReadRegisterDRV();`**  
  CORE FUNCTION! Reads a 24-bit ADC value from the CS5550 and return unsigned long value.

These three functions are sufficient to use the CS5550, while other functions are legacy. Please note that you need to set your own pins (SCLK, CS, SDO, SDI) according to your board.
