/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _CALLBACK_H_RPCGEN
#define _CALLBACK_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct returndata_1_argument {
	int stream;
	char *data;
	int size;
};
typedef struct returndata_1_argument returndata_1_argument;

#define callBack 0x20000002
#define v1 1


void callback_1_clnt(char *host, int result, char* data, int stream, int size);
int main2 (int argc, char **argv);
extern int pid;
#if defined(__STDC__) || defined(__cplusplus)
#define sendResult 1
extern  void * sendresult_1(int , CLIENT *);
extern  void * sendresult_1_svc(int , struct svc_req *);
#define returnData 2
extern  void * returndata_1(int , char *, int, CLIENT *);
extern  void * returndata_1_svc(int , char *, int, struct svc_req *);
extern int callback_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define sendResult 1
extern  void * sendresult_1();
extern  void * sendresult_1_svc();
#define returnData 2
extern  void * returndata_1();
extern  void * returndata_1_svc();
extern int callback_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_returndata_1_argument (XDR *, returndata_1_argument*);

#else /* K&R C */
extern bool_t xdr_returndata_1_argument ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_CALLBACK_H_RPCGEN */
