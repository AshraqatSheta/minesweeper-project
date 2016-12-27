#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include "winlose.h"
#include "SaveLoad.h"
#include "leaderboard.h"
#include "functions.h"
int n,m;
int moves=0;
int questionCells=0;
int FlagCells;
int recenttimediff=0;
int timediff;
int endofboard;

void Opencells(char A[100][100],char B[100][100],char c[100][100],int l , int s,int n,int m){
        if(l<0||s<0||l>n||s>m){
                return;}
        else{
        A[l][s]=B[l][s];
        if((c[l][s]==' ')){
                c[l][s]='V';
                Opencells(A,B,c,l-1,s-1,n,m);
                Opencells(A,B,c,l,s-1,n,m);
                Opencells(A,B,c,l,s+1,n,m);
                Opencells(A,B,c,l+1,s,n,m);
                Opencells(A,B,c,l-1,s,n,m);
                Opencells(A,B,c,l+1,s-1,n,m);
                Opencells(A,B,c,l+1,s+1,n,m);
                Opencells(A,B,c,l-1,s+1,n,m);
        }}}

    int main(){
        int i,j,r,c;
        int mainmenu,t,s;
        char Game[100][100];
        char Display[100][100];
        char Game1[100][100];
        int mines=0,loser=0,win=0;
        char GameAction[10];
        int min,sec,idletime;
        int PlayerScore;
        char counter;
        time_t startis, endis;
        Player Playerlist[30];
           SetColor(6);
           printf("WELCOME TO MINESWEEPER! %c\n",2);
           printf("CHOOSE FROM MAIN MENU(1,2,3):\n");
           SetColor(24);
           printf("1.Start new game\n");
           printf("2.continue game\n");
           printf("3.Leaderboard\n");
           scanf("%d",&mainmenu);
           while((mainmenu!=1)&&(mainmenu!=2)&&(mainmenu!=3)){
           printf("INVALID CHOICE!\n");
           printf("Enter a valid choice\n");
           scanf("%d",&mainmenu);}

           if(mainmenu==3){
             readd(Playerlist,30);
             selectionSort(Playerlist,30);
             SetColor(6);
            for(i=0;i<endofboard;i++){
            printf("%d.%s : %d\n",i+1,Playerlist[i].name,Playerlist[i].score);}}

           if(mainmenu!=3){
           if(mainmenu==2){
                readgame(Game);
                ReadDisplay(Display,n,m);
                  for(i=0;i<n;i++){
                  for(j=0;j<m;j++){
                  Game1[i][j]=Game[i][j];
                }}
                startis=clock();}


           if(mainmenu==1){
           printf("Enter the size of the game:\n");
           scanf("%d%d",&n,&m);
           while(n<=1||m<=1||n>30||m>30){
                printf("INVALID SIZE!\n");
                printf("Enter the size of the game(r*c)\n");
           scanf("%d%d",&n,&m);}
           int noOfMines=1+(n*m)/10;
           FlagCells=noOfMines;
           //initializing Display Grid
            for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                Display[i][j]='X';}}

        SetColor(6);
        PrintArray(Display,n,m);
        SetColor(24);
            printf("Enter first cell coordinate(r,c):\n");
                scanf("%d%d",&r,&c);
         while(r<=0||c<=0||r>n||c>m){
                 printf("INVALID COORDINATES!\n");
                 printf("Enter a valid cell coordinates(r,c):\n");
                scanf("%d%d",&r,&c);}

        //distributing mines
        while(mines<noOfMines){
                srand(time(NULL));
                i=(rand()%n);
                j=(rand()%m);
                if((i!=r-1)||(j!=c-1)){
                if(Game[i][j]!= '*'){
                        Game[i][j]='*';
                    mines++;}}}

        //changing the rest of the grid to zero
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if (Game[i][j]!='*'){
                    Game[i][j]='0';
            }
            }
            }

        //distributing numbers
         for(i=0;i<n;i++){
          for(j=0;j<m;j++){
                if(Game[i][j]=='*'){
                        CheckGame(Game,i,j+1);
                        CheckGame(Game,i,j-1);
                        CheckGame(Game,i+1,j);
                        CheckGame(Game,i-1,j);
                        CheckGame(Game,i+1,j+1);
                        CheckGame(Game,i-1,j-1);
                        CheckGame(Game,i+1,j-1);
                        CheckGame(Game,i-1,j+1);
                            }}}


        //changing the rest of the grid to spaces
              for(i=0;i<n;i++){
              for(j=0;j<m;j++){
                 if(Game[i][j]=='0'){
                    Game[i][j]=' ';}}}

               writefile(Game,n,m);
                for(i=0;i<n;i++){
                for(j=0;j<m;j++){
                  Game1[i][j]=Game[i][j];
                }}
                if(Game[r-1][c-1]==' '){
                  Opencells(Display,Game,Game1,r-1,c-1,n,m);
                              }
                Display[r-1][c-1]=Game[r-1][c-1];
                moves++;
                SaveGame(Display,n,m);
                startis=clock();}


           while(1){

           //marking a flag
           if(strcmp(strlwr(GameAction),"f") == 0){

               if(Display[r-1][c-1]=='F'){
                    Display[r-1][c-1]='X';
                    FlagCells++;
                    endis=clock();
                    moves++;}
                else{if(Display[r-1][c-1]=='X'){
                    Display[r-1][c-1]='F';
                    moves++;
                    endis=clock();
                    FlagCells--;}}}

          // marking a question
           if(strcmp(strlwr(GameAction),"q")==0){
               if(Display[r-1][c-1]=='?'){
                    Display[r-1][c-1]='X';
                    questionCells--;
                    endis=clock();
                    moves++;}
               else { if(Display[r-1][c-1]=='X'){
                    Display[r-1][c-1]='?';
                    moves++;
                    endis=clock();
                    questionCells++;}}}

            //opening a cell
            if(strcmp(strlwr(GameAction),"o")==0){
                if(Game[r-1][c-1]==' '){
                    Opencells(Display,Game,Game1,r-1,c-1,n,m);
                              }
            if(Game[r-1][c-1]!=' '&&Game[r-1][c-1]!='*'&&Display[r-1][c-1]!='F'&&Display[r-1][c-1]!='?'){
                        counter='0';
                    for(i=r-2;i<r+1;i++){
                    for(j=c-2;j<c+1;j++){
                    if(i>=0&&i<=n&&c>=0&&c<=m){
                    if(Display[i][j]=='F'){
                        counter++;}}}}
                    if(counter==Game[r-1][c-1]){
                    for(i=r-2;i<r+1;i++){
                    for(j=c-2;j<c+1;j++){
                    if(i>=0&&i<=n&&j>=0&&j<=m){
                    if(Display[i][j]!='F'){
                        Display[i][j]=Game[i][j];
                        if(Game[i][j]=='*'){
                            t=i;
                            s=j;
                            loser=1;
                            break;
                    }
                    if(Game[i][j]==' '){
                        Opencells(Display,Game,Game1,i,j,n,m);}

                    }}}}}}
                if(loser==1){
                 Lose(Display,Game,t+1,s+1,n,m);
                 endis=clock();
                 timediff=((endis-startis)/CLOCKS_PER_SEC)+recenttimediff;
                 min=timediff/60;
                 sec=timediff%60;
                 SetColor(6);
                 PrintArray(Display,n,m);
                 printf("QUESTION CELLS : %d\n",questionCells);
                 printf("FLAG CELLS : %d\n",FlagCells);
                 printf("NUMBER OF MOVES : %d\n",moves);
                 printf("TIME %.2d:%.2d\n",min,sec);
                 printf("YOU LOST!\n");
                 break;}


                if((Display[r-1][c-1]!='F')&&(Display[r-1][c-1]!='?')){
                   Display[r-1][c-1]= Game[r-1][c-1];
                   moves++;
                   endis=clock();}
                  if(Display[r-1][c-1]=='*'){
                    Lose(Display,Game,r,c,n,m);
                    endis=clock();
                    timediff=((endis-startis)/CLOCKS_PER_SEC)+recenttimediff;
                    min=timediff/60;
                    sec=timediff%60;
                    SetColor(6);
                    PrintArray(Display,n,m);
                    printf("QUESTION CELLS : %d\n",questionCells);
                    printf("FLAG CELLS : %d\n",FlagCells);
                    printf("NUMBER OF MOVES : %d\n",moves);
                    printf("TIME %.2d:%.2d\n",min,sec);
                    printf("YOU LOST!\n");
                    break;}}

                    int test=CheckWin(Display,Game,n,m);
                    if(test!=1){
                    for(i=0;i<n;i++){
                    for(j=0;j<m;j++){
                        if(Game[i][j]=='*'){
                        if(Display[i][j]!='F'){
                        Display[i][j]='F';
                        FlagCells--;}}}}
                        endis=clock();
                        timediff=((endis-startis)/CLOCKS_PER_SEC)+recenttimediff;
                        min=timediff/60;
                        sec=timediff%60;
                        system("COLOR 0F");
                        PrintArray(Display,n,m);
                        printf("QUESTION CELLS : %d\n",questionCells);
                        printf("FLAG CELLS : %d\n",FlagCells);
                        printf("NUMBER OF MOVES : %d\n",moves);
                        printf("TIME %.2d:%.2d\n",min,sec);
                        printf("YOU WON! %c\n",2);
                        win=1;
                        break;    }

                  else{endis=clock();}


           timediff=((endis-startis)/CLOCKS_PER_SEC)+recenttimediff;
           min=timediff/60;
           sec=timediff%60;
           SetColor(6);
           PrintArray(Display,n,m);
           SaveGame(Display,n,m);
           printf("QUESTION CELLS : %d\n",questionCells);
           printf("FLAG CELLS : %d\n",FlagCells);
           printf("NUMBER OF MOVES : %d\n",moves);
           printf("TIME %.2d:%.2d\n",min,sec);
           SetColor(24);
           printf("\nOpen/flag/question(O,F,Q):\n");
            time_t startt,endd;
            startt=clock();
            while(!kbhit()){
            endd=clock();
            idletime=(endd-startt)/CLOCKS_PER_SEC;
              if(idletime==60){
              SetColor(6);
              PrintArray(Display,n,m);
              endis=clock();
              startt=clock();

           timediff=((endis-startis)/CLOCKS_PER_SEC)+recenttimediff;
           SaveGame(Display,n,m);
           min=timediff/60;
           sec=timediff%60;
           printf("QUESTION CELLS : %d\n",questionCells);
           printf("FLAG CELLS : %d\n",FlagCells);
           printf("NUMBER OF MOVES : %d\n",moves);
           printf("TIME %.2d:%.2d\n",min,sec);
            SetColor(24);
            printf("\nOpen/flag/question(O,F,Q):\n");
                }}
           scanf(" %s",&GameAction);
           printf("Enter cell coordinates(r,c):\n");
            startt=clock();
            while(!kbhit()){
            endd=clock();
            idletime=(endd-startt)/CLOCKS_PER_SEC;
              if(idletime==60){
              SetColor(6);
              PrintArray(Display,n,m);
              endis=clock();
              startt=clock();
              timediff=((endis-startis)/CLOCKS_PER_SEC)+recenttimediff;
              SaveGame(Display,n,m);
              min=timediff/60;
              sec=timediff%60;
              printf("QUESTION CELLS : %d\n",questionCells);
              printf("FLAG CELLS : %d\n",FlagCells);
              printf("NUMBER OF MOVES : %d\n",moves);
              printf("TIME %.2d:%.2d\n",min,sec);
              SetColor(24);
              printf("Enter cell coordinates(r,c):\n");
                }}

           scanf("%d%d",&r,&c);
             while(r<=0||c<=0||r>n||c>m){
                printf("INVALID COORDINATES!\n");
                printf("Enter valid cell coordinates(r,c):\n");
                scanf("%d%d",&r,&c);}
           }
           char PlayerName[30];
           if(win==1){
                if(moves!=1){
                 PlayerScore=(pow(n,4)*pow(m,4))/(timediff*moves);
                 printf("YOUR SCORE IS %d\n",PlayerScore);
                 printf("Enter your name (only first name): ");
                 scanf("%s",PlayerName);
                 readd(Playerlist,30);
          int checks=0,index=0;
          for(i=0;i<endofboard+1;i++){
            if(strcmp(Playerlist[i].name,strlwr(PlayerName))==0){
                index=i;
                checks=1;}}
            if(checks==1){
                Playerlist[index].score+=PlayerScore;
                updateleaderboard(Playerlist,30);
                         }
            else{
             strncpy(Playerlist[endofboard].name,strlwr(PlayerName),30);
             Playerlist[endofboard].score=PlayerScore;
             endofboard++;
             Playerlist[endofboard].score=0;
             updateleaderboard(Playerlist,30);
            }
            selectionSort(Playerlist,30);
            updateleaderboard(Playerlist,30);

            for(i=0;i<endofboard;i++){
            printf("%d. %s : %d\n",i+1,Playerlist[i].name,Playerlist[i].score);}}

            else{
                printf("NICE LUCK BUT NO SCORE! %c\n",2);}}}

            return 0;
}

