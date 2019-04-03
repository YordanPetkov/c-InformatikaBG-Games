#include<iostream>
#include<utility>
using namespace std;
char Table[9][3][3];
bool BigTTT[3][3],NewGame=true;
char BigTTTG[3][3];
bool PosMoves[9],HeCanWin[9];
int R,C,Array[9]={4,0,2,6,8,1,3,5,7};

///basic methods
//bool isSmallWinner();
bool isBigWinner();
bool isSmallWinnerMe2();
bool makeBigTTT();
bool isMiddle();
///tacticks
//void Tactic1_random();

void Tactic1_random()
{
    if(R!=-1 && C!=-1)
    {
        int First=R*3+C;
        for(int i=0;i<=2;i++)
        for(int j=0;j<=2;j++)
            if(Table[First][i][j]=='.'){cout<<R<<" "<<C<<" "<<i<<" "<<j<<endl;return ;}
    }
        for( int First=0;First<=8;First++)
        for(int i=0;i<=2;i++)
        for(int j=0;j<=2;j++)
            if(Table[First][i][j]=='.'){cout<<First/3<<" "<<First%3<<" "<<i<<" "<<j<<endl;return ;}
}

bool isSmallWinnerMe()
{
    if(R!=-1 && C!=-1)
    {
        int First=R*3+C;
        if(Table[First][0][0]=='X' && Table[First][0][1]=='X' && Table[First][0][2]=='.' && PosMoves[2]){cout<<R<<" "<<C<<" "<<0<<" "<<2<<endl;return true;}
        if(Table[First][0][0]=='X' && Table[First][0][1]=='.' && Table[First][0][2]=='X' && PosMoves[1]){cout<<R<<" "<<C<<" "<<0<<" "<<1<<endl;return true;}
        if(Table[First][0][0]=='.' && Table[First][0][1]=='X' && Table[First][0][2]=='X' && PosMoves[0]){cout<<R<<" "<<C<<" "<<0<<" "<<0<<endl;return true;}

        if(Table[First][1][0]=='X' && Table[First][1][1]=='X' && Table[First][1][2]=='.' && PosMoves[5]){cout<<R<<" "<<C<<" "<<1<<" "<<2<<endl;return true;}
        if(Table[First][1][0]=='X' && Table[First][1][1]=='.' && Table[First][1][2]=='X' && PosMoves[4]){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][1][0]=='.' && Table[First][1][1]=='X' && Table[First][1][2]=='X' && PosMoves[3]){cout<<R<<" "<<C<<" "<<1<<" "<<0<<endl;return true;}

        if(Table[First][2][0]=='X' && Table[First][2][1]=='X' && Table[First][2][2]=='.' && PosMoves[8]){cout<<R<<" "<<C<<" "<<2<<" "<<2<<endl;return true;}
        if(Table[First][2][0]=='X' && Table[First][2][1]=='.' && Table[First][2][2]=='X' && PosMoves[7]){cout<<R<<" "<<C<<" "<<2<<" "<<1<<endl;return true;}
        if(Table[First][2][0]=='.' && Table[First][2][1]=='X' && Table[First][2][2]=='X' && PosMoves[6]){cout<<R<<" "<<C<<" "<<2<<" "<<0<<endl;return true;}

        if(Table[First][0][0]=='X' && Table[First][1][0]=='X' && Table[First][2][0]=='.' && PosMoves[6]){cout<<R<<" "<<C<<" "<<2<<" "<<0<<endl;return true;}
        if(Table[First][0][0]=='X' && Table[First][1][0]=='.' && Table[First][2][0]=='X' && PosMoves[3]){cout<<R<<" "<<C<<" "<<1<<" "<<0<<endl;return true;}
        if(Table[First][0][0]=='.' && Table[First][1][0]=='X' && Table[First][2][0]=='X' && PosMoves[0]){cout<<R<<" "<<C<<" "<<0<<" "<<0<<endl;return true;}

        if(Table[First][0][1]=='X' && Table[First][1][1]=='X' && Table[First][2][1]=='.' && PosMoves[7]){cout<<R<<" "<<C<<" "<<2<<" "<<1<<endl;return true;}
        if(Table[First][0][1]=='X' && Table[First][1][1]=='.' && Table[First][2][1]=='X' && PosMoves[4]){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][0][1]=='.' && Table[First][1][1]=='X' && Table[First][2][1]=='X' && PosMoves[1]){cout<<R<<" "<<C<<" "<<0<<" "<<1<<endl;return true;}

        if(Table[First][0][2]=='X' && Table[First][1][2]=='X' && Table[First][2][2]=='.' && PosMoves[8]){cout<<R<<" "<<C<<" "<<2<<" "<<2<<endl;return true;}
        if(Table[First][0][2]=='X' && Table[First][1][2]=='.' && Table[First][2][2]=='X' && PosMoves[5]){cout<<R<<" "<<C<<" "<<1<<" "<<2<<endl;return true;}
        if(Table[First][0][2]=='.' && Table[First][1][2]=='X' && Table[First][2][2]=='X' && PosMoves[2]){cout<<R<<" "<<C<<" "<<0<<" "<<2<<endl;return true;}

        if(Table[First][0][0]=='X' && Table[First][1][1]=='X' && Table[First][2][2]=='.' && PosMoves[8]){cout<<R<<" "<<C<<" "<<2<<" "<<2<<endl;return true;}
        if(Table[First][0][0]=='X' && Table[First][1][1]=='.' && Table[First][2][2]=='X' && PosMoves[4]){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][0][0]=='.' && Table[First][1][1]=='X' && Table[First][2][2]=='X' && PosMoves[0]){cout<<R<<" "<<C<<" "<<0<<" "<<0<<endl;return true;}

        if(Table[First][0][2]=='X' && Table[First][1][1]=='X' && Table[First][2][0]=='.' && PosMoves[6]){cout<<R<<" "<<C<<" "<<2<<" "<<0<<endl;return true;}
        if(Table[First][0][2]=='X' && Table[First][1][1]=='.' && Table[First][2][0]=='X' && PosMoves[4]){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][0][2]=='.' && Table[First][1][1]=='X' && Table[First][2][0]=='X' && PosMoves[2]){cout<<R<<" "<<C<<" "<<0<<" "<<2<<endl;return true;}


    }
    else
    {
        for(int k=0;k<9;k++)
        {
                int i=Array[k]/3;
                int j=Array[k]%3;
                if(BigTTT[i][j]==1)continue;
                R=i;
                C=j;
                int First=R*3+C;
        if(Table[First][0][0]=='X' && Table[First][0][1]=='X' && Table[First][0][2]=='.' && PosMoves[2]){cout<<R<<" "<<C<<" "<<0<<" "<<2<<endl;return true;}
        if(Table[First][0][0]=='X' && Table[First][0][1]=='.' && Table[First][0][2]=='X' && PosMoves[1]){cout<<R<<" "<<C<<" "<<0<<" "<<1<<endl;return true;}
        if(Table[First][0][0]=='.' && Table[First][0][1]=='X' && Table[First][0][2]=='X' && PosMoves[0]){cout<<R<<" "<<C<<" "<<0<<" "<<0<<endl;return true;}

        if(Table[First][1][0]=='X' && Table[First][1][1]=='X' && Table[First][1][2]=='.' && PosMoves[5]){cout<<R<<" "<<C<<" "<<1<<" "<<2<<endl;return true;}
        if(Table[First][1][0]=='X' && Table[First][1][1]=='.' && Table[First][1][2]=='X' && PosMoves[4]){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][1][0]=='.' && Table[First][1][1]=='X' && Table[First][1][2]=='X' && PosMoves[3]){cout<<R<<" "<<C<<" "<<1<<" "<<0<<endl;return true;}

        if(Table[First][2][0]=='X' && Table[First][2][1]=='X' && Table[First][2][2]=='.' && PosMoves[8]){cout<<R<<" "<<C<<" "<<2<<" "<<2<<endl;return true;}
        if(Table[First][2][0]=='X' && Table[First][2][1]=='.' && Table[First][2][2]=='X' && PosMoves[7]){cout<<R<<" "<<C<<" "<<2<<" "<<1<<endl;return true;}
        if(Table[First][2][0]=='.' && Table[First][2][1]=='X' && Table[First][2][2]=='X' && PosMoves[6]){cout<<R<<" "<<C<<" "<<2<<" "<<0<<endl;return true;}

        if(Table[First][0][0]=='X' && Table[First][1][0]=='X' && Table[First][2][0]=='.' && PosMoves[6]){cout<<R<<" "<<C<<" "<<2<<" "<<0<<endl;return true;}
        if(Table[First][0][0]=='X' && Table[First][1][0]=='.' && Table[First][2][0]=='X' && PosMoves[3]){cout<<R<<" "<<C<<" "<<1<<" "<<0<<endl;return true;}
        if(Table[First][0][0]=='.' && Table[First][1][0]=='X' && Table[First][2][0]=='X' && PosMoves[0]){cout<<R<<" "<<C<<" "<<0<<" "<<0<<endl;return true;}

        if(Table[First][0][1]=='X' && Table[First][1][1]=='X' && Table[First][2][1]=='.' && PosMoves[7]){cout<<R<<" "<<C<<" "<<2<<" "<<1<<endl;return true;}
        if(Table[First][0][1]=='X' && Table[First][1][1]=='.' && Table[First][2][1]=='X' && PosMoves[4]){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][0][1]=='.' && Table[First][1][1]=='X' && Table[First][2][1]=='X' && PosMoves[1]){cout<<R<<" "<<C<<" "<<0<<" "<<1<<endl;return true;}

        if(Table[First][0][2]=='X' && Table[First][1][2]=='X' && Table[First][2][2]=='.' && PosMoves[8]){cout<<R<<" "<<C<<" "<<2<<" "<<2<<endl;return true;}
        if(Table[First][0][2]=='X' && Table[First][1][2]=='.' && Table[First][2][2]=='X' && PosMoves[5]){cout<<R<<" "<<C<<" "<<1<<" "<<2<<endl;return true;}
        if(Table[First][0][2]=='.' && Table[First][1][2]=='X' && Table[First][2][2]=='X' && PosMoves[2]){cout<<R<<" "<<C<<" "<<0<<" "<<2<<endl;return true;}

        if(Table[First][0][0]=='X' && Table[First][1][1]=='X' && Table[First][2][2]=='.' && PosMoves[8]){cout<<R<<" "<<C<<" "<<2<<" "<<2<<endl;return true;}
        if(Table[First][0][0]=='X' && Table[First][1][1]=='.' && Table[First][2][2]=='X' && PosMoves[4]){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][0][0]=='.' && Table[First][1][1]=='X' && Table[First][2][2]=='X' && PosMoves[0]){cout<<R<<" "<<C<<" "<<0<<" "<<0<<endl;return true;}

        if(Table[First][0][2]=='X' && Table[First][1][1]=='X' && Table[First][2][0]=='.' && PosMoves[6]){cout<<R<<" "<<C<<" "<<2<<" "<<0<<endl;return true;}
        if(Table[First][0][2]=='X' && Table[First][1][1]=='.' && Table[First][2][0]=='X' && PosMoves[4]){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][0][2]=='.' && Table[First][1][1]=='X' && Table[First][2][0]=='X' && PosMoves[2]){cout<<R<<" "<<C<<" "<<0<<" "<<2<<endl;return true;}


            }


        R=-1;
    C=-1;
    }




    return false;
}
bool isSmallWinnerMe2()
{

    if(R!=-1 && C!=-1)
    {
        int First=R*3+C;
        if(Table[First][0][0]=='X' && Table[First][0][1]=='X' && Table[First][0][2]=='.'){cout<<R<<" "<<C<<" "<<0<<" "<<2<<endl;return true;}
        if(Table[First][0][0]=='X' && Table[First][0][1]=='.' && Table[First][0][2]=='X'){cout<<R<<" "<<C<<" "<<0<<" "<<1<<endl;return true;}
        if(Table[First][0][0]=='.' && Table[First][0][1]=='X' && Table[First][0][2]=='X'){cout<<R<<" "<<C<<" "<<0<<" "<<0<<endl;return true;}

        if(Table[First][1][0]=='X' && Table[First][1][1]=='X' && Table[First][1][2]=='.'){cout<<R<<" "<<C<<" "<<1<<" "<<2<<endl;return true;}
        if(Table[First][1][0]=='X' && Table[First][1][1]=='.' && Table[First][1][2]=='X'){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][1][0]=='.' && Table[First][1][1]=='X' && Table[First][1][2]=='X'){cout<<R<<" "<<C<<" "<<1<<" "<<0<<endl;return true;}

        if(Table[First][2][0]=='X' && Table[First][2][1]=='X' && Table[First][2][2]=='.'){cout<<R<<" "<<C<<" "<<2<<" "<<2<<endl;return true;}
        if(Table[First][2][0]=='X' && Table[First][2][1]=='.' && Table[First][2][2]=='X'){cout<<R<<" "<<C<<" "<<2<<" "<<1<<endl;return true;}
        if(Table[First][2][0]=='.' && Table[First][2][1]=='X' && Table[First][2][2]=='X'){cout<<R<<" "<<C<<" "<<2<<" "<<0<<endl;return true;}

        if(Table[First][0][0]=='X' && Table[First][1][0]=='X' && Table[First][2][0]=='.'){cout<<R<<" "<<C<<" "<<2<<" "<<0<<endl;return true;}
        if(Table[First][0][0]=='X' && Table[First][1][0]=='.' && Table[First][2][0]=='X'){cout<<R<<" "<<C<<" "<<1<<" "<<0<<endl;return true;}
        if(Table[First][0][0]=='.' && Table[First][1][0]=='X' && Table[First][2][0]=='X'){cout<<R<<" "<<C<<" "<<0<<" "<<0<<endl;return true;}

        if(Table[First][0][1]=='X' && Table[First][1][1]=='X' && Table[First][2][1]=='.'){cout<<R<<" "<<C<<" "<<2<<" "<<1<<endl;return true;}
        if(Table[First][0][1]=='X' && Table[First][1][1]=='.' && Table[First][2][1]=='X'){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][0][1]=='.' && Table[First][1][1]=='X' && Table[First][2][1]=='X'){cout<<R<<" "<<C<<" "<<0<<" "<<1<<endl;return true;}

        if(Table[First][0][2]=='X' && Table[First][1][2]=='X' && Table[First][2][2]=='.'){cout<<R<<" "<<C<<" "<<2<<" "<<2<<endl;return true;}
        if(Table[First][0][2]=='X' && Table[First][1][2]=='.' && Table[First][2][2]=='X'){cout<<R<<" "<<C<<" "<<1<<" "<<2<<endl;return true;}
        if(Table[First][0][2]=='.' && Table[First][1][2]=='X' && Table[First][2][2]=='X'){cout<<R<<" "<<C<<" "<<0<<" "<<2<<endl;return true;}

        if(Table[First][0][0]=='X' && Table[First][1][1]=='X' && Table[First][2][2]=='.'){cout<<R<<" "<<C<<" "<<2<<" "<<2<<endl;return true;}
        if(Table[First][0][0]=='X' && Table[First][1][1]=='.' && Table[First][2][2]=='X'){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][0][0]=='.' && Table[First][1][1]=='X' && Table[First][2][2]=='X'){cout<<R<<" "<<C<<" "<<0<<" "<<0<<endl;return true;}

        if(Table[First][0][2]=='X' && Table[First][1][1]=='X' && Table[First][2][0]=='.'){cout<<R<<" "<<C<<" "<<2<<" "<<0<<endl;return true;}
        if(Table[First][0][2]=='X' && Table[First][1][1]=='.' && Table[First][2][0]=='X'){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][0][2]=='.' && Table[First][1][1]=='X' && Table[First][2][0]=='X'){cout<<R<<" "<<C<<" "<<0<<" "<<2<<endl;return true;}


    }
    return false;

}
bool isSmallWinnerHe()
{
    if(R!=-1 && C!=-1)
    {
        int First=R*3+C;
        if(Table[First][0][0]=='O' && Table[First][0][1]=='O' && Table[First][0][2]=='.' && PosMoves[2]){cout<<R<<" "<<C<<" "<<0<<" "<<2<<endl;return true;}
        if(Table[First][0][0]=='O' && Table[First][0][1]=='.' && Table[First][0][2]=='O' && PosMoves[1]){cout<<R<<" "<<C<<" "<<0<<" "<<1<<endl;return true;}
        if(Table[First][0][0]=='.' && Table[First][0][1]=='O' && Table[First][0][2]=='O' && PosMoves[0]){cout<<R<<" "<<C<<" "<<0<<" "<<0<<endl;return true;}

        if(Table[First][1][0]=='O' && Table[First][1][1]=='O' && Table[First][1][2]=='.' && PosMoves[5]){cout<<R<<" "<<C<<" "<<1<<" "<<2<<endl;return true;}
        if(Table[First][1][0]=='O' && Table[First][1][1]=='.' && Table[First][1][2]=='O' && PosMoves[4]){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][1][0]=='.' && Table[First][1][1]=='O' && Table[First][1][2]=='O' && PosMoves[3]){cout<<R<<" "<<C<<" "<<1<<" "<<0<<endl;return true;}

        if(Table[First][2][0]=='O' && Table[First][2][1]=='O' && Table[First][2][2]=='.' && PosMoves[8]){cout<<R<<" "<<C<<" "<<2<<" "<<2<<endl;return true;}
        if(Table[First][2][0]=='O' && Table[First][2][1]=='.' && Table[First][2][2]=='O' && PosMoves[7]){cout<<R<<" "<<C<<" "<<2<<" "<<1<<endl;return true;}
        if(Table[First][2][0]=='.' && Table[First][2][1]=='O' && Table[First][2][2]=='O' && PosMoves[6]){cout<<R<<" "<<C<<" "<<2<<" "<<0<<endl;return true;}

        if(Table[First][0][0]=='O' && Table[First][1][0]=='O' && Table[First][2][0]=='.' && PosMoves[6]){cout<<R<<" "<<C<<" "<<2<<" "<<0<<endl;return true;}
        if(Table[First][0][0]=='O' && Table[First][1][0]=='.' && Table[First][2][0]=='O' && PosMoves[3]){cout<<R<<" "<<C<<" "<<1<<" "<<0<<endl;return true;}
        if(Table[First][0][0]=='.' && Table[First][1][0]=='O' && Table[First][2][0]=='O' && PosMoves[0]){cout<<R<<" "<<C<<" "<<0<<" "<<0<<endl;return true;}

        if(Table[First][0][1]=='O' && Table[First][1][1]=='O' && Table[First][2][1]=='.' && PosMoves[7]){cout<<R<<" "<<C<<" "<<2<<" "<<1<<endl;return true;}
        if(Table[First][0][1]=='O' && Table[First][1][1]=='.' && Table[First][2][1]=='O' && PosMoves[4]){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][0][1]=='.' && Table[First][1][1]=='O' && Table[First][2][1]=='O' && PosMoves[1]){cout<<R<<" "<<C<<" "<<0<<" "<<1<<endl;return true;}

        if(Table[First][0][2]=='O' && Table[First][1][2]=='O' && Table[First][2][2]=='.' && PosMoves[8]){cout<<R<<" "<<C<<" "<<2<<" "<<2<<endl;return true;}
        if(Table[First][0][2]=='O' && Table[First][1][2]=='.' && Table[First][2][2]=='O' && PosMoves[5]){cout<<R<<" "<<C<<" "<<1<<" "<<2<<endl;return true;}
        if(Table[First][0][2]=='.' && Table[First][1][2]=='O' && Table[First][2][2]=='O' && PosMoves[2]){cout<<R<<" "<<C<<" "<<0<<" "<<2<<endl;return true;}

        if(Table[First][0][0]=='O' && Table[First][1][1]=='O' && Table[First][2][2]=='.' && PosMoves[8]){cout<<R<<" "<<C<<" "<<2<<" "<<2<<endl;return true;}
        if(Table[First][0][0]=='O' && Table[First][1][1]=='.' && Table[First][2][2]=='O' && PosMoves[4]){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][0][0]=='.' && Table[First][1][1]=='O' && Table[First][2][2]=='O' && PosMoves[0]){cout<<R<<" "<<C<<" "<<0<<" "<<0<<endl;return true;}

        if(Table[First][0][2]=='O' && Table[First][1][1]=='O' && Table[First][2][0]=='.' && PosMoves[6]){cout<<R<<" "<<C<<" "<<2<<" "<<0<<endl;return true;}
        if(Table[First][0][2]=='O' && Table[First][1][1]=='.' && Table[First][2][0]=='O' && PosMoves[4]){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][0][2]=='.' && Table[First][1][1]=='O' && Table[First][2][0]=='O' && PosMoves[2]){cout<<R<<" "<<C<<" "<<0<<" "<<2<<endl;return true;}


    }
    else
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(BigTTT[i][j]==1)continue;
                R=i;
                C=j;
                int First=R*3+C;
        if(Table[First][0][0]=='O' && Table[First][0][1]=='O' && Table[First][0][2]=='.' && PosMoves[2]){cout<<R<<" "<<C<<" "<<0<<" "<<2<<endl;return true;}
        if(Table[First][0][0]=='O' && Table[First][0][1]=='.' && Table[First][0][2]=='O' && PosMoves[1]){cout<<R<<" "<<C<<" "<<0<<" "<<1<<endl;return true;}
        if(Table[First][0][0]=='.' && Table[First][0][1]=='O' && Table[First][0][2]=='O' && PosMoves[0]){cout<<R<<" "<<C<<" "<<0<<" "<<0<<endl;return true;}

        if(Table[First][1][0]=='O' && Table[First][1][1]=='O' && Table[First][1][2]=='.' && PosMoves[5]){cout<<R<<" "<<C<<" "<<1<<" "<<2<<endl;return true;}
        if(Table[First][1][0]=='O' && Table[First][1][1]=='.' && Table[First][1][2]=='O' && PosMoves[4]){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][1][0]=='.' && Table[First][1][1]=='O' && Table[First][1][2]=='O' && PosMoves[3]){cout<<R<<" "<<C<<" "<<1<<" "<<0<<endl;return true;}

        if(Table[First][2][0]=='O' && Table[First][2][1]=='O' && Table[First][2][2]=='.' && PosMoves[8]){cout<<R<<" "<<C<<" "<<2<<" "<<2<<endl;return true;}
        if(Table[First][2][0]=='O' && Table[First][2][1]=='.' && Table[First][2][2]=='O' && PosMoves[7]){cout<<R<<" "<<C<<" "<<2<<" "<<1<<endl;return true;}
        if(Table[First][2][0]=='.' && Table[First][2][1]=='O' && Table[First][2][2]=='O' && PosMoves[6]){cout<<R<<" "<<C<<" "<<2<<" "<<0<<endl;return true;}

        if(Table[First][0][0]=='O' && Table[First][1][0]=='O' && Table[First][2][0]=='.' && PosMoves[6]){cout<<R<<" "<<C<<" "<<2<<" "<<0<<endl;return true;}
        if(Table[First][0][0]=='O' && Table[First][1][0]=='.' && Table[First][2][0]=='O' && PosMoves[3]){cout<<R<<" "<<C<<" "<<1<<" "<<0<<endl;return true;}
        if(Table[First][0][0]=='.' && Table[First][1][0]=='O' && Table[First][2][0]=='O' && PosMoves[0]){cout<<R<<" "<<C<<" "<<0<<" "<<0<<endl;return true;}

        if(Table[First][0][1]=='O' && Table[First][1][1]=='O' && Table[First][2][1]=='.' && PosMoves[7]){cout<<R<<" "<<C<<" "<<2<<" "<<1<<endl;return true;}
        if(Table[First][0][1]=='O' && Table[First][1][1]=='.' && Table[First][2][1]=='O' && PosMoves[4]){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][0][1]=='.' && Table[First][1][1]=='O' && Table[First][2][1]=='O' && PosMoves[1]){cout<<R<<" "<<C<<" "<<0<<" "<<1<<endl;return true;}

        if(Table[First][0][2]=='O' && Table[First][1][2]=='O' && Table[First][2][2]=='.' && PosMoves[8]){cout<<R<<" "<<C<<" "<<2<<" "<<2<<endl;return true;}
        if(Table[First][0][2]=='O' && Table[First][1][2]=='.' && Table[First][2][2]=='O' && PosMoves[5]){cout<<R<<" "<<C<<" "<<1<<" "<<2<<endl;return true;}
        if(Table[First][0][2]=='.' && Table[First][1][2]=='O' && Table[First][2][2]=='O' && PosMoves[2]){cout<<R<<" "<<C<<" "<<0<<" "<<2<<endl;return true;}

        if(Table[First][0][0]=='O' && Table[First][1][1]=='O' && Table[First][2][2]=='.' && PosMoves[8]){cout<<R<<" "<<C<<" "<<2<<" "<<2<<endl;return true;}
        if(Table[First][0][0]=='O' && Table[First][1][1]=='.' && Table[First][2][2]=='O' && PosMoves[4]){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][0][0]=='.' && Table[First][1][1]=='O' && Table[First][2][2]=='O' && PosMoves[0]){cout<<R<<" "<<C<<" "<<0<<" "<<0<<endl;return true;}

        if(Table[First][0][2]=='O' && Table[First][1][1]=='O' && Table[First][2][0]=='.' && PosMoves[6]){cout<<R<<" "<<C<<" "<<2<<" "<<0<<endl;return true;}
        if(Table[First][0][2]=='O' && Table[First][1][1]=='.' && Table[First][2][0]=='O' && PosMoves[4]){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][0][2]=='.' && Table[First][1][1]=='O' && Table[First][2][0]=='O' && PosMoves[2]){cout<<R<<" "<<C<<" "<<0<<" "<<2<<endl;return true;}


            }

        }
        R=-1;
    C=-1;
    }


     if(R!=-1 && C!=-1)
    {
        int First=R*3+C;
        if(Table[First][0][0]=='O' && Table[First][0][1]=='O' && Table[First][0][2]=='.'){cout<<R<<" "<<C<<" "<<0<<" "<<2<<endl;return true;}
        if(Table[First][0][0]=='O' && Table[First][0][1]=='.' && Table[First][0][2]=='O'){cout<<R<<" "<<C<<" "<<0<<" "<<1<<endl;return true;}
        if(Table[First][0][0]=='.' && Table[First][0][1]=='O' && Table[First][0][2]=='O'){cout<<R<<" "<<C<<" "<<0<<" "<<0<<endl;return true;}

        if(Table[First][1][0]=='O' && Table[First][1][1]=='O' && Table[First][1][2]=='.'){cout<<R<<" "<<C<<" "<<1<<" "<<2<<endl;return true;}
        if(Table[First][1][0]=='O' && Table[First][1][1]=='.' && Table[First][1][2]=='O'){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][1][0]=='.' && Table[First][1][1]=='O' && Table[First][1][2]=='O'){cout<<R<<" "<<C<<" "<<1<<" "<<0<<endl;return true;}

        if(Table[First][2][0]=='O' && Table[First][2][1]=='O' && Table[First][2][2]=='.'){cout<<R<<" "<<C<<" "<<2<<" "<<2<<endl;return true;}
        if(Table[First][2][0]=='O' && Table[First][2][1]=='.' && Table[First][2][2]=='O'){cout<<R<<" "<<C<<" "<<2<<" "<<1<<endl;return true;}
        if(Table[First][2][0]=='.' && Table[First][2][1]=='O' && Table[First][2][2]=='O'){cout<<R<<" "<<C<<" "<<2<<" "<<0<<endl;return true;}

        if(Table[First][0][0]=='O' && Table[First][1][0]=='O' && Table[First][2][0]=='.'){cout<<R<<" "<<C<<" "<<2<<" "<<0<<endl;return true;}
        if(Table[First][0][0]=='O' && Table[First][1][0]=='.' && Table[First][2][0]=='O'){cout<<R<<" "<<C<<" "<<1<<" "<<0<<endl;return true;}
        if(Table[First][0][0]=='.' && Table[First][1][0]=='O' && Table[First][2][0]=='O'){cout<<R<<" "<<C<<" "<<0<<" "<<0<<endl;return true;}

        if(Table[First][0][1]=='O' && Table[First][1][1]=='O' && Table[First][2][1]=='.'){cout<<R<<" "<<C<<" "<<2<<" "<<1<<endl;return true;}
        if(Table[First][0][1]=='O' && Table[First][1][1]=='.' && Table[First][2][1]=='O'){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][0][1]=='.' && Table[First][1][1]=='O' && Table[First][2][1]=='O'){cout<<R<<" "<<C<<" "<<0<<" "<<1<<endl;return true;}

        if(Table[First][0][2]=='O' && Table[First][1][2]=='O' && Table[First][2][2]=='.'){cout<<R<<" "<<C<<" "<<2<<" "<<2<<endl;return true;}
        if(Table[First][0][2]=='O' && Table[First][1][2]=='.' && Table[First][2][2]=='O'){cout<<R<<" "<<C<<" "<<1<<" "<<2<<endl;return true;}
        if(Table[First][0][2]=='.' && Table[First][1][2]=='O' && Table[First][2][2]=='O'){cout<<R<<" "<<C<<" "<<0<<" "<<2<<endl;return true;}

        if(Table[First][0][0]=='O' && Table[First][1][1]=='O' && Table[First][2][2]=='.'){cout<<R<<" "<<C<<" "<<2<<" "<<2<<endl;return true;}
        if(Table[First][0][0]=='O' && Table[First][1][1]=='.' && Table[First][2][2]=='O'){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][0][0]=='.' && Table[First][1][1]=='O' && Table[First][2][2]=='O'){cout<<R<<" "<<C<<" "<<0<<" "<<0<<endl;return true;}

        if(Table[First][0][2]=='O' && Table[First][1][1]=='O' && Table[First][2][0]=='.'){cout<<R<<" "<<C<<" "<<2<<" "<<0<<endl;return true;}
        if(Table[First][0][2]=='O' && Table[First][1][1]=='.' && Table[First][2][0]=='O'){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][0][2]=='.' && Table[First][1][1]=='O' && Table[First][2][0]=='O'){cout<<R<<" "<<C<<" "<<0<<" "<<2<<endl;return true;}


    }
    else
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(BigTTT[i][j]==1)continue;
                R=i;
                C=j;
                int First=R*3+C;
        if(Table[First][0][0]=='O' && Table[First][0][1]=='O' && Table[First][0][2]=='.'){cout<<R<<" "<<C<<" "<<0<<" "<<2<<endl;return true;}
        if(Table[First][0][0]=='O' && Table[First][0][1]=='.' && Table[First][0][2]=='O'){cout<<R<<" "<<C<<" "<<0<<" "<<1<<endl;return true;}
        if(Table[First][0][0]=='.' && Table[First][0][1]=='O' && Table[First][0][2]=='O'){cout<<R<<" "<<C<<" "<<0<<" "<<0<<endl;return true;}

        if(Table[First][1][0]=='O' && Table[First][1][1]=='O' && Table[First][1][2]=='.'){cout<<R<<" "<<C<<" "<<1<<" "<<2<<endl;return true;}
        if(Table[First][1][0]=='O' && Table[First][1][1]=='.' && Table[First][1][2]=='O'){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][1][0]=='.' && Table[First][1][1]=='O' && Table[First][1][2]=='O'){cout<<R<<" "<<C<<" "<<1<<" "<<0<<endl;return true;}

        if(Table[First][2][0]=='O' && Table[First][2][1]=='O' && Table[First][2][2]=='.'){cout<<R<<" "<<C<<" "<<2<<" "<<2<<endl;return true;}
        if(Table[First][2][0]=='O' && Table[First][2][1]=='.' && Table[First][2][2]=='O'){cout<<R<<" "<<C<<" "<<2<<" "<<1<<endl;return true;}
        if(Table[First][2][0]=='.' && Table[First][2][1]=='O' && Table[First][2][2]=='O'){cout<<R<<" "<<C<<" "<<2<<" "<<0<<endl;return true;}

        if(Table[First][0][0]=='O' && Table[First][1][0]=='O' && Table[First][2][0]=='.'){cout<<R<<" "<<C<<" "<<2<<" "<<0<<endl;return true;}
        if(Table[First][0][0]=='O' && Table[First][1][0]=='.' && Table[First][2][0]=='O'){cout<<R<<" "<<C<<" "<<1<<" "<<0<<endl;return true;}
        if(Table[First][0][0]=='.' && Table[First][1][0]=='O' && Table[First][2][0]=='O'){cout<<R<<" "<<C<<" "<<0<<" "<<0<<endl;return true;}

        if(Table[First][0][1]=='O' && Table[First][1][1]=='O' && Table[First][2][1]=='.'){cout<<R<<" "<<C<<" "<<2<<" "<<1<<endl;return true;}
        if(Table[First][0][1]=='O' && Table[First][1][1]=='.' && Table[First][2][1]=='O'){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][0][1]=='.' && Table[First][1][1]=='O' && Table[First][2][1]=='O'){cout<<R<<" "<<C<<" "<<0<<" "<<1<<endl;return true;}

        if(Table[First][0][2]=='O' && Table[First][1][2]=='O' && Table[First][2][2]=='.'){cout<<R<<" "<<C<<" "<<2<<" "<<2<<endl;return true;}
        if(Table[First][0][2]=='O' && Table[First][1][2]=='.' && Table[First][2][2]=='O'){cout<<R<<" "<<C<<" "<<1<<" "<<2<<endl;return true;}
        if(Table[First][0][2]=='.' && Table[First][1][2]=='O' && Table[First][2][2]=='O'){cout<<R<<" "<<C<<" "<<0<<" "<<2<<endl;return true;}

        if(Table[First][0][0]=='O' && Table[First][1][1]=='O' && Table[First][2][2]=='.'){cout<<R<<" "<<C<<" "<<2<<" "<<2<<endl;return true;}
        if(Table[First][0][0]=='O' && Table[First][1][1]=='.' && Table[First][2][2]=='O'){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][0][0]=='.' && Table[First][1][1]=='O' && Table[First][2][2]=='O'){cout<<R<<" "<<C<<" "<<0<<" "<<0<<endl;return true;}

        if(Table[First][0][2]=='O' && Table[First][1][1]=='O' && Table[First][2][0]=='.'){cout<<R<<" "<<C<<" "<<2<<" "<<0<<endl;return true;}
        if(Table[First][0][2]=='O' && Table[First][1][1]=='.' && Table[First][2][0]=='O'){cout<<R<<" "<<C<<" "<<1<<" "<<1<<endl;return true;}
        if(Table[First][0][2]=='.' && Table[First][1][1]=='O' && Table[First][2][0]=='O'){cout<<R<<" "<<C<<" "<<0<<" "<<2<<endl;return true;}


            }

        }
        R=-1;
    C=-1;
    }

    return false;
}
int main()
{
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    BigTTTG[i][j]='.';
    for(int i=0;i<9;i++)
    PosMoves[i]=true;
    for(int i=0;i<9;i++)
    HeCanWin[i]=false;
    char h;
    cin>>R>>C;
    for(int i=0;i<=8;i++)
    {
        for(int j=0;j<=2;j++)
        {
            for(int k=0;k<=2;k++)
            {
                int X=j*3+k,FP=i/3*3+X/3;
                cin>>Table[i/3*3+X/3][i%3][k];
                if(Table[FP][i%3][k]=='#'){BigTTT[(FP)/3][(FP)%3]=1;}
                if(Table[i/3*3+X/3][i%3][k]!='.')NewGame=false;
                //cout<<FP/3<<" "<<FP%3<<endl;}
                //if(FP/3==1 && FP%3==0)cout<<i<<" "<<j<<" "<<k<<endl;
                //if(Table[i/3*3+X/3][i%3][k]!='.'&&Table[i/3*3+X/3][i%3][k]!='#'&&Table[i/3*3+X/3][i%3][k]!='x'&&Table[i/3*3+X/3][i%3][k]!='o')cout<<"BABABABAB"<<Table[i/3*3+X/3][i%3][k]<<endl;
            }
            if(j!=2)cin>>h;
        }
        if(i==2 || i==5){for(int o=0;o<=10;o++)cin>>h;}

    }


    if(NewGame){cout<<1<<" "<<1<<" "<<2<<" "<<2<<endl;return 0;}
    if(R==-1 && C==-1){
        for(int i=-1;i<9;i++){
            if(i!=-1)R=Array[i]/3;
            if(i!=-1)C=Array[i]%3;
            if(i!=-1)if(BigTTT[R][C])continue;
            if(i!=-1)if(isBigWinner())return 0;
            if(isSmallWinnerMe())return 0;//cout<<1<<endl;
            if(isMiddle())return 0;//cout<<2<<endl;
            if(makeBigTTT())return 0;//cout<<3<<endl;
            if(isSmallWinnerMe2())return 0;
            if(isSmallWinnerHe())return 0;

        }
    }
    else{
        if(isBigWinner())return 0;
            if(isSmallWinnerMe())return 0;//cout<<1<<endl;
            if(isMiddle())return 0;//cout<<2<<endl;
            if(makeBigTTT())return 0;//cout<<3<<endl;
            if(isSmallWinnerMe2())return 0;
            if(isSmallWinnerHe())return 0;
            //if(isBigWinner())return 0;
    }


    Tactic1_random();

    /*
    for(int i=0;i<=8;i++){
        for(int j=0;j<=2;j++){
            for(int k=0;k<=2;k++){
                cout<<Table[i][j][k];
            }
            cout<<" ";

        }
        cout<<endl;
    }
           */

    return 0;
}

