#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pinAssign.h"
#include <wiringPi.h>

//wiringPiにてPWM制御

//緊急停止用にの出力値を記憶
int	pwmCnt;

//18ピンをPWM出力に設定
void InitPWM()
{
	pinMode(GPIO18, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	pwmSetClock(16);
	pwmSetRange(1024);
}

int main(int argc, char *argv[])
{
	int			i;

	//GPIOのイニシャライズ
	if(wiringPiSetup() == -1){
		printf("Initialization of wiringPi failed.\n");
		return -1;
	}

	//18ピンをPWM出力モードに設定
	InitPWM();

	//10ms周期ごとに1ずつインクリメント
	for(i = 0; i < 1024; i++){
		pwmCnt	= i;
		//PWM出力
		pwmWrite(GPIO18, pwmCnt);
		delay(10);
	}
	delay(2000);

	for(i = 1024; i >= 0; i--){
		pwmCnt	= i;

		//PWMを減衰
		pwmWrite(GPIO18, pwmCnt);
		delay(10);
	}

	delay(1000);
	
	// PWM stop
	pwmWrite(GPIO18, 0);

	return 0;
}
