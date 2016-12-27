#include "winlose.h"


void Lose(char Display[100][100],char Game[100][100],int r,int c,int n,int m){
    Display[r-1][c-1]='!';
         int i,j;
                    for(i=0;i<n;i++){
                            for(j=0;j<m;j++){
                             if (Display[i][j]=='F'){
                                    if(Game[i][j]!='*'){
                                            Display[i][j]='-';}
                             else {
                                Display[i][j]='*';
                             }}
                             else if(Display[i][j]=='?'){
                                    Display[i][j] = Game[i][j];}
                             else if(Game[i][j]=='*'){
                                    if((i!=(r-1))||(j!=(c-1))){
                                            Display[i][j]='M';}}
                             else{Display[i][j]=Game[i][j];}
                            }}}

          int CheckWin(char Display[100][100],char Game[100][100],int n,int m){
                    int flag=0;
                    int i,j;
                    for(i=0;i<n;i++){
                    for(j=0;j<m;j++){
                    if(Game[i][j]!='*'){
                    if(Display[i][j]!=Game[i][j]){
                                            flag=1;}}}}
                return flag;}


