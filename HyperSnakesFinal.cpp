#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
struct Snake
{
    int HeadX;
    int HeadY;
    int Size;
    bool CanUp,CanDown,CanRight,CanLeft;
    int LeftX,LeftY;
    int DownX,DownY;
    int RightX,RightY;
    int UpX,UpY;
}Human,Enemy;

struct Point
{
    int X;
    int Y;
    bool IsNear;
    int DistDiff;
    //bool operator()(const Point& lhs, const Point& rhs) const { lhs.DistDiff >= rhs.DistDiff && lhs.IsNear; }
}Apples[30];

char table[25][25];
int CountApples;
string FinalMove;

bool OnePossibleMove()
{
    int Xup,Yup,Xdown,Ydown,Xright,Yright,Xleft,Yleft;
    Xup = Human.HeadX-1;
    Yup = Human.HeadY;
    Xdown = Human.HeadX+1;
    Ydown = Human.HeadY;
    Xright = Human.HeadX;
    Yright = Human.HeadY+1;
    Xleft = Human.HeadX;
    Yleft = Human.HeadY-1;

    Human.CanUp = table[Xup][Yup] == '.' || table[Xup][Yup] == '@';
    Human.CanDown = table[Xdown][Ydown] == '.' || table[Xdown][Ydown] == '@';
    Human.CanRight = table[Xright][Yright] == '.' || table[Xright][Yright] == '@';
    Human.CanLeft = table[Xleft][Yleft] == '.' || table[Xleft][Yleft] == '@';

    if(!Human.CanUp && !Human.CanDown && !Human.CanRight){FinalMove="Left";return true;}
    if(!Human.CanUp && !Human.CanDown && !Human.CanLeft){FinalMove="Right";return true;}
    if(!Human.CanUp && !Human.CanLeft && !Human.CanRight){FinalMove="Down";return true;}
    if(!Human.CanLeft && !Human.CanDown && !Human.CanRight){FinalMove="Up";return true;}


    Xup = Enemy.HeadX-1;
    Yup = Enemy.HeadY;
    Xdown = Enemy.HeadX+1;
    Ydown = Enemy.HeadY;
    Xright = Enemy.HeadX;
    Yright = Enemy.HeadY+1;
    Xleft = Enemy.HeadX;
    Yleft = Enemy.HeadY-1;

    Enemy.CanUp = table[Xup][Yup] == '.' || table[Xup][Yup] == '@';
    Enemy.CanDown = table[Xdown][Ydown] == '.' || table[Xdown][Ydown] == '@';
    Enemy.CanRight = table[Xright][Yright] == '.' || table[Xright][Yright] == '@';
    Enemy.CanLeft = table[Xleft][Yleft] == '.' || table[Xleft][Yleft] == '@';
    return false;
}

bool CanBlockHim()
{
    if(!Enemy.CanUp && !Enemy.CanDown && !Enemy.CanRight)
    {
        if(Human.LeftX==Enemy.LeftX && Human.LeftY==Enemy.LeftY){FinalMove="Left";return true;}
        if(Human.RightX==Enemy.LeftX && Human.RightY==Enemy.LeftY){FinalMove="Right";return true;}
        if(Human.DownX==Enemy.LeftX && Human.DownY==Enemy.LeftY){FinalMove="Down";return true;}
        if(Human.UpX==Enemy.LeftX && Human.UpY==Enemy.LeftY){FinalMove="Up";return true;}

    }

    if(!Enemy.CanUp && !Enemy.CanDown && !Enemy.CanLeft)
    {
        if(Human.LeftX==Enemy.RightX && Human.LeftY==Enemy.RightY){FinalMove="Left";return true;}
        if(Human.RightX==Enemy.RightX && Human.RightY==Enemy.RightY){FinalMove="Right";return true;}
        if(Human.DownX==Enemy.RightX && Human.DownY==Enemy.RightY){FinalMove="Down";return true;}
        if(Human.UpX==Enemy.RightX && Human.UpY==Enemy.RightY){FinalMove="Up";return true;}

    }
    if(!Enemy.CanUp && !Enemy.CanLeft && !Enemy.CanRight)
    {
        if(Human.LeftX==Enemy.DownX && Human.LeftY==Enemy.DownY){FinalMove="Left";return true;}
        if(Human.RightX==Enemy.DownX && Human.RightY==Enemy.DownY){FinalMove="Right";return true;}
        if(Human.DownX==Enemy.DownX && Human.DownY==Enemy.DownY){FinalMove="Down";return true;}
        if(Human.UpX==Enemy.DownX && Human.UpY==Enemy.DownY){FinalMove="Up";return true;}

    }
    if(!Enemy.CanLeft && !Enemy.CanDown && !Enemy.CanRight)
    {
        if(Human.LeftX==Enemy.UpX && Human.LeftY==Enemy.UpY){FinalMove="Left";return true;}
        if(Human.RightX==Enemy.UpX && Human.RightY==Enemy.UpY){FinalMove="Right";return true;}
        if(Human.DownX==Enemy.UpX && Human.DownY==Enemy.UpY){FinalMove="Down";return true;}
        if(Human.UpX==Enemy.UpX && Human.UpY==Enemy.UpY){FinalMove="Up";return true;}

    }
    return false;
}

