void Gameplay1()
{
    CONRAN r;
    QUA qua;
    int Huong = 0;
    char t;
  while (1){
        r.XoaCu();
        r.Ve();
        if (kbhit()){
            t = getch();
            if (t=='a'&& Huong!=0) Huong = 2;
            if (t=='w'&& Huong!=1) Huong = 3;
            if (t=='d'&& Huong!=2) Huong = 0;
            if (t=='s'&& Huong!=3) Huong = 1;
        }
        r.DiChuyen(Huong);
        Sleep(300);
    }
}
