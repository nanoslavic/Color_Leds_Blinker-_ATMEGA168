#define ADC_VREF_TYPE 0x00

void adc_Init(void){
// ADC initialization
// ADC Clock frequency: 500,000 kHz
// ADC Voltage Reference: AREF pin
// ADC High Speed Mode: Off
// ADC Auto Trigger Source: None
ADMUX=ADC_VREF_TYPE & 0xff;
ADCSRA=0x85;
//SFIOR&=0xEF;
}

// Read the AD conversion result
uint16_t adc_Read(uint8_t adc_input){
ADMUX=adc_input | (ADC_VREF_TYPE & 0xff);
// Delay needed for the stabilization of the ADC input voltage
delay_us(10);
// Start the AD conversion
ADCSRA|=0x40;
// Wait for the AD conversion to complete
while ((ADCSRA & 0x10)==0);
ADCSRA|=0x10;
return ADCW;
}
