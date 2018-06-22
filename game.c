
#include "common.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int count = 0;
int randGuess;

/*====== Fork Only Implementation Start ======*/
/**
 * Fork Only Implementation Block
 * Write all code related to the fork only implementation within this block
 */ 
#ifdef FORK_IMPL
int main(void){

int status;
pid_t pid; 

while(1){ // infinite loop until exit is chosen 
	printf("-----------------------------------------\n");
	printf("Select a game to play\n");
	printf("Press [1] to play guess number game\n");
	printf("Press [2] to play tic tac toe game\n");
	printf("Press [3] to exit\n");
	printf("-----------------------------------------\n");

	int check = scanf("%d", &randGuess); // gets user input 
    if(check!=1){ // checks for string invalid 
        printf("Invalid\n");
        return 0;
    }
	if((randGuess != 1 && randGuess != 2 &&randGuess != 3) || count>0){ // checks for int invalids 
		printf("Invalid\n");
	}


	if(randGuess == 1){ // if wants to play guess 
		pid = fork(); 
		if(pid == 0){ // child process 
			guess_run(); // run game 
			exit(randGuess); 
		}

		else{ // parent process 
			wait(&status);   //waits for child process to finish 
			randGuess = 1;
		}

	}
	if(randGuess == 2){
		pid = fork();
		if(pid == 0){
			ttt_run();
			exit(randGuess);
		}


		else{
			wait(&status);
			randGuess = 1;
		}

	}
	if(randGuess == 3){
		return 0; // exit loop and game 
}

}

}
#endif

/*====== Fork Only Implementation End ======*/




#ifdef FORK_EXEC_IMPL
/*====== Fork + Exec Implementation Start ======*/
/**
 * Fork + Exec Implementation Block
 * Write all code related to the fork + exec implementation within this block
 */ 

int main(void)
{
	int status;
	pid_t pid; 
	while(1){
		printf("-----------------------------------------\n");
		printf("Select a game to play\n");
		printf("Press [1] to play guess number game\n");
		printf("Press [2] to play tic tac toe game\n");
		printf("Press [3] to exit\n");
		printf("-----------------------------------------\n");

		int check = scanf("%d", &randGuess); // gets user input 
        if(check!=1){ // checks for string invalid 
        printf("Invalid\n");
        return 0;
        }
        if((randGuess != 1 && randGuess != 2 &&randGuess != 3) || count>0){ // checks for int invalids 
		printf("Invalid\n");
        }


		if(randGuess == 1){
			pid = fork();// forks 
			if(pid == 0){
				execlp("./guess",NULL); // executes file  
				exit(randGuess);
			}

			else{
				wait(&status);   
				randGuess = 1;
			}

		}
		if(randGuess == 2){
			pid = fork();
			if(pid == 0){
				execlp("./ttt",NULL);
				exit(randGuess);
			}


			else{
				wait(&status);
				randGuess = 1;
			}

		}
		if(randGuess == 3){
			return 0;
		}
	}
}

/*====== Fork + Exec Implementation End ======*/



#endif

#ifdef None
/*====== No Implementation Start ======*/
/**
 * No Implementation Block
 * Do not write anything in this block
 */ 
#error "Did not specify implementation to compile."

/*====== No Implementation End ======*/
#endif 

