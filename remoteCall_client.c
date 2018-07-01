/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "remoteCall.h"


void
remotecall_1(char *host)
{
	CLIENT *clnt;
	int  *result_1;
	char *callcommand_1_command;
	void  *result_2;
	char *senddata_1_data;

#ifndef	DEBUG
	clnt = clnt_create (host, remoteCall, v1, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = callcommand_1(callcommand_1_command, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_2 = senddata_1(senddata_1_data, clnt);
	if (result_2 == (void *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	remotecall_1 (host);
exit (0);
}
