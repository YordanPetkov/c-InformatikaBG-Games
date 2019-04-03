 #include<iostream>
#include<algorithm>
using namespace std;
char Table[21][21];
char LastMe='A',LastHe='a';
int AppleONSameRow;
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
bool CanEscape();
bool BlockEnemy();
void GoToApple();
int main()
{
    Input();
    SortApples();

    if(OnlyOneMove())return 0;
    if(CanEscape())return 0;
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
                if(LastHe<Table[i][j])LastHe=Table[i][j];
            }
            if(Table[i][j]>='A' && Table[i][j]<='Z')
            {
                if(Table[i][j]=='A')
                {
                    s[0].x=i;
                    s[0].y=j;
                }
                s[0].Size++;
                if(LastMe<Table[i][j])LastMe=Table[i][j];
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
    int NeedAppleX=a[BrApples/2].x,NeedAppleY=a[BrApples/2].y;
    for(int i=BrApples;i>0;i--)
    for(int j=0;j<i-1;j++)
    {
        //if(a[j].x==a[j+1].x && a[j].ya[j+1].dYou )swap(a[j],a[j+1]);
        //if(a[j].x==s[0].x)AppleONSameRow=j;
        //if(a[j].dEnemy)
        if(a[j].dYou>a[j+1].dYou)swap(a[j],a[j+1]);

    }

    //for(int i=0;i<BrApples;i++)
    //cout<<a[i].x<<" "<<a[i].y<<endl;

}
bool CanHere(int i,int j)
{
    if(Table[i][j]=='.' || Table[i][j]=='@')return true;
    return false;
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
bool CanEscape()
{
    int PosMoves=4;


    for(int k=1;k<19;k++)
    {
       char BefA='A'-k-1,Befa='a'-k-1;
        if(
       s[0].x>k+1 && s[0].y>1 && s[0].x<=20 && s[0].y<20 &&
       !CanHere((s[0].x)-k-1,s[0].y) && Table[(s[0].x)-k-1][s[0].y]!=LastMe-BefA+'A' && Table[(s[0].x)-k-1][s[0].y]!=LastHe-Befa+'a' &&
        !CanHere(s[0].x-k,s[0].y-1) && Table[s[0].x-k][s[0].y-1]!=LastMe-BefA+'A' && Table[s[0].x-k][s[0].y-1]!=LastHe-Befa+'a' &&
       !CanHere(s[0].x-k,s[0].y+1) && Table[s[0].x-k][s[0].y+1]!=LastMe-BefA+'A' && Table[s[0].x-k][s[0].y+1]!=LastHe-Befa+'a' &&
       CanUp(s[0].x-k+1,s[0].y)
       ){Table[s[0].x-1][s[0].y]='$';PosMoves--;}

    if(
       s[0].x>0 && s[0].y>1 && s[0].x<=20-k-1 && s[0].y<20 &&
       !CanHere(s[0].x+k+1,s[0].y) && Table[s[0].x+k+1][s[0].y]!=LastMe-BefA+'A' && Table[s[0].x+k+1][s[0].y]!=LastHe-Befa+'a' &&
       !CanHere(s[0].x+k,s[0].y-1) && Table[s[0].x+k][s[0].y-1]!=LastMe-BefA+'A' && Table[s[0].x+k][s[0].y-1]!=LastHe-Befa+'a' &&
       !CanHere(s[0].x+k,s[0].y+1) && Table[s[0].x+k][s[0].y+1]!=LastMe-BefA+'A' && Table[s[0].x+k][s[0].y+1]!=LastHe-Befa+'a' &&
       CanDown(s[0].x+k-1,s[0].y)
       ){Table[s[0].x+1][s[0].y]='$';PosMoves--;}

    if(
       s[0].x>1 && s[0].y>2 && s[0].x<20 && s[0].y<=20 &&
       !CanHere(s[0].x,s[0].y-k-1) && Table[s[0].x][s[0].y-k-1]!=LastMe-BefA+'A' && Table[s[0].x][s[0].y-k-1]!=LastHe-Befa+'a' &&
       !CanHere(s[0].x-1,s[0].y-k) && Table[s[0].x-1][s[0].y-k]!=LastMe-BefA+'A' && Table[s[0].x-1][s[0].y-k]!=LastHe-Befa+'a' &&
       !CanHere(s[0].x+1,s[0].y-k) && Table[s[0].x+1][s[0].y-k]!=LastMe-BefA+'A' && Table[s[0].x+1][s[0].y-k]!=LastHe-Befa+'a' &&
       CanLeft(s[0].x,s[0].y-k+1)
       ){Table[s[0].x][s[0].y-1]='$';PosMoves--;}


    if(
       s[0].x>1 && s[0].y>0 && s[0].x<20 && s[0].y<=18 &&
       !CanHere(s[0].x,s[0].y+k+1) && Table[s[0].x][s[0].y+k+1]!=LastMe-BefA+'A' && Table[s[0].x][s[0].y+k+1]!=LastHe-Befa+'a' &&
       !CanHere(s[0].x-1,s[0].y+k) && Table[s[0].x-1][s[0].y+k]!=LastMe-BefA+'A' && Table[s[0].x-1][s[0].y+k]!=LastHe-Befa+'a' &&
       !CanHere(s[0].x+1,s[0].y+k) && Table[s[0].x+1][s[0].y+k]!=LastMe-BefA+'A' && Table[s[0].x+1][s[0].y+k]!=LastHe-Befa+'a' &&
       CanRight(s[0].x,s[0].y+k-1)
       ){Table[s[0].x][s[0].y+1]='$';PosMoves--;}
    }
    if(PosMoves==1)
    {
        if(CanUp(s[0].x,s[0].y)){cout<<"Up"<<endl;return true;}
        if(CanDown(s[0].x,s[0].y)){cout<<"Down"<<endl;return true;}
        if(CanLeft(s[0].x,s[0].y)){cout<<"Left"<<endl;return true;}
        if(CanRight(s[0].x,s[0].y)){cout<<"Right"<<endl;return true;}

    }
    return false;

}
bool BlockEnemy()
{
    if(!CanUp(s[1].x,s[1].y) && !CanDown(s[1].x,s[1].y) && !CanRight(s[1].x,s[1].y) && abs(s[0].x-s[1].x)==1 && s[0].y==s[1].y)
    {
        if(CanLeft(s[0].x,s[0].y)){cout<<"Left"<<endl;return true;}
    }

    if(!CanUp(s[1].x,s[1].y) && !CanDown(s[1].x,s[1].y) && !CanLeft(s[1].x,s[1].y) && abs(s[0].x-s[1].x)==1 && s[0].y==s[1].y)
    {
        if(CanRight(s[0].x,s[0].y)){cout<<"Right"<<endl;return true;}
    }
    if(!CanUp(s[1].x,s[1].y) && !CanLeft(s[1].x,s[1].y) && !CanRight(s[1].x,s[1].y) && abs(s[0].y-s[1].y)==1 && s[0].x==s[1].x)
    {
        if(CanDown(s[0].x,s[0].y)){cout<<"Down"<<endl;return true;}
    }
    if(!CanLeft(s[1].x,s[1].y) && !CanDown(s[1].x,s[1].y) && !CanRight(s[1].x,s[1].y) && abs(s[0].y-s[1].y)==1 && s[0].x==s[1].x)
    {
        if(CanUp(s[0].x,s[0].y)){cout<<"Up"<<endl;return true;}
    }



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

    if(!CanUp(s[1].x,s[1].y) && !CanDown(s[1].x,s[1].y) && !CanRight(s[1].x,s[1].y))
    {
        if(s[0].x==s[1].x && s[0].y-1==s[1].y-1){cout<<"Left"<<endl;return true;}
        if(s[0].x==s[1].x && s[0].y+1==s[1].y-1){cout<<"Right"<<endl;return true;}
        if(s[0].x+1==s[1].x && s[0].y==s[1].y-1){cout<<"Down"<<endl;return true;}
        if(s[0].x-1==s[1].x && s[0].y==s[1].y-1){cout<<"Up"<<endl;return true;}

    }

    if(!CanUp(s[1].x,s[1].y) && !CanDown(s[1].x,s[1].y) && !CanLeft(s[1].x,s[1].y))
    {
        if(s[0].x==s[1].x && s[0].y-1==s[1].y+1){cout<<"Left"<<endl;return true;}
        if(s[0].x==s[1].x && s[0].y+1==s[1].y+1){cout<<"Right"<<endl;return true;}
        if(s[0].x+1==s[1].x && s[0].y==s[1].y+1){cout<<"Down"<<endl;return true;}
        if(s[0].x-1==s[1].x && s[0].y==s[1].y+1){cout<<"Up"<<endl;return true;}

    }    if(!CanUp(s[1].x,s[1].y) && !CanLeft(s[1].x,s[1].y) && !CanRight(s[1].x,s[1].y))
    {
        if(s[0].x==s[1].x+1 && s[0].y-1==s[1].y){cout<<"Left"<<endl;return true;}
        if(s[0].x==s[1].x+1 && s[0].y+1==s[1].y){cout<<"Right"<<endl;return true;}
        if(s[0].x+1==s[1].x+1 && s[0].y==s[1].y){cout<<"Down"<<endl;return true;}
        if(s[0].x-1==s[1].x+1 && s[0].y==s[1].y){cout<<"Up"<<endl;return true;}

    }
        if(!CanLeft(s[1].x,s[1].y) && !CanDown(s[1].x,s[1].y) && !CanRight(s[1].x,s[1].y))
    {
        if(s[0].x==s[1].x-1 && s[0].y-1==s[1].y){cout<<"Left"<<endl;return true;}
        if(s[0].x==s[1].x-1 && s[0].y+1==s[1].y){cout<<"Right"<<endl;return true;}
        if(s[0].x+1==s[1].x-1 && s[0].y==s[1].y){cout<<"Down"<<endl;return true;}
        if(s[0].x-1==s[1].x-1 && s[0].y==s[1].y){cout<<"Up"<<endl;return true;}

    }
    return false;

}
void GoToApple()
{
    if(s[1].Size<14)
    {
        /*if(s[0].x>s[1].x)
        {
            for(int i=BrApples-1;i>=0;i--)
            {
                if(BrApples-1<i)break;
                if(a[i].dYou<=a[i].dEnemy)
                {
                bool ApOnUp=false,ApOnDown=false,ApOnRight=false,ApOnLeft=false;
                for(int j=0;j<BrApples;j++)
                {
                    if(a[j].x>a[i].x && a[j].x<s[0].x && ((a[j].y<=a[i].y && a[j].y>=s[0].y)||(a[j].y>=a[i].y && a[j].y<=s[0].y)))ApOnUp=true;
                    if(a[j].x<a[i].x && a[j].x>s[0].x && ((a[j].y<=a[i].y && a[j].y>=s[0].y)||(a[j].y>=a[i].y && a[j].y<=s[0].y)))ApOnDown=true;
                    if(a[j].y>a[i].y && a[j].y<s[0].y && ((a[j].x<=a[i].x && a[j].x>=s[0].x)||(a[j].x>=a[i].x && a[j].x<=s[0].x)))ApOnLeft=true;
                    if(a[j].y<a[i].y && a[j].y>s[0].y && ((a[j].x<=a[i].x && a[j].x>=s[0].x)||(a[j].x>=a[i].x && a[j].x<=s[0].x)))ApOnRight=true;
                }
                if(a[i].x<=s[0].x && abs(a[i].x-s[0].x)>=abs(a[i].y-s[0].y) && CanUp(s[0].x,s[0].y) && ApOnUp){cout<<"Up"<<endl;return;}
                if(a[i].x>=s[0].x && abs(a[i].x-s[0].x)>=abs(a[i].y-s[0].y) && CanDown(s[0].x,s[0].y) && ApOnDown){cout<<"Down"<<endl;return;}
                if(a[i].y<=s[0].y && abs(a[i].x-s[0].x)<=abs(a[i].y-s[0].y) && CanLeft(s[0].x,s[0].y) && ApOnLeft){cout<<"Left"<<endl;return;}
                if(a[i].y>=s[0].y && abs(a[i].x-s[0].x)<=abs(a[i].y-s[0].y) && CanRight(s[0].x,s[0].y) && ApOnRight){cout<<"Right"<<endl;return;}



                if(a[i].x<=s[0].x && abs(a[i].x-s[0].x)>=abs(a[i].y-s[0].y) && CanUp(s[0].x,s[0].y)){cout<<"Up"<<endl;return;}
                if(a[i].x>=s[0].x && abs(a[i].x-s[0].x)>=abs(a[i].y-s[0].y) && CanDown(s[0].x,s[0].y)){cout<<"Down"<<endl;return;}
                if(a[i].y<=s[0].y && abs(a[i].x-s[0].x)<=abs(a[i].y-s[0].y) && CanLeft(s[0].x,s[0].y)){cout<<"Left"<<endl;return;}
                if(a[i].y>=s[0].y && abs(a[i].x-s[0].x)<=abs(a[i].y-s[0].y) && CanRight(s[0].x,s[0].y)){cout<<"Right"<<endl;return;}

                    if(a[i].x<=s[0].x && CanUp(s[0].x,s[0].y)){cout<<"Up"<<endl;return;}
                    if(a[i].x>=s[0].x && CanDown(s[0].x,s[0].y)){cout<<"Down"<<endl;return;}
                    if(a[i].y<=s[0].y && CanLeft(s[0].x,s[0].y)){cout<<"Left"<<endl;return;}
                    if(a[i].y>=s[0].y && CanRight(s[0].x,s[0].y)){cout<<"Right"<<endl;return;}
                }
            }
        }
        if(s[0].x<=s[1].x)
        {
            for(int i=AppleONSameRow;i>=0;i--)
            {
                if(BrApples-1<i)break;
                if(a[i].dYou<=a[i].dEnemy)
                {
                bool ApOnUp=false,ApOnDown=false,ApOnRight=false,ApOnLeft=false;
                for(int j=0;j<BrApples;j++)
                {
                    if(a[j].x>a[i].x && a[j].x<s[0].x && ((a[j].y<=a[i].y && a[j].y>=s[0].y)||(a[j].y>=a[i].y && a[j].y<=s[0].y)))ApOnUp=true;
                    if(a[j].x<a[i].x && a[j].x>s[0].x && ((a[j].y<=a[i].y && a[j].y>=s[0].y)||(a[j].y>=a[i].y && a[j].y<=s[0].y)))ApOnDown=true;
                    if(a[j].y>a[i].y && a[j].y<s[0].y && ((a[j].x<=a[i].x && a[j].x>=s[0].x)||(a[j].x>=a[i].x && a[j].x<=s[0].x)))ApOnLeft=true;
                    if(a[j].y<a[i].y && a[j].y>s[0].y && ((a[j].x<=a[i].x && a[j].x>=s[0].x)||(a[j].x>=a[i].x && a[j].x<=s[0].x)))ApOnRight=true;
                }
                if(a[i].x<=s[0].x && abs(a[i].x-s[0].x)>=abs(a[i].y-s[0].y) && CanUp(s[0].x,s[0].y) && ApOnUp){cout<<"Up"<<endl;return;}
                if(a[i].x>=s[0].x && abs(a[i].x-s[0].x)>=abs(a[i].y-s[0].y) && CanDown(s[0].x,s[0].y) && ApOnDown){cout<<"Down"<<endl;return;}
                if(a[i].y<=s[0].y && abs(a[i].x-s[0].x)<=abs(a[i].y-s[0].y) && CanLeft(s[0].x,s[0].y) && ApOnLeft){cout<<"Left"<<endl;return;}
                if(a[i].y>=s[0].y && abs(a[i].x-s[0].x)<=abs(a[i].y-s[0].y) && CanRight(s[0].x,s[0].y) && ApOnRight){cout<<"Right"<<endl;return;}



                if(a[i].x<=s[0].x && abs(a[i].x-s[0].x)>=abs(a[i].y-s[0].y) && CanUp(s[0].x,s[0].y)){cout<<"Up"<<endl;return;}
                if(a[i].x>=s[0].x && abs(a[i].x-s[0].x)>=abs(a[i].y-s[0].y) && CanDown(s[0].x,s[0].y)){cout<<"Down"<<endl;return;}
                if(a[i].y<=s[0].y && abs(a[i].x-s[0].x)<=abs(a[i].y-s[0].y) && CanLeft(s[0].x,s[0].y)){cout<<"Left"<<endl;return;}
                if(a[i].y>=s[0].y && abs(a[i].x-s[0].x)<=abs(a[i].y-s[0].y) && CanRight(s[0].x,s[0].y)){cout<<"Right"<<endl;return;}

                    if(a[i].x<=s[0].x && CanUp(s[0].x,s[0].y)){cout<<"Up"<<endl;return;}
                    if(a[i].x>=s[0].x && CanDown(s[0].x,s[0].y)){cout<<"Down"<<endl;return;}
                    if(a[i].y<=s[0].y && CanLeft(s[0].x,s[0].y)){cout<<"Left"<<endl;return;}
                    if(a[i].y>=s[0].y && CanRight(s[0].x,s[0].y)){cout<<"Right"<<endl;return;}
                }
            }
        }*/
        for(int i=0;i<BrApples;i++)
        {
            if(a[i].dYou<=a[i].dEnemy)
            {
                bool ApOnUp=false,ApOnDown=false,ApOnRight=false,ApOnLeft=false;
                for(int j=0;j<BrApples;j++)
                {
                    if(a[j].x>a[i].x && a[j].x<s[0].x && ((a[j].y<=a[i].y && a[j].y>=s[0].y)||(a[j].y>=a[i].y && a[j].y<=s[0].y)))ApOnUp=true;
                    if(a[j].x<a[i].x && a[j].x>s[0].x && ((a[j].y<=a[i].y && a[j].y>=s[0].y)||(a[j].y>=a[i].y && a[j].y<=s[0].y)))ApOnDown=true;
                    if(a[j].y>a[i].y && a[j].y<s[0].y && ((a[j].x<=a[i].x && a[j].x>=s[0].x)||(a[j].x>=a[i].x && a[j].x<=s[0].x)))ApOnLeft=true;
                    if(a[j].y<a[i].y && a[j].y>s[0].y && ((a[j].x<=a[i].x && a[j].x>=s[0].x)||(a[j].x>=a[i].x && a[j].x<=s[0].x)))ApOnRight=true;
                }
                if(a[i].x<=s[0].x && abs(a[i].x-s[0].x)>=abs(a[i].y-s[0].y) && CanUp(s[0].x,s[0].y) && ApOnUp){cout<<"Up"<<endl;return;}
                if(a[i].x>=s[0].x && abs(a[i].x-s[0].x)>=abs(a[i].y-s[0].y) && CanDown(s[0].x,s[0].y) && ApOnDown){cout<<"Down"<<endl;return;}
                if(a[i].y<=s[0].y && abs(a[i].x-s[0].x)<=abs(a[i].y-s[0].y) && CanLeft(s[0].x,s[0].y) && ApOnLeft){cout<<"Left"<<endl;return;}
                if(a[i].y>=s[0].y && abs(a[i].x-s[0].x)<=abs(a[i].y-s[0].y) && CanRight(s[0].x,s[0].y) && ApOnRight){cout<<"Right"<<endl;return;}


                if(a[i].x<=s[0].x && abs(a[i].x-s[0].x)>=abs(a[i].y-s[0].y) && CanUp(s[0].x,s[0].y)){cout<<"Up"<<endl;return;}
                if(a[i].x>=s[0].x && abs(a[i].x-s[0].x)>=abs(a[i].y-s[0].y) && CanDown(s[0].x,s[0].y)){cout<<"Down"<<endl;return;}
                if(a[i].y<=s[0].y && abs(a[i].x-s[0].x)<=abs(a[i].y-s[0].y) && CanLeft(s[0].x,s[0].y)){cout<<"Left"<<endl;return;}
                if(a[i].y>=s[0].y && abs(a[i].x-s[0].x)<=abs(a[i].y-s[0].y) && CanRight(s[0].x,s[0].y)){cout<<"Right"<<endl;return;}

                if(a[i].x<=s[0].x && CanUp(s[0].x,s[0].y)){cout<<"Up"<<endl;return;}
                if(a[i].x>=s[0].x && CanDown(s[0].x,s[0].y)){cout<<"Down"<<endl;return;}
                if(a[i].y<=s[0].y && CanLeft(s[0].x,s[0].y)){cout<<"Left"<<endl;return;}
                if(a[i].y>=s[0].y && CanRight(s[0].x,s[0].y)){cout<<"Right"<<endl;return;}
            }
        }

        for(int i=0;i<BrApples;i++)
        {
                bool ApOnUp=false,ApOnDown=false,ApOnRight=false,ApOnLeft=false;
                for(int j=0;j<BrApples;j++)
                {
                    if(a[j].x>a[i].x && a[j].x<s[0].x && ((a[j].y<=a[i].y && a[j].y>=s[0].y)||(a[j].y>=a[i].y && a[j].y<=s[0].y)))ApOnUp=true;
                    if(a[j].x<a[i].x && a[j].x>s[0].x && ((a[j].y<=a[i].y && a[j].y>=s[0].y)||(a[j].y>=a[i].y && a[j].y<=s[0].y)))ApOnDown=true;
                    if(a[j].y>a[i].y && a[j].y<s[0].y && ((a[j].x<=a[i].x && a[j].x>=s[0].x)||(a[j].x>=a[i].x && a[j].x<=s[0].x)))ApOnLeft=true;
                    if(a[j].y<a[i].y && a[j].y>s[0].y && ((a[j].x<=a[i].x && a[j].x>=s[0].x)||(a[j].x>=a[i].x && a[j].x<=s[0].x)))ApOnRight=true;
                }
                if(a[i].x<=s[0].x && abs(a[i].x-s[0].x)>=abs(a[i].y-s[0].y) && CanUp(s[0].x,s[0].y) && ApOnUp){cout<<"Up"<<endl;return;}
                if(a[i].x>=s[0].x && abs(a[i].x-s[0].x)>=abs(a[i].y-s[0].y) && CanDown(s[0].x,s[0].y) && ApOnDown){cout<<"Down"<<endl;return;}
                if(a[i].y<=s[0].y && abs(a[i].x-s[0].x)<=abs(a[i].y-s[0].y) && CanLeft(s[0].x,s[0].y) && ApOnLeft){cout<<"Left"<<endl;return;}
                if(a[i].y>=s[0].y && abs(a[i].x-s[0].x)<=abs(a[i].y-s[0].y) && CanRight(s[0].x,s[0].y) && ApOnRight){cout<<"Right"<<endl;return;}


                if(a[i].x<=s[0].x && abs(a[i].x-s[0].x)>=abs(a[i].y-s[0].y) && CanUp(s[0].x,s[0].y)){cout<<"Up"<<endl;return;}
                if(a[i].x>=s[0].x && abs(a[i].x-s[0].x)>=abs(a[i].y-s[0].y) && CanDown(s[0].x,s[0].y)){cout<<"Down"<<endl;return;}
                if(a[i].y<=s[0].y && abs(a[i].x-s[0].x)<=abs(a[i].y-s[0].y) && CanLeft(s[0].x,s[0].y)){cout<<"Left"<<endl;return;}
                if(a[i].y>=s[0].y && abs(a[i].x-s[0].x)<=abs(a[i].y-s[0].y) && CanRight(s[0].x,s[0].y)){cout<<"Right"<<endl;return;}

                if(a[i].x<=s[0].x && CanUp(s[0].x,s[0].y)){cout<<"Up"<<endl;return;}
                if(a[i].x>=s[0].x && CanDown(s[0].x,s[0].y)){cout<<"Down"<<endl;return;}
                if(a[i].y<=s[0].y && CanLeft(s[0].x,s[0].y)){cout<<"Left"<<endl;return;}
                if(a[i].y>=s[0].y && CanRight(s[0].x,s[0].y)){cout<<"Right"<<endl;return;}

        }
    }
    else
    {

        if(s[1].x<=s[0].x && abs(s[1].x-s[0].x)>=abs(s[1].y-s[0].y) && CanUp(s[0].x,s[0].y)){cout<<"Up"<<endl;return;}
        if(s[1].x>=s[0].x && abs(s[1].x-s[0].x)>=abs(s[1].y-s[0].y) && CanDown(s[0].x,s[0].y)){cout<<"Down"<<endl;return;}
        if(s[1].y<=s[0].y && abs(s[1].x-s[0].x)<=abs(s[1].y-s[0].y) && CanLeft(s[0].x,s[0].y)){cout<<"Left"<<endl;return;}
        if(s[1].y>=s[0].y && abs(s[1].x-s[0].x)<=abs(s[1].y-s[0].y) && CanRight(s[0].x,s[0].y)){cout<<"Right"<<endl;return;}

        if(s[1].x<=s[0].x && CanUp(s[0].x,s[0].y)){cout<<"Up"<<endl;return;}
        if(s[1].x>=s[0].x && CanDown(s[0].x,s[0].y)){cout<<"Down"<<endl;return;}
        if(s[1].y<=s[0].y && CanLeft(s[0].x,s[0].y)){cout<<"Left"<<endl;return;}
        if(s[1].y>=s[0].y && CanRight(s[0].x,s[0].y)){cout<<"Right"<<endl;return;}
    }
    if(CanUp(s[0].x,s[0].y)){cout<<"Up"<<endl;return;}
    if(CanDown(s[0].x,s[0].y)){cout<<"Down"<<endl;return ;}
    if(CanLeft(s[0].x,s[0].y)){cout<<"Left"<<endl;return ;}
    if(CanRight(s[0].x,s[0].y)){cout<<"Right"<<endl;return;}
    cout<<"Right"<<endl;
    return ;
}
