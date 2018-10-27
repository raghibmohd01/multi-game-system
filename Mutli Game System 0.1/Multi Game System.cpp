#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
void selection_page();
 int width=1000,height=600,x_bar=175,y_bar=10;
#include "get_key.c"
#include  "puzzle.cpp"
#include  "snake.cpp"
#include "sudoku.cpp"
int main()
{
    int ch=0;
    bool selection=false;
    int gd=0,gm;
    initgraph(&gd,&gm,"");


    initwindow(width,height,"Multi Game System",100,50,0);
     setbkcolor(BLUE);
     cleardevice();

      {

   settextstyle(8,0,4);
      rectangle(300,100,665,150);
      rectangle(305,105,660,145);
     outtextxy(312,110,"MULTI GAME SYSTEM");
      }

  selection_page();



      while(selection!=true)

         {



          ch=getKey();



           if(ch==13||ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch==ESC)
           {
               if(ch==13)
               {
                   if(y_bar==10)
                     ch='1';
                   else if(y_bar==55)
                      ch='2';
                   else if(y_bar==100)
                       ch='3';
                   else
                         ch=ESC;
               }
               if(ch=='4')
                 ch=ESC;
               selection=true;
               //break;
           }
           else
           {

               if(ch==DOWN||ch==RIGHT)

                  {
                      y_bar=y_bar+45;
                  if(y_bar>150)
                    y_bar=10;
                  }

                  else if(ch==UP||ch==LEFT)
                  {
                      y_bar=y_bar-45;
                  if(y_bar<10)
                    y_bar=145;
                  }

                   selection_page();


           }


    }


     switch(ch)
          {

          case '1':
                     closegraph();
                     puzzle_starter();

                   break;
          case '2':
                    closegraph();
                    snake_starter();

                    break;
            case '3':

                      closegraph();
                      sudoku_starter();
                      break;
            case ESC:
                       void end_msg();
                       cleardevice();
                          end_msg();
                       //getch();
                      exit(1);


          }



      closegraph();

      return 0;


}

void selection_page()
{

  setbkcolor(BLUE);
    outtextxy(100,300,"Select");

     setviewport(250,350,520,530,1);
     clearviewport();
    setbkcolor(COLOR(05,25,252));

     outtextxy(5,5,"1.Puzzle");
      outtextxy(5,50,"2.Snake ");
      outtextxy(5,95,"3.Suduko");
      outtextxy(5,140,"4.Exit  ");
      bar(x_bar,y_bar,x_bar+30,y_bar+25);


}


void end_msg()
{
         setviewport(0,0,500,500,1);
                       outtextxy(10,100,"Thank you....");
                        outtextxy(20,200,"Created By: ");
                        //outtextxy(70,350,"Mohd Raghib");
                         readimagefile("mr_pic.jpg",50,300,150,400);
                         if(kbhit())
                         {
                             getch();
                         }
                         outtextxy(50,410,"Mohd Raghib");
                         getch();
                       // delay(1200);


}

