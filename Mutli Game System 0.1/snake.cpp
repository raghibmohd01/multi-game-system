void select_level();
void logic();
void create_new_food();
void input();
void display();
void border();
void update_tail_cord();
void show_score();
void game_over();
int gd=0,gm,i;
int x,y,food_x,food_y,width_snk=1000,height_snk=600,key,length=2;
int score,tail_x[100],tail_y[100],prev_x,prev_y,prev_x2,prev_y2,margin_x=30,margin_y=30;
int life=2,run=0,old_key,del=60;

bool gameover=false;
void display_food();
void game_start();
int snake_starter()
{


    initgraph(&gd,&gm,"");


    initwindow(width_snk,height_snk,"Multi Game System (Snake_game)",10,50,0);

      setbkcolor(COLOR(217, 229, 249));
    cleardevice();
      settextstyle(8,0,4);
      setcolor(BLUE);
   outtextxy(100,100,"Select Level");
    select_level();
     settextstyle(8,0,2);
      setbkcolor(COLOR(84, 92, 104));
    cleardevice();

    setbkcolor(COLOR(34, 104, 226)); // background  color of view port
     border();
    game_start();


     //end_msg();

closegraph();
    return 0;
}

void game_start()
{
     x=width_snk/2;
    y=height_snk/2;

/*
    tail_x[1]=x-run;
    tail_y[1]=y;
    tail_x[2]=x-2*run;
    tail_y[2]=y;
    */
    create_new_food();

while(!gameover||life)
    {



        if(kbhit())
        {
          input();
          old_key=key;
        }
        //display_food();
        display();
        logic();
        //display();
          show_score();



    }
      settextstyle(8,0,5);
     outtextxy(300,250,"GAME OVER!");
     getch();


}

void input()
{
       key=getKey();


}

void display()
{


 setviewport(margin_x,margin_y,(width_snk-margin_x),height_snk-margin_y,1);
     display_food();
     setfillstyle(1,4);
    circle(x,y,8); //Face
    floodfill(x,y,15);
    circle(x-3,y,2); //eyes
    circle(x+3,y,2);  //eyes
    setcolor(15);

   // line(x-3,y-9,x-10,y-16); // ear
   // line(x+3,y-9,x+10,y-16);


     for(int k=1;k<=length;k++)
     {
       setfillstyle(1,COLOR(161, 186, 24));
     circle(tail_x[k],tail_y[k],6);  //tail
     floodfill(tail_x[k],tail_y[k],15);

     }

    delay(del); //controls speed

    //cleardevice();
    clearviewport();


}

void logic()
{

            prev_x=tail_x[1];
            prev_y=tail_y[1];
            tail_x[1]=x;
            tail_y[1]=y;


             update_tail_cord();

                switch(key)
                {

                case LEFT:
                             x=x-run;
                            break;

                case RIGHT:
                             x=x+run;

                              break;

                case UP:

                        y=y-run;

                        break;

                case DOWN:
                            y=y+run;
                            break;

                case ESC:
                        cleardevice();

                        outtextxy(300,300,"Thank you....");
                        delay(1200);

                        exit(1);
            }
              // end of switch







if(x<=(5)||y<=(5)||x>=(width_snk-margin_x-33)||y>=(height_snk-margin_y-33))
    {
      game_over();
     }


     for(int b=2;b<=length;b++)  //to check if head collapse with tail
     {
         if(tail_x[b]==x && tail_y[b]==y)
                game_over();

     }

if((x>=(food_x-10)&&x<=(food_x+10))&&(y<=(food_y+10)&&y>=(food_y-10))) //to check if food eaten
        {
            length++;
            //if(length==1)
                //length=length+2;
            score+=5;
            create_new_food();

        }

}
// end of logic function



void create_new_food()
{
    int min_x=margin_x+10,max_x=width_snk-margin_x-25;
    int min_y=margin_y+10,max_y=height_snk-margin_y-29;
      srand(time(NULL));
     food_x=rand()%(max_x-min_x)+min_x;
     food_y=rand()%(max_y-min_y)+min_y;
}
void display_food()
{
    int t=getcolor();

     setcolor(14);
     setfillstyle(1,15);
    circle(food_x,food_y,5);
     circle(food_x,food_y,2);
    setcolor(t);


}

void show_score()
{
    int t=getbkcolor(),t1=getcolor();
    char str[128];

    setviewport(width_snk-300,7,width_snk-50,30,1);

    setbkcolor(0);
    setcolor(15);
    sprintf(str,"Score: %d ",score);
 outtextxy(0,0,str);
    sprintf(str,"Life: %d",life);
 outtextxy(130,0,str);
 setbkcolor(t);
 setcolor(t1);


}

void border()
{
    int t=getcolor();

      setcolor(1);
    rectangle(margin_x-5,margin_y-5,width_snk-margin_x+3,height_snk-margin_y+3);
     rectangle(margin_x-2,margin_y-2,width_snk-margin_x,height_snk-margin_y);
     setcolor(t);
      t=getbkcolor();
     setbkcolor(0);
     outtextxy(width_snk-230,height_snk-18,"Press ESC to Exit");

   setbkcolor(t);
}


void update_tail_cord()
{

     for(int s=2;s<length;s++)
            {

                prev_x2=tail_x[s];
                prev_y2=tail_y[s];

                tail_x[s]=prev_x;
                tail_y[s]=prev_y;

                prev_x=prev_x2;

                prev_y=prev_y2;

            }


}
void game_over()
{
    gameover=true;
     life--;
    if(life>=0)
     {

         key=' ';
          length=2;
         game_start();
     }


}

void select_level()
{
    int ch;
    static int y_crd=0;



    setviewport(300,150,600,400,1);

     outtextxy(5,5,"Easy  ");
     outtextxy(5,45,"Medium");
     outtextxy(5,85,"Hard ");
     rectangle(0,y_crd,150,y_crd+35);
     ch=getch();
     if(ch==13)
     {

         if(y_crd==0)
         {
              run=7;
              del=50;
         }
            else if(y_crd==40)
         {
               run=9;
              del=70;
         }
            else if(y_crd==80)
         {
           run=10;
              del=60;
         }
         return;

     }
     else
     {
         if(ch==DOWN||ch==RIGHT)

                  {
                      y_crd=y_crd+40;
                  if(y_crd>80)
                    y_crd=0;
                  }

                  else if(ch==UP||ch==LEFT)
                  {
                      y_crd=y_crd-40;
                  if(y_crd<0)
                    y_crd=80;
                  }
                  clearviewport();
                 select_level();
     }



}
