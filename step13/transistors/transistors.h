#ifndef TRANSISTORS_H
#define TRANSISTORS_H

/* Types */
#define NPN 1
#define PNP 2

/* Cases */
#define TO18 1
#define TO92A 2
#define TO92C 3
#define TO220 4
#define TO39 5

// struct Transistor
// {
//     char number[10];
//     int type;       /* NPN, PNP, etc. */
//     int caseStyle;  /* TO18, etc. */
//     double pmax;    /* Maximum power dissipation watts */
//     double icmax;   /* Maximum collector current amps */
// } Tran;
typedef struct{
    char number[10];
    int type;       /* NPN, PNP, etc. */
    int caseStyle;  /* TO18, etc. */
    double pmax;    /* Maximum power dissipation watts */
    double icmax;   /* Maximum collector current amps */
} Tran;

// void DisplayTransistor(struct Transistor tran);
void DisplayTransistor(Tran tran);
// struct Transistor InputTransistor();
Tran InputTransistor();
void InputString(char *str, int max);
double InputPositiveValue(char *prompt);
int InputTransistorType(char *prompt);
#endif