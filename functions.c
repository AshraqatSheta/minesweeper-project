#include "functions.h"
#include <windows.h>


void SetColor(int ForgC)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
void PrintArray(char A[100][100],int n,int m){
        int i,j;
        for(i=0;i<n;i++){
        for(j=0;j<m;j++){
             printf("%c ",A[i][j]);}
             printf("\n");}}


void CheckGame(char A[100][100],int i,int j){
         if(A[i][j]!='*'){
                        A[i][j]++;}}
