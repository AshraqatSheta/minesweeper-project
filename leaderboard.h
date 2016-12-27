#ifndef LEADERBOARD_H_INCLUDED
#define LEADERBOARD_H_INCLUDED


typedef struct{
    char name[30];
    int score;
}Player;
 void updateleaderboard(Player playerlist[30],int n);
 void namee(char name[30],int score);
 void readd(Player Playerlist[30],int n);
 int getMaxIndex(Player Playerlist[30], int first, int last) ;
 void swap (Player Playerlist[30], int a, int b);
 void selectionSort(Player Playerlist[30], int size);

#endif // LEADERBOARD_H_INCLUDED