bool isBigWinner()
{
    if(R==-1 && C==-1)return false;
    for(int i=0;i<9;i++)
    {
        if(BigTTT[i/3][i%3])HeCanWin[i]=true;
        ///EnemyWinner
        if(Table[i][0][0]=='O' && Table[i][0][1]=='O' && Table[i][0][2]=='.'){HeCanWin[i]=true;}
        if(Table[i][0][0]=='O' && Table[i][0][1]=='.' && Table[i][0][2]=='O'){HeCanWin[i]=true;}
        if(Table[i][0][0]=='.' && Table[i][0][1]=='O' && Table[i][0][2]=='O'){HeCanWin[i]=true;}

        if(Table[i][1][0]=='O' && Table[i][1][1]=='O' && Table[i][1][2]=='.'){HeCanWin[i]=true;}
        if(Table[i][1][0]=='O' && Table[i][1][1]=='.' && Table[i][1][2]=='O'){HeCanWin[i]=true;}
        if(Table[i][1][0]=='.' && Table[i][1][1]=='O' && Table[i][1][2]=='O'){HeCanWin[i]=true;}

        if(Table[i][2][0]=='O' && Table[i][2][1]=='O' && Table[i][2][2]=='.'){HeCanWin[i]=true;}
        if(Table[i][2][0]=='O' && Table[i][2][1]=='.' && Table[i][2][2]=='O'){HeCanWin[i]=true;}
        if(Table[i][2][0]=='.' && Table[i][2][1]=='O' && Table[i][2][2]=='O'){HeCanWin[i]=true;}

        if(Table[i][0][0]=='O' && Table[i][1][0]=='O' && Table[i][2][0]=='.'){HeCanWin[i]=true;}
        if(Table[i][0][0]=='O' && Table[i][1][0]=='.' && Table[i][2][0]=='O'){HeCanWin[i]=true;}
        if(Table[i][0][0]=='.' && Table[i][1][0]=='O' && Table[i][2][0]=='O'){HeCanWin[i]=true;}

        if(Table[i][0][1]=='O' && Table[i][1][1]=='O' && Table[i][2][1]=='.'){HeCanWin[i]=true;}
        if(Table[i][0][1]=='O' && Table[i][1][1]=='.' && Table[i][2][1]=='O'){HeCanWin[i]=true;}
        if(Table[i][0][1]=='.' && Table[i][1][1]=='O' && Table[i][2][1]=='O'){HeCanWin[i]=true;}

        if(Table[i][0][2]=='O' && Table[i][1][2]=='O' && Table[i][2][2]=='.'){HeCanWin[i]=true;}
        if(Table[i][0][2]=='O' && Table[i][1][2]=='.' && Table[i][2][2]=='O'){HeCanWin[i]=true;}
        if(Table[i][0][2]=='.' && Table[i][1][2]=='O' && Table[i][2][2]=='O'){HeCanWin[i]=true;}

        if(Table[i][0][0]=='O' && Table[i][1][1]=='O' && Table[i][2][2]=='.'){HeCanWin[i]=true;}
        if(Table[i][0][0]=='O' && Table[i][1][1]=='.' && Table[i][2][2]=='O'){HeCanWin[i]=true;}
        if(Table[i][0][0]=='.' && Table[i][1][1]=='O' && Table[i][2][2]=='O'){HeCanWin[i]=true;}

        if(Table[i][0][2]=='O' && Table[i][1][1]=='O' && Table[i][2][0]=='.'){HeCanWin[i]=true;}
        if(Table[i][0][2]=='O' && Table[i][1][1]=='.' && Table[i][2][0]=='O'){HeCanWin[i]=true;}
        if(Table[i][0][2]=='.' && Table[i][1][1]=='O' && Table[i][2][0]=='O'){HeCanWin[i]=true;}



    }
    for(int i=0;i<9;i++)
    {
        if(BigTTT[i/3][i%3]==0)continue;
        ///EnemyWinner
        if(Table[i][0][0]=='O' && Table[i][0][1]=='O' && Table[i][0][2]=='O'){BigTTTG[i/3][i%3]='O';continue;}
        if(Table[i][0][0]=='O' && Table[i][0][1]=='O' && Table[i][0][2]=='O'){BigTTTG[i/3][i%3]='O';continue;}
        if(Table[i][0][0]=='O' && Table[i][0][1]=='O' && Table[i][0][2]=='O'){BigTTTG[i/3][i%3]='O';continue;}

        if(Table[i][1][0]=='O' && Table[i][1][1]=='O' && Table[i][1][2]=='O'){BigTTTG[i/3][i%3]='O';continue;}
        if(Table[i][1][0]=='O' && Table[i][1][1]=='O' && Table[i][1][2]=='O'){BigTTTG[i/3][i%3]='O';continue;}
        if(Table[i][1][0]=='O' && Table[i][1][1]=='O' && Table[i][1][2]=='O'){BigTTTG[i/3][i%3]='O';continue;}

        if(Table[i][2][0]=='O' && Table[i][2][1]=='O' && Table[i][2][2]=='O'){BigTTTG[i/3][i%3]='O';continue;}
        if(Table[i][2][0]=='O' && Table[i][2][1]=='O' && Table[i][2][2]=='O'){BigTTTG[i/3][i%3]='O';continue;}
        if(Table[i][2][0]=='O' && Table[i][2][1]=='O' && Table[i][2][2]=='O'){BigTTTG[i/3][i%3]='O';continue;}

        if(Table[i][0][0]=='O' && Table[i][1][0]=='O' && Table[i][2][0]=='O'){BigTTTG[i/3][i%3]='O';continue;}
        if(Table[i][0][0]=='O' && Table[i][1][0]=='O' && Table[i][2][0]=='O'){BigTTTG[i/3][i%3]='O';continue;}
        if(Table[i][0][0]=='O' && Table[i][1][0]=='O' && Table[i][2][0]=='O'){BigTTTG[i/3][i%3]='O';continue;}

        if(Table[i][0][1]=='O' && Table[i][1][1]=='O' && Table[i][2][1]=='O'){BigTTTG[i/3][i%3]='O';continue;}
        if(Table[i][0][1]=='O' && Table[i][1][1]=='O' && Table[i][2][1]=='O'){BigTTTG[i/3][i%3]='O';continue;}
        if(Table[i][0][1]=='O' && Table[i][1][1]=='O' && Table[i][2][1]=='O'){BigTTTG[i/3][i%3]='O';continue;}

        if(Table[i][0][2]=='O' && Table[i][1][2]=='O' && Table[i][2][2]=='O'){BigTTTG[i/3][i%3]='O';continue;}
        if(Table[i][0][2]=='O' && Table[i][1][2]=='O' && Table[i][2][2]=='O'){BigTTTG[i/3][i%3]='O';continue;}
        if(Table[i][0][2]=='O' && Table[i][1][2]=='O' && Table[i][2][2]=='O'){BigTTTG[i/3][i%3]='O';continue;}

        if(Table[i][0][0]=='O' && Table[i][1][1]=='O' && Table[i][2][2]=='O'){BigTTTG[i/3][i%3]='O';continue;}
        if(Table[i][0][0]=='O' && Table[i][1][1]=='O' && Table[i][2][2]=='O'){BigTTTG[i/3][i%3]='O';continue;}
        if(Table[i][0][0]=='O' && Table[i][1][1]=='O' && Table[i][2][2]=='O'){BigTTTG[i/3][i%3]='O';continue;}

        if(Table[i][0][2]=='O' && Table[i][1][1]=='O' && Table[i][2][0]=='O'){BigTTTG[i/3][i%3]='O';continue;}
        if(Table[i][0][2]=='O' && Table[i][1][1]=='O' && Table[i][2][0]=='O'){BigTTTG[i/3][i%3]='O';continue;}
        if(Table[i][0][2]=='O' && Table[i][1][1]=='O' && Table[i][2][0]=='O'){BigTTTG[i/3][i%3]='O';continue;}

        BigTTTG[i/3][i%3]='X';

    }



        for(int i=0;i<9;i++)PosMoves[i]=true;

        ///EnemyWinner
        if(BigTTTG[0][0]=='O' && BigTTTG[0][1]=='O' && BigTTTG[0][2]=='.' && HeCanWin[2]){PosMoves[2]=false;}
        if(BigTTTG[0][0]=='O' && BigTTTG[0][1]=='.' && BigTTTG[0][2]=='O' && HeCanWin[1]){PosMoves[1]=false;}
        if(BigTTTG[0][0]=='.' && BigTTTG[0][1]=='O' && BigTTTG[0][2]=='O' && HeCanWin[0]){PosMoves[0]=false;}

        if(BigTTTG[1][0]=='O' && BigTTTG[1][1]=='O' && BigTTTG[1][2]=='.' && HeCanWin[5]){PosMoves[5]=false;}
        if(BigTTTG[1][0]=='O' && BigTTTG[1][1]=='.' && BigTTTG[1][2]=='O' && HeCanWin[4]){PosMoves[4]=false;}
        if(BigTTTG[1][0]=='.' && BigTTTG[1][1]=='O' && BigTTTG[1][2]=='O' && HeCanWin[3]){PosMoves[3]=false;}

        if(BigTTTG[2][0]=='O' && BigTTTG[2][1]=='O' && BigTTTG[2][2]=='.' && HeCanWin[8]){PosMoves[8]=false;}
        if(BigTTTG[2][0]=='O' && BigTTTG[2][1]=='.' && BigTTTG[2][2]=='O' && HeCanWin[7]){PosMoves[7]=false;}
        if(BigTTTG[2][0]=='.' && BigTTTG[2][1]=='O' && BigTTTG[2][2]=='O' && HeCanWin[6]){PosMoves[6]=false;}

        if(BigTTTG[0][0]=='O' && BigTTTG[1][0]=='O' && BigTTTG[2][0]=='.' && HeCanWin[6]){PosMoves[6]=false;}
        if(BigTTTG[0][0]=='O' && BigTTTG[1][0]=='.' && BigTTTG[2][0]=='O' && HeCanWin[3]){PosMoves[3]=false;}
        if(BigTTTG[0][0]=='.' && BigTTTG[1][0]=='O' && BigTTTG[2][0]=='O' && HeCanWin[0]){PosMoves[0]=false;}

        if(BigTTTG[0][1]=='O' && BigTTTG[1][1]=='O' && BigTTTG[2][1]=='.' && HeCanWin[7]){PosMoves[7]=false;}
        if(BigTTTG[0][1]=='O' && BigTTTG[1][1]=='.' && BigTTTG[2][1]=='O' && HeCanWin[4]){PosMoves[4]=false;}
        if(BigTTTG[0][1]=='.' && BigTTTG[1][1]=='O' && BigTTTG[2][1]=='O' && HeCanWin[1]){PosMoves[1]=false;}

        if(BigTTTG[0][2]=='O' && BigTTTG[1][2]=='O' && BigTTTG[2][2]=='.' && HeCanWin[8]){PosMoves[8]=false;}
        if(BigTTTG[0][2]=='O' && BigTTTG[1][2]=='.' && BigTTTG[2][2]=='O' && HeCanWin[5]){PosMoves[5]=false;}
        if(BigTTTG[0][2]=='.' && BigTTTG[1][2]=='O' && BigTTTG[2][2]=='O' && HeCanWin[2]){PosMoves[2]=false;}

        if(BigTTTG[0][0]=='O' && BigTTTG[1][1]=='O' && BigTTTG[2][2]=='.' && HeCanWin[8]){PosMoves[8]=false;}
        if(BigTTTG[0][0]=='O' && BigTTTG[1][1]=='.' && BigTTTG[2][2]=='O' && HeCanWin[4]){PosMoves[4]=false;}
        if(BigTTTG[0][0]=='.' && BigTTTG[1][1]=='O' && BigTTTG[2][2]=='O' && HeCanWin[0]){PosMoves[0]=false;}

        if(BigTTTG[0][2]=='O' && BigTTTG[1][1]=='O' && BigTTTG[2][0]=='.' && HeCanWin[6]){PosMoves[6]=false;}
        if(BigTTTG[0][2]=='O' && BigTTTG[1][1]=='.' && BigTTTG[2][0]=='O' && HeCanWin[4]){PosMoves[4]=false;}
        if(BigTTTG[0][2]=='.' && BigTTTG[1][1]=='O' && BigTTTG[2][0]=='O' && HeCanWin[2]){PosMoves[2]=false;}

        /*for(int i=0;i<9;i++)
        {
            if(PosMoves[i])
            {
                if(Table[R*3+C][i/3][i%3]=='.'){cout<<R<<" "<<C<<" "<<i/3<<" "<<i%3<<endl;return true;}
            }
        }*/



    return false;
}
bool makeBigTTT()
{
    if(R==-1 && C==-1)return false;
    for(int i=0;i<9;i++)
    {
        if(BigTTT[i/3][i%3])continue;
        ///EnemyWinner
        if(Table[i][0][0]=='O' && Table[i][0][1]=='O' && Table[i][0][2]=='.'){continue;}
        if(Table[i][0][0]=='O' && Table[i][0][1]=='.' && Table[i][0][2]=='O'){continue;}
        if(Table[i][0][0]=='.' && Table[i][0][1]=='O' && Table[i][0][2]=='O'){continue;}

        if(Table[i][1][0]=='O' && Table[i][1][1]=='O' && Table[i][1][2]=='.'){continue;}
        if(Table[i][1][0]=='O' && Table[i][1][1]=='.' && Table[i][1][2]=='O'){continue;}
        if(Table[i][1][0]=='.' && Table[i][1][1]=='O' && Table[i][1][2]=='O'){continue;}

        if(Table[i][2][0]=='O' && Table[i][2][1]=='O' && Table[i][2][2]=='.'){continue;}
        if(Table[i][2][0]=='O' && Table[i][2][1]=='.' && Table[i][2][2]=='O'){continue;}
        if(Table[i][2][0]=='.' && Table[i][2][1]=='O' && Table[i][2][2]=='O'){continue;}

        if(Table[i][0][0]=='O' && Table[i][1][0]=='O' && Table[i][2][0]=='.'){continue;}
        if(Table[i][0][0]=='O' && Table[i][1][0]=='.' && Table[i][2][0]=='O'){continue;}
        if(Table[i][0][0]=='.' && Table[i][1][0]=='O' && Table[i][2][0]=='O'){continue;}

        if(Table[i][0][1]=='O' && Table[i][1][1]=='O' && Table[i][2][1]=='.'){continue;}
        if(Table[i][0][1]=='O' && Table[i][1][1]=='.' && Table[i][2][1]=='O'){continue;}
        if(Table[i][0][1]=='.' && Table[i][1][1]=='O' && Table[i][2][1]=='O'){continue;}

        if(Table[i][0][2]=='O' && Table[i][1][2]=='O' && Table[i][2][2]=='.'){continue;}
        if(Table[i][0][2]=='O' && Table[i][1][2]=='.' && Table[i][2][2]=='O'){continue;}
        if(Table[i][0][2]=='.' && Table[i][1][2]=='O' && Table[i][2][2]=='O'){continue;}

        if(Table[i][0][0]=='O' && Table[i][1][1]=='O' && Table[i][2][2]=='.'){continue;}
        if(Table[i][0][0]=='O' && Table[i][1][1]=='.' && Table[i][2][2]=='O'){continue;}
        if(Table[i][0][0]=='.' && Table[i][1][1]=='O' && Table[i][2][2]=='O'){continue;}

        if(Table[i][0][2]=='O' && Table[i][1][1]=='O' && Table[i][2][0]=='.'){continue;}
        if(Table[i][0][2]=='O' && Table[i][1][1]=='.' && Table[i][2][0]=='O'){continue;}
        if(Table[i][0][2]=='.' && Table[i][1][1]=='O' && Table[i][2][0]=='O'){continue;}

        if(Table[R*3+C][i/3][i%3]=='.'){cout<<R<<" "<<C<<" "<<i/3<<" "<<i%3<<endl;return true;}

    }
    return false;
}

