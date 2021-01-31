#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include<conio.h>
#define length 8
int whoplay=0;
char chessboard[length][length],killed[30];
char *numofkilled=killed;
void fullchess();
void printchessboard ();
void checkmove (int a,int b,int c,int d);
void smallmove (int a,int b,int c,int d);
void bigmove (int a,int b,int c,int d);
bool isempty (int c, int d);
bool checkwhitebowns (int a,int b,int c,int d);
bool checkblackbowns (int a,int b,int c,int d);
bool checkrooks (int a,int b,int c,int d);
bool checkknights (int a,int b,int c,int d);
bool checkbishops (int a,int b,int c,int d);
bool checkqueen (int a,int b,int c,int d);
bool checkking (int a,int b,int c,int d);
int main(void){
    fullchess();
    printchessboard();
    }
void fullchess(){
    for (int i=0;i<length;i++){
        for (int j=0;j<length;j++)
            if ((i-j)%2==0) chessboard[i][j]='.';
            else chessboard[i][j]='-';
    }
    for (int j=0;j<length;j++) chessboard[1][j]='p';
    for (int j=0;j<length;j++) chessboard[6][j]='P';
    chessboard[0][0]=chessboard[0][7]='r';
    chessboard[7][0]=chessboard[7][7]='R';
    chessboard[0][1]=chessboard[0][6]='n';
    chessboard[7][1]=chessboard[7][6]='N';
    chessboard[0][2]=chessboard[0][5]='b';
    chessboard[7][2]=chessboard[7][5]='B';
    chessboard[0][4]='q';
    chessboard[7][4]='Q';
    chessboard[0][3]='k';
    chessboard[7][3]='K';
    return;
}
void printchessboard (){
    system("cls");
    printf(".................................\n..............CHESS..............\n.................................\n");
    for (int i=0;i<length;i++) printf("   %c",'a'+i);
    printf("\n");
    for (int i=0;i<length;i++){
        printf(" %d",abs(8-i));
        for (int j=0;j<length;j++)
            printf("[%c] ",chessboard[i][j]);
        printf("\n");
    }
    printf(" KILLED : ");
    for (int i=0;killed[i]!=*numofkilled;i++) printf("%c",killed[i]);
    printf("\n");
    printf("Make sure u don't open caps lock\n");
    printf("For undo click u for redo click r for play click n\n");
    if (whoplay%2==0)printf("White Should Play\n");
    else printf("Black Should Play\n");
    char choise;
    scanf(" %c",&choise);
    switch(choise){
        case 'u':
            choise='u';
            break;
        case 'r':
            choise='r';
            break;
        case 'n':{
            char x1,x2;
            int y1,y2;
            printf("From ?");
            while (getchar()!='\n');
            scanf(" %c %d",&x1,&y1);
            printf("To?");
            scanf(" %c %d",&x2,&y2);
            checkmove(y1,x1,y2,x2);
            break;
        default:
            printf("NOT Valid. You Have To Chose u , r or n");
                    while (getchar()!='\n');
                    while (getchar()!='\n');
                    printchessboard();}}
    return;
}
void checkmove (int a,int b,int c,int d){
    a=abs(8-a);
    b=b-97;
    c=abs(8-c);
    d=d-97;
    //cheak who play white or black
    if (whoplay%2==0&&chessboard[a][b]>65&&chessboard[a][b]<83){
            printf("NOT Valid. White Should Play");
                while (getchar()!='\n');
                while (getchar()!='\n');
                printchessboard();
            }
    else if(whoplay%2==1&&chessboard[a][b]>97&&chessboard[a][b]<115){
                    printf("NOT Valid. black Should Play");
                    while (getchar()!='\n');
                    while (getchar()!='\n');
                    printchessboard();
                }
    if (whoplay%2==0&&chessboard[c][d]>97&&chessboard[c][d]<115){
        printf("NOT Valid. hanhzr ?");
                while (getchar()!='\n');
                while (getchar()!='\n');
                printchessboard();
    }
    else if (whoplay%2==1&&chessboard[c][d]>65&&chessboard[c][d]<83){
        printf("NOT Valid. hanhzr ?");
                while (getchar()!='\n');
                while (getchar()!='\n');
                printchessboard();
    }
    switch (chessboard[a][b]){
        case 'p':
            if (checkwhitebowns(a,b,c,d)){
                if (isempty(c,d))smallmove(a,b,c,d);
                else bigmove(a,b,c,d);
                whoplay++;
                printchessboard();
            }
            else {
                    printf("NOT Valid.You can't Use This Place");
                    while (getchar()!='\n');
                    while (getchar()!='\n');
                    printchessboard();
                }
            break;
        case 'P':
            if (checkblackbowns(a,b,c,d)){
                if (isempty(c,d))smallmove(a,b,c,d);
                else bigmove(a,b,c,d);
                whoplay++;
                    printchessboard();
            }
            else {
                    printf("NOT Valid.You can't Use This Place");
                    while (getchar()!='\n');
                    while (getchar()!='\n');
                    printchessboard();
                }
            break;
        case 'R' : case 'r':
               if (checkrooks(a,b,c,d)){
                if (isempty(c,d))smallmove(a,b,c,d);
                else bigmove(a,b,c,d);
                whoplay++;
                printchessboard();
            }
            else {
                    printf("NOT Valid.You can't Use This Place");
                    while (getchar()!='\n');
                    while (getchar()!='\n');
                    printchessboard();
                }
            break;
        case 'N' : case 'n' :
               if (checkknights(a,b,c,d)){
                if (isempty(c,d))smallmove(a,b,c,d);
                else bigmove(a,b,c,d);
                whoplay++;
                printchessboard();
            }
            else {
                    printf("NOT Valid.You can't Use This Place");
                    while (getchar()!='\n');
                    while (getchar()!='\n');
                    printchessboard();
                }
            break;
        case 'B': case 'b':
               if (checkbishops(a,b,c,d)){
                if (isempty(c,d))smallmove(a,b,c,d);
                else bigmove(a,b,c,d);
                whoplay++;
                printchessboard();
            }
            else {
                    printf("NOT Valid.You can't Use This Place");
                    while (getchar()!='\n');
                    while (getchar()!='\n');
                    printchessboard();
                }
            break;
        case 'Q': case 'q':
               if (checkqueen(a,b,c,d)){
                if (isempty(c,d))smallmove(a,b,c,d);
                else bigmove(a,b,c,d);
                whoplay++;
                printchessboard();
            }
            else {
                    printf("NOT Valid.You can't Use This Place");
                    while (getchar()!='\n');
                    while (getchar()!='\n');
                    printchessboard();
                }
            break;
        case 'K': case 'k':
               if (checkking(a,b,c,d)){
                if (isempty(c,d))smallmove(a,b,c,d);
                else bigmove(a,b,c,d);
                whoplay++;
                printchessboard();
            }
            else {
                    printf("NOT Valid.You can't Use This Place");
                    while (getchar()!='\n');
                    while (getchar()!='\n');
                    printchessboard();
                }
            break;}
    printchessboard();
    return;
}
void smallmove (int a,int b,int c,int d){
    chessboard[c][d]=chessboard[a][b];
     if ((a-b)%2==0) chessboard[a][b]='.';
    else chessboard[a][b]='-';
}
void bigmove (int a,int b,int c,int d){
    if (chessboard[c][d]=='k'||chessboard[c][d]=='K') {
           system("cls");
           printf("END GAME");
           printf("play again y or n ?");
           char what;
           scanf(" %c",&what);
           if (what=='y') {
               fullchess();
                printchessboard();
           }
           else if (what=='n') exit(0);
           else printf("NOT Valid. You Have To Chose y or n");
    }
    *numofkilled=chessboard[c][d];
    numofkilled++;
    chessboard[c][d]=chessboard[a][b];
    if ((a-b)%2==0) chessboard[a][b]='.';
        else chessboard[a][b]='-';
}
bool isempty (int c, int d){
    if (chessboard[c][d]=='-'||chessboard[c][d]=='.') return true;
    return false;
}
bool checkwhitebowns (int a,int b,int c,int d){
    if (c-a==2){
        if (d==b){
            if (a==1) return true;
            else return false;
        }
        else return false;
    }
    else if (c-a==1){
        if (d==b) {
            if (isempty(c,d)) return true;
            else return false;
        }
        else if (abs(d-b)==1){
            if (!isempty(c,d)){
                return true;
            }
        }
        else return false;
    }
    else return false;
}
bool checkblackbowns (int a,int b,int c,int d){
    if (a-c==2){
        if (d==b){
            if (a==6) return true;
            else return false;
        }
        else return false;
    }
    else if (a-c==1){
        if (d==b) {
            if (isempty(c,d)) return true;
            else return false;
        }
        else if (abs(d-b)==1){
            if (!isempty(c,d)){
                return true;
            }
        }
        else return false;
    }
    else return false;
}
bool checkrooks (int a,int b,int c,int d){
    if (a==c&&d!=b){
    for (int i=d>b?b+1:b-1;i!=d;d>b?i++:i--){
        if (!(chessboard[a][i]=='.'||chessboard[a][i]=='-')) return false;
    }
    return true;
    }
    else if (a!=c&&d==b){
      for (int i=c>a?a+1:a-1 ; i!=c ; c>a?i++:i--){
        if (!(chessboard[i][b]=='.'||chessboard[i][b]=='-')) return false;
    }
        return true;
    }
    else return false;
}
bool checkknights (int a,int b,int c,int d){
    if (abs(a-c)==1&&abs(d-b)==2) return true;
    else if (abs(a-c)==2&&abs(d-b)==1)  return true;
    else return false;
}
bool checkbishops (int a,int b,int c,int d){
    if (abs(a-c)==abs(d-b)) {
        for (int i=c>a?a+1:a-1, j=d>b?b+1:b-1  ; i!=c ; c>a?i++:i--,d>b?j++:j--){
            if (!(chessboard[i][j]=='.'||chessboard[i][j]=='-')) return false;
        }
        return true;
    }
    else return false;
}
bool checkqueen (int a,int b,int c,int d){
    if (checkrooks(a,b,c,d)||checkbishops(a,b,c,d)) return true;
    else return false;
}
bool checkking (int a,int b,int c,int d){
    if (abs(a-c)==1&&abs(d-b)==1)  return true;
    if (a==c&&abs(d-b)==1) return true;
    if (abs(a-c)==1&&d==b)  return true;
    else return false;
}
