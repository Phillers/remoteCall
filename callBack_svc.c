/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "callBack.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static void *
_sendresult_1 (int  *argp, struct svc_req *rqstp)
{
	return (sendresult_1_svc(*argp, rqstp));
}

static void *
_returndata_1 (returndata_1_argument *argp, struct svc_req *rqstp)
{
	return (returndata_1_svc(argp->stream, argp->data, rqstp));
}

static void
callback_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		int sendresult_1_arg;
		returndata_1_argument returndata_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);
	char do_exit = 0;
	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case sendResult:
		do_exit = 1;
		_xdr_argument = (xdrproc_t) xdr_int;
		_xdr_result = (xdrproc_t) xdr_void;
		local = (char *(*)(char *, struct svc_req *)) _sendresult_1;
		break;

	case returnData:
		_xdr_argument = (xdrproc_t) xdr_returndata_1_argument;
		_xdr_result = (xdrproc_t) xdr_void;
		local = (char *(*)(char *, struct svc_req *)) _returndata_1;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	int retval=argument.sendresult_1_arg;
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	if(do_exit>0) {
		printf("\n%d\n", retval);
		exit(retval);
	}
	return;
}

int
main2 (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (callBack, v1);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, callBack, v1, callback_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (callBack, v1, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, callBack, v1, callback_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (callBack, v1, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
