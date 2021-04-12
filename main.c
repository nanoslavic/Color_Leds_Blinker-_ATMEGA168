#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <stdio.h>

#include "add_lib.c"
#include "delays_lib.c"
#include "adc_M168_lib.c"

void SetLeds_0(uint8_t n){
if (n==0){
	sbi(PORTD,0); sbi(PORTD,1); sbi(PORTD,2);
	return;
	};
if (n==1){
	cbi(PORTD,0); sbi(PORTD,1); sbi(PORTD,2);
	return;
	};
if (n==2){
	sbi(PORTD,0); cbi(PORTD,1); sbi(PORTD,2);
	return;
	};
if (n==3){
	sbi(PORTD,0); sbi(PORTD,1); cbi(PORTD,2);
	return;
	};
if (n==4){
	cbi(PORTD,0); cbi(PORTD,1); sbi(PORTD,2);
	return;
	};	
if (n==5){
	sbi(PORTD,0); cbi(PORTD,1); cbi(PORTD,2);
	return;
	};	
if (n==6){
	cbi(PORTD,0); sbi(PORTD,1); cbi(PORTD,2);
	return;
	};	
if (n==7){
	cbi(PORTD,0); cbi(PORTD,1); cbi(PORTD,2);
	return;
	};	
}

void SetLeds_1(uint8_t n){
if (n==0){
	sbi(PORTC,0); sbi(PORTC,1); sbi(PORTC,2);
	return;
	};
if (n==1){
	cbi(PORTC,0); sbi(PORTC,1); sbi(PORTC,2);
	return;
	};
if (n==2){
	sbi(PORTC,0); cbi(PORTC,1); sbi(PORTC,2);
	return;
	};
if (n==3){
	sbi(PORTC,0); sbi(PORTC,1); cbi(PORTC,2);
	return;
	};
if (n==4){
	cbi(PORTC,0); cbi(PORTC,1); sbi(PORTC,2);
	return;
	};	
if (n==5){
	sbi(PORTC,0); cbi(PORTC,1); cbi(PORTC,2);
	return;
	};	
if (n==6){
	cbi(PORTC,0); sbi(PORTC,1); cbi(PORTC,2);
	return;
	};	
if (n==7){
	cbi(PORTC,0); cbi(PORTC,1); cbi(PORTC,2);
	return;
	};	
}

void SetLeds_2(uint8_t n){
if (n==0){
	sbi(PORTC,3); sbi(PORTC,4); sbi(PORTC,5);
	return;
	};
if (n==1){
	cbi(PORTC,3); sbi(PORTC,4); sbi(PORTC,5);
	return;
	};
if (n==2){
	sbi(PORTC,3); cbi(PORTC,4); sbi(PORTC,5);
	return;
	};
if (n==3){
	sbi(PORTC,3); sbi(PORTC,4); cbi(PORTC,5);
	return;
	};
if (n==4){
	cbi(PORTC,3); cbi(PORTC,4); sbi(PORTC,5);
	return;
	};	
if (n==5){
	sbi(PORTC,3); cbi(PORTC,4); cbi(PORTC,5);
	return;
	};	
if (n==6){
	cbi(PORTC,3); sbi(PORTC,4); cbi(PORTC,5);
	return;
	};	
if (n==7){
	cbi(PORTC,3); cbi(PORTC,4); cbi(PORTC,5);
	return;
	};	
}

uint8_t GetRND(void){
uint8_t i=0;
uint8_t n=0;

for (i=0;i<255;i++){
	if ((adc_Read(7)&0x1)>0) n++;
	};

return (n%8);
}



int main(void){

sbi(PORTD,0); sbi(PORTD,1); sbi(PORTD,2);
sbi(PORTC,0); sbi(PORTC,1); sbi(PORTC,2);
sbi(PORTC,3); sbi(PORTC,4); sbi(PORTC,5);
sbi(DDRD,0); sbi(DDRD,1); sbi(DDRD,2);
sbi(DDRC,5); sbi(DDRC,4); sbi(DDRC,3);
sbi(DDRC,2); sbi(DDRC,1); sbi(DDRC,0);

adc_Init();

uint8_t T0=0;
uint8_t T1=0;
uint8_t T2=0;

while (1){
	if (T0==0){
		T0=GetRND()+1;
		SetLeds_0(GetRND());
		};

	if (T1==0){
		T1=GetRND()+1;
		SetLeds_1(GetRND());
		};
		
	if (T2==0){
		T2=GetRND()+1;
		SetLeds_2(GetRND());
		};

	delay_ms(50);

	T0--; T1--; T2--;
	};
	
return(0);
}
