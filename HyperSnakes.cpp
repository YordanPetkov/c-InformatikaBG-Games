#include<iostream>
#include<cmath>
using namespace std;
int AppleX[28],AppleY[28],Apples=0;
char Table[23][23];
class Snake
{
    public:
    int HeadX,HeadY;
    int Size;
    int TailX,TailY;
    int TailName;
    void Show()
    {
        cout<<HeadX<<" "<<HeadY<<endl;
        cout<<"SIZE : "<<Size<<endl;
        cout<<TailX<<" "<<TailY<<endl;
    }
};
Snake I,Enemy;
void Input()
{
    
    I.Size=1;
    Enemy.Size=1;
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=20;j++)
        {
            cin>>Table[i][j];
            if(Table[i][j]=='@')
            {
                Apples++;
                AppleX[Apples]=i;
                AppleY[Apples]=j;
            }
            if(Table[i][j]=='A')
            {
                I.HeadX=i;
                I.HeadY=j;
                
                
            }
            if(Table[i][j]>'A' && Table[i][j]<='Z')
            {
                
                if(I.Size<Table[i][j]-'A'){I.Size=Table[i][j]-'A'+1;I.TailX=i;I.TailY=j;I.TailName=Table[i][j];}
            }
            if(Table[i][j]=='a')
            {
                Enemy.HeadX=i;
                Enemy.HeadY=j;
                
                
            }
            if(Table[i][j]>'a' && Table[i][j]<='z')
            {
                if(Enemy.Size<Table[i][j]-'a'){Enemy.Size=Table[i][j]-'a'+1;Enemy.TailX=i;Enemy.TailY=j;Enemy.TailName=Table[i][j];}
            }
        }
    }
    //I.Show();
    //Enemy.Show();
    
}
bool GoUp=true,GoDown=true,GoRight=true,GoLeft=true;
char OnePossibleMove()
{
    int x=I.HeadX,y=I.HeadY;
    if(Table[x-1][y]!='.' && Table[x-1][y]!='@')GoDown=false;
    if(Table[x+1][y]!='.' && Table[x+1][y]!='@')GoUp=false;
    if(Table[x][y-1]!='.' && Table[x][y-1]!='@')GoLeft=false;
    if(Table[x][y+1]!='.' && Table[x][y+1]!='@')GoRight=false;
    if(GoUp+GoDown+GoRight+GoLeft==1)
    {
        if(GoUp)return 'u';
        if(GoDown)return 'd';
        if(GoRight)return 'r';
        if(GoLeft)return 'l';
    }
    return 'n';
}
char AttackTheEnemy()
{
    
    return 'n';
}
char DoNotGoThere()
{
    return 'n';
}
char GoForApple()
{
    int minx=0,miny=0,min=51;
    for(int i=1;i<=Apples;i++)
    {
        if(abs(AppleX[i]-I.HeadX)+abs(AppleY[i]-I.HeadY)<min){min=abs(AppleX[i]-I.HeadX)+abs(AppleY[i]-I.HeadY);minx=AppleX[i];miny=AppleY[i];}
    }
    //cout<<minx<<" "<<miny<<endl;
    if(minx<I.HeadX && GoUp)return 'u';
    if(miny>I.HeadY && GoRight)return 'r';
    if(minx>I.HeadX && GoDown)return 'd';
    if(miny>I.HeadY && GoLeft)return 'l';
   
    if(minx<I.HeadX){
    if(GoUp)return 'u';
    }
    if(GoDown)return 'd';
    if(GoRight)return 'r';
    if(GoLeft)return 'l';
    return 'n';
}
char HyperSnakesBrain()
{
    char CurrentAnswer;
    
    CurrentAnswer=OnePossibleMove();
    if(CurrentAnswer!='n')return CurrentAnswer;
    
    CurrentAnswer=AttackTheEnemy();
    if(CurrentAnswer!='n')return CurrentAnswer;
    
    CurrentAnswer=DoNotGoThere();
    if(CurrentAnswer!='n')return CurrentAnswer;
    
    CurrentAnswer=GoForApple();
    if(CurrentAnswer!='n')return CurrentAnswer;
}
int main()
{
    Input();
    char ANSWER;
    ANSWER=HyperSnakesBrain();
    if(ANSWER=='u')cout<<"Up"<<endl;
    if(ANSWER=='d')cout<<"Down"<<endl;
    if(ANSWER=='r')cout<<"Right"<<endl;
    if(ANSWER=='l')cout<<"Left"<<endl;
    //cout<<GoUp<<GoDown<<GoRight<<GoLeft<<endl;
    //cout<<GoUp+GoDown+GoRight+GoLeft<<endl;
    return 0;
}