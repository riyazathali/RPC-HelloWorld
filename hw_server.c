#include <rpc/rpc.h>
#include "hw.h"

/* 
   Returns the String, This is Hello world RPC server
*/

char **hw_1_svc(void *a, struct svc_req *req) {
	static char msg[256];
	static char *p;

	printf("getting ready to return value to the client side\n");
	strcpy(msg, "Hello world!! I am Ali");
	p = msg;
	printf("Returning to the client...\n");
         

	return(&p);
}
