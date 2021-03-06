/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "remoteCall.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

void *
callcommand_1(char *command,  CLIENT *clnt)
{
	static char clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, callCommand,
		(xdrproc_t) xdr_wrapstring, (caddr_t) &command,
		(xdrproc_t) xdr_void, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return ((void *)&clnt_res);
}

void *
senddata_1(char *data, int size,  CLIENT *clnt)
{
	senddata_1_argument arg;
	static char clnt_res;
	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	arg.data = data;
	arg.size = size;
	if (clnt_call (clnt, sendData, (xdrproc_t) xdr_senddata_1_argument,
				   (caddr_t) &arg,
		(xdrproc_t) xdr_void, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return ((void *)&clnt_res);
}
