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