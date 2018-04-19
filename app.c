#include <stdio.h>
#include <string.h>
#include "mf624.h"


/* helper functions */
void delay(int d)  
{
     for (int i =0; i<d; i++)
        for(int j=0; j<10000*10000; j++);
}

/* print one byte as binary number */
void print_8bin(int nr)
{
    for (int i = 7; i >= 0; i--) {
        printf("%d" , ((nr & (1 << i)) > 0));
     }

    printf("\n");
}


int main(int argc, char* argv[])
{
    mf624_state_t* mfst = &mf624_state;
    mmap_regions(mfst);

    while (1){
        printf("Reading DIO: ");
        print_8bin(DIO_read(mfst));
        delay(1);

        printf("Reading ADC0: ");
        printf("%f V\n", ADC_read(mfst, AD0));
        delay(1);

        printf("Reading ADC1: ");
        printf("%f V\n", ADC_read(mfst, AD1));
        delay(1);

        printf("Setting DA1 to 10 V\n");
        DAC_write(mfst, DA1, 0x3FFF);
        delay(1);

        printf("Setting DA1 to 5 V\n");
        DAC_write(mfst, DA1, 0x3000);
        delay(1);

        printf("Setting DIO to 0xff\n");
        DIO_write(mfst, 0xff);
        delay(1);

        printf("Setting DIO to 0x00\n");
        DIO_write(mfst, 0x00);
        delay(1);

        printf("----------------------\n\n");
    }

    return 0;
}

