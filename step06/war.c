#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void PrintCard(int rand, int suit);
void PrintResult(int c1, int s1, int c2, int s2);

int main(){
	int suit1, card1,
		suit2, card2;

	// This seeds the random number generator with the current time
	srand(time(NULL));
	
	suit1 = rand()%4;
	suit2 = rand()%4;

	card1 = rand()%13 + 1;
	card2 = rand()%13 + 1;

	printf("Player 1 : ");
	PrintCard(card1, suit1);

	printf(", Player 2 : ");
	PrintCard(card2, suit2);

	printf("\n");

	PrintResult(card1, suit1, card2, suit2);
}

void PrintCard(int card, int suit){
    switch(card)
    {
    case 1:
        printf("Ace");
        break;
        
    case 11:
        printf("Jack");
        break;
        
    case 12:
        printf("Queen");
        break;
        
    case 13:
        printf("King");
        break;
        
    default:
        printf("%d", card);
        break;
    }
    
    printf(" of ");
    
    switch(suit)
    {
    case 0:
        printf("Hearts");
        break;
        
    case 1:
        printf("Diamonds");
        break;
        
    case 2:
        printf("Spades");
        break;
        
    case 3:
        printf("Clubs");
        break;
    }
}

void PrintResult(int c1, int s1, int c2, int s2){
	if(c1 == c2){
		// Hearts:0 > Diamonds:1 > Spades:2 > Clubs:3
		if(s1 > s2)// s2 win
			printf("Player 2 wins\n");
		else 
			printf("player 1 wins\n");
	}else{
		if(c1 == 1)
			printf("Player 1 wins\n");
		else if(c2 == 1)
			printf("Player 2 wins\n");
		else if(c1 > c2)
			printf("Player 1 wins\n");
		else
			printf("Player 2 wins\n");
	}
}