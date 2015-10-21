#define NOTE_B0  0x1B
#define NOTE_C1  0x10
#define NOTE_CS1 0x11
#define NOTE_D1  0x12
#define NOTE_DS1 0x13
#define NOTE_E1  0x14
#define NOTE_F1  0x15
#define NOTE_FS1 0x16
#define NOTE_G1  0x17
#define NOTE_GS1 0x18
#define NOTE_A1  0x19
#define NOTE_AS1 0x1A
#define NOTE_B1  0x1B
#define NOTE_C2  0x20
#define NOTE_CS2 0x21
#define NOTE_D2  0x22
#define NOTE_DS2 0x23
#define NOTE_E2  0x24
#define NOTE_F2  0x25
#define NOTE_FS2 0x26
#define NOTE_G2  0x27
#define NOTE_GS2 0x28
#define NOTE_A2  0x29
#define NOTE_AS2 0x2A
#define NOTE_B2  0x2B
#define NOTE_C3  0x30
#define NOTE_CS3 0x31
#define NOTE_D3  0x32
#define NOTE_DS3 0x33
#define NOTE_E3  0x34
#define NOTE_F3  0x35
#define NOTE_FS3 0x36
#define NOTE_G3  0x37
#define NOTE_GS3 0x38
#define NOTE_A3  0x39
#define NOTE_AS3 0x3A
#define NOTE_B3  0x3B
#define NOTE_C4  0x40
#define NOTE_CS4 0x41
#define NOTE_D4  0x42
#define NOTE_DS4 0x43
#define NOTE_E4  0x44
#define NOTE_F4  0x45
#define NOTE_FS4 0x46
#define NOTE_G4  0x47
#define NOTE_GS4 0x48
#define NOTE_A4  0x49
#define NOTE_AS4 0x4A
#define NOTE_B4  0x4B
#define NOTE_C5  0x50
#define NOTE_CS5 0x51
#define NOTE_D5  0x52
#define NOTE_DS5 0x53
#define NOTE_E5  0x54
#define NOTE_F5  0x55
#define NOTE_FS5 0x56
#define NOTE_G5  0x57
#define NOTE_GS5 0x58
#define NOTE_A5  0x59
#define NOTE_AS5 0x5A
#define NOTE_B5  0x5B
#define NOTE_C6  0x60
#define NOTE_CS6 0x61
#define NOTE_D6  0x62
#define NOTE_DS6 0x63
#define NOTE_E6  0x64
#define NOTE_F6  0x65
#define NOTE_FS6 0x66
#define NOTE_G6  0x67
#define NOTE_GS6 0x68
#define NOTE_A6  0x69
#define NOTE_AS6 0x6A
#define NOTE_B6  0x6B
#define NOTE_C7  0x70
#define NOTE_CS7 0x71
#define NOTE_D7  0x72
#define NOTE_DS7 0x73
#define NOTE_E7  0x74
#define NOTE_F7  0x75
#define NOTE_FS7 0x76
#define NOTE_G7  0x77
#define NOTE_GS7 0x78
#define NOTE_A7  0x79
#define NOTE_AS7 0x7A
#define NOTE_B7  0x7B
#define NOTE_C8  0x80
#define NOTE_CS8 0x81
#define NOTE_D8  0x82
#define NOTE_DS8 0x83
typedef struct {
	byte note;
	int duration;
	int delay;
}Tone;

Tone songOfStorm[43] = {
	{ NOTE_D5,100,80 },
	{ NOTE_F5,100,80 },
	{ NOTE_D6,200,250 },

	{ NOTE_D5,100,80 },
	{ NOTE_F5,100,80 },
	{ NOTE_D6,200,250 },

	{ NOTE_E6,200,200 },
	{ NOTE_F6,100,100 },
	{ NOTE_E6,100,80 },
	{ NOTE_F6,100,80 },
	{ NOTE_E6,100,80 },
	{ NOTE_C6,100,80 },
	{ NOTE_A5,100,300 },

	{ NOTE_A5,200,100 },
	{ NOTE_D5,200,100 },
	{ NOTE_F5,100,100 },
	{ NOTE_G5,100,100 },
	{ NOTE_A5,100,500 },

	{ NOTE_A5,200,100 },
	{ NOTE_D5,200,100 },
	{ NOTE_F5,100,100 },
	{ NOTE_G5,100,100 },
	{ NOTE_E5,100,500 },

	{ NOTE_D5,100,80 },
	{ NOTE_F5,100,80 },
	{ NOTE_D6,200,250 },

	{ NOTE_D5,100,80 },
	{ NOTE_F5,100,80 },
	{ NOTE_D6,200,250 },

	{ NOTE_E6,200,200 },
	{ NOTE_F6,100,100 },
	{ NOTE_E6,100,80 },
	{ NOTE_F6,100,80 },
	{ NOTE_E6,100,80 },
	{ NOTE_C6,100,80 },
	{ NOTE_A5,100,300 },

	{ NOTE_A5,200,100 },
	{ NOTE_D5,200,100 },
	{ NOTE_F5,100,100 },
	{ NOTE_G5,100,100 },
	{ NOTE_A5,300,100 },
	{ NOTE_A5,200,100 },
	{ NOTE_D5,300,2000 },
};
int freqTable[12] = { 2093, 2217, 2349, 2489, 2637, 2794, 2960, 3136, 3322, 3520, 3729, 3951 };
int freq = 0;
int ledPin = 13; //For visual as well
int speakerPin = 11; //Speaker or Piezo buzzer on pin 11
void beep(unsigned char speakerPin, byte note, long timeInMilliseconds)  //code for working out the rate at which each note plays and the frequency.
{
	freq = freqTable[note & 0x0F] >> (7 - (note / 16));
	digitalWrite(ledPin, HIGH);

	long delayAmount = (long)(1000000 / freq);
	long loopTime = (long)((timeInMilliseconds * 1000) / (delayAmount * 2));
	for (int x = 0; x<loopTime; x++)
	{
		digitalWrite(speakerPin, HIGH);
		delayMicroseconds(delayAmount);
		digitalWrite(speakerPin, LOW);
		delayMicroseconds(delayAmount);
	}
	digitalWrite(ledPin, LOW);
	delay(20);
}

void song()
{
	for (int i = 0; i< 43; i++)
	{
		beep(speakerPin, songOfStorm[i].note, songOfStorm[0].duration);
		delay(songOfStorm[i].delay);
	}
}

void setup()
{
	pinMode(ledPin, OUTPUT); // Setting both pins to outputs
	pinMode(speakerPin, OUTPUT);
	Serial.begin(9600);
}

void loop()
{
	song();
}


