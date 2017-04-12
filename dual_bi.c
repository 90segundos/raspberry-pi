// RaspberryPi
// Control de motores DC mediante controlador
// MR001-004.1
// 30 marzo 2015
// Utiliza wiringPi

#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define M1_FORW 17
#define M1_BACK 22
#define M1_CONTROL 18

#define M2_FORW 23
#define M2_BACK 24
#define M2_CONTROL 4

int main(void){ 

// Setup control digital
wiringPiSetupGpio();
softPwmCreate(M2_CONTROL, 0, 1023);

pinMode(M1_CONTROL, PWM_OUTPUT); 	// Motor 1 Control de velocidad (a partir de 500/1023)
pinMode(M1_FORW, OUTPUT);		// Motor 1 avance
pinMode(M1_BACK, OUTPUT);		// Motor 1 retroceso

pinMode(M2_FORW, OUTPUT);		// Motor 2 avance
pinMode(M2_BACK, OUTPUT);		// Motor 2 retroceso


// Inicialización de Motores
pwmSetMode(PWM_MODE_MS);
pwmWrite(M1_CONTROL, 1000);
softPwmWrite(M2_CONTROL, 1000);
digitalWrite(M1_FORW, 0);
digitalWrite(M2_FORW, 0);
digitalWrite(M1_BACK, 0);
digitalWrite(M2_BACK, 0);

	printf("\nControl de motor dual --- TEST ---\n"); //Secuencia de prueba
	
	// Motor 1
	digitalWrite(M1_FORW, 1);
	delay(500);
	digitalWrite(M1_FORW, 0);
	delay(500);
	digitalWrite(M1_BACK, 1);
	delay(500);
	digitalWrite(M1_BACK, 0);
	delay(500);
	
	// Motor 2
	digitalWrite(M2_FORW, 1);
	delay(500);
	digitalWrite(M2_FORW, 0);
	delay(500);
	digitalWrite(M2_BACK, 1);
	delay(500);
	digitalWrite(M2_BACK, 0);
	delay(500);
	
	// Motores 1 y 2
	digitalWrite(M1_FORW, 1);
	digitalWrite(M2_FORW, 1);
	delay(500);
	digitalWrite(M1_FORW, 0);
	digitalWrite(M2_FORW, 0);
	delay(500);
	digitalWrite(M1_BACK, 1);
	digitalWrite(M2_BACK, 1);
	delay(500);
	digitalWrite(M1_BACK, 0);
	digitalWrite(M2_BACK, 0);
	delay(500);
	digitalWrite(M1_FORW, 1);
	digitalWrite(M2_BACK, 1);
	delay(500);
	digitalWrite(M1_FORW, 0);
	digitalWrite(M2_BACK, 0);
	delay(500);
	digitalWrite(M2_FORW, 1);
	digitalWrite(M1_BACK, 1);
	delay(500);
	digitalWrite(M2_FORW, 0);
	digitalWrite(M1_BACK, 0);
	delay(500);

return(0);
}


