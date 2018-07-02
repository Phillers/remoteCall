#include<stdio.h>
#include<unistd.h>


int main(){
	char buf[1024];
	int c;
	while((c=read(0, buf, 1024))>0){
		int i=c;
		char e='\n';
		while(c-->0){
			if(buf[c]<0){
				c--;
				write(1, &buf[c], 2);
				write(1, &e, 1);
			} else
				printf("%c\n",buf[c]);
			fflush(stdout);
		}
	}
	printf("bye :(");
	return 25;
}
