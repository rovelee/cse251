#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
 * Name :  <insert name here>
 * 
 * Simple Wumpus game in 2D
*/

/* Id's for things in our Cave */
#define Empty 0
#define Wumpus 1
#define End 2
#define Pit 3

/* Number of rooms in our Cave in each dimension */
#define CaveSize 10
#define ArraySize (CaveSize + 2)

/* Directions I can face */
#define Left 0
#define Up 1
#define Right 2
#define Down 3

void CreateWorld(int cave[ArraySize][ArraySize]);
int *GetEmptyRoom(int cave[ArraySize][ArraySize]);
void DisplayWorld(int cave[ArraySize][ArraySize], int *agent, int agentDir);
int DifferenceByDirection(int dir);
bool DisplayStatus(int *agent);
void OpenFire(int* agent, int dir);
 
int main()
{
    int *agentRoom;
    int agentDirection;
    char command[20];
    
    /* Seed the random number generator */
    srand(time(NULL));
    
    int cave[ArraySize][ArraySize];

    CreateWorld(cave);
    agentDirection = rand() % 4;
    agentRoom = GetEmptyRoom(cave);
    int d;
    
    /* The game loop */
    while(true)
    {
        if(DisplayStatus(agentRoom))
            break;
        DisplayWorld(cave, agentRoom, agentDirection);

        /* Get the command */
        printf("Command: ");
        scanf("%20s", command);
        if(strcmp(command, "quit") == 0)
        {
            /* Exit, we are doing */
            break;
        }
        else if(strcmp(command, "move") == 0)
        {
            d = DifferenceByDirection(agentDirection);

            if(*(agentRoom+d)!=End)
                agentRoom+=d;
        }
        else if(strcmp(command, "turn") == 0)
        {
            agentDirection++;
            if(agentDirection > Down)
                agentDirection=Left;
        }
        else if(strcmp(command, "fire") == 0)
        {
            OpenFire(agentRoom, agentDirection);
        }
        else
        {
            printf("I don't know what you are talking about\n");
        }
    }
    
}

void CreateWorld(int cave[ArraySize][ArraySize]){
    int i, j;

    for (int j = 0; i < ArraySize; i++)
    {
        for ( j = 0; j < ArraySize; j++)
        {
            if(i == 0 || j == 0 || i == ArraySize-1 || j == ArraySize-1)
            {
                cave[i][j] = End;
            }
            else
            {
                cave[i][j] = Empty;
            }       
        }        
    }
    int* room = GetEmptyRoom(cave);
    *room = Wumpus;
    for(i=0;i<10;i++){
        room = GetEmptyRoom(cave);
        *room = Pit;
    }
}

int *GetEmptyRoom(int cave[ArraySize][ArraySize])
{
    int row, col;
    int *room;
    
    do
    {
        /* We need a random number in each dimension */
        row = rand() % ArraySize;
        col = rand() % ArraySize;
        
        room = &cave[row][col];
    } while(*room != Empty);
    
    return room;
}

void DisplayWorld(int cave[ArraySize][ArraySize], int *agent, int agentDir)
{
    int row, col;
    int *room;
    
    /* Loop over the rows of the cave */
    for(row=1;  row <= CaveSize + 1;  row++)
    {
        /* 
         * This loop lets us print an up direction 
         * above the agent or a v below the agent
         */
         
        for(col=1; col<=CaveSize; col++)
        {
            if(&cave[row][col] == agent && agentDir == Up)
            {
                printf(" ^  ");
            }
            else if(&cave[row-1][col] == agent && agentDir == Down)
            {
                printf(" v  ");
            }
            else
            {
                printf("    ");
            }
        }
        
        printf("\n");
        if(row > CaveSize)
            break;
            
        /*
         * This loop prints the agent or the room contents
         */ 
         
        for(col=1; col<=CaveSize; col++)
        {
            room = &cave[row][col];
            if(room == agent)
            {
                switch(agentDir)
                {
                case Left:
                    printf("<A  ");
                    break;
                    
                case Right:
                    printf(" A> ");
                    break;
                    
                default:
                    printf(" A  ");
                    break;
                        
                }
                continue;
            }
            
            switch(*room)
            {
            case Wumpus:
                printf("-W- ");
                break;
            case Pit:
                printf("-P- ");
                break;
            default:
                printf(" .  ");
                break;    
            }  
            
        }

        printf("\n");
    }
    
}

int DifferenceByDirection(int dir){
    switch(dir)
    {
    case Up:
        return -ArraySize;
        
    case Down:
        return ArraySize;
        
    case Left:
        return -1;
        
    case Right:
        return 1;
    }
}

bool DisplayStatus(int *agent){
    if(*(agent-1)==Wumpus||*(agent+1)==Wumpus||*(agent-ArraySize)==Wumpus||*(agent+ArraySize)==Wumpus)
        printf("I smell a Wumpus.");
    if(*(agent-1)==Pit||*(agent+1)==Pit||*(agent-ArraySize)==Pit||*(agent+ArraySize)==Pit)
        printf("I felt a draft.");
    if(*agent == Wumpus){
        printf("You have been eaten by the Wumpus\n");
        return true;
    }else if(*agent == Pit){
        printf("You feel a draft.");
        return true;
    }
    if(*(agent+1) == End || *(agent-1) == End||*(agent-ArraySize)==End||*(agent+ArraySize)==End){
        printf("You have arrived at the end! You got win!");
        return true;
    }
    return false;
}

void OpenFire(int* agent, int dir){
    int i = 1;
    if (dir==Right)
    {
        while(*(agent+i)!=End&&i<=3){
            if(*(agent+i)==Wumpus)
                *(agent+i)=Empty;
            i++;
        }
    }else if(dir==Left){
        while(*(agent-i)!=End&&i<=3){
            if(*(agent-i)==Wumpus)
                *(agent-i)=Empty;
            i++;
        }
    }else if(dir==Up){
        while(*(agent+ArraySize)!=Empty&&i<=3){
            if(*(agent+i*ArraySize)==Wumpus)
                *(agent+i*ArraySize)=Empty;
            i++;
        }
    }else{
        while(*(agent-ArraySize)!=Empty&&i<=3){
            if(*(agent-i*ArraySize)==Wumpus)
                *(agent-i*ArraySize)=Empty;
            i++;
        }
    }
    
}