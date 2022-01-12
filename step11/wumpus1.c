#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
 * Name :  <insert name here>
 * 
 * Simple Wumpus game in 1D
*/

/* Add any #defines here */
/* Id's for thins in our Cave */
#define Empty 0
#define Wumpus 1
#define End 2

/* Number of rooms in our Cave */
#define CaveSize 20
#define ArraySize (CaveSize + 2)

/* Directions I can face */
#define Left 0
#define Right 1

/* Add any function prototypes here */
void CreateWorld(int cave[]);
int* GetEmpthRoom(int cave[]);
void DisplayWorld(int cave[], int* agent, int agentDIr);
int DifferenceByDirection(int dir);
bool DisplayStatus(int cave[], int* agent);
void OpenFire(int cave[], int* agent, int agentDIr);
 
int main()
{
    int cave[ArraySize];
    int *agentRoom;
    int agentDirection;
    
    /* Seed the random number generator */
    srand(time(NULL));
    
    CreateWorld(cave);
    
    agentRoom = GetEmpthRoom(cave);
    agentDirection = rand()%2;

    char command[20];
    int direction;

    /* The game loop */
    while(true){
        if(DisplayStatus(cave, agentRoom))
            break;
        // DisplayWorld(cave, agentRoom, agentDirection);
         /* Get the command */
        printf("Command: ");
        scanf("%20s", command);

        if(strcmp(command, "quit") == 0)
            break;
        else if(strcmp(command, "move") == 0){
            /* Move command */
            /* What way do we need to go? */
            direction = DifferenceByDirection(agentDirection);
            if( *(agentRoom + direction) != End)
                agentRoom += direction;
        }else if(strcmp(command, "turn") == 0){
            agentDirection = !agentDirection;
        }else if(strcmp(command, "fire") == 0){
            /* Fire command */
            OpenFire(cave, agentRoom, agentDirection);
        }
        else    
            printf("I don't know what you are talking about\n");
    }
}

void CreateWorld(int cave[]){
    int i;
    /* Initialize cave to empty */
    for(i=0;i<ArraySize;i++){
        cave[i]=Empty;
    }
    /* Set the ends */
    cave[0] = End;
    cave[ArraySize-1] = End;

    int* room;
    /* Get a random empty room and put the Wumpus in it*/
    room = GetEmpthRoom(cave);
    *room = Wumpus;
    
}

int* GetEmpthRoom(int cave[]){
    int room;

    do{
        room = rand() % ArraySize;
    }while(cave[room]!=Empty);
    return &cave[room];
}

void DisplayWorld(int cave[], int* agent, int agentDIr){
    int* room;
    for(room = cave + 1; *room != End; room++){
        if(room == agent){
            switch (agentDIr)
            {
            case Left:
                printf("<A  ");
                break;
            case Right:
                printf(" A> ");
            }
            continue;
        }

        switch(*room){
            case Wumpus:
                printf("-W- ");
                break;
            default:
                printf(" .  ");
                break;
        }
    }
    printf("\n");
}

int DifferenceByDirection(int dir){
    if(dir == Left)
        return -1;
    else    
        return 1;
}

bool DisplayStatus(int cave[], int* agent){
    if(*agent == Wumpus){
        printf("You have been eaten by the Wumpus\n");
        return true;
    }
    if(*(agent+1) == End || *(agent-1) == End){
        printf("You have arrived at the end! You got win!");
        return true;
    }
    if(*(agent-1) == Wumpus || *(agent+1) == Wumpus)
        printf("I smell a Wumpus\n");
    return false;
}

void OpenFire(int cave[], int* agent, int agentDIr){
    int* room = agent;
    int fireCounts = 3;
    while((*room + 1 != End || *room - 1 != End) && fireCounts > 0){
        fireCounts--;
        if(agentDIr==Left)
        {
            room--;
        }else{
            room++;
        }
        // *room = Wumpus;
        *room = Empty;
    }
}