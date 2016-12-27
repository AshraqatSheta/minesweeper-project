#include "leaderboard.h"
#include <stdio.h>
int endofboard;

void updateleaderboard(Player playerlist[30],int n){
     FILE *playersNames;
     playersNames=fopen("Playersnames.txt","w");
      int i;
     for(i=0;i<n;i++){
            fprintf(playersNames,"%s %d\n",playerlist[i].name,playerlist[i].score);}
     fclose(playersNames);}



void namee(char name[30],int score){
       FILE *playersNames;
        playersNames=fopen("Playersnames.txt","a");
        fprintf(playersNames,"%s",name);
     fprintf(playersNames,"%d\n",score);
   fclose(playersNames);}

    void readd(Player Playerlist[30],int n){
        FILE *playersNames;
        playersNames=fopen("Playersnames.txt","r");
        int i;
        for(i=0;i<n;i++){
            fscanf(playersNames,"%s %d\n",&Playerlist[i].name,&Playerlist[i].score);
            if(Playerlist[i].score==0){
                    endofboard=i;
                    break;}}

        fclose(playersNames);}
        int getMaxIndex(Player Playerlist[30], int first, int last) {
int maxiIndex;
int index;
maxiIndex = first;
for (index = first + 1; index <= last; index++) {
if (Playerlist[index].score>Playerlist[maxiIndex].score)
maxiIndex = index;
}
return maxiIndex;}
void swap (Player Playerlist[30], int a, int b) {
int temp = Playerlist[a].score;
char namechange[30];
Playerlist[a].score = Playerlist[b].score;
Playerlist[b].score = temp;
strncpy(namechange,Playerlist[a].name,30);
strncpy(Playerlist[a].name,Playerlist[b].name,30);
strncpy(Playerlist[b].name,namechange,30);}

 void selectionSort(Player Playerlist[30], int size) {
int maxiIndex;
int index;
for (index = 0; index < size -1; index++) {
maxiIndex = getMaxIndex(Playerlist, index, size-1);
swap(Playerlist, index, maxiIndex);}}

