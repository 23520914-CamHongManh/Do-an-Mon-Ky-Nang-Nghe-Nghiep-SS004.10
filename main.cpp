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
        DoDai = 4;
        for(int i=0;i<DoDai-1;i++)
        {
            A[i].x=tuongtrai+9-i;
            A[i].y=15;
        }
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
            switch (Huong)
        {
        case 2:
            A[0].x--; break;
        case 1:
            A[0].y++; break;
        case 0:
            A[0].x++; break;
        case 3:
            A[0].y--; break;
        }
    }
    void XoaCu()
    {
        gotoxy(A[DoDai].x,A[DoDai].y);
        cout<<" ";
    }

    bool Game_Over2()
    {
    for( int i=1; i < DoDai ; i++)
    {
        if(( A[0].x== A[i].x)&& (A[0].y == A[i].y))
            return true;
    }
    return false;

    }
    bool Game_Over1()
    {   if(A[0].x==tuongtrai ||A[0].x== tuongphai ||A[0].y==tuongtren ||A[0].y==tuongduoi)
        {return true;}

     return false;
    }
};
void Ve_Tuong();
bool operator==(Point A,Point B);
bool KiemTraQuaTrungThan(QUA qua, CONRAN r);
void TaoQua(QUA &qua,CONRAN r) ;
void AnQua(QUA &qua,CONRAN &r,int &Diem);
void RanXuyenTuong(CONRAN &r);
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

