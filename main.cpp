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
};
void Ve_Tuong();
bool operator==(Point A,Point B);
bool KiemTraQuaTrungThan(QUA qua, CONRAN r);
void TaoQua(QUA &qua,CONRAN r) ;
void AnQua(QUA &qua,CONRAN &r,int &Diem);
void RanXuyenTuong(CONRAN &r);
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
