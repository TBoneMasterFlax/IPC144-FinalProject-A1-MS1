/*
    ==================================================
    Assignment #1 Milestone #1:
    ==================================================
    Name   : Tuan Nguyen
    ID     : 109062166
    Email  : tnguyen140@myseneca.ca
    Section: NFF
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "commonHelpers.h"

#include <time.h>

#include <string.h>

#include <stdlib.h>

// -----------------------------------------
// Function Definitions

void test01_getInteger(void)
{
    int intValue = 999;

    printf("TEST #1: Enter the word 'error' [ENTER], then the number -100: ");

    // You may want to comment the next line if you have not yet created the getInteger function:
    intValue = getInteger();

    if (intValue == -100)
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }
}

void test02_getPositiveInteger(void)
{
    int intValue = 999;

    printf("TEST #2: Enter the number -100 [ENTER], then the number 200: ");

    // You may want to comment the next line if you have not yet created the getPositiveInteger function:
    intValue = getPositiveInteger();

    if (intValue == 200)
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }
}

void test03_getIntFromRange(void)
{
    int intValue = 999;

    printf("TEST #3: Enter the word 'error' [ENTER], then the number -4 [ENTER], then 12 [ENTER], then -3: ");

    // You may want to comment the next line if you have not yet created the getIntFromRange function:
    intValue = getIntFromRange1(-3, 11);

    if (intValue == -3)
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }
}

void test04_getIntFromRange(void)
{
    int intValue = 999;

    printf("TEST #4: Enter the number 14: ");

    // You may want to comment the next line if you have not yet created the getIntFromRange function:
    intValue = getIntFromRange2(-40, 14);

    if (intValue == 14)
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }
}

void test05_getDouble(void)
{
    double dblValue = 999.0;

    printf("TEST #5: Enter the word 'error' then, the number -150.75: ");

    // You may want to comment the next line if you have not yet created the getDouble function:
    dblValue = getDouble();

    if (dblValue == -150.75)
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }
}

void test06_getPositiveDouble(void)
{
    double dblValue = 999.0;

    printf("TEST #6: Enter the number -22.11 [ENTER], the number 225.55: ");

    // You may want to comment the next line if you have not yet created the getPositiveDouble function:
    dblValue = getPositiveDouble();

    if (dblValue == 225.55)
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }
}

void test07_getCharOption(void)
{
    char charValue = 'x';

    printf("TEST #7: Enter the character 'R' [ENTER], then 'p' [ENTER], then 'r': ");

    // You may want to comment the next line if you have not yet created the getCharOption function:
    charValue = getCharOption("qwerty");

    if (charValue == 'r')
    {
        printf("*** PASS *** \n\n");
    }
    else
    {
        printf("### FAILED ###\n\n");
    }
}

void test08_getCString(void)
{
    char cstringValue[7] = { '\0' };

    printf("TEST #8: Enter the word 'horse' [ENTER], then 'SENECA': ");

    // You may want to comment the next line if you have not yet created the getCString function:
    getCString(cstringValue, 6, 6);

    printf("Your Result: %s (Answer: SENECA)\n\n", cstringValue);
}

void test09_getCString(void)
{
    char cstringValue[7] = { '\0' };

    printf("TEST #9: Enter the words 'Seneca College' [ENTER], then 'IPC': ");

    // You may want to comment the next line if you have not yet created the getCString function:
    getCString(cstringValue, 3, 6);

    printf("Your Result: %s (Answer: IPC)\n\n", cstringValue);
}

void test10_getCString(void)
{
    char cstringValue[7] = { '\0' };

    printf("TEST #10: Enter the words 'ipc' [ENTER], then 'SCHOOL': ");

    // You may want to comment the next line if you have not yet created the getCString function:
    getCString(cstringValue, 4, 6);

    printf("Your Result: %s (Answer: SCHOOL)\n\n", cstringValue);
}

// Uses the time.h library to obtain current year information
// Get the current 4-digit year from the system
int currentYear(void)
{
    time_t currentTime = time(NULL);
    return localtime(&currentTime)->tm_year + 1900;
}

// As demonstrated in the course notes: https://ict.senecacollege.ca//~ipc144/pages/content/formi.html#buf
// Empty the standard input buffer
void clearStandardInputBuffer(void)
{
    while (getchar() != '\n')
    {
        ; // On purpose: do nothing 
    }
}

int getInteger()
{
    int intValue;
    char newLine;
    scanf("%d%c", &intValue, &newLine);
    do
    {
        clearStandardInputBuffer();
        printf("ERROR: Value must be an integer: ");
        scanf("%d%c", &intValue, &newLine);
    } while (newLine != '\n');
    return intValue;
}

int getPositiveInteger()
{
    int intValue;
    scanf("%d", &intValue);
    do
    {
        printf("ERROR: Value must be a positive integer greater than zero: ");
        scanf("%d", &intValue);
        clearStandardInputBuffer();
    } while (intValue <= 0);
    return intValue;
}

double getDouble()
{
    double doubleValue;
    char newLine;
    scanf("%lf%c", &doubleValue, &newLine);
    do
    {
        clearStandardInputBuffer();
        printf("ERROR: Value must be a double floating-point number: ");
        scanf("%lf%c", &doubleValue, &newLine);
    } while (newLine != '\n');
    return doubleValue;
}

double getPositiveDouble()
{
    double doubleValue;
    scanf("%lf", &doubleValue);
    do
    {
        printf("ERROR: Value must be a positive double floating-point number: ");
        scanf("%lf", &doubleValue);
        clearStandardInputBuffer();
    } while (doubleValue <= 0);
    return doubleValue;
}

int getIntFromRange1(int lowerBound, int upperBound)
{
    int intValue;
    intValue = getInteger();
    do
    {
        printf("ERROR: Value must be between %d and %d inclusive: ", lowerBound, upperBound);
        scanf("%d", &intValue);
        clearStandardInputBuffer();
    } while (intValue < lowerBound || intValue > upperBound);
    return intValue;
}

int getIntFromRange2(int lowerBound, int upperBound)
{
    int intValue;
    int flag = 1;
    do
    {
        scanf("%d", &intValue);
        if (intValue < lowerBound || intValue > upperBound)
            printf("ERROR: Value must be between %d and %d inclusive: ", lowerBound, upperBound);
        else
            flag = 0;
        clearStandardInputBuffer();
    } while (flag);
    return intValue;
}

char getCharOption(char string[])
{
    char ch;
    int i;
    int length = strlen(string);
    int flag = 1;
    do
    {
        scanf("%c", &ch);
        for (i = 0; i < length; i++)
        {
            if (string[i] == ch)
                flag = 0;
        }
        if (flag == 1)
        {
            printf("ERROR: Character must be one of [%s]: ", string);
        }
        clearStandardInputBuffer();
    } while (flag);
    return ch;
}

void getCString(char* string, int lowerBound, int upperBound)
{
    char userString[30];
    int flag = 1;
    int i;
    int userLength;
    do
    {

        scanf("%30[^\n]", userString);
        userLength = strlen(userString);
        if (lowerBound == upperBound && userLength != lowerBound)
        {
            printf("ERROR: String length must be exactly %d chars: ", lowerBound);
        }
        else if (userLength > upperBound)
        {
            printf("ERROR: String length must be no more than %d chars: ", upperBound);
        }
        else if (userLength < lowerBound)
        {
            printf("ERROR: String length must be between %d and %d chars: ", lowerBound, upperBound);
        }
        else
        {
            for (i = 0; i < userLength + 1; i++)
            {
                if (i < userLength + 1)
                {
                    string[i] = userString[i];
                }
                /*else
                {
                    string[i] = '\0';
                }*/
            }
            flag = 0;
        }
        clearStandardInputBuffer();
    } while (flag);
}