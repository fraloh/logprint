/*
 * logPrintTest.c
 * 
 * logPrinttestprogramm
 * 
 * klein und nicht durchdacht aufpassen beim ausführen
 * 
 */


#include <stdio.h>
#include <logPrint.h>

int main(int argc, char **argv)
{
	int x=0,y=0,i=0;
	char msg[100];
		
	    logprintf(0,0,"obenlinks1");
		logprintf(0,1,"obenlinks2");
		logprintf(0,2,"obenlinks3");

		
	    logprintf(1,0,"obenrechts1");
	    logprintf(1,1,"obenrechts2");
	    logprintf(1,2,"obenrechts3");

	    
	    /*
	    logprintf(2,0,"mittelinks1");
	    logprintf(2,1,"mittelinks2");
	    logprintf(2,2,"mittelinks3");
	    
	    logprintf(3,0,"mitterechts1");
	    logprintf(3,1,"mitterechts2");
	    logprintf(3,2,"mitterechts3");
	    */
		//logprintf(0,0,"Eins");
	    
	while(i!=10){ //aufpassen schlechter abbruch!!!!!!
		i++;
	    scanf("%s",&msg); //Beispieleingabe: 1 1 test
		logprintf(0,-1,"%s",msg);
	}
	return 0;
}