bool isMiddle()
{
    if(R==-1 && C==-1)return false;
    for(int k=0;k<9;k++)
    {
        int i=Array[k];
    if(BigTTT[i/3][i%3])continue;

        ///EnemyWinner
        if(Table[i][0][0]=='O' && Table[i][0][1]=='O' && Table[i][0][2]=='.'){continue;}
        if(Table[i][0][0]=='O' && Table[i][0][1]=='.' && Table[i][0][2]=='O'){continue;}
        if(Table[i][0][0]=='.' && Table[i][0][1]=='O' && Table[i][0][2]=='O'){continue;}

        if(Table[i][1][0]=='O' && Table[i][1][1]=='O' && Table[i][1][2]=='.'){continue;}
        if(Table[i][1][0]=='O' && Table[i][1][1]=='.' && Table[i][1][2]=='O'){continue;}
        if(Table[i][1][0]=='.' && Table[i][1][1]=='O' && Table[i][1][2]=='O'){continue;}

        if(Table[i][2][0]=='O' && Table[i][2][1]=='O' && Table[i][2][2]=='.'){continue;}
        if(Table[i][2][0]=='O' && Table[i][2][1]=='.' && Table[i][2][2]=='O'){continue;}
        if(Table[i][2][0]=='.' && Table[i][2][1]=='O' && Table[i][2][2]=='O'){continue;}

        if(Table[i][0][0]=='O' && Table[i][1][0]=='O' && Table[i][2][0]=='.'){continue;}
        if(Table[i][0][0]=='O' && Table[i][1][0]=='.' && Table[i][2][0]=='O'){continue;}
        if(Table[i][0][0]=='.' && Table[i][1][0]=='O' && Table[i][2][0]=='O'){continue;}

        if(Table[i][0][1]=='O' && Table[i][1][1]=='O' && Table[i][2][1]=='.'){continue;}
        if(Table[i][0][1]=='O' && Table[i][1][1]=='.' && Table[i][2][1]=='O'){continue;}
        if(Table[i][0][1]=='.' && Table[i][1][1]=='O' && Table[i][2][1]=='O'){continue;}

        if(Table[i][0][2]=='O' && Table[i][1][2]=='O' && Table[i][2][2]=='.'){continue;}
        if(Table[i][0][2]=='O' && Table[i][1][2]=='.' && Table[i][2][2]=='O'){continue;}
        if(Table[i][0][2]=='.' && Table[i][1][2]=='O' && Table[i][2][2]=='O'){continue;}

        if(Table[i][0][0]=='O' && Table[i][1][1]=='O' && Table[i][2][2]=='.'){continue;}
        if(Table[i][0][0]=='O' && Table[i][1][1]=='.' && Table[i][2][2]=='O'){continue;}
        if(Table[i][0][0]=='.' && Table[i][1][1]=='O' && Table[i][2][2]=='O'){continue;}

        if(Table[i][0][2]=='O' && Table[i][1][1]=='O' && Table[i][2][0]=='.'){continue;}
        if(Table[i][0][2]=='O' && Table[i][1][1]=='.' && Table[i][2][0]=='O'){continue;}
        if(Table[i][0][2]=='.' && Table[i][1][1]=='O' && Table[i][2][0]=='O'){continue;}

        if(Table[R*3+C][i/3][i%3]=='.' && PosMoves[i]){cout<<R<<" "<<C<<" "<<i/3<<" "<<i%3<<endl;return true;}
    }
        return false;
}

