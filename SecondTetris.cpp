#include<iostream>
using namespace std;
bool Tetris[25][15];
int brR[25],brC[25];
void Print()
{
    cout<<endl;
    for(int i=20;i>=1;i--)
    {
        for(int j=1;j<=10;j++)
        {
            cout<<Tetris[i][j]<<" ";
        }
        cout<<endl;
    }
}
void RemoveLine(int k)
{




            for(int i=k;i<20;i++)
            {
                if(brR[i+1]==0)break;
                for(int j=1;j<=10;j++)
                {
                    Tetris[i][j]=Tetris[i+1][j];

                }
                brR[i]=brR[i+1];
            }
        brR[k]=0;
        return;

}
void Fill(int i1,int j1,int i2,int j2,int i3,int j3,int i4,int j4)
{
    Tetris[i1][j1]=1;
    Tetris[i2][j2]=1;
    Tetris[i3][j3]=1;
    Tetris[i4][j4]=1;
    brR[i1]++;if(brR[i1]==10)RemoveLine(i1);
    brR[i2]++;if(brR[i2]==10)RemoveLine(i2);
    brR[i3]++;if(brR[i3]==10)RemoveLine(i3);
    brR[i4]++;if(brR[i4]==10)RemoveLine(i4);
    brC[j1]++;
    brC[j2]++;
    brC[j3]++;
    brC[j4]++;
    return;
}

