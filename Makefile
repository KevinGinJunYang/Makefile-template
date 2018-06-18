

# Do not remove the line below:
.PHONY: clean egame

# Write the rules below, as specified in Task 2.


#--------------------------------------------------
fgame:  fgame.o guess.o ttt.o common.o common.h
	gcc -o fgame game.o guess.o  ttt.o common.o 	
egame:  egame.o common.o common.h
	gcc  -o egame game.o common.o 	
	gcc -D FORK_EXEC_IMPL guess.c common.o -o guess
	gcc -D FORK_EXEC_IMPL ttt.c common.o -o ttt

#--------------------------------------------------	
	
fgame.o: game.c common.h 
	gcc -D FORK_IMPL -c game.c common.h	
		
egame.o: game.c common.h 
	gcc -D FORK_EXEC_IMPL -c game.c common.h  	

#--------------------------------------------------
	
game.o:  game.c common.h 
	gcc -c game.c 
common.o: common.c common.h
	gcc -c common.c
guess.o: guess.c common.h
	gcc -c guess.c
ttt.o: ttt.c common.h
	gcc -c ttt.c
	
#--------------------------------------------------	
	
clean: rm -rf *o fgame egame

