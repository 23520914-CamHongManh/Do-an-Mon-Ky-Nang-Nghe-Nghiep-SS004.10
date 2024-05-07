#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#include <string.h>
#define tuongtrai 10
#define tuongphai 70
#define tuongtren 5
#define tuongduoi 25
using namespace std;
void gotoxy( int column, int line );

typedef struct Point{
    int x,y;
}Point;

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
        for (int i = DoDai; i>0;i--)
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
};
void Ve_Tuong();
bool operator==(Point A,Point B);
bool KiemTraQuaTrungThan(QUA qua, CONRAN r);
void TaoQua(QUA &qua,CONRAN r) ;
void AnQua(QUA &qua,CONRAN &r,int &Diem);
bool Game_Over1(CONRAN r);
bool Game_Over2(CONRAN r);
void RanXuyenTuong(CONRAN &r);
void Gameplay1(int mucdo);
void Gameplay2(int mucdo);
int main()
{
    cout<<"--------------- CHAO MUNG BAN DEN VOI GAME RAN SAN MOI CUA CHUNG TOI ---------------\n\n";
    while(1)
    {
        int chedo;
    cout<<"****** Hay nhap che do ban muon choi ******\n\n";
    cout<<"-Nhap 1 de mo che do choi co dien"<<endl;
    cout<<"-Nhap 2 de mo che do choi tu do"<<endl;
    cout<<"-Nhap 3 de thoat khoi tro choi\n"<<endl;
    cin>>chedo;
    while(chedo!=1&&chedo!=2&&chedo!=3)
    {
        cout<<"Che do da nhap khong hop le, nhap lai: ";
        cin>>chedo;
    }
    if(chedo==3)
    {
        cout<<"\n--------------- HEN GAP LAI BAN ---------------";
        return 0;
    }
    int mucdo;
    cout<<"****** Hay nhap muc do choi ban muon ******\n\n";
    cout<<"   Chung toi co 3 muc do kho:"<<endl;
    cout<<"-Nhap 1 de choi muc DE"<<endl<<"-Nhap 2 choi muc TRUNG BINH"<<endl<<"-Nhap 3 de choi muc KHO"<<endl;
    cin>>mucdo;
    while(mucdo!=1&&mucdo!=2&&mucdo!=3)
    {
        cout<<"Muc do da nhap khong hop le, nhap lai: ";
        cin>>mucdo;
    }
    if(chedo==1)
    {
        if(mucdo==1) mucdo=200;
    if(mucdo==2) mucdo=100;
    if(mucdo==3) mucdo=60;
            system("cls");
            time_t t;
            srand((unsigned) time(&t));
            Gameplay1(mucdo);
            int c;
            gotoxy(tuongtrai,tuongduoi+2);
            cout<<"Nhap 0 de quay ve menu hoac so khac de thoat: ";
            cin>>c;
            cout<<endl;
            if(c!=0)
            {
                cout<<"\n--------------- HEN GAP LAI BAN ---------------";
        return 0;
            }
    }
    if(chedo==2)
    {
        if(mucdo==1) mucdo=200;
    if(mucdo==2) mucdo=100;
    if(mucdo==3) mucdo=40;
        system("cls");
            time_t t;
            srand((unsigned) time(&t));
            Gameplay2(mucdo);
            int c;
            gotoxy(tuongtrai,tuongduoi+2);
            cout<<"Nhap 0 de quay ve menu hoac so khac de thoat: ";
            cin>>c;
            cout<<endl;
            if(c!=0)
            {
                cout<<"\n--------------- HEN GAP LAI BAN ---------------";
        return 0;
            }
    }
    }
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
void Ve_Tuong()
{
    for(int i=tuongtrai+1 ;i<=tuongphai-1 ;i++)
    {
        gotoxy(i,tuongtren ); cout<<"-";
    gotoxy(i,tuongduoi ); cout<<"-";
    }
    for(int i=tuongtren+1 ;i<=tuongduoi-1 ;i++)
    {
        gotoxy(tuongtrai,i); cout<<"|";
        gotoxy(tuongphai,i); cout<<"|";
    }
    gotoxy(tuongtrai,tuongtren); cout<<"+";
    gotoxy(tuongphai,tuongtren); cout<<"+";
    gotoxy(tuongtrai,tuongduoi); cout<<"+";
    gotoxy(tuongphai,tuongduoi); cout<<"+";
}
void AnQua(QUA &qua,CONRAN &r,int &Diem)
{
    if(r.A[0]==qua.A)
    {
        r.DoDai++;
        Diem+=10;
        gotoxy(tuongtrai+38,tuongtren-2);
        cout<<Diem;
        TaoQua(qua,r);
        qua.Ve();
    }
}
void TaoQua(QUA &qua,CONRAN r)
{
    bool check =KiemTraQuaTrungThan(qua,r);
    do{
        qua.A.x=rand()%(tuongphai-tuongtrai-1)+tuongtrai+1;
      qua.A.y=rand()%(tuongduoi-tuongtren-1)+tuongtren+1;
      check =KiemTraQuaTrungThan(qua,r);
    }while(check);
}
bool KiemTraQuaTrungThan(QUA qua, CONRAN r)
{
    for(int i=0;i<r.DoDai;i++)
    {
        if(qua.A==r.A[i]) return 1;
    }
    return 0;
}
bool operator==(Point A,Point B)
{
    if(A.x==B.x&&A.y==B.y)
        return true;
    else return false;
}
bool Game_Over1(CONRAN r)
{
    for(int i=1;i<r.DoDai;i++)
    {
        if(r.A[0]==r.A[i]) return true;
    }
    if(r.A[0].x==tuongtrai||r.A[0].x==tuongphai||r.A[0].y==tuongtren||r.A[0].y==tuongduoi) return true;
    return false;
}
bool Game_Over2(CONRAN r)
{
    for(int i=1;i<r.DoDai;i++)
    {
        if(r.A[0]==r.A[i]) return true;
    }
    return false;
}
void RanXuyenTuong(CONRAN &r)
{
    for(int i=0;i<r.DoDai;i++)
    {
        if(r.A[i].x==tuongtrai)
        {
            r.A[i].x+=59;
        }
    if(r.A[i].x==tuongphai)
    {
        r.A[i].x-=59;
    }
    if(r.A[i].y==tuongtren)
    {
        r.A[i].y+=19;
    }
    if(r.A[i].y==tuongduoi)
    {
        r.A[i].y-=19;
    }
    }
}
void Gameplay1(int mucdo)
{
    int DIEM=0;
    gotoxy(tuongtrai+24,tuongtren-2);
    cout<<"DIEM CUA BAN: ";
    gotoxy(tuongtrai+38,tuongtren-2);
    cout<<DIEM;
    CONRAN r;
    QUA qua;
    int Huong = 0;
    char t;
    Ve_Tuong();
    TaoQua(qua,r);
    qua.Ve();
  while (1){
        r.XoaCu();
        r.Ve();
        if(Game_Over1(r))
        {
            gotoxy(tuongtrai+25,tuongduoi-10);
            cout<<"BAN DA CHET";
            break;
        }
        if (kbhit()){
            t = getch();
            if (t=='a'&& Huong!=0) Huong = 2;
            if (t=='w'&& Huong!=1) Huong = 3;
            if (t=='d'&& Huong!=2) Huong = 0;
            if (t=='s'&& Huong!=3) Huong = 1;
        }
        AnQua(qua,r,DIEM);
        r.DiChuyen(Huong);
        Sleep(mucdo);
    }
}
void Gameplay2(int mucdo)
{
    int DIEM=0;
    gotoxy(tuongtrai+24,tuongtren-2);
    cout<<"DIEM CUA BAN: ";
    gotoxy(tuongtrai+38,tuongtren-2);
    cout<<DIEM;
    CONRAN r;
    QUA qua;
    int Huong = 0;
    char t;
    Ve_Tuong();
    TaoQua(qua,r);
    qua.Ve();
  while (1){
        r.XoaCu();
        r.Ve();
        if(Game_Over2(r))
        {
            gotoxy(tuongtrai+25,tuongduoi-10);
            cout<<"BAN DA CHET";
            break;
        }
        if (kbhit()){
            t = getch();
            if (t=='a'&& Huong!=0) Huong = 2;
            if (t=='w'&& Huong!=1) Huong = 3;
            if (t=='d'&& Huong!=2) Huong = 0;
            if (t=='s'&& Huong!=3) Huong = 1;
        }
        AnQua(qua,r,DIEM);
        r.DiChuyen(Huong);
        RanXuyenTuong(r);
        Sleep(mucdo);
    }
}
