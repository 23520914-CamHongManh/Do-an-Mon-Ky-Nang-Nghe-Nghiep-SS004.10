void Gameplay2(int mucdo)
{
    int DIEM=0;
    gotoxy(tuongtrai+24,tuongtren-2);
    cout<<"DIEM CUA BAN: ";
    gotoxy(tuongtrai+38,tuongtren-2);
    cout<<DIEM;
    CONRAN r;
    QUA qua;
    int x= tuongtrai+9;
    int y=15;
    int Huong = 0;
    char t;
    Ve_Tuong();
    TaoQua(qua,r);
    qua.Ve();
  while (1){
        r.XoaCu();
        r.Ve();
        if(r.Game_Over2())
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

