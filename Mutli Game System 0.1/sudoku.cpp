int check_row(int *p);
int check_colm(int *p);
void brdr();
void display_sud();
void show_box();
void show_timer();
int box_x=0,box_y=0;
float tm;
int cc[9][9];
int mat_sud[9][9] ={
                   3,1,4,8,0,9,5,6,0,
                   5,0,9,0,1,6,0,4,7,
                   2,6,7,0,4,5,8,9,1,
                   0,5,2,7,0,4,1,0,6,
                   6,0,1,9,8,0,4,0,3,
                   0,4,3,0,5,1,2,7,0,
                   1,0,6,5,9,8,7,0,4,
                   0,3,8,0,6,7,0,2,5,
                   7,9,0,4,2,3,6,0,8
                };


int sudoku_starter()
{
    void load_cc();
    void initialize();
    int gd=0,gm;
    int c[9],r[9],*p,i,j,c_temp=0,r_temp=0;
    int key,value;
    bool done=false;
    initgraph(&gd,&gm,"");
    initwindow(950,670,"Sudoku",100,10);

    setbkcolor(COLOR(151, 169, 178)); //background color
    cleardevice();

   // initialize();


    p=(int *)mat_sud;


     load_cc();
     brdr();

     display_sud();
      show_box();

 t=clock();

while(done!=true)
{

  r_temp=0;
  c_temp=0;
   key=getch();

       if(key>='1'&&key<='9')
       {
           if(cc[box_x][box_y]==0)
           {

          mat_sud[box_x][box_y]=key-48;
          sprintf(str,"%d",key-48);
          setviewport(0,0,1000,600,0);
          outtextxy(223+60*box_x,85+60*box_y,str);
           }
       }
       else
       {
        if(key==UP&&box_y>0)
        {

        box_y=box_y-1;
         show_box();
        }
        if(key==DOWN&&box_y<8)
        {
          box_y=box_y+1;

          show_box();

        }
          if(key==RIGHT&&box_x<8)

        {
            box_x=box_x+1;
           show_box();
        }
        if(key==LEFT&&box_x>0)
        {
          box_x=box_x-1;
          show_box();
        }

        if(key==ESC)
        {
            cleardevice();
            setviewport(0,0,700,600,0);
            outtextxy(300,300,"Thank you");
            delay(1000);
            exit(1);
        }

       }


for(i=0;i<=8;i++)
{

r[i]=check_row(p+9*i);
if(r[i]==1)
    r_temp++;
}
for(i=0;i<=8;i++)
{
c[i]=check_colm(p+i);
if(c[i]==1)
    c_temp++;

}


if(r_temp==9&&c_temp==9)
     done=true;

}

 t=clock()-t;
 tm=tm+t/CLOCKS_PER_SEC;

   cleardevice();
   outtextxy(350,300,"Done!");
   show_timer();

  getch();
  closegraph();
return 0;


}




int check_row(int *p)
{
    int v=1,s=0,cnt[9]={0};
   for(int i=0;i<=8;i++)
    {
        s=*(p+i);
        switch(s)
        {     case 1:
               cnt[0]=cnt[0]+1; break;
               case 2:
               cnt[1]=cnt[1]+1; break;
               case 3:
               cnt[2]=cnt[2]+1; break;
               case 4:
               cnt[3]=cnt[3]+1; break;
               case 5:
               cnt[4]=cnt[4]+1; break;
               case 6:
               cnt[5]=cnt[5]+1; break;
               case 7:
               cnt[6]=cnt[6]+1; break;
               case 8:
               cnt[7]=cnt[7]+1; break;
               case 9:
               cnt[8]=cnt[8]+1;
        }
}
  for(i=0;i<=8;i++)
  {
      if(cnt[i]!=1)
        v=0;
  }
  return v;

}

int check_colm(int *p)
{

    int v=1,cnt[9]={0};

    for(int i=0;i<=8;i++)
    {
        switch(*(p+i*9))
        {     case 1:
               cnt[0]=cnt[0]+1; break;
               case 2:
               cnt[1]=cnt[1]+1; break;
               case 3:
               cnt[2]=cnt[2]+1; break;
               case 4:
               cnt[3]=cnt[3]+1; break;
               case 5:
               cnt[4]=cnt[4]+1; break;
               case 6:
               cnt[5]=cnt[5]+1; break;
               case 7:
               cnt[6]=cnt[6]+1; break;
               case 8:
               cnt[7]=cnt[7]+1; break;
               case 9:
               cnt[8]=cnt[8]+1;
        }
}
  for(i=0;i<=8;i++)
  {
      if(cnt[i]!=1)
        v=0;
  }
  return v;

}

void brdr()
{
  // div=60
  setviewport(0,0,1000,800,0);

  setcolor(/*COLOR(15, 27, 33)*/15);
   rectangle(200,70,740,610);
   rectangle(199,69,741,611);


    setcolor(BLUE);
  for(int t=1;t<=8;t++)
  {

      line(200+60*t,70,200+60*t,610);
  }

  for(int t=1;t<=8;t++)
  {

      line(200,60*t+70,740,60*t+70);
  }



  for(int t=1;t<=2;t++)
  {

  line(180*t+199,70,180*t+199,610);
  line(180*t+201,70,180*t+201,610);

}

for(int t=1;t<=2;t++)
  {

  line(200,69+180*t,740,69+180*t);
  line(200,71+180*t,740,71+180*t);

}

}
void display_sud()
{
    int t1,t2;
    int i,j;
    settextstyle(8,0,4);
    setcolor(/*COLOR(244, 244, 12)*/0);
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            t1=i*60+200;
            t2=j*60+70;

            setviewport(t1,t2,t1+50,t2+50,1);


               if(mat_sud[i][j]==0)
               {
                  outtextxy(22,15," ");
               }
               else
               {
                   int tt=getcolor();
                   if(cc[i][j]==0)
                    setcolor(COLOR(244, 244, 12));
              sprintf(str,"%d",mat_sud[i][j]);
              outtextxy(20,18,str);
               setcolor(tt);
               }
        }


    }




}
void show_box()
 {
     cleardevice();

     int t1=box_x*60,t2=box_y*60;
     setviewport(202+t1,72+t2,255+t1,125+t2,1);
     setcolor(RED);
     rectangle(10,10,50,52);
     setcolor(15);
       brdr();
    display_sud();


 }
void show_timer()
{  float s;
   // setviewport(20,20,200,70,1);
   if(tm>60)
   {
         s=tm/60.0;
    tm=(int)tm%60;

    sprintf(str,"Time: %.0f.%.0f min",s,tm);
    outtextxy(300,350,str);
   }
   else
   {
    sprintf(str,"Time: %.1f sec",tm);
    outtextxy(300,350,str);
   }
}

void load_cc()
{

    for(int i=0;i<9;i++)
    {

        for(int j=0;j<9;j++)
        {

            if(mat_sud[i][j]!=0)
            {
                cc[i][j]=1;
            }
        }
    }
}

/*
void initialize()
{

    int x,y,n,i,j;
    int t1,len=50;
    srand(time(0));


for(j=0;j<len;j++)
{
    t1=1;
    x=rand()%(9);
    y=rand()%9;
     n=rand()%9+1;
  for(i=0;i<9;i++)
  {
      if(mat_sud[x][i]==n)
       t1=0;
       if(mat_sud[i][y]==n)
       t1=0;
  }
  if(t1==0)
    len++;
    else
         mat_sud[x][y]=n;


}


}
*/
