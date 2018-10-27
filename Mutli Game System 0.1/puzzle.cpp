void display_border();
void print();
void draw_lines();
void show_steps();
int check();
void win();
time_t t;
int mat[4][4]={
	             1,4,15,7,
	             8,10,2,11,
	             14,3,6,13,
	             12,9,5,16

};
int vp_x=300,vp_y=200,vp_width=300,vp_height=300;
int x_sqr=240,y_sqr=240,x_p=3,y_p=3,steps=1;
  char str[128];
int puzzle_starter()
{
    int gd=0,gm;
    int done=0;
    int key,tmp1;
    initgraph(&gd,&gm,"");
    initwindow(900,600,"Puzzle",5,10,0);

    setbkcolor(COLOR(104, 125, 145));
    cleardevice();

    display_border();
    setbkcolor(BLUE);

    setviewport(vp_x,vp_y,vp_x+vp_width,vp_y+vp_height,0);

       print();

       t=clock();
      while(done!=1)
      {
          done=check();

          key=getKey();

         switch(key)
         {

     case UP:
          if(x_p>0){
         tmp1=mat[x_p-1][y_p];
          mat[x_p][y_p]=tmp1;
          x_p=x_p-1;
          mat[x_p][y_p]=21;
          print();
          }
          else
            printf("\a");
          break;
 case DOWN:
             if(x_p<3){
          tmp1=mat[x_p+1][y_p];
          mat[x_p][y_p]=tmp1;
          x_p=x_p+1;
          mat[x_p][y_p]=21;
          print();
          }
          else
            printf("\a");
      break;
 case LEFT:
            if(y_p>0){
          tmp1=mat[x_p][y_p-1];
          mat[x_p][y_p]=tmp1;
          y_p=y_p-1;
          mat[x_p][y_p]=21;
          print();
          }
          else
            printf("\a");

     break;
 case RIGHT:
             if(y_p<3){

          tmp1=mat[x_p][y_p+1];
          mat[x_p][y_p]=tmp1;
          y_p=y_p+1;
          mat[x_p][y_p]=21;
          print();
          }
          else
            printf("\a");
     break;


    case ESC:
                    cleardevice();
                       outtextxy(0,0,"Thank you....");
                         outtextxy(100,50,"Created By: ");
                         readimagefile("mr_pic.jpg",110,110,200,200);
                        delay(1200);
                      exit(1);

         }
         steps++;



      }
     t=clock()-t;
     t=t/CLOCKS_PER_SEC;
     win();
     getch();

    closegraph();
    return 0;

}

void display_border()
{
    settextstyle(6, 0, 3);
   // outtextxy(0,0,"Player : ");
    outtextxy(700,0,"Steps: ");
   outtextxy(600,570,"Press ESC to exit");
    rectangle(300-2,200-2,600+2,500+2);




}

void print()
{
    int i,j;
    clearviewport();

    draw_lines();

         settextstyle(8,0,4);

         for(i=0;i<=3;i++)
         {

          for(j=0;j<=3;j++)

           {
             sprintf(str,"%d",mat[i][j]);
               outtextxy(20+75*(j),20+75*(i),str);

            }

         }

         bar(y_p*75+20,x_p*75+20,y_p*75+70,x_p*75+70);
        show_steps();



}
void draw_lines()
{
    //horizontal
   line(0,75,vp_width,75);
    line(0,150,vp_width,150);
    line(0,225,vp_width,225);

    //vertical
    line(75,0,75,vp_height);
    line(150,0,150,vp_height);
    line(225,0,225,vp_height);


}
int check()
{
    int *p;
    short v;
    v=1;

    p=(int*)mat;


    for(int i=0;i<16;i++)
    {

        if(*(p+i)>*(p+i+1))
           v=0;

    }
    return v;
}

void show_steps()
{
    sprintf(str,"%d",steps/2);
    outtextxy(500,-202,str);
}

void win()
{
    float tm=t;
    setviewport(0,0,700,600,0);
    cleardevice();
    outtextxy(300,250,"Done ! ");
    sprintf(str,"Steps :  %d",steps/2);
    outtextxy(300,350,str);
    sprintf(str,"Time Taken: %.1f sec",tm);
    outtextxy(300,400,str);


    getch();
}



