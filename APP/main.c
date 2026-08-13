#include "../LIB/STd_Types.h"
#include "../LIB/BitMath.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/Timer0/Timer0.h"

#include "../HAL/LED/LED.h"
#include "../HAL/Button/Button.h"
#include "../HAL/Buzzer/Buzzer.h"
#include "../HAL/Motor/Motor.h"

/* Directions order: 0=North , 1=East , 2=South , 3=West */
#define NUM_DIRECTIONS   4

u8 G_au8Port[NUM_DIRECTIONS]       = {DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD} ;

u8 G_au8LedRedPin[NUM_DIRECTIONS]   = {DIO_PIN0 , DIO_PIN0 , DIO_PIN0 , DIO_PIN2} ;
u8 G_au8LedGreenPin[NUM_DIRECTIONS] = {DIO_PIN1 , DIO_PIN1 , DIO_PIN1 , DIO_PIN3} ;
u8 G_au8MotorPin1[NUM_DIRECTIONS]   = {DIO_PIN2 , DIO_PIN2 , DIO_PIN2 , DIO_PIN4} ;
u8 G_au8MotorPin2[NUM_DIRECTIONS]   = {DIO_PIN3 , DIO_PIN3 , DIO_PIN3 , DIO_PIN5} ;
u8 G_au8ButtonPin[NUM_DIRECTIONS]   = {DIO_PIN4 , DIO_PIN4 , DIO_PIN4 , DIO_PIN6} ;
u8 G_au8BuzzerPin[NUM_DIRECTIONS]   = {DIO_PIN5 , DIO_PIN5 , DIO_PIN5 , DIO_PIN7} ;

volatile u8 G_u8ActiveDirection = 0 ;

void Timer_Callback (void)
{
	G_u8ActiveDirection ++ ;
	if (G_u8ActiveDirection >= NUM_DIRECTIONS)
	{
		G_u8ActiveDirection = 0 ;
	}
}

int main(void)
{
	u8 L_u8Dir ;
	u8 L_u8BtnStatus ;

	/* ===================================================
	 * 1. Initialization
	 * =================================================== */
	for (L_u8Dir = 0 ; L_u8Dir < NUM_DIRECTIONS ; L_u8Dir++)
	{
		HLED_voidInit (G_au8Port[L_u8Dir] , G_au8LedRedPin[L_u8Dir]) ;
		HLED_voidInit (G_au8Port[L_u8Dir] , G_au8LedGreenPin[L_u8Dir]) ;

		HDCM_voidInit (G_au8Port[L_u8Dir] , G_au8MotorPin1[L_u8Dir] , G_au8MotorPin2[L_u8Dir]) ;

		HPB_voidInit  (G_au8Port[L_u8Dir] , G_au8ButtonPin[L_u8Dir]) ;

		HBUZZER_voidInit (G_au8Port[L_u8Dir] , G_au8BuzzerPin[L_u8Dir]) ;
	}

	MTimer0_voidInit (TIMER0_PRESCALLER_64 , TIMER0_OVF) ;
	MTimer0_voidSetDesiredTime (3000000 , Timer_Callback) ;

	/* ===================================================
	 * 2. Main Super Loop
	 * =================================================== */
	while(1)
	{
		for (L_u8Dir = 0 ; L_u8Dir < NUM_DIRECTIONS ; L_u8Dir++)
		{
			if (L_u8Dir == G_u8ActiveDirection)
			{
				/* Light open (green) */
				HLED_voidTurnOn  (G_au8Port[L_u8Dir] , G_au8LedGreenPin[L_u8Dir]) ;
				HLED_voidTurnOff (G_au8Port[L_u8Dir] , G_au8LedRedPin[L_u8Dir]) ;
			}
			else
			{
				/* Light closed (red) */
				HLED_voidTurnOff (G_au8Port[L_u8Dir] , G_au8LedGreenPin[L_u8Dir]) ;
				HLED_voidTurnOn  (G_au8Port[L_u8Dir] , G_au8LedRedPin[L_u8Dir]) ;
			}

			L_u8BtnStatus = HPB_u8GetStatues (G_au8Port[L_u8Dir] , G_au8ButtonPin[L_u8Dir]) ;

			if (L_u8BtnStatus == PB_PRESSED)
			{
				if (L_u8Dir == G_u8ActiveDirection)
				{
					/* Button pressed while light is open -> motor moves */
					HDCM_voidTurnOn  (G_au8Port[L_u8Dir] , G_au8MotorPin1[L_u8Dir] , G_au8MotorPin2[L_u8Dir]) ;
					HBUZZER_voidTurnOff (G_au8Port[L_u8Dir] , G_au8BuzzerPin[L_u8Dir]) ;
				}
				else
				{
					/* Button pressed while light is closed -> buzzer warns */
					HDCM_voidTurnOff (G_au8Port[L_u8Dir] , G_au8MotorPin1[L_u8Dir] , G_au8MotorPin2[L_u8Dir]) ;
					HBUZZER_voidTurnOn  (G_au8Port[L_u8Dir] , G_au8BuzzerPin[L_u8Dir]) ;
				}
			}
			else
			{
				HDCM_voidTurnOff (G_au8Port[L_u8Dir] , G_au8MotorPin1[L_u8Dir] , G_au8MotorPin2[L_u8Dir]) ;
				HBUZZER_voidTurnOff (G_au8Port[L_u8Dir] , G_au8BuzzerPin[L_u8Dir]) ;
			}
		}
	}

	return 0 ;
}
