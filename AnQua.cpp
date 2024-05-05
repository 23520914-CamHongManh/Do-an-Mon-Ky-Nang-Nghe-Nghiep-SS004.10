
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
bool operator==(Point A,Point B)
{
    if(A.x==B.x&&A.y==B.y)
        return true;
    else return false;
}
bool KiemTraQuaTrungThan(QUA qua, CONRAN r)
{
    for(int i=0;i<r.DoDai;i++)
    {
        if(qua.A==r.A[i]) return 1;
    }
    return 0;
}