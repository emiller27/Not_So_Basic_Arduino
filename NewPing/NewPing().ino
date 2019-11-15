#include <NewPing.h>
int TRIGGER_PIN = 12;
int ECHO_PIN = 11;
#define MAX_DISTANCE 200
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int distance; //
int redPin = 10;
int yellowPin = 3;
int greenPin = 6;
void setup()
{
	Serial.begin(9600);
	pinMode(TRIGGER_PIN, OUTPUT);
	pinMode(ECHO_PIN, INPUT);
	pinMode(redPin, OUTPUT);
	pinMode(yellowPin, OUTPUT);
	pinMode(greenPin, OUTPUT);
	/*PIN GREEN: 6
	PIN YELLOW: 3  g
	PIN RED: 10 */
}

void loop()
{
	distance = sonar.ping_cm();
	Serial.println(distance);
	delay(50);
	/* DISTANCES
	GREEN: COLD
	YELLOW: MEDIUM
	RED : HOT */
	if (distance != 0 && distance < 150)
	{
		if (distance < 15)
		{
			digitalWrite(greenPin, HIGH);
		}
		else
		{
			digitalWrite(greenPin, LOW);
		}
		if (distance < 10)
		{
			digitalWrite(yellowPin, HIGH);
		}
		else
		{
			digitalWrite(yellowPin, LOW);
		}
		if (distance < 5)
		{
			digitalWrite(redPin, HIGH);
		}
		else
		{
			digitalWrite(redPin, LOW);
		}
	}
}