#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "GarageLib.h"

#define DoorClosed 1
#define DoorOpening 2
#define DoorOpen 3
#define DoorClosing 4

void StateDoorClosed(int* state);
void StateDoorOpening(int* state);
void StateDoorOpen(int *state);
void StateDoorClosing(int *state);


int main()
{
    printf("Garage Startup\n");
    GarageStartup();
    SetDoorSpeed(1);

    int state = DoorClosed;

    while(IsGarageRunning())
    {
        switch(state)
        {
        case DoorClosed:
            StateDoorClosed(&state);
            break;
        case DoorOpening:
            StateDoorOpening(&state);
            break;
        case DoorOpen:
            StateDoorOpening(&state);
            break;
        case DoorClosing:
            StateDoorClosing(&state);
            break;
        }

    }

    printf("Garage Shutdown\n");
    GarageShutdown();
    return 0;
}

void StateDoorClosed(int *state)
{
    if(WasButtonPressed())
    {
        SetMotorPower(1);
        *state = DoorOpening;
    }
}

void StateDoorOpening(int* state){
    if(GetDoorPosition() >= (DoorHeight - DoorTolerance)){
        SetMotorPower(0);
        *state = DoorOpen;
    }
}

void StateDoorOpen(int *state)
{
    if(WasButtonPressed())
    {
        SetMotorPower(-1);
        *state = DoorClosing;
    }
}

void StateDoorClosing(int *state)
{
    if(GetDoorPosition() < DoorTolerance)
    {
        SetMotorPower(0);
        *state = DoorClosed;
    }
}