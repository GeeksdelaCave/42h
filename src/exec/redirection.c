#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>


void redirection (char *argv[], char* in,char* out)
{
	int fichier_entree;
        int fichier_sortie;
        int res=0;
	int pid,retour;
	printf("in : %s, out : %s\n",in,out);
	argv = 0;	
	fichier_entree = open(in,O_RDONLY);
	fichier_sortie = open(out,O_WRONLY | O_CREAT);
	pid = fork();
	printf("pid : %d\n",pid);
	if(pid == 0)
	{ 
		
		if(retour != -1 && fichier_entree != -1)
		{
			res = dup2(fichier_entree,STDIN_FILENO);
			printf("res 1 : %d\n",res);
			res = dup2(fichier_sortie, STDOUT_FILENO);
			printf("res 2 : %d\n",res);
		}	
                retour = execvp(argv[0],argv);
		printf("retour : %d\n",retour); 
	}
	else
		wait(&pid);

}

void exec_redirection_node(struct list_node_s *n, struct list_node_s *prev, struct list_node_s *next, struct s_node_redirection *node)
{
    assert(node);
    switch(node->redirection)
    {
        case R_GREAT: exec_R_GREAT(&node->word, &node->number); 
            break;
        case R_DGREAT: exec_R_GREAT(&body->word, &node->number);
            break;   
        default:
            assert(0);    
    }
}

/*int main (int argc, char *argv[])
{
  //case for ">"
  redirection(argv, argv[0], argv[2]);
  return 0;
}
*/