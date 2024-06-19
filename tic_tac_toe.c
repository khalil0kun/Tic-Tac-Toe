#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

void DispBoard(char Board[3][3]) {
    printf("\n\n%c  | %c | %c \n---+---+---\n%c  | %c | %c \n---+---+---\n%c  | %c | %c \n",Board[0][0], Board[0][1], Board[0][2],Board[1][0], Board[1][1], Board[1][2],Board[2][0], Board[2][1], Board[2][2]);
}

bool Winner(char Board[3][3], char user) {
    // Check rows and columns
    for (int i=0;i<3;i++) {
        // Checking if row win
        if (Board[i][0]==user && Board[i][1]==user && Board[i][2]==user) {
            return true;
        }
        // Checking if column win
        if (Board[0][i]==user && Board[1][i]==user && Board[2][i]==user) {
            return true;
        }
    }
    // Check diagonals
    if (Board[0][0]==user && Board[1][1]==user && Board[2][2]==user) {
        return true;
    }
    if (Board[0][2]==user && Board[1][1]==user && Board[2][0]==user) {
        return true;
    }
    // If no winning combination is found, return false
    return false;
}

void Computer(char Board[3][3], char comp){
    srand(time(NULL));
    int Line=rand()%3,Column=rand()%3;
    //check if the postion is empty enter 'O'
    while(Board[Line][Column] != ' '){
        Line=rand()%3;
        Column=rand()%3;
    }
    Board[Line][Column]=comp;
    printf("\n\nComputer Chose Line %d Column %d",Line,Column);
}

void User(char Board[3][3], char user){
    int Line,Column;
    printf("\nWhere Do You Want To Play ? Enter Line(range 0~2)   ");
    scanf("%d",&Line);
    printf("\nEnter Column(range 0~2)   ");
    scanf("%d",&Column);
    //check if the postion is empty enter 'X'
    while(Board[Line][Column] != ' '){
        printf("\nInvalid Input! Enter Line(range 0~2)   ");
        scanf("%d",&Line);
        printf("\nEnter Column(range 0~2)   ");
        scanf("%d",&Column);
    }
    Board[Line][Column]=user;
    printf("\nYou Chose Line %d Column %d",Line,Column);
}

int main(){
    char Board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};
    bool Win;
    char UserChar='X',CompChar='O';
    int Counter=0;
    while(Counter<=9 && !Win){
        User(Board,UserChar);
        Counter+=1;
        if (Counter>=4){
            Win=Winner(Board,UserChar);
            if (Win){
                DispBoard(Board);
                printf("\nBRAVOO !!! YOU WON");
                break;
            }
        }
        Sleep(1000);
        Computer(Board,CompChar);
        Counter+=1;
        DispBoard(Board);
    }
    if (!Win){
        printf("\nYou're Trash...");
    }
    return 0;
}