void Type1()
{
    //Rotation 1
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=7;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i][j+2]==0 && Tetris[i][j+3]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i-1][j+2]+ Tetris[i-1][j+3]==4){
            cout<<1<<" "<<j-1;Fill(i,j,i,j+1,i,j+2,i,j+3);return;}
        }
    }
    //Rotation 0
    for(int i=1;i<=17;i++)
    {
        for(int j=1;j<=10;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+2][j]==0 && Tetris[i+3][j]==0 && Tetris[i-1][j]==1 &&
               Tetris[i][j+1]+ Tetris[i+1][j+1]+ Tetris[i+2][j+1]+ Tetris[i+3][j+1]==4){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+2,j,i+3,j);return;}
        }
    }
    //Rotation 0
    for(int i=1;i<=17;i++)
    {
        for(int j=1;j<=10;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+2][j]==0 && Tetris[i+3][j]==0 && Tetris[i-1][j]==1 &&
               Tetris[i][j+1]+ Tetris[i+1][j+1]+ Tetris[i+2][j+1]+ Tetris[i+3][j+1]==3){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+2,j,i+3,j);return;}
        }
    }//Rotation 0
    for(int i=1;i<=17;i++)
    {
        for(int j=1;j<=10;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+2][j]==0 && Tetris[i+3][j]==0 && Tetris[i-1][j]==1 &&
               Tetris[i][j+1]+ Tetris[i+1][j+1]+ Tetris[i+2][j+1]+ Tetris[i+3][j+1]==2){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+2,j,i+3,j);return;}
        }
    }
    //Rotation 1
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=7;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i][j+2]==0 && Tetris[i][j+3]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i-1][j+2]+ Tetris[i-1][j+3]==3){
            cout<<1<<" "<<j-1;Fill(i,j,i,j+1,i,j+2,i,j+3);return;}
        }
    }
    //Rotation 0
    for(int i=1;i<=17;i++)
    {
        for(int j=1;j<=10;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+2][j]==0 && Tetris[i+3][j]==0 && Tetris[i-1][j]==1 &&
                Tetris[i][j+1]+ Tetris[i+1][j+1]+ Tetris[i+2][j+1]+ Tetris[i+3][j+1]==1){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+2,j,i+3,j);return;}
        }
    }
    //Rotation 1
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=7;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i][j+2]==0 && Tetris[i][j+3]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i-1][j+2]+ Tetris[i-1][j+3]==2){
            cout<<1<<" "<<j-1;Fill(i,j,i,j+1,i,j+2,i,j+3);return;}
        }
    }
    //Rotation 0
    for(int i=1;i<=17;i++)
    {
        for(int j=1;j<=10;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+2][j]==0 && Tetris[i+3][j]==0 && Tetris[i-1][j]==1 &&
               Tetris[i][j+1]+ Tetris[i+1][j+1]+ Tetris[i+2][j+1]+ Tetris[i+3][j+1]==0){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+2,j,i+3,j);return;}
        }
    }
    //Rotation 1
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=7;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i][j+2]==0 && Tetris[i][j+3]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i-1][j+2]+ Tetris[i-1][j+3]==1){
            cout<<1<<" "<<j-1;Fill(i,j,i,j+1,i,j+2,i,j+3);return;}
        }
    }
    //Rotation 1
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=7;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i][j+2]==0 && Tetris[i][j+3]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i-1][j+2]+ Tetris[i-1][j+3]==0){
            cout<<1<<" "<<j-1;Fill(i,j,i,j+1,i,j+2,i,j+3);return;}
        }
    }
    cout<<0<<" "<<0<<endl;
    return;
}
void Type2()
{
    //Rotation 0
    for(int i=1;i<=18;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+2][j]==0 && Tetris[i+2][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i][j+1]+ Tetris[i+1][j+1]+ Tetris[i+2][j+2]==4){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+2,j,i+2,j+1);return;}
        }
    }
    //Rotation 1
    for(int i=2;i<=20;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i][j+2]==0 && Tetris[i-1][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i-2][j+2]+ Tetris[i-1][j+3]==4){
            cout<<1<<" "<<j-1;Fill(i,j,i,j+1,i,j+2,i-1,j+2);return;}
        }
    }
    //Rotation 3
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i][j+1]==0 && Tetris[i][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i-1][j+2]+ Tetris[i][j+3]==4){
            cout<<3<<" "<<j-1;Fill(i,j,i+1,j,i,j+1,i,j+2);return;}
        }
    }
    //Rotation 2
    for(int i=1;i<=18;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i+1][j+1]==0 && Tetris[i+2][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==4){
            cout<<2<<" "<<j-1;Fill(i,j,i,j+1,i+1,j+1,i+2,j+1);return;}
        }
    }

    //Rotation 2
    for(int i=1;i<=18;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i+1][j+1]==0 && Tetris[i+2][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==3){
            cout<<2<<" "<<j-1;Fill(i,j,i,j+1,i+1,j+1,i+2,j+1);return;}
        }
    }
    //Rotation 2
    for(int i=1;i<=18;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i+1][j+1]==0 && Tetris[i+2][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==2){
            cout<<2<<" "<<j-1;Fill(i,j,i,j+1,i+1,j+1,i+2,j+1);return;}
        }
    }
    //Rotation 3
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i][j+1]==0 && Tetris[i][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i-1][j+2]+ Tetris[i][j+3]==3){
            cout<<3<<" "<<j-1;Fill(i,j,i+1,j,i,j+1,i,j+2);return;}
        }
    }
    //Rotation 1
    for(int i=2;i<=20;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i][j+2]==0 && Tetris[i-1][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i-2][j+2]+ Tetris[i-1][j+3]==3){
            cout<<1<<" "<<j-1;Fill(i,j,i,j+1,i,j+2,i-1,j+2);return;}
        }
    }
    //Rotation 0
    for(int i=1;i<=18;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+2][j]==0 && Tetris[i+2][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i][j+1]+ Tetris[i+1][j+1]+ Tetris[i+2][j+2]==3){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+2,j,i+2,j+1);return;}
        }
    }
    //Rotation 0
    for(int i=1;i<=18;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+2][j]==0 && Tetris[i+2][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i][j+1]+ Tetris[i+1][j+1]+ Tetris[i+2][j+2]==2){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+2,j,i+2,j+1);return;}
        }
    }
    //Rotation 1
    for(int i=2;i<=20;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i][j+2]==0 && Tetris[i-1][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i-2][j+2]+ Tetris[i-1][j+3]==2){
            cout<<1<<" "<<j-1;Fill(i,j,i,j+1,i,j+2,i-1,j+2);return;}
        }
    }
    //Rotation 1
    for(int i=2;i<=20;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i][j+2]==0 && Tetris[i-1][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i-2][j+2]+ Tetris[i-1][j+3]==1){
            cout<<1<<" "<<j-1;Fill(i,j,i,j+1,i,j+2,i-1,j+2);return;}
        }
    }
    //Rotation 0
    for(int i=1;i<=18;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+2][j]==0 && Tetris[i+2][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i][j+1]+ Tetris[i+1][j+1]+ Tetris[i+2][j+2]==1){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+2,j,i+2,j+1);return;}
        }
    }
    //Rotation 3
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i][j+1]==0 && Tetris[i][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i-1][j+2]+ Tetris[i][j+3]==2){
            cout<<3<<" "<<j-1;Fill(i,j,i+1,j,i,j+1,i,j+2);return;}
        }
    }
    //Rotation 3
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i][j+1]==0 && Tetris[i][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i-1][j+2]+ Tetris[i][j+3]==1){
           cout<<3<<" "<<j-1;Fill(i,j,i+1,j,i,j+1,i,j+2);return;}
        }
    }
    //Rotation 2
    for(int i=1;i<=18;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i+1][j+1]==0 && Tetris[i+2][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==1){
            cout<<2<<" "<<j-1;Fill(i,j,i,j+1,i+1,j+1,i+2,j+1);return;}
        }
    }
    //Rotation 2
    for(int i=1;i<=18;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i+1][j+1]==0 && Tetris[i+2][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==0){
            cout<<2<<" "<<j-1;Fill(i,j,i,j+1,i+1,j+1,i+2,j+1);return;}
        }
    }
    //Rotation 3
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i][j+1]==0 && Tetris[i][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i-1][j+2]+ Tetris[i][j+3]==0){
            cout<<3<<" "<<j-1;Fill(i,j,i+1,j,i,j+1,i,j+2);return;}
        }
    }
    //Rotation 0
    for(int i=1;i<=18;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+2][j]==0 && Tetris[i+2][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i][j+1]+ Tetris[i+1][j+1]+ Tetris[i+2][j+2]==0){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+2,j,i+2,j+1);return;}
        }
    }
    //Rotation 1
    for(int i=2;i<=20;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i][j+2]==0 && Tetris[i-1][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i-2][j+2]+ Tetris[i-1][j+3]==0){
            cout<<1<<" "<<j-1;Fill(i,j,i,j+1,i,j+2,i-1,j+2);return;}
        }
    }
}
void Type3()
{
    //Rotation 0
    for(int i=3;i<=19;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i-1][j+1]==0 && Tetris[i-2][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-2][j]+ Tetris[i-3][j+1]+ Tetris[i-2][j+2]==4){
            cout<<0<<" "<<j-1;Fill(i,j,i,j+1,i-1,j+1,i-2,j+1);return;}
        }
    }
    //Rotation 3
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+1][j+1]==0 && Tetris[i+1][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+3]==4){
            cout<<3<<" "<<j-1;Fill(i,j,i+1,j,i+1,j+1,i+1,j+2);return;}
        }
    }
    //Rotation 1
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i][j+2]==0 && Tetris[i+1][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i-2][j+2]+ Tetris[i][j+3]==4){
            cout<<1<<" "<<j-1; Fill(i,j,i,j+1,i,j+2,i+1,j+2);return;}
        }
    }
    //Rotation 2
    for(int i=1;i<=18;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+2][j]==0 && Tetris[i][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==4){
            cout<<2<<" "<<j-1;Fill(i,j,i+1,j,i+2,j,i,j+1);return;}
        }
    }
    //Rotation 2
    for(int i=1;i<=18;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+2][j]==0 && Tetris[i][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==3){
            cout<<2<<" "<<j-1;Fill(i,j,i+1,j,i+2,j,i,j+1);return;}
        }
    }
    //Rotation 2
    for(int i=1;i<=18;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+2][j]==0 && Tetris[i][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==2){
            cout<<2<<" "<<j-1;Fill(i,j,i+1,j,i+2,j,i,j+1);return;}
        }
    }
    //Rotation 0
    for(int i=3;i<=19;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i-1][j+1]==0 && Tetris[i-2][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-2][j]+ Tetris[i-3][j+1]+ Tetris[i-2][j+2]==3){
            cout<<0<<" "<<j-1;Fill(i,j,i,j+1,i-1,j+1,i-2,j+1);return;}
        }
    }
    //Rotation 3
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+1][j+1]==0 && Tetris[i+1][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+3]==3){
            cout<<3<<" "<<j-1;Fill(i,j,i+1,j,i+1,j+1,i+1,j+2);return;}
        }
    }
    //Rotation 1
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i][j+2]==0 && Tetris[i+1][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i-2][j+2]+ Tetris[i][j+3]==3){
            cout<<1<<" "<<j-1;Fill(i,j,i,j+1,i,j+2,i+1,j+2);return;}
        }
    }
    //Rotation 0
    for(int i=3;i<=19;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i-1][j+1]==0 && Tetris[i-2][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-2][j]+ Tetris[i-3][j+1]+ Tetris[i-2][j+2]==2){
            cout<<0<<" "<<j-1;Fill(i,j,i,j+1,i-1,j+1,i-2,j+1);return;}
        }
    }
    //Rotation 0
    for(int i=3;i<=19;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i-1][j+1]==0 && Tetris[i-2][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-2][j]+ Tetris[i-3][j+1]+ Tetris[i-2][j+2]==1){
            cout<<0<<" "<<j-1;Fill(i,j,i,j+1,i-1,j+1,i-2,j+1);return;}
        }
    }
    //Rotation 3
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+1][j+1]==0 && Tetris[i+1][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+3]==2){
            cout<<3<<" "<<j-1;Fill(i,j,i+1,j,i+1,j+1,i+1,j+2);return;}
        }
    }
    //Rotation 3
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+1][j+1]==0 && Tetris[i+1][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+3]==1){
            cout<<3<<" "<<j-1;Fill(i,j,i+1,j,i+1,j+1,i+1,j+2);return;}
        }
    }
    //Rotation 2
    for(int i=1;i<=18;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+2][j]==0 && Tetris[i][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==1){
            cout<<2<<" "<<j-1;Fill(i,j,i+1,j,i+2,j,i,j+1);return;}
        }
    }
    //Rotation 2
    for(int i=1;i<=18;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+2][j]==0 && Tetris[i][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==0){
            cout<<2<<" "<<j-1;Fill(i,j,i+1,j,i+2,j,i,j+1);return;}
        }
    }
    //Rotation 0
    for(int i=3;i<=19;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i-1][j+1]==0 && Tetris[i-2][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-2][j]+ Tetris[i-3][j+1]+ Tetris[i-2][j+2]==0){
            cout<<0<<" "<<j-1;Fill(i,j,i,j+1,i-1,j+1,i-2,j+1);return;}
        }
    }
    //Rotation 3
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+1][j+1]==0 && Tetris[i+1][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+3]==0){
            cout<<3<<" "<<j-1;Fill(i,j,i+1,j,i+1,j+1,i+1,j+2);return;}
        }
    }
    //Rotation 1
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i][j+2]==0 && Tetris[i+1][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i-2][j+2]+ Tetris[i][j+3]==0){
            cout<<1<<" "<<j-1;Fill(i,j,i,j+1,i,j+2,i+1,j+2);return;}
        }
    }

}
void Type4()
{
    //Rotation 0
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+1][j+1]==0 && Tetris[i][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==4){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+1,j+1,i,j+1);return;}
        }
    }
    //Rotation 0
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+1][j+1]==0 && Tetris[i][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==3){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+1,j+1,i,j+1);return;}
        }
    }
    //Rotation 0
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+1][j+1]==0 && Tetris[i][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==2){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+1,j+1,i,j+1);return;}
        }
    }
    //Rotation 0
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+1][j+1]==0 && Tetris[i][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==1){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+1,j+1,i,j+1);return;}
        }
    }


    //Rotation 0
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+1][j+1]==0 && Tetris[i][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==0){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+1,j+1,i,j+1);return;}
        }
    }
}
void Type5()
{
    //Rotation 0
    for(int i=2;i<=19;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i][j+1]==0 && Tetris[i-1][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-2][j+1]+ Tetris[i][j+2]+ Tetris[i-1][j+2]==4){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i,j+1,i-1,j+1);return;}
        }
    }
    //Rotation 1
    for(int i=2;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i+1][j+1]==0 && Tetris[i+1][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i][j+2]+ Tetris[i][j+3]==4){
            cout<<1<<" "<<j-1;Fill(i,j,i,j+1,i+1,j+1,i+1,j+2);return;}
        }
    }
    //Rotation 0
    for(int i=2;i<=19;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i][j+1]==0 && Tetris[i-1][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-2][j+1]+ Tetris[i][j+2]+ Tetris[i-1][j+2]==3){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i,j+1,i-1,j+1);return;}
        }
    }
    //Rotation 0
    for(int i=2;i<=19;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i][j+1]==0 && Tetris[i-1][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-2][j+1]+ Tetris[i][j+2]+ Tetris[i-1][j+2]==2){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i,j+1,i-1,j+1);return;}
        }
    }
     //Rotation 1
    for(int i=2;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i+1][j+1]==0 && Tetris[i+1][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i][j+2]+ Tetris[i][j+3]==3){
            cout<<1<<" "<<j-1;Fill(i,j,i,j+1,i+1,j+1,i+1,j+2);return;}
        }
    }
    //Rotation 0
    for(int i=2;i<=19;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i][j+1]==0 && Tetris[i-1][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-2][j+1]+ Tetris[i][j+2]+ Tetris[i-1][j+2]==1){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i,j+1,i-1,j+1);return;}
        }
    }
    //Rotation 1
    for(int i=2;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i+1][j+1]==0 && Tetris[i+1][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i][j+2]+ Tetris[i][j+3]==2){
            cout<<1<<" "<<j-1;Fill(i,j,i,j+1,i+1,j+1,i+1,j+2);return;}
        }
    }
    //Rotation 1
    for(int i=2;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i+1][j+1]==0 && Tetris[i+1][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i][j+2]+ Tetris[i][j+3]==1){
            cout<<1<<" "<<j-1;Fill(i,j,i,j+1,i+1,j+1,i+1,j+2);return;}
        }
    }
    //Rotation 1
    for(int i=2;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i+1][j+1]==0 && Tetris[i+1][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i][j+2]+ Tetris[i][j+3]==0){
            cout<<1<<" "<<j-1;Fill(i,j,i,j+1,i+1,j+1,i+1,j+2);return;}
        }
    }
    //Rotation 0
    for(int i=2;i<=19;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i][j+1]==0 && Tetris[i-1][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-2][j+1]+ Tetris[i][j+2]+ Tetris[i-1][j+2]==0){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i,j+1,i-1,j+1);return;}
        }
    }
}
void Type6()
{


    //Rotation 1
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+1][j+1]==0 && Tetris[i+2][j]==0 &&
               Tetris[i-1][j]+ Tetris[i-2][j+1]+ Tetris[i-1][j+2]+ Tetris[i][j+2]==4){
            cout<<1<<" "<<j-1;Fill(i,j,i+1,j,i+1,j+1,i+2,j);return;}
        }
    }
    //Rotation 0
    for(int i=3;i<=19;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+1][j+1]==0 && Tetris[i+2][j]==0 &&
               Tetris[i-1][j]+ Tetris[i][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==4){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+1,j+1,i+2,j);return;}
        }
    }
    //Rotation 2
    for(int i=1;i<=18;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i+1][j+1]==0 && Tetris[i-1][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-2][j+1]+ Tetris[i-1][j+2]+ Tetris[i][j+2]==4){
            cout<<2<<" "<<j-1;Fill(i,j,i,j+1,i+1,j+1,i-1,j+1);return;}
        }
    }
    //Rotation 3
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i][j+2]==0 && Tetris[i+1][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i-1][j+2]+ Tetris[i][j+3]==4){
            cout<<3<<" "<<j-1;Fill(i,j,i,j+1,i,j+2,i+1,j+1);return;}
        }
    }
    //Rotation 1
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+1][j+1]==0 && Tetris[i+2][j]==0 &&
               Tetris[i-1][j]+ Tetris[i-2][j+1]+ Tetris[i-1][j+2]+ Tetris[i][j+2]==3){
            cout<<1<<" "<<j-1;Fill(i,j,i+1,j,i+1,j+1,i+2,j);return;}
        }
    }
    //Rotation 0
    for(int i=3;i<=19;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+1][j+1]==0 && Tetris[i+2][j]==0 &&
               Tetris[i-1][j]+ Tetris[i][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==3){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+1,j+1,i+2,j);return;}
        }
    }
    //Rotation 2
    for(int i=1;i<=18;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i+1][j+1]==0 && Tetris[i-1][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-2][j+1]+ Tetris[i-1][j+2]+ Tetris[i][j+2]==3){
            cout<<2<<" "<<j-1;Fill(i,j,i,j+1,i+1,j+1,i-1,j+1);return;}
        }
    }
    //Rotation 0
    for(int i=3;i<=19;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+1][j+1]==0 && Tetris[i+2][j]==0 &&
               Tetris[i-1][j]+ Tetris[i][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==2){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+1,j+1,i+2,j);return;}
        }
    }
    //Rotation 2
    for(int i=1;i<=18;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i+1][j+1]==0 && Tetris[i-1][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-2][j+1]+ Tetris[i-1][j+2]+ Tetris[i][j+2]==2){
            cout<<2<<" "<<j-1;Fill(i,j,i,j+1,i+1,j+1,i-1,j+1);return;}
        }
    }
    //Rotation 3
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i][j+2]==0 && Tetris[i+1][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i-1][j+2]+ Tetris[i][j+3]==3){
            cout<<3<<" "<<j-1;Fill(i,j,i,j+1,i,j+2,i+1,j+1);return;}
        }
    }
    //Rotation 1
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+1][j+1]==0 && Tetris[i+2][j]==0 &&
               Tetris[i-1][j]+ Tetris[i-2][j+1]+ Tetris[i-1][j+2]+ Tetris[i][j+2]==2){
            cout<<1<<" "<<j-1;Fill(i,j,i+1,j,i+1,j+1,i+2,j);return;}
        }
    }
    //Rotation 1
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+1][j+1]==0 && Tetris[i+2][j]==0 &&
               Tetris[i-1][j]+ Tetris[i-2][j+1]+ Tetris[i-1][j+2]+ Tetris[i][j+2]==1){
            cout<<1<<" "<<j-1;Fill(i,j,i+1,j,i+1,j+1,i+2,j);return;}
        }
    }
    //Rotation 0
    for(int i=3;i<=19;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+1][j+1]==0 && Tetris[i+2][j]==0 &&
               Tetris[i-1][j]+ Tetris[i][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==1){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+1,j+1,i+2,j);return;}
        }
    }
    //Rotation 2
    for(int i=1;i<=18;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i+1][j+1]==0 && Tetris[i-1][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-2][j+1]+ Tetris[i-1][j+2]+ Tetris[i][j+2]==1){
            cout<<2<<" "<<j-1;Fill(i,j,i,j+1,i+1,j+1,i-1,j+1);return;}
        }
    }
    //Rotation 0
    for(int i=3;i<=19;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+1][j+1]==0 && Tetris[i+2][j]==0 &&
               Tetris[i-1][j]+ Tetris[i][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==0){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+1,j+1,i+2,j);return;}
        }
    }
    //Rotation 2
    for(int i=1;i<=18;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i+1][j+1]==0 && Tetris[i-1][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-2][j+1]+ Tetris[i-1][j+2]+ Tetris[i][j+2]==0){
            cout<<2<<" "<<j-1;Fill(i,j,i,j+1,i+1,j+1,i-1,j+1);return;}
        }
    }
    //Rotation 3
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i][j+2]==0 && Tetris[i+1][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i-1][j+2]+ Tetris[i][j+3]==2){
            cout<<3<<" "<<j-1;Fill(i,j,i,j+1,i,j+2,i+1,j+1);return;}
        }
    }
    //Rotation 3
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i][j+2]==0 && Tetris[i+1][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i-1][j+2]+ Tetris[i][j+3]==1){
            cout<<3<<" "<<j-1;Fill(i,j,i,j+1,i,j+2,i+1,j+1);return;}
        }
    }
    //Rotation 3
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i][j+2]==0 && Tetris[i+1][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i-1][j+1]+ Tetris[i-1][j+2]+ Tetris[i][j+3]==0){
            cout<<3<<" "<<j-1;Fill(i,j,i,j+1,i,j+2,i+1,j+1);return;}
        }
    }
}
void Type7()
{
    //Rotation 1
    for(int i=2;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i-1][j+1]==0 && Tetris[i-1][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i-2][j+1]+ Tetris[i][j+2]+ Tetris[i-2][j+2]==4){
            cout<<1<<" "<<j-1;Fill(i,j,i,j+1,i-1,j+1,i-1,j+2);return;}
        }
    }
    //Rotation 0
    for(int i=2;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+1][j+1]==0 && Tetris[i+2][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==4){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+1,j+1,i+2,j+1);return;}
        }
    }
    //Rotation 0
    for(int i=2;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+1][j+1]==0 && Tetris[i+2][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==3){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+1,j+1,i+2,j+1);return;}
        }
    }
    //Rotation 0
    for(int i=2;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+1][j+1]==0 && Tetris[i+2][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==2){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+1,j+1,i+2,j+1);return;}
        }
    }
    //Rotation 1
    for(int i=2;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i-1][j+1]==0 && Tetris[i-1][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i-2][j+1]+ Tetris[i][j+2]+ Tetris[i-2][j+2]==3){
            cout<<1<<" "<<j-1;Fill(i,j,i,j+1,i-1,j+1,i-1,j+2);return;}
        }
    }
    //Rotation 1
    for(int i=2;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i-1][j+1]==0 && Tetris[i-1][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i-2][j+1]+ Tetris[i][j+2]+ Tetris[i-2][j+2]==2){
            cout<<1<<" "<<j-1;Fill(i,j,i,j+1,i-1,j+1,i-1,j+2);return;}
        }
    }
    //Rotation 1
    for(int i=2;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i-1][j+1]==0 && Tetris[i-1][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i-2][j+1]+ Tetris[i][j+2]+ Tetris[i-2][j+2]==1){
            cout<<1<<" "<<j-1;Fill(i,j,i,j+1,i-1,j+1,i-1,j+2);return;}
        }
    }
    //Rotation 0
    for(int i=2;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+1][j+1]==0 && Tetris[i+2][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==1){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+1,j+1,i+2,j+1);return;}
        }
    }
    //Rotation 0
    for(int i=2;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i+1][j]==0 && Tetris[i+1][j+1]==0 && Tetris[i+2][j+1]==0 &&
               Tetris[i-1][j]+ Tetris[i][j+1]+ Tetris[i][j+2]+ Tetris[i+1][j+2]==0){
            cout<<0<<" "<<j-1;Fill(i,j,i+1,j,i+1,j+1,i+2,j+1);return;}
        }
    }
    //Rotation 1
    for(int i=2;i<=19;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(Tetris[i][j]==0 && Tetris[i][j+1]==0 && Tetris[i-1][j+1]==0 && Tetris[i-1][j+2]==0 &&
               Tetris[i-1][j]+ Tetris[i-2][j+1]+ Tetris[i][j+2]+ Tetris[i-2][j+2]==0){
            cout<<1<<" "<<j-1;Fill(i,j,i,j+1,i-1,j+1,i-1,j+2);return;}
        }
    }
}
int main()
{
    for(int i=0;i<=21;i++)
        Tetris[i][0]=1;
    for(int j=0;j<=11;j++)
        Tetris[0][j]=1;
    int n,br=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        //Print();

        int Shape;
        cin>>Shape;
        switch(Shape)
        {
             case 1:
            Type1();
            break;
            case 2:
            Type2();
            break;
            case 3:
            Type3();
            break;
            case 4:
            Type4();
            break;
            case 5:
            Type5();
            break;
            case 6:
            Type6();
            break;
            case 7:
            Type7();
            break;
        }
    if(i!=n)cout<<" ";
    }
    cout<<endl;

    return 0;
}

