// AABISKAR GIRI
// 1002050945

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define row 5
#define column 5

void fill_BINGOcard(int BINGO_interface[5][5]);
void print_BINGOcard(int BINGO_interface[5][5]);
int pickNumber(int DUP[75], int counter);
int a_numberCHECK(int random_number, int BINGO_interface[5][5]);
int row_check(int BINGO_interface[5][5]);
int column_check(int BINGO_interface[5][5]);
int diagonal_check(int BINGO_interface[5][5]);

int main()
{
    srand(time(0));
    int BINGO_interface[5][5];
    char mark_num;
    int pickNumber();
    int DUP[75] = {0};
    fill_BINGOcard(BINGO_interface);
    print_BINGOcard(BINGO_interface);
    int count = 0;

    while (row_check(BINGO_interface) == 0 && column_check(BINGO_interface) == 0 && diagonal_check(BINGO_interface) == 0)
    {
        int interface = pickNumber(DUP, count);
        count = count + 1;
        switch (interface)
        {
        case 1 ... 15:
            printf("\nThe next number is B%d", interface);
            break;

        case 16 ... 30:
            printf("\nThe next number is I%d", interface);
            break;

        case 31 ... 45:
            printf("\nThe next number is N%d", interface);
            break;

        case 46 ... 60:
            printf("\nThe next number is G%d", interface);
            break;

        case 61 ... 75:
            printf("\nThe next number is O%d", interface);
            break;
        }
        printf("\n\n");

        printf("Do you have it? (Y/N) ");
        scanf(" %c", &mark_num);
        printf("\n");

        switch (mark_num)
        {
        default:
            print_BINGOcard(BINGO_interface);
            break;

        case 'Y':
            if (a_numberCHECK(interface, BINGO_interface) == 1)
            {
                print_BINGOcard(BINGO_interface);
            }
            else
            {
                printf("\nThat value is not on your BINGO card - Are you trying to cheat??\n\n");
                print_BINGOcard(BINGO_interface);
            }
        }

        if (row_check(BINGO_interface) == 1 && column_check(BINGO_interface) == 1)
        {
            printf("Completed by Rows & columns\n");
        }

        else if (row_check(BINGO_interface) == 1)
        {
            printf("Completed by Rows\n");
        }

        else if (column_check(BINGO_interface) == 1)
        {
            printf("Completed by Column\n");
        }

        else if (diagonal_check(BINGO_interface) == 1)
        {
            printf("completed by diagonal");
        }
    }
}

void fill_BINGOcard(int BINGO_interface[5][5])
{
    int randomArray[75] = {0};
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            int randomnumber;
            do
            {
                randomnumber = rand() % 15 + 15 * j + 1;
            } while (randomArray[randomnumber - 1] != 0);

            randomArray[randomnumber - 1] = 1;
            BINGO_interface[i][j] = randomnumber;
        }
    }
    BINGO_interface[2][2] = 0;
}

void print_BINGOcard(int BINGO_interface[5][5])
{
    char cast[5] = {'B', 'I', 'N', 'G', 'O'};

    for (int c = 0; c < 5; c++)
    {
        printf("  %2c ", cast[c]);
    }

    printf("\n");

    for (int i = 0; i < 5; i++)
    {

        for (int j = 0; j < 4; j++)
        {
            printf("-----");
        }
        printf("-----\n");

        printf("| ");

        for (int k = 1; k < 6; k++)
        {

            if (BINGO_interface[i][k - 1] == 0)
            {

                printf("%2c ", BINGO_interface[i][k - 1] + 88);
            }

            else
            {
                printf("%2d ", BINGO_interface[i][k - 1]);
            }

            printf("| ");
        }
        printf("\n");
    }

    for (int k = 1; k < 6; k++)
    {
        printf("-----");
    }
    printf("-\n");
}

int pickNumber(int DUP[75], int counter)
{
    int rand_Number;
    rand_Number = rand() % 75 + 1;

    for (int i = 0; i < counter; i++)
    {
        while (DUP[i] == rand_Number)
        {
            rand_Number = rand() % 75 + 1;
            i = -1;
        }
        DUP[counter] = rand_Number;
    }
    printf("\n");

    return rand_Number;
}

int a_numberCHECK(int random_number, int BINGO_interface[5][5])
{
    int check = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (BINGO_interface[i][j] == random_number)
            {

                BINGO_interface[i][j] = 0;
                check = 1;
            }
        }
    }

    return check;
}

int row_check(int BINGO_interface[5][5])
{
    int check = 0;
    for (int i = 0; i < 5; i++)
    {
        if (BINGO_interface[i][0] == BINGO_interface[i][1] && BINGO_interface[i][2] == BINGO_interface[i][3] && BINGO_interface[i][4] == BINGO_interface[i][1] && BINGO_interface[i][4] == BINGO_interface[i][3])
        {
            check = 1;
        }
    }
    return check;
}

int column_check(int BINGO_interface[5][5])
{
    int check = 0;
    for (int i = 0; i < 5; i++)
    {
        if (BINGO_interface[0][i] == BINGO_interface[1][i] && BINGO_interface[2][i] == BINGO_interface[3][i] && BINGO_interface[4][i] == BINGO_interface[1][i] && BINGO_interface[4][i] == BINGO_interface[3][i])
        {
            check = 1;
        }
    }
    return check;
}

int diagonal_check(int BINGO_interface[5][5])
{
    int i, count;
    count = 0;
    int check = 0;
    for (i = 0; i < row; i++)
    {
        if (BINGO_interface[i][i] == 0)
            count++;
    }
    if (count == 5)
    {
        check = 1;
    }

    count = 0;
    for (i = 0; i < row; i++)
    {
        if (BINGO_interface[i][row - 1 - i] == 0)
            count++;
    }
    if (count == 5)
    {
        check = 1;
    }

    return check;
}
