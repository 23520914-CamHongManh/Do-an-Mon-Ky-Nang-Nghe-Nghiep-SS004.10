#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#define tuongtrai 10
#define tuongphai 70
#define tuongtren 5
#define tuongduoi 25
using namespace std;
void gotoxy( int column, int line );
struct Point{
    int x,y;
};
class QUA{
    public:
    struct Point A;
    QUA()
    {
        A.x=rand()%(tuongphai-tuongtrai-1)+tuongtrai+1;
      A.y=rand()%(tuongduoi-tuongtren-1)+tuongtren+1;
    }
    void Ve(){
            gotoxy(A.x,A.y);
            cout<<"#";
        }
};
class CONRAN{
public:
    struct Point A[100];
    int DoDai;
    CONRAN(){
        DoDai = 3;
        A[0].x = 10; A[0].y = 10;
        A[1].x = 11; A[1].y = 10;
        A[2].x = 12; A[2].y = 10;
    }
    void Ve(){
        for (int i = 0; i < DoDai; i++){
            if(i==0)
            {
                gotoxy(A[i].x,A[i].y);
            cout<<"O";
            }
            else{
                gotoxy(A[i].x,A[i].y);
            cout<<"o";
            }
        }
    }
    void DiChuyen(int Huong){
        for (int i = DoDai-1; i>0;i--)
            A[i] = A[i-1];
        if (Huong==0) A[0].x = A[0].x + 1;
        if (Huong==1) A[0].y = A[0].y + 1;
        if (Huong==2) A[0].x = A[0].x - 1;
        if (Huong==3) A[0].y = A[0].y - 1;
    }
};
void Ve_Tuong();
bool operator==(Point A,Point B);
bool KiemTraQuaTrungThan(QUA qua, CONRAN r);
void TaoQua(QUA &qua,CONRAN r) ;
void AnQua(QUA &qua,CONRAN &r,int &Diem);
int main()
{
    CONRAN r;
    int Huong = 0;
    char t;
Ve_Tuong();
    while (1){
        if (kbhit()){
            t = getch();
            if (t=='a') Huong = 2;
            if (t=='w') Huong = 3;
            if (t=='d') Huong = 0;
            if (t=='s') Huong = 1;
        }
        //system("cls");
        //r.DiChuyen(Huong);
        r.Ve();
        Sleep(300);
    }

    return 0;
}
typedef struct Point{
    int x,y;
}Point;
class QUA{
    public:
    struct Point A;
    QUA(){
        int x=rand()%(tuongphai-tuongtrai+1)+tuongtrai;
        int y=rand()%(tuongduoi-tuongtren+1)+tuongtren;
        A.x=x;
        A.y=y;
    }
    void Ve(){
            gotoxy(A.x,A.y);
            cout<<"#";
        }

};

void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }

