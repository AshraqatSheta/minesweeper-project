#include <stdio.h>
        int moves;
        int questionCells;
        int FlagCells;
       int recenttimediff;
       int timediff;
       int n,m;

  void writefile(char A[100][100],int n,int m){
     int i,j;
     FILE *Gamegrid ;
     Gamegrid=fopen("Gamegrid.txt","w");
     fprintf(Gamegrid,"%d %d\n",n,m);
      for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(A[i][j]==' '){
                fprintf(Gamegrid,"S");}
               else{fprintf(Gamegrid,"%c",A[i][j]);}
        } fprintf(Gamegrid,"\n");}
    fclose(Gamegrid);}

 void SaveGame(char A[100][100],int n,int m){
     int i,j;
     FILE *Displaygrid;
     Displaygrid=fopen("Displaygame.txt","w");
     fprintf(Displaygrid,"%d %d %d %d\n",questionCells,FlagCells,moves,timediff);
     for(i=0;i<n;i++){
        for(j=0;j<m;j++){
                 if(A[i][j]==' '){
                fprintf(Displaygrid,"S");}
               else{fprintf(Displaygrid,"%c",A[i][j]);}
        } fprintf(Displaygrid,"\n");}

        fclose(Displaygrid);}

 void readgame(char A[100][100]){
     int i,j;
     FILE *Gamegrid;
     Gamegrid=fopen("Gamegrid.txt","r");
     fscanf(Gamegrid,"%d %d ",&n,&m);
     for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                    fscanf(Gamegrid,"%c ",&A[i][j]);
            if(A[i][j]=='S'){
                    A[i][j]=' ';}}}}

  void ReadDisplay(char A[100][100],int n,int m){
      int i,j;
      FILE *Displaygrid;
      Displaygrid=fopen("Displaygame.txt","r");
      fscanf(Displaygrid,"%d %d %d %d ",&questionCells,&FlagCells,&moves,&recenttimediff);
      for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                    fscanf(Displaygrid,"%c ",&A[i][j]);
            if(A[i][j]=='S'){
                    A[i][j]=' ';}}}
    }



