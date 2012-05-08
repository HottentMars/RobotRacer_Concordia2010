the setBitHigh function is just a define that sets the bit to 1 and setBitLow sets the bit to 0
here is the function that inits the ADC:

void initADC(void)
{
    setBitHigh(ADMUX, REFS1);
    setBitHigh(ADMUX, REFS0);

//chaneel select
    ADMUX = ADMUX + channelPos;

    setBitHigh(ADMUX, ADLAR);    // channel 0, left-justified result

    //enable ADC interupts
    setBitHigh(ADCSRA, ADIF);    
    setBitHigh(ADCSRA, ADIE);

    setBitHigh(ADCSRA, ADFR);    //set ADC to free run

//start ADC
    setBitHigh(ADCSRA, ADEN);
    setBitHigh(ADCSRA, ADSC);
}

and this is the ADC interupt:

ISR(ADC_vect)
{
    crSample = meanOfSample(ADCH); //try to remove the nois

    if (channelPos == LEFT || channelPos == RIGHT)    //ir sensors
    {
        dist = voltToDist(crSample);
        sensorVal[0][channelPos] = dist;
    }

//print something on the serial port so we know we are in business.
// the usart functions are my own so you will need to write your owns if you want to use them.

    usartPuts("left:");
    usartPutn(sensorVal[0][LEFT]);
    usartPuts("  right:");
    usartPutn(sensorVal[0][RIGHT]);
    usartPuts("  ADC:");
    usartPutn(crSample);
    usartPuts("\r\n");

    handleEvents();

//read the next channel
    ADMUX = ADMUX - channelPos;  // remove the old channel from the mux registry
    channelPos = (channelPos + 1)%ADC_CHANELS;
    ADMUX = ADMUX + channelPos;// add the new channel to the mux registry
}


for this code to work you need to enable the interupts also by calling:

 sei();//enable software interrupts

after initializing the ADC.
hope this helps.



void readSensors()
{
	senseReg = 0x00;  // clear teh sensor register
	int z;
	for(z = 0; z < 6; z++)
	{
		ADCSRA |= ( 1<<ADSC ); 		// scan cahnnel 0-5
		while( ADCSRA & (1<<ADSC) );
		if(ADCH > 240)
		{
			senseReg |= (1 << z);		// set bit if line detected	
		}
		ADMUX++;
	}
	ADMUX = ADMUX - 6;
	
	
	

	if( senseReg & 0x01  ) // S1 maybe
	{
		//driveForward(200);
		//delayMe(2);
		//stop();
	}

	if( (senseReg & (0x0002 )) == 0x02 ) // S2
	{
		ValueS2=1;
	}
	else
		ValueS2=0;

	if( (senseReg & (0x0004 )) == 0x04 )
	{

	}

	if( (senseReg & (0x0008 )) == 0x08 ) // S3
	{
		ValueS3=1;
	}
	else
		ValueS3=0;

	if(( senseReg & (0x0010 )) == 0x10 )
	{
		//driveForward(200);
	}
	
	if( (senseReg & (0x0020 )) == 0x20 )



//SECTION 8.2.2   		  Appendix

	{
		//leftCheck = checkTime; 	//new
		//PORTB &= ~( 1<<PB0 ) ;
	}
}


void adcInitialize()
{
	ADMUX |= ((0<<REFS1 )| (1 << REFS0) | (1 << ADLAR));

	// enable the ADC and set the ADC clock to 125 KHz ; 8MHz/64 = 125 KHz ; 64 is a prescaler
	ADCSRA |= ( (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) );

	return;

}
