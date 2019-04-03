#include<iostream>
using namespace std;
int N,K;
int table[10][10];
/*
void Connect_Game_3x3_Pl1()
{
    if(table[0][0]==0){cout<<0<<" "<<0<<endl;return;}
    if(table[0][1] !=1 && table[1][1] !=1 && table[2][1]!=1)
    {

        if(table[0][1]==0){cout<<0<<" "<<1<<endl;return;}
        if(table[1][1]==0){cout<<1<<" "<<1<<endl;return;}

        if(table[2][1]==0){cout<<2<<" "<<1<<endl;return;}
    }
    if(table[0][2] !=1 && table[1][2] !=1 && table[2][2]!=1)
    {
        if(table[0][1]==1){
            if(table[0][2]==0){cout<<0<<" "<<2<<endl;return;}
            if(table[1][2]==0){cout<<1<<" "<<2<<endl;return;}

        if(table[2][2]==0){cout<<2<<" "<<2<<endl;return;}
        }
        if(table[1][2]==0){cout<<1<<" "<<2<<endl;return;}
        if(table[2][2]==0){cout<<2<<" "<<2<<endl;return;}
        if(table[0][2]==0){cout<<0<<" "<<2<<endl;return;}
    }

}
void Connect_Game_3x3_Pl2()
{
    bool Sec=0,Fir=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(table[i][j]==2)Sec=1;
            if(table[i][j]==1)Fir=1;
        }
        if(Sec==0 && Fir==1)
        {

            for(int k=1;k<=2;k++)
            {
                if(table[i][k]==0){cout<<i<<" "<<k<<endl;return;}
            }
            if(table[i][0]==0){cout<<i<<" "<<0<<endl;return;}
        }
        Sec=0;Fir=0;
    }
    for(int i=0;i<3;i++)
    {
        if(table[i][1]==0){cout<<i<<" "<<1<<endl;return;}


    }
    for(int i=0;i<3;i++)
    {if(table[i][2]==0){cout<<i<<" "<<2<<endl;return;}


    }
    for(int i=0;i<3;i++)
    {

        if(table[i][0]==0){cout<<i<<" "<<1<<endl;return;}

    }
}

void Connect_Game_7x7_Pl1()
{
    bool Sec=0,Fir=0;
    if(table[4][4]==0){cout<<4<<" "<<4<<endl;return;}
    for(int j=0;j<N;j++)
    {
        for(int i=0;i<N;i++)
        {
            if(table[i][j]==2)Sec=1;
            if(table[i][j]==1)Fir=1;
        }
        if(Sec==1 && Fir==0)
        {

            for(int k=3;k<=6;k++)
            {
                if(table[k][j]==0){cout<<k<<" "<<j<<endl;return;}
            }
            if(table[0][j]==0){cout<<0<<" "<<j<<endl;return;}
            if(table[1][j]==0){cout<<1<<" "<<j<<endl;return;}
            else if(table[2][j]==0){cout<<2<<" "<<j<<endl;return;}
        }
        Sec=0;Fir=0;
    }
    for(int j=0;j<7;j++)
    {
        if(table[3][j]==0){cout<<3<<" "<<j<<endl;return;}


    }
    for(int j=0;j<7;j++)
    {if(table[4][j]==0){cout<<4<<" "<<j<<endl;return;}

    }
}

void Connect_Game_7x7_Pl2()
{
    bool Sec=0,Fir=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(table[i][j]==2)Sec=1;
            if(table[i][j]==1)Fir=1;
        }
        if(Sec==0 && Fir==1)
        {

            for(int k=3;k<=6;k++)
            {
                if(table[i][k]==0){cout<<i<<" "<<k<<endl;return;}
            }
            if(table[i][0]==0){cout<<i<<" "<<0<<endl;return;}
            if(table[i][1]==0){cout<<i<<" "<<1<<endl;return;}
            else if(table[i][2]==0){cout<<i<<" "<<2<<endl;return;}
        }
        Sec=0;Fir=0;
    }
    for(int i=0;i<7;i++)
    {
        if(table[i][3]==0){cout<<i<<" "<<3<<endl;return;}

    }
    for(int i=0;i<7;i++)
    {

    if(table[i][4]==0){cout<<i<<" "<<4<<endl;return;}

    }
}

void Connect_Game_10x10_Pl1()
{
    bool Sec=0,Fir=0;
    if(table[5][5]==0){cout<<5<<" "<<5<<endl;return;}
    for(int j=0;j<N;j++)
    {
        for(int i=0;i<N;i++)
        {
            if(table[i][j]==2)Sec=1;
            if(table[i][j]==1)Fir=1;
        }
        if(Sec==1 && Fir==0)
        {

            for(int k=4;k<=9;k++)
            {
                if(table[k][j]==0){cout<<k<<" "<<j<<endl;return;}
            }
            if(table[1][j]==0){cout<<1<<" "<<j<<endl;return;}
            else if(table[2][j]==0){cout<<2<<" "<<j<<endl;return;}
            else if(table[3][j]==0){cout<<3<<" "<<j<<endl;return;}
            else if(table[0][j]==0){cout<<0<<" "<<j<<endl;return;}
        }
        Sec=0;Fir=0;
    }
    for(int j=0;j<10;j++)
    {
        if(table[4][j]==0){cout<<4<<" "<<j<<endl;return;}


    }
    for(int j=0;j<10;j++)
    {
   if(table[5][j]==0){cout<<5<<" "<<j<<endl;return;}

    }
}

void Connect_Game_10x10_Pl2()
{
    bool Sec=0,Fir=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(table[i][j]==2)Sec=1;
            if(table[i][j]==1)Fir=1;
        }
        if(Sec==0 && Fir==1)
        {

            for(int k=4;k<=9;k++)
            {
                if(table[i][k]==0){cout<<i<<" "<<k<<endl;return;}
            }
            if(table[i][1]==0){cout<<i<<" "<<1<<endl;return;}
            else if(table[i][2]==0){cout<<i<<" "<<2<<endl;return;}
            else if(table[i][3]==0){cout<<i<<" "<<3<<endl;return;}
            else if(table[i][0]==0){cout<<i<<" "<<0<<endl;return;}
        }
        Sec=0;Fir=0;
    }
    for(int i=0;i<10;i++)
    {
        if(table[i][4]==0){cout<<i<<" "<<4<<endl;return;}


    }
    for(int i=0;i<10;i++)
    {
        if(table[i][5]==0){cout<<i<<" "<<5<<endl;return;}

    }
}
*/
int Array3x3[10];
void game()
{
    if(K==1)
    {
        if(N==3)
        {
            int SavedJ;
            if(table[1][1]==0){cout<<1<<" "<<1<<endl;return;}
            for(int j=0;j<N;j++)
            {
                int s=0;
                for(int i=0;i<N;i++)
                {
                    s+=table[i][j];
                }
                if(s==2)
                {
                    if(table[0][j]==0 && j==0){cout<<0<<" "<<j<<endl;return;}
                    if(table[1][j]==0){cout<<1<<" "<<j<<endl;return;}
                    if(table[2][j]==0 && j==2){cout<<2<<" "<<j<<endl;return;}
                }
                else if(s==0)SavedJ=j;
            }
            cout<<1<<" "<<SavedJ<<endl;
            return;


        }
        else
        {
            if(table[0][0]==0){cout<<0<<" "<<0<<endl;return;}
            int lastI=0,lastJ=0;

            for(int i=0;i<N;i++)
            {
                bool sec=false;
                for(int j=0;j<N;j++)
                {
                    if(table[i][j]==1){lastI=i;lastJ=j;}
                    if(table[i][j]==2){sec=true;}
                }
                if(sec==false)
                {
                    if(lastI==i)
                    {
                        if(table[lastI][lastJ+1]==0){cout<<lastI<<" "<<lastJ+1<<endl;return;}

                    }
                    else
                    {
                        if(table[lastI+1][lastJ+1]==0){cout<<lastI+1<<" "<<lastJ+1<<endl;return;}

                    }
                }

            }
            if(table[lastI][lastJ+1]==0){cout<<lastI<<" "<<lastJ+1<<endl;return;}
            if(table[lastI+1][lastJ+1]==0){cout<<lastI+1<<" "<<lastJ+1<<endl;return;}
            if(table[lastI+1][lastJ]==0){cout<<lastI+1<<" "<<lastJ<<endl;return;}
            for(int i=1;i<N;i++)
            {
                for(int j=1;j<N;j++)
                {
                    if(j<=lastJ && i<=lastI && table[i-1][j]==1 && table[i][j]==0){cout<<i<<" "<<j<<endl;return;}
                }
            }
            for(int i=1;i<N;i++)
                for(int j=1;j<N;j++)
                if(table[i][j]==0){cout<<i<<" "<<j<<endl;return;}
        }
    }
    else
    {
        if(N==3)
        {
            int br0=0;
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    if(table[i][j]==0)br0++;
                    Array3x3[i*3+j]=table[i][j];
                }
            }
            int Case3x3;
            int F1=-1,F2=-1,S1;
            switch(br0)
            {
                case 8:
                for(int i=0;i<9;i++)
                {
                    if(Array3x3[i]==1)
                    {
                        Case3x3=i;
                    }
                }
                switch(Case3x3)
                {
                    case 0:
                    case 1:
                    cout<<1<<" "<<2<<endl;
                    return;
                    break;
                    case 2:
                    cout<<0<<" "<<0<<endl;
                    return;
                    break;
                    case 3:
                    case 4:
                    cout<<2<<" "<<2<<endl;
                    return;
                    break;
                    case 5:

                    cout<<1<<" "<<1<<endl;
                    return;
                    break;
                    case 8:
                    cout<<1<<" "<<0<<endl;
                    return;
                    break;
                    case 6:
                    case 7:
                    cout<<2<<" "<<2<<endl;
                    return;
                    break;
                }
                break;
                case 6:
                if(table[0][0]==2)
                {

                    for(int i=0;i<N;i++)
                    {
                        for(int j=0;j<N;j++)
                        {
                            if(table[i][j]==1 && (i*3+j)!=2)
                            {
                                int k=i*3+j;
                                switch(k)
                                {
                                    case 1:
                                    cout<<1<<" "<<0<<endl;
                                    return;
                                    break;
                                    case 3:
                                    cout<<1<<" "<<1<<endl;
                                    return;
                                    break;

                                    case 4:
                                    cout<<1<<" "<<0<<endl;
                                    return;
                                    break;

                                    case 5:
                                    cout<<1<<" "<<0<<endl;
                                    return;
                                    break;

                                    case 6:
                                    cout<<1<<" "<<1<<endl;
                                    return;
                                    break;

                                    case 7:
                                    cout<<1<<" "<<1<<endl;
                                    return;
                                    break;

                                    case 8:
                                    cout<<1<<" "<<0<<endl;
                                    return;
                                    break;

                                }
                            }
                        }
                    }
                }
                if(table[1][1]==2)
                {
                    if(table[1][2]==1){
                    for(int i=0;i<N;i++)
                    {
                        for(int j=0;j<N;j++)
                        {

                                if(table[i][j]==1 &&  (i*3+j)!=5)
                                {
                                int k=i*3+j;
                                switch(k)
                                {
                                    case 0:
                                    cout<<0<<" "<<1<<endl;
                                    return;
                                    break;
                                    case 1:
                                    cout<<0<<" "<<0<<endl;
                                    return;
                                    break;
                                    case 2:
                                    cout<<0<<" "<<0<<endl;
                                    return;
                                    break;
                                    case 3:
                                    cout<<0<<" "<<0<<endl;
                                    return;
                                    break;

                                    case 6:
                                    cout<<0<<" "<<0<<endl;
                                    return;
                                    break;

                                    case 7:
                                    cout<<2<<" "<<2<<endl;
                                    return;
                                    break;

                                    case 8:
                                    cout<<2<<" "<<1<<endl;
                                    return;
                                    break;

                                }
                                }

                        }
                        }
                    }


                    if(table[2][2]==1){
                    for(int i=0;i<N;i++)
                    {
                        for(int j=0;j<N;j++)
                        {

                                if(table[i][j]==1 &&  (i*3+j)!=8)
                                {
                                int k=i*3+j;
                                switch(k)
                                {
                                    case 0:
                                    cout<<0<<" "<<1<<endl;
                                    return;
                                    break;
                                    case 1:
                                    cout<<0<<" "<<0<<endl;
                                    return;
                                    break;
                                    case 2:
                                    cout<<2<<" "<<1<<endl;
                                    return;
                                    break;
                                    case 3:
                                    cout<<2<<" "<<1<<endl;
                                    return;
                                    break;



                                    case 5:
                                    cout<<2<<" "<<1<<endl;
                                    return;
                                    break;

                                    case 6:
                                    cout<<2<<" "<<1<<endl;
                                    return;
                                    break;

                                    case 7:
                                    cout<<1<<" "<<0<<endl;
                                    return;
                                    break;



                                }
                                }

                        }
                        }
                    }
                }
                if(table[1][0]==2)
                {

                    for(int i=0;i<N;i++)
                    {
                        for(int j=0;j<N;j++)
                        {
                            if(table[i][j]==1 && (i*3+j)!=8)
                            {
                                int k=i*3+j;
                                switch(k)
                                {
                                    case 0:
                                    cout<<1<<" "<<1<<endl;
                                    return;
                                    break;
                                    case 1:
                                    cout<<0<<" "<<0<<endl;
                                    return;
                                    break;
                                    case 2:
                                    cout<<0<<" "<<0<<endl;
                                    return;
                                    break;

                                    case 4:
                                    cout<<0<<" "<<0<<endl;
                                    return;
                                    break;

                                    case 5:
                                    cout<<0<<" "<<0<<endl;
                                    return;
                                    break;

                                    case 6:
                                    cout<<2<<" "<<1<<endl;
                                    return;
                                    break;

                                    case 7:
                                    cout<<2<<" "<<0<<endl;
                                    return;
                                    break;



                                }
                            }
                        }
                    }
                }

                if(table[0][0]==1 && table[0][1]==1){cout<<0<<" "<<2<<endl;return;}
                if(table[0][0]==1 && table[0][2]==1){cout<<0<<" "<<1<<endl;return;}
                if(table[0][2]==1 && table[0][1]==1){cout<<0<<" "<<0<<endl;return;}
                if(table[0][0]==1 && table[1][1]==1 && table[1][2]==2){cout<<2<<" "<<2<<endl;return;}
                if(table[0][0]==1 && table[1][1]==1 && table[2][2]==2){cout<<1<<" "<<2<<endl;return;}
                if(table[0][1]==1 && table[1][1]==1){cout<<1<<" "<<2<<endl;return;}
                if(table[1][2]==1 && table[1][1]==1){cout<<0<<" "<<1<<endl;return;}
                if(table[0][1]==1 && table[1][2]==1){cout<<1<<" "<<1<<endl;return;}

                if(table[1][2]==2){cout<<0<<" "<<2<<endl;return;}
                else
                {
                    if(table[1][1]==1 || table[1][0]==1){cout<<1<<" "<<2<<endl;return;}
                    if(table[0][1]==1 || table[0][0]==1){cout<<0<<" "<<2<<endl;return;}
                    if(table[1][1]==0){cout<<0<<" "<<0<<endl;return;}
                    else {cout<<0<<" "<<1<<endl;return;}
                }

                break;
                case 4:
                if(table[0][0]==2 && table[1][0]==2 && table[2][0]==0){cout<<2<<" "<<0<<endl;return;}
                if(table[0][0]==2 && table[1][0]==2 && table[2][1]==0){cout<<2<<" "<<1<<endl;return;}
                if(table[0][0]==2 && table[1][1]==2 && table[2][1]==0){cout<<2<<" "<<1<<endl;return;}
                if(table[0][0]==2 && table[1][1]==2 && table[2][2]==0){cout<<2<<" "<<2<<endl;return;}
                if(table[0][1]==2 && table[1][1]==2 && table[2][1]==0){cout<<2<<" "<<1<<endl;return;}
                if(table[0][1]==2 && table[1][2]==2 && table[2][2]==0){cout<<2<<" "<<2<<endl;return;}
                if(table[0][1]==2 && table[1][1]==2 && table[2][2]==0){cout<<2<<" "<<2<<endl;return;}
                if(table[0][2]==2 && table[1][2]==2 && table[2][2]==0){cout<<2<<" "<<2<<endl;return;}

                if(table[0][0]==2 && table[1][0]==0 && table[0][0]==2){cout<<1<<" "<<0<<endl;return;}
                if(table[0][0]==2 && table[1][0]==0 && table[2][1]==2){cout<<1<<" "<<0<<endl;return;}
                if(table[0][0]==2 && table[1][1]==0 && table[2][1]==2){cout<<1<<" "<<1<<endl;return;}
                if(table[0][0]==2 && table[1][1]==0 && table[2][2]==2){cout<<1<<" "<<1<<endl;return;}
                if(table[0][1]==2 && table[1][1]==0 && table[2][1]==2){cout<<1<<" "<<1<<endl;return;}
                if(table[0][1]==2 && table[1][2]==0 && table[2][2]==2){cout<<1<<" "<<2<<endl;return;}
                if(table[0][1]==2 && table[1][1]==0 && table[2][2]==2){cout<<1<<" "<<1<<endl;return;}
                if(table[0][2]==2 && table[1][2]==0 && table[2][2]==2){cout<<1<<" "<<2<<endl;return;}

                if(table[0][0]==0 && table[1][0]==2 && table[2][0]==2){cout<<0<<" "<<0<<endl;return;}
                if(table[0][0]==0 && table[1][0]==2 && table[2][1]==2){cout<<0<<" "<<0<<endl;return;}
                if(table[0][0]==0 && table[1][1]==2 && table[2][1]==2){cout<<0<<" "<<0<<endl;return;}
                if(table[0][0]==0 && table[1][1]==2 && table[2][2]==2){cout<<0<<" "<<0<<endl;return;}
                if(table[0][1]==0 && table[1][1]==2 && table[2][1]==2){cout<<0<<" "<<1<<endl;return;}
                if(table[0][1]==0 && table[1][2]==2 && table[2][2]==2){cout<<0<<" "<<1<<endl;return;}
                if(table[0][1]==0 && table[1][1]==2 && table[2][2]==2){cout<<0<<" "<<1<<endl;return;}
                if(table[0][2]==0 && table[1][2]==2 && table[2][2]==2){cout<<0<<" "<<2<<endl;return;}


                if(table[0][0]==1 && table[0][1]==1 && table[0][2]==0){cout<<0<<" "<<2<<endl;return;}
                if(table[0][0]==1 && table[0][1]==1 && table[1][2]==0){cout<<1<<" "<<2<<endl;return;}
                if(table[0][0]==1 && table[1][1]==1 && table[1][2]==0){cout<<1<<" "<<2<<endl;return;}
                if(table[0][0]==1 && table[1][1]==1 && table[2][2]==0){cout<<2<<" "<<2<<endl;return;}
                if(table[1][0]==1 && table[1][1]==1 && table[1][2]==0){cout<<1<<" "<<2<<endl;return;}
                if(table[1][0]==1 && table[2][1]==1 && table[2][2]==0){cout<<2<<" "<<2<<endl;return;}
                if(table[1][0]==1 && table[1][1]==1 && table[2][2]==0){cout<<2<<" "<<2<<endl;return;}
                if(table[2][0]==1 && table[2][1]==1 && table[2][2]==0){cout<<2<<" "<<2<<endl;return;}

                if(table[0][0]==1 && table[0][1]==0 && table[0][2]==1){cout<<0<<" "<<1<<endl;return;}
                if(table[0][0]==1 && table[0][1]==0 && table[1][2]==1){cout<<0<<" "<<1<<endl;return;}
                if(table[0][0]==1 && table[1][1]==0 && table[1][2]==1){cout<<1<<" "<<1<<endl;return;}
                if(table[0][0]==1 && table[1][1]==0 && table[2][2]==1){cout<<1<<" "<<1<<endl;return;}
                if(table[1][0]==1 && table[1][1]==0 && table[1][2]==1){cout<<1<<" "<<1<<endl;return;}
                if(table[1][0]==1 && table[2][1]==0 && table[2][2]==1){cout<<2<<" "<<1<<endl;return;}
                if(table[1][0]==1 && table[1][1]==0 && table[2][2]==1){cout<<1<<" "<<1<<endl;return;}
                if(table[2][0]==1 && table[2][1]==0 && table[2][2]==1){cout<<2<<" "<<1<<endl;return;}

                if(table[0][0]==0 && table[0][1]==1 && table[0][2]==1){cout<<0<<" "<<0<<endl;return;}
                if(table[0][0]==0 && table[0][1]==1 && table[1][2]==1){cout<<0<<" "<<0<<endl;return;}
                if(table[0][0]==0 && table[1][1]==1 && table[1][2]==1){cout<<0<<" "<<0<<endl;return;}
                if(table[0][0]==0 && table[1][1]==1 && table[2][2]==1){cout<<0<<" "<<0<<endl;return;}
                if(table[1][0]==0 && table[1][1]==1 && table[1][2]==1){cout<<1<<" "<<0<<endl;return;}
                if(table[1][0]==0 && table[2][1]==1 && table[2][2]==1){cout<<1<<" "<<0<<endl;return;}
                if(table[1][0]==0 && table[1][1]==1 && table[2][2]==1){cout<<1<<" "<<0<<endl;return;}
                if(table[2][0]==0 && table[2][1]==1 && table[2][2]==1){cout<<2<<" "<<0<<endl;return;}

                for(int i=0;i<N;i++)
                    for(int j=0;j<N;j++)
                    {
                        if(table[i][j]==0){cout<<i<<" "<<j<<endl;return;}
                    }
                break;
                case 2:
                if(table[0][0]==2 && table[1][0]==2 && table[2][0]==0){cout<<2<<" "<<0<<endl;return;}
                if(table[0][0]==2 && table[1][0]==2 && table[2][1]==0){cout<<2<<" "<<1<<endl;return;}
                if(table[0][0]==2 && table[1][1]==2 && table[2][1]==0){cout<<2<<" "<<1<<endl;return;}
                if(table[0][0]==2 && table[1][1]==2 && table[2][2]==0){cout<<2<<" "<<2<<endl;return;}
                if(table[0][1]==2 && table[1][1]==2 && table[2][1]==0){cout<<2<<" "<<1<<endl;return;}
                if(table[0][1]==2 && table[1][2]==2 && table[2][2]==0){cout<<2<<" "<<2<<endl;return;}
                if(table[0][1]==2 && table[1][1]==2 && table[2][2]==0){cout<<2<<" "<<2<<endl;return;}
                if(table[0][2]==2 && table[1][2]==2 && table[2][2]==0){cout<<2<<" "<<2<<endl;return;}

                if(table[0][0]==2 && table[1][0]==0 && table[0][0]==2){cout<<1<<" "<<0<<endl;return;}
                if(table[0][0]==2 && table[1][0]==0 && table[2][1]==2){cout<<1<<" "<<0<<endl;return;}
                if(table[0][0]==2 && table[1][1]==0 && table[2][1]==2){cout<<1<<" "<<1<<endl;return;}
                if(table[0][0]==2 && table[1][1]==0 && table[2][2]==2){cout<<1<<" "<<1<<endl;return;}
                if(table[0][1]==2 && table[1][1]==0 && table[2][1]==2){cout<<1<<" "<<1<<endl;return;}
                if(table[0][1]==2 && table[1][2]==0 && table[2][2]==2){cout<<1<<" "<<2<<endl;return;}
                if(table[0][1]==2 && table[1][1]==0 && table[2][2]==2){cout<<1<<" "<<1<<endl;return;}
                if(table[0][2]==2 && table[1][2]==0 && table[2][2]==2){cout<<1<<" "<<2<<endl;return;}

                if(table[0][0]==0 && table[1][0]==2 && table[2][0]==2){cout<<0<<" "<<0<<endl;return;}
                if(table[0][0]==0 && table[1][0]==2 && table[2][1]==2){cout<<0<<" "<<0<<endl;return;}
                if(table[0][0]==0 && table[1][1]==2 && table[2][1]==2){cout<<0<<" "<<0<<endl;return;}
                if(table[0][0]==0 && table[1][1]==2 && table[2][2]==2){cout<<0<<" "<<0<<endl;return;}
                if(table[0][1]==0 && table[1][1]==2 && table[2][1]==2){cout<<0<<" "<<1<<endl;return;}
                if(table[0][1]==0 && table[1][2]==2 && table[2][2]==2){cout<<0<<" "<<1<<endl;return;}
                if(table[0][1]==0 && table[1][1]==2 && table[2][2]==2){cout<<0<<" "<<1<<endl;return;}
                if(table[0][2]==0 && table[1][2]==2 && table[2][2]==2){cout<<0<<" "<<2<<endl;return;}


                if(table[0][0]==1 && table[0][1]==1 && table[0][2]==0){cout<<0<<" "<<2<<endl;return;}
                if(table[0][0]==1 && table[0][1]==1 && table[1][2]==0){cout<<1<<" "<<2<<endl;return;}
                if(table[0][0]==1 && table[1][1]==1 && table[1][2]==0){cout<<1<<" "<<2<<endl;return;}
                if(table[0][0]==1 && table[1][1]==1 && table[2][2]==0){cout<<2<<" "<<2<<endl;return;}
                if(table[1][0]==1 && table[1][1]==1 && table[1][2]==0){cout<<1<<" "<<2<<endl;return;}
                if(table[1][0]==1 && table[2][1]==1 && table[2][2]==0){cout<<2<<" "<<2<<endl;return;}
                if(table[1][0]==1 && table[1][1]==1 && table[2][2]==0){cout<<2<<" "<<2<<endl;return;}
                if(table[2][0]==1 && table[2][1]==1 && table[2][2]==0){cout<<2<<" "<<2<<endl;return;}

                if(table[0][0]==1 && table[0][1]==0 && table[0][2]==1){cout<<0<<" "<<1<<endl;return;}
                if(table[0][0]==1 && table[0][1]==0 && table[1][2]==1){cout<<0<<" "<<1<<endl;return;}
                if(table[0][0]==1 && table[1][1]==0 && table[1][2]==1){cout<<1<<" "<<1<<endl;return;}
                if(table[0][0]==1 && table[1][1]==0 && table[2][2]==1){cout<<1<<" "<<1<<endl;return;}
                if(table[1][0]==1 && table[1][1]==0 && table[1][2]==1){cout<<1<<" "<<1<<endl;return;}
                if(table[1][0]==1 && table[2][1]==0 && table[2][2]==1){cout<<2<<" "<<1<<endl;return;}
                if(table[1][0]==1 && table[1][1]==0 && table[2][2]==1){cout<<1<<" "<<1<<endl;return;}
                if(table[2][0]==1 && table[2][1]==0 && table[2][2]==1){cout<<2<<" "<<1<<endl;return;}

                if(table[0][0]==0 && table[0][1]==1 && table[0][2]==1){cout<<0<<" "<<0<<endl;return;}
                if(table[0][0]==0 && table[0][1]==1 && table[1][2]==1){cout<<0<<" "<<0<<endl;return;}
                if(table[0][0]==0 && table[1][1]==1 && table[1][2]==1){cout<<0<<" "<<0<<endl;return;}
                if(table[0][0]==0 && table[1][1]==1 && table[2][2]==1){cout<<0<<" "<<0<<endl;return;}
                if(table[1][0]==0 && table[1][1]==1 && table[1][2]==1){cout<<1<<" "<<0<<endl;return;}
                if(table[1][0]==0 && table[2][1]==1 && table[2][2]==1){cout<<1<<" "<<0<<endl;return;}
                if(table[1][0]==0 && table[1][1]==1 && table[2][2]==1){cout<<1<<" "<<0<<endl;return;}
                if(table[2][0]==0 && table[2][1]==1 && table[2][2]==1){cout<<2<<" "<<0<<endl;return;}

                for(int i=0;i<N;i++)
                    for(int j=0;j<N;j++)
                    {
                        if(table[i][j]==0){cout<<i<<" "<<j<<endl;return;}
                    }
                break;
            }
        }

        else
        {
            int br1=0,lastI,lastJ,Si=-1,Sj=-1,Fi,Fj;
            for(int i=0;i<N;i++)
                    for(int j=0;j<N;j++)
                    {
                        if(table[i][j]==1){br1++;Fi=i;Fj=j;}
                        if(table[i][j]==2){if(Si==-1)Si=i;if(Sj==-1)Sj=j;lastI=i;lastJ=j;}
                    }
                   if(br1==1)
                   {
                       int SecI,SecJ;
                       if(Fi<=N/2)SecI=Fi+1;
                       if(Fi>N/2)SecI=Fi-1;
                       if(Fj<=N/2)SecJ=Fj+2;
                       if(Fj>N/2)SecJ=Fj-2;
                       cout<<SecI<<" "<<SecJ<<endl;
                       return;
                   }
                   else
                   {
                            if(Si>0 && Sj>0 && table[Si-1][Sj-1]==1 && table[Si-1][Sj]==0)
                           {cout<<Si-1<<" "<<Sj<<endl;return;}
                           if(Si>0 && Sj>0 && table[Si-1][Sj-1]==0 && table[Si-1][Sj]==1)
                           {cout<<Si-1<<" "<<Sj-1<<endl;return;}
                           if(lastI<N-1 && lastJ<N-1 && table[lastI+1][lastJ+1]==1 && table[lastI+1][lastJ]==0)
                           {cout<<lastI+1<<" "<<lastJ<<endl;return;}
                           if(lastI<N-1 && lastJ<N-1 && table[lastI+1][lastJ+1]==0 && table[lastI+1][lastJ]==1)
                           {cout<<lastI+1<<" "<<lastJ+1<<endl;return;}

                            if(Sj<N-1 && Si>0 && table[Si][Sj+1]==1 && table[Si-1][Sj]==0){cout<<Si-1<<" "<<Sj<<endl;return;}
                            if(lastI<N-1 && lastJ>0 && table[lastI][lastJ-1]==1 && table[lastI+1][lastJ]==0){cout<<lastI+1<<" "<<lastJ<<endl;return;}

                            if(Si > N-1-lastI && Si>0 && table[Si-1][Sj]==0){cout<<Si-1<<" "<<Sj<<endl;return;}
                       if(Si > N-1-lastI && Si>0 && Sj>0 && table[Si-1][Sj-1]==0){cout<<Si-1<<" "<<Sj-1<<endl;return;}
                       if(Si <= N-1-lastI && lastI<N-1 && table[lastI+1][lastJ]==0){cout<<lastI+1<<" "<<lastJ<<endl;return;}
                       if(Si <= N-1-lastI && lastI<N-1 && lastJ<N-1 && table[lastI+1][lastJ+1]==0){cout<<lastI+1<<" "<<lastJ+1<<endl;return;}

                       if(Si>0)
                       {
                          for(int j=0;j<N;j++)
                            {
                                if(table[Si-1][j]==1 && table[Si-1][Sj]==0){cout<<Si-1<<" "<<Sj<<endl;return;}

                            }
                       }
                       if(lastI<N-1)
                       {
                          for(int j=0;j<N;j++)
                            {
                                if(table[lastI+1][j]==1 && table[lastI+1][lastJ]==0){cout<<lastI+1<<" "<<lastJ<<endl;return;}

                            }
                       }


                    for(int i=0;i<N;i++)
                    {
                        int br1=0,br2=0,lj=0;
                        for(int j=0;j<N;j++)
                        {
                            if(table[i][j]==1){br1++;lj=j;}
                            if(table[i][j]==2)br2++;
                        }
                        if(br2==0 && br1>0 && lj+2<N && table[i][lj+2]==0){cout<<i<<" "<<lj+2<<endl;return;}
                        if(br2==0 && br1>0 && lj+2>N )
                        {
                            for(int k=1;k<=lj;k++)
                            if(table[i][lj-k]==0){cout<<i<<" "<<lj-k<<endl;return;}
                        }

                    }
                    for(int i=0;i<N;i++)
                        for(int j=0;j<N;j++)
                        {
                            if(table[i][j]==1)
                            {
                                if(i+1<N && table[i+1][j]==0){cout<<i+1<<" "<<j<<endl;return;}
                                if(i+1<N && j+1<N && table[i+1][j+1]==0){cout<<i+1<<" "<<j+1<<endl;return;}
                                if(i-1>=0 && table[i-1][j]==0){cout<<i-1<<" "<<j<<endl;return;}
                                if(i-1>=0 && j-1>=0 && table[i-1][j-1]==0){cout<<i-1<<" "<<j-1<<endl;return;}
                            }


                        }
                        for(int i=0;i<N;i++)


                        for(int j=0;j<N;j++)
                        {
                            if(table[i][j]==0)
                            {
                                {cout<<i<<" "<<j<<endl;return;}
                            }


                        }

                   }
        }
    }



}

int main()
{
    cin>>N>>K;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        cin>>table[i][j];
        game();
    /*switch (N)
    {
        case 3:
            if(K==1)Connect_Game_3x3_Pl1();
            if(K==2)Connect_Game_3x3_Pl2();
            break;
        case 7:
            if(K==1)Connect_Game_7x7_Pl1();
            if(K==2)Connect_Game_7x7_Pl2();
            break;
        case 10:
            if(K==1)Connect_Game_10x10_Pl1();
            if(K==2)Connect_Game_10x10_Pl2();
            break;
        default:
        break;

    }*/
    return 0;
}
