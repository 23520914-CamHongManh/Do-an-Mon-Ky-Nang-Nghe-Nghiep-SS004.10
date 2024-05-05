#define tuongtrai 10
#define tuongphai 70
#define tuongtren 5
#define tuongduoi 25
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