bool CanStopHim()
{
    if(!Enemy.CanUp && !Enemy.CanDown && !Enemy.CanRight && abs(Human.HeadX-Enemy.HeadX)==1 && Human.HeadY==Enemy.HeadY)
    {
        if(Human.CanLeft){FinalMove="Left";return true;}
    }

    if(!Enemy.CanUp && !Enemy.CanDown && !Enemy.CanLeft && abs(Human.HeadX-Enemy.HeadX)==1 && Human.HeadY==Enemy.HeadY)
    {
        if(Human.CanRight){FinalMove="Right";return true;}
    }
    if(!Enemy.CanUp && !Enemy.CanLeft && !Enemy.CanRight && abs(Human.HeadY-Enemy.HeadY)==1 && Human.HeadX==Enemy.HeadX)
    {
        if(Human.CanDown){FinalMove="Down";return true;}

    }
    if(!Enemy.CanLeft && !Enemy.CanDown && !Enemy.CanRight && abs(Human.HeadY-Enemy.HeadY)==1 && Human.HeadX==Enemy.HeadX)
    {
        if(Human.CanUp){FinalMove="Up";return true;}

    }
    return false;
}

bool GoForApples()
{
    for(int i=0;i<CountApples;i++)
    {
        int DistToHuman,DistToEnemy;

        DistToEnemy=abs(Apples[i].X-Enemy.HeadX)+abs(Apples[i].Y-Enemy.HeadY);
        DistToHuman=abs(Apples[i].X-Human.HeadX)+abs(Apples[i].Y-Human.HeadY);
        Apples[i].DistDiff=abs(DistToEnemy-DistToHuman);
        if(DistToEnemy>=DistToHuman)Apples[i].IsNear=true;
        else Apples[i].IsNear=false;

    }
    for(int i=CountApples;i>0;i--)
        for(int j=0;j<i-1;j++)
            {
                if(Apples[j].DistDiff<=Apples[j+1].DistDiff)swap(Apples[j],Apples[j+1]);
                //if((abs(Apples[i].X-Human.HeadX)+abs(Apples[i].Y-Human.HeadY))<=(abs(Apples[j].X-Human.HeadX)+abs(Apples[j].Y-Human.HeadY)))swap(Apples[i],Apples[j]);
                if(Apples[j].IsNear==0 && Apples[j+1].IsNear==1)swap(Apples[j],Apples[j+1]);
            }
    //sort(Apples, Apples+CountApples, Apples[0]);
    //for(int i=0;i<CountApples;i++)
    //cout<<Apples[i].DistDiff<<" "<<Apples[i].X<<" "<<Apples[i].Y<<" "<<Apples[i].IsNear<<endl;

    int ApplesForWin,HuntedApple=CountApples-1;
    ApplesForWin=13-Human.Size;
    if(ApplesForWin>=CountApples)ApplesForWin=CountApples-1;
    for(int i=0;i<ApplesForWin;i++)
    {
        if(Apples[i].IsNear){HuntedApple=i;}

    }

    bool PossUp=0,PossDown=0,PossRight=0,PossLeft=0;
    if(Apples[HuntedApple].X>Human.HeadX)PossDown=true;
    if(Apples[HuntedApple].X<Human.HeadX)PossUp=true;
    if(Apples[HuntedApple].X==Human.HeadX){PossDown=true;PossUp=true;}
    if(Apples[HuntedApple].Y>Human.HeadX)PossRight=true;
    if(Apples[HuntedApple].Y<Human.HeadX)PossLeft=true;
    if(Apples[HuntedApple].Y==Human.HeadX){PossRight=true;PossLeft=true;}

    if(PossUp && table[Human.UpX][Human.UpY]=='@'){FinalMove="Up";return true;}
    if(PossDown && table[Human.DownX][Human.DownY]=='@'){FinalMove="Down";return true;}
    if(PossRight && table[Human.RightX][Human.RightY]=='@'){FinalMove="Right";return true;}
    if(PossLeft && table[Human.LeftX][Human.LeftY]=='@'){FinalMove="Left";return true;}

    if(PossUp && abs(Apples[HuntedApple].X-Human.HeadX)>=abs(Apples[HuntedApple].Y-Human.HeadY) && Human.CanUp){FinalMove="Up";return true;}
    if(PossDown && abs(Apples[HuntedApple].X-Human.HeadX)>=abs(Apples[HuntedApple].Y-Human.HeadY) && Human.CanDown){FinalMove="Down";return true;}
    if(PossRight && abs(Apples[HuntedApple].Y-Human.HeadY)>=abs(Apples[HuntedApple].X-Human.HeadX) && Human.CanRight){FinalMove="Right";return true;}
    if(PossLeft && abs(Apples[HuntedApple].Y-Human.HeadY)>=abs(Apples[HuntedApple].X-Human.HeadX) && Human.CanLeft){FinalMove="Left";return true;}

    int Ax=Apples[HuntedApple].X,AN=Human.HeadX,aN=Enemy.HeadX,Ay=Apples[HuntedApple].Y,AM=Human.HeadY,aM=Enemy.HeadY;
    bool Down=Human.CanDown,Up=Human.CanUp,Right=Human.CanRight,Left=Human.CanLeft;

    bool Aup=false,Aright=false,Adown=false,Aleft=false;
    if(Ax<=AN)Aup=true;
    if(Ax>=AN)Adown=true;
    if(Ay<=AM)Aleft=true;
    if(Ay>=AM)Aright=true;
    if(abs(AN-Ax)>abs(aN-Ax) && abs(AM-Ay)<abs(aM-Ay) && AN<Ax && Down==true){FinalMove="Down";return true;}
    if(abs(AN-Ax)>abs(aN-Ax) && abs(AM-Ay)<abs(aM-Ay) && AN>Ax && Up==true){FinalMove="Up";return true;}
    if(abs(AM-Ay)>abs(aM-Ay) && abs(AN-Ax)<abs(aN-Ax) && AM>Ay && Left==true){FinalMove="Left";return true;}
    if(abs(AM-Ay)>abs(aM-Ay) && abs(AN-Ax)<abs(aN-Ax) && AM<Ay && Right==true){FinalMove="Right";return true;}
  // cout<<7;
    if(abs(AN-Ax)>=abs(AM-Ay) && Ax<=AN && Up==1){FinalMove="Up";return true;}
    if(abs(AN-Ax)>=abs(AM-Ay) && Ax>=AN && Down==1){FinalMove="Down";return true;}
    if(abs(AN-Ax)<=abs(AM-Ay) && Ay<=AM && Left==1){FinalMove="Left";return true;}
    if(abs(AN-Ax)<=abs(AM-Ay) && Ay>=AM && Right==1){FinalMove="Right";return true;}
    //cout<<8;
    if(Aup && Up){FinalMove="Up";return true;}
    if(Adown && Down){FinalMove="Down";return true;}
    if(Aleft && Left){FinalMove="Left";return true;}
    if(Aright && Right){FinalMove="Right";return true;}
    return false;
}
string MyMove()
{
    if(OnePossibleMove())return FinalMove;
    if(CanBlockHim())return FinalMove;
    if(CanStopHim())return FinalMove;
    if(GoForApples())return FinalMove;
    if(Human.CanUp)return "Up";
    if(Human.CanDown)return "Down";
    if(Human.CanRight)return "Right";
    if(Human.CanLeft)return "Left";
}
int main()
{
    Human.Size=0;
    Enemy.Size=0;
    for(int i=1;i<=20;i++)
        for(int j=1;j<=20;j++)
        {
            cin>>table[i][j];
            if(table[i][j]=='A')
            {
                Human.HeadX=i;Human.HeadY=j;
                Human.LeftX=i;Human.LeftY=j-1;
                Human.DownX=i+1;Human.DownY=j;
                Human.RightX=i;Human.RightY=j+1;
                Human.UpX=i-1;Human.UpY=j;
            }
            if(table[i][j]=='a')
            {
                Enemy.HeadX=i;Enemy.HeadY=j;
                Enemy.LeftX=i;Enemy.LeftY=j-1;
                Enemy.DownX=i+1;Enemy.DownY=j;
                Enemy.RightX=i;Enemy.RightY=j+1;
                Enemy.UpX=i-1;Enemy.UpY=j;
            }
            if(table[i][j]>'A' && table[i][j]<='Z')Human.Size++;
            if(table[i][j]>'a' && table[i][j]<='z')Enemy.Size++;
            if(table[i][j]=='@'){Apples[CountApples].X=i;Apples[CountApples].Y=j;CountApples++;}
        }


    cout<<MyMove()<<endl;
    return 0;
}
