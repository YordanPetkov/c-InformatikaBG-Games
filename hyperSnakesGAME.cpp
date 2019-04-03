#include<iostream>
#include<algorithm>
using namespace std;
char Table[21][21];

struct Apple
{
    public:
    int x,y;
    int dYou,dEnemy;
}a[25];
int BrApples=0;
class Snake
{
    public:
    int x,y;
    int Size;
    Snake();
    
}s[2];
Snake::Snake(void)
{
    Size=0;
}


void Input();
void SortApples();
bool CanLeft(int i,int j);
bool CanRight(int i,int j);
bool CanUp(int i,int j);
bool CanDown(int i,int j);

///Moves
bool OnlyOneMove();
bool BlockEnemy();
void GoToApple();
int main()
{
    Input();
    SortApples();
    
    if(OnlyOneMove())return 0;
    if(BlockEnemy())return 0;
    GoToApple();
    return 0;
}

void Input()
{
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=20;j++)
        {
            cin>>Table[i][j];
            if(Table[i][j]=='@')
            {
                a[BrApples].x=i;
                a[BrApples].y=j;
                BrApples++;
            }
            if(Table[i][j]>='a' && Table[i][j]<='z')
            {
                if(Table[i][j]=='a')
                {
                    s[1].x=i;
                    s[1].y=j;
                }
                s[1].Size++;
            }
            if(Table[i][j]>='A' && Table[i][j]<='Z')
            {
                if(Table[i][j]=='A')
                {
                    s[0].x=i;
                    s[0].y=j;
                }
                s[0].Size++;
            }
        }
    }
    
    for(int i=0;i<BrApples;i++)
    {
        a[i].dYou=abs(s[0].x-a[i].x)+abs(s[0].y-a[i].y);
        a[i].dEnemy=abs(s[1].x-a[i].x)+abs(s[1].y-a[i].y);
    }
}
void SortApples()
{
    for(int i=BrApples;i>0;i--)
    for(int j=0;j<i-1;j++)
    if(a[j].dYou>a[j+1].dYou)swap(a[j],a[j+1]);
    //for(int i=0;i<BrApples;i++)
    //cout<<a[i].x<<" "<<a[i].y<<endl;
    
}
bool CanLeft(int i,int j)
{
    if(Table[i][j-1]=='.' || Table[i][j-1]=='@')return true;
    return false;
}
bool CanRight(int i,int j)
{
    if(Table[i][j+1]=='.' || Table[i][j+1]=='@')return true;
    return false;
}
bool CanUp(int i,int j)
{
    if(Table[i-1][j]=='.' || Table[i-1][j]=='@')return true;
    return false;
}
bool CanDown(int i,int j)
{
    if(Table[i+1][j]=='.' || Table[i+1][j]=='@')return true;
    return false;
}

///MOVES
bool OnlyOneMove()
{
    bool L=true,R=true,U=true,D=true,TRUE=true;
    if(!CanLeft(s[0].x,s[0].y))L=false;
    if(!CanRight(s[0].x,s[0].y))R=false;
    if(!CanUp(s[0].x,s[0].y))U=false;
    if(!CanDown(s[0].x,s[0].y))D=false;
    
    if(L+R+U+D==1)
    {
        if(L==true){cout<<"Left"<<endl;return true;}
        if(R==true){cout<<"Right"<<endl;return true;}
        if(U==true){cout<<"Up"<<endl;return true;}
        if(D==true){cout<<"Down"<<endl;return true;}
    }
    return false;
}
bool BlockEnemy()
{
    if((s[1].x==1 && s[0].x==2 && s[1].y==s[0].y) || (s[1].x==20 && s[0].x==19 && s[1].y==s[0].y))
    {
        if(!CanLeft(s[1].x,s[1].y) && CanRight(s[0].x,s[0].y)){cout<<"Right"<<endl;return true;}
        if(CanLeft(s[0].x,s[0].y) && !CanRight(s[1].x,s[1].y)){cout<<"Left"<<endl;return true;}
    }
    if((s[1].y==1 && s[0].y==2 && s[1].x==s[0].x) || (s[1].y==20 && s[0].y==19 && s[1].x==s[0].x))
    {
        if(!CanUp(s[1].x,s[1].y) && CanDown(s[0].x,s[0].y)){cout<<"Down"<<endl;return true;}
        if(CanUp(s[0].x,s[0].y) && !CanDown(s[1].x,s[1].y)){cout<<"Up"<<endl;return true;}
    }
    return false;
    
}
void GoToApple()
{
    
    for(int i=0;i<BrApples;i++)
    {
        if(a[i].dYou<=a[i].dEnemy)
        {
            if(a[i].x<s[0].x && CanUp(s[0].x,s[0].y)){cout<<"Up"<<endl;return;}
            if(a[i].x>s[0].x && CanDown(s[0].x,s[0].y)){cout<<"Down"<<endl;return;}
            if(a[i].y<s[0].y && CanLeft(s[0].x,s[0].y)){cout<<"Left"<<endl;return;}
            if(a[i].y>s[0].y && CanRight(s[0].x,s[0].y)){cout<<"Right"<<endl;return;}
        }
    }
    if(CanUp(s[0].x,s[0].y)){cout<<"Up"<<endl;return;}
    if(CanDown(s[0].x,s[0].y)){cout<<"Down"<<endl;return ;}
    if(CanLeft(s[0].x,s[0].y)){cout<<"Left"<<endl;return ;}
    if(CanRight(s[0].x,s[0].y)){cout<<"Right"<<endl;return;}
    cout<<"Right"<<endl;
    return ;
}
