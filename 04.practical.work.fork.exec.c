#include <stdio.h>
#include <unistd.h>

int main(){
        int pid = fork();
        if(pid == 0){
            printf("i am a child after fork(), launching ps -ef\n");
            char *args[]  = { "/bin/ps", "-ef", NULL};      
            execvp("/bin/ps", args);
        }else printf("I am parent after fork(), child ps is %d\n", pid);
		
	int pid1 = fork();
	if(pid1 == 0){
		printf("i am a child after fork(), launching free -h\n");
        	char *args[]  = { "free", "-h", NULL};      
            	execvp("free", args);
	}else printf("I am parent after fork(), child free is %d\n", pid1);
        return 0;

}

