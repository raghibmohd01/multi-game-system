#define ESC 27
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
int getKey();
int getKey()
{
 int ch;
 ch=getch();
if(ch==0)
{
    ch=(int)getch;
	return ch;
}
return ch;
}




