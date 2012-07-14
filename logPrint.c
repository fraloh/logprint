/*
 *  logPrint.c 
 * 	Alternative Konsolenausgabe
 *  version 1.0		13.06.2012
 *
 *  Author: Frank Lohfink, Florian Rausch 
 * 	
 */


#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <logPrint.h>

//
// Anzahl der Positionen und Größe
//
#define LOGWINDOWSIZE_Y 6
#define LOGWINDOWSIZE_X 30
#define LOGPOSITIONS 4
#define COLUMS 2

#ifdef windows

 
#define CLEAR //ToDo <WindowsClearBefehl>
#define TOTOP //ToDo <WindowsCursorToTop>

#else
#define CLEAR printf("\033[2J")
#define TOTOP printf("%c[%d;%df",0x1B,0,0)
#endif


char log_window[LOGPOSITIONS][LOGWINDOWSIZE_Y+2][LOGWINDOWSIZE_X+2];
int threadisrunning = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


	
void *updatelog(){
	while(1){
		
		usleep(10000); //ToDo windows sleep
		//CLEAR;
		TOTOP;
	
	//Print LogWindow
		int x,y,z=0; //x=coloums y=logheight z=positions
	
		do{	
		for(y=0;y<LOGWINDOWSIZE_Y+2;y++){ //(y=0;y<LOGWINDOWSIZE_Y;y++)
			for(x=z;x<(COLUMS+z);x++){
				printf("%-30s",log_window[x][y]);
				
				if(x%2!=0) {printf("\n");}
				}
			}
			z=z+2;
		}while(z<=LOGPOSITIONS-1);
		
		printf("\n\\>");
	
		}
	return 0;
	}

void drawframe();

// Starten des Updatethreads
void initLog(){
	char frame[LOGWINDOWSIZE_X];
	int i;
	pthread_t updateThread;
	pthread_create(&updateThread, NULL, updatelog ,NULL);
	threadisrunning = 1;
	//topframe
	frame[0]='.';
	for(i=1;i<LOGWINDOWSIZE_X-1;i++){
			frame[i]='-';
		}
	frame[LOGWINDOWSIZE_X-1]='.';
	
	
	for(i=0;i<=LOGPOSITIONS;i++){
			strcpy(log_window[i][0],frame);
			strcpy(log_window[i][LOGWINDOWSIZE_Y+1],frame);
		}


	} 





void logprintf( int pos,int line ,const char* format, ... ) {
	int i;
	if(!threadisrunning) initLog();
	char frame[LOGWINDOWSIZE_X] = "|";
    va_list args;
    va_start( args, format );
    
    if(line == -1){
		
		for(i=0;i<(LOGWINDOWSIZE_Y-1);i++){ 
				strcpy(log_window[pos][i],log_window[pos][i+1]);
			}
		vsprintf( log_window[pos][LOGWINDOWSIZE_Y-1], format, args );
		}
	else{
	vsprintf( log_window[pos][line+1], format, args );
	strcat(frame,log_window[pos][line+1]);
	strcpy(log_window[pos][line+1],frame);
	}
    va_end( args ); 

}








