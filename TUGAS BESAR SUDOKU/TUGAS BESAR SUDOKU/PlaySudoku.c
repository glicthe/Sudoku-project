#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include "PlaySudoku.h"
#include "GameSudoku.h"


void* timer( void * arg){
	int hour = 0, minute = 0, second = 0;
	printTimer(hour, minute, second);
	counter(hour, minute, second);
	return NULL;
	
}

int printTimer(int h, int m, int s){
	printf("%d:%d:%d", h, m, s);
}

int counter(int h, int m, int s){
	while(1){
		if (m > 59){
			m = 0;
			h++;
		}
		if (s > 59){
			s = 0;
			m++;
		}
		printTimer(h, m, s);
		delay(1000);
		s++;
	}
}

void delay(int ms){
	clock_t timeDelay = ms + clock();
	while(timeDelay > clock());
}
