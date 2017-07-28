
/* part specific constants and macros */
#include <m8c.h>

/* PSoC API definitions for all User Modules */
#include "PSoCAPI.h"

/* Definitions for all input and output operation */
#include "stdio.h"

/* Macros to set ADC parameters */
#define GAIN	1
#define MAX_ADC_COUNTS	16383
#define ADC_RANGE	5000

/* Macros to select port 1 */
#define PORT_1_3	PRT1DR

/* Variable to store the ADC result */
WORD adc_result;

/* Variable to store the measured input in millivolts */
WORD v_in;

void main(void)
{
	static unsigned int index;
	
		/* Buffer used for the long to ASCII conversion */
		char LCDBuffer[17];

		/* Initializes LCD to use the multi-line 4-bit interface */
		LCD_1_Start();
		
		/* Enable global interrupts */
		M8C_EnableGInt ;

		/* Set the position to print the character */
		LCD_1_Position(0,0);

		/* print the Hello World in the first line */
		LCD_1_PrCString("Hello World!");

		/* Starts the LED1_PWM and LED2_PWM, high enable input begins the Counter */
		LED1_PWM_Start();
		LED2_PWM_Start();

		/* Initializes and starts the EzADC User Module resources */
		EzADC_1_Start(EzADC_1_HIGHPOWER);

		/* Starts the ADC conversion */
		EzADC_1_GetSamples(0);
		while(1)
		{
			/* Wait for the ADC result to be available */
			while(!(EzADC_1_fIsDataAvailable()));

			/* Read the ADC result and clear the data ready flag */
			adc_result = EzADC_1_iGetDataClearFlag();

			/* Calculate input voltage in mV */
			v_in = (DWORD)adc_result*ADC_RANGE / MAX_ADC_COUNTS / GAIN;

			/* Convert the input voltage to an ascii string */
			csprintf(LCDBuffer, "ADC INPUT:%4dmV", v_in);

			/* Set the position to print the character */
			LCD_1_Position(1,0);

			/* print the voltage in the second line */
			LCD_1_PrString(LCDBuffer);

			/* Toggle the pin 1[3]*/
			PORT_1_3 ^= 0x08;

			/* Give some delay to view toggling effect*/
			for(index = 0; index < 22000; index++);
			}
}

