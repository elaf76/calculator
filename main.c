/*
3 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: EVA
 */


#include "Dio.h"
#include "lcd.h"
#include "KeyPad.h"


uint16 calc_sum(  uint8 a[],uint8 b[],uint8 n,uint8 m);
uint16 calc_sub(  uint8 a[],uint8 b[],uint8 n,uint8 m);
uint16 calc_multi(uint8 a[],uint8 b[],uint8 n,uint8 m);
uint16 calc_div(  uint8 a[],uint8 b[],uint8 n,uint8 m);

uint8 KpValue=255;

uint8 FristNum[4];                       //Array to store the first number (Assuming the number of digits 4)
uint8 SecondNum[4];		                //Array to store the Second number (Assuming the number of digits 4)

uint8 counter = 0;
int main()
{
	Dio_init();                          //Initialise pins
	LCD_Init();							 //Initialise LCD
	/*   Loading to Start Calculator    */
	LCD_Send_Command(_LCD_CLEAR);
	LCD_Send_String_Pos("Loading",1,1);
	for(uint8 counter=0;counter<4;counter++)
	{
	LCD_Send_Char_Pos('.',1,counter+8);
	_delay_ms(500);
}
	_delay_ms(200);
	LCD_Send_Command(_LCD_CLEAR);
	LCD_Send_String_Pos("Welecome",1,1);

		KpValue == '\0';
		counter=0;
		uint8 opration=0;


		/*    Getting The First Number    */
		while(1)
		{
			do{
				KpValue = KP_GetPressed();
				_delay_ms(200);
			}while(KpValue == '\0');
			if(KpValue == '+' || KpValue == '-' || KpValue == '/' || KpValue == '*'){
				opration = KpValue;
				LCD_Send_Char_Pos(KpValue,1,counter+1);
				break;
			}
			FristNum[counter]=KpValue;
			counter++;
			LCD_Send_Number_Pos(KpValue,1,counter);

		}
		uint8 counter2=counter+1;
		uint8 counter3=0;


		/*    Getting The Second Number    */
		while(1)
		{
			do{
				KpValue = KP_GetPressed();
				_delay_ms(200);
			}while(KpValue == '\0');
			if(KpValue == '=' ){
				LCD_Send_Char_Pos(KpValue,1,counter2+1);
				break;}
			SecondNum[counter3]=KpValue;
			counter2++;
			counter3++;
			LCD_Send_Number_Pos(KpValue,1,counter2);
		}


		/*     switch which operation was Selected */
		switch(opration)
		{
		case '+': LCD_Send_Number_Pos(calc_sum(FristNum,SecondNum,counter,counter3),1,counter2+3);break;
		case '-': LCD_Send_Number_Pos(calc_sub(FristNum,SecondNum,counter,counter3),1,counter2+3);break;
		case '*': LCD_Send_Number_Pos(calc_multi(FristNum,SecondNum,counter,counter3),1,+3);break;
		case '/': LCD_Send_Number_Pos(calc_div(FristNum,SecondNum,counter,counter3),1,counter2+3);break;
		}
		_delay_ms(3000);
		LCD_Send_Command(_LCD_CLEAR);

	}






uint16 calc_sum(uint8 a[],uint8 b[],uint8 n,uint8 m){
	uint16 num1=a[0];
	uint16 num2=b[0];
	for(uint8 counter=1;counter<n;counter++)
	{

		num1 = num1*10 +a[counter];
	}

	for(uint8 counter=1;counter<m;counter++)
	{
		num2= num2*10 +b[counter];
	}

	return (num1+num2);
}


uint16 calc_sub(uint8 a[],uint8 b[],uint8 n,uint8 m){
	uint16 num1=a[0];
	uint16 num2=b[0];
	for(uint8 counter=1;counter<n;counter++)
	{
		num1 = num1*10 +a[counter];
	}

	for(uint8 counter=1;counter<m;counter++)
	{
		num2= num2*10 +b[counter];
	}

	return (num1-num2);
}

uint16 calc_multi(uint8 a[],uint8 b[],uint8 n,uint8 m){
	uint16 num1=a[0];
	uint16 num2=b[0];
	for(uint8 counter=1;counter<n;counter++)
	{
		num1 = num1*10 +a[counter];
	}

	for(uint8 counter=1;counter<m;counter++)
	{
		num2= num2*10 +b[counter];
	}

	return (num1*num2);
}

uint16 calc_div(uint8 a[],uint8 b[],uint8 n,uint8 m){
	uint16 num1=a[0];
	uint16 num2=b[0];
	for(uint8 counter=1;counter<n;counter++)
	{
		num1 = num1*10 +a[counter];
	}

	for(uint8 counter=1;counter<m;counter++)
	{
		num2= num2*10 +b[counter];
	}

	return (num1/num2);
}


