#include<iostream>
#include<cmath>
using namespace std;
int MOVES();
int n,m,k,Ax,Ay,T[21][21],pm=4;
char Tc[21][21],q='A',oq='a';
bool up=true,down=true,righ=true,lef=true,AinSq=false;
struct Head
{
    int N;
    int M;
    int l;
}a,A;
void INPUT()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char c;
            cin>>c;
            Tc[i][j]=c;
            if(c=='a'){a.N=i;a.M=j;}
            if(c=='A')
            {
                A.N=i;A.M=j;


                        for(int ii=i-1;ii<=i+1;ii++)
                        {
                        for(int jj=j-1;jj<=j+1;jj++)
                        {
                        if(Tc[ii][jj]=='@')AinSq=true;
                        }
                        }
            }
            if(c>'a' && c<='z')
                {
                    if(a.l<c-'a'+1)a.l=c-'a'+1;
                    if(Tc[i][j]>oq)oq=Tc[i][j];
                }
            if(c>'A' && c<='Z')
                {
                    if(A.l<c-'A'+1)A.l=c-'A'+1;
                    if(Tc[i][j]>q)q=Tc[i][j];

                }
            if(c=='.'){T[i][j]=1;}
            if(c=='@')
            {
                Ax=i;
                Ay=j;
                T[i][j]=1;

                for(int ii=i-1;ii<=i+1;ii++)
                {
                    for(int jj=j-1;jj<=j+1;jj++)

                    {
                        if(Tc[ii][jj]=='Á')AinSq=true;
                    }
                }
            }

        }
    }
    //cout<<"A.N = "<<A.N<<endl;
    //cout<<"A.M = "<<A.M<<endl;
    //cout<<"A.l = "<<A.l<<endl;
    //cout<<"a.M = "<<a.M<<endl;
    //cout<<"a.N = "<<a.N<<endl;
    //cout<<"a.l = "<<a.l<<endl;
    //cout<<"Ax = "<<Ax<<endl;
    //cout<<"Ay = "<<Ay<<endl;
}
int MOVES_Second_Ed()
{
    //cout<<"AinSq : "<<AinSq<<endl;
    //Svobodni
    bool Up=true,Left=true,Down=true,Right=true;
    if(T[A.N-1][A.M]==0 ){Up=false;pm--;}
    if(T[A.N][A.M-1]==0 ){Left=false;pm--;}
    if(T[A.N+1][A.M]==0 ){Down=false;pm--;}
    if(T[A.N][A.M+1]==0 ){Right=false;pm--;}
    if(pm==1)
    {
        if(Up==1)return 1;
        if(Right==1)return 2;
        if(Down==1)return 3;
        if(Left==1)return 4;

    }


    //prank
    if(T[a.N-1][a.M]+T[a.N+1][a.M]+ T[a.N][a.M+1]+T[a.N][a.M-1]==1)
    {
        //cout<<"1";
        if(T[a.N][a.M-1]==1)
        {
            if(A.N==a.N+1 && A.M==a.M-1)return 1;
            if(A.N==a.N && A.M==a.M-2)return 2;
            if(A.N==a.N-1 && A.M==a.M-1)return 3;
        }
        if(T[a.N][a.M+1]==1)
        {
            if(A.N==a.N-1 && A.M==a.M+1)return 3;
            if(A.N==a.N && A.M==a.M+2)return 4;
            if(A.N==a.N+1 && A.M==a.M+1)return 1;
        }
        if(T[a.N-1][a.M]==1)
        {
            if(A.N==a.N-1 && A.M==a.M-1)return 2;
            if(A.N==a.N-1 && A.M==a.M+1)return 4;
            if(A.N==a.N-2 && A.M==a.M)return 3;
        }
        if(T[a.N+1][a.M]==1)
        {
            if(A.N==a.N+1 && A.M==a.M-1)return 2;
            if(A.N==a.N+1 && A.M==a.M+1)return 4;
            if(A.N==a.N+2 && A.M==a.M)return 1;
        }
    }
    //cout<<2;
    //cout<<"pm="<<pm;
    //escape
    if(Ax==A.N-1 && Ay==A.M && A.l==k)return 1;
    else
    {
        if(T[A.N-2][A.M]==0 && Tc[A.N-2][A.M]!=q && T[A.N-1][A.M-1]==0 && Tc[A.N-1][A.M-1]!=q && T[A.N-1][A.M+1]==0 && Tc[A.N-1][A.M+1]!=q && Tc[A.N-2][A.M]!=oq && Tc[A.N-1][A.M-1]!=oq && Tc[A.N-1][A.M+1]!=oq && Up){Up=false;pm--;}
    }

    if(Ax==A.N+1 && Ay==A.M && A.l==k)return 3;
    else
    {
        if(T[A.N+1][A.M-1]==0 && Tc[A.N+1][A.M-1]!=q && T[A.N+1][A.M+1]==0 && Tc[A.N+1][A.M+1]!=q && T[A.N+2][A.M]==0 && Tc[A.N+2][A.M]!=q && Tc[A.N+1][A.M-1]!=oq && Tc[A.N+1][A.M+1]!=oq && Tc[A.N+2][A.M]!=oq && Down){Down=false;pm--;}
    }

    if(Ax==A.N && Ay==A.M+1&& A.l==k)return 2;
    else
    {
        if(T[A.N-1][A.M+1]==0 && T[A.N][A.M+2]==0 && T[A.N+1][A.M+1]==0 && Tc[A.N-1][A.M+1]!=q && Tc[A.N][A.M+2]!=q && Tc[A.N+1][A.M+1]!=q && Tc[A.N-1][A.M+1]!=oq && Tc[A.N][A.M+2]!=oq && Tc[A.N+1][A.M+1]!=oq && Right){Right=false;pm--;}
    }

    if(Ax==A.N && Ay==A.M-1 && A.l==k)return 4;
    else
    {
        if(T[A.N-1][A.M-1]==0 && T[A.N+1][A.M-1]==0 && T[A.N][A.M-2]==0 && Tc[A.N-1][A.M-1]!=q && Tc[A.N+1][A.M-1]!=q && Tc[A.N][A.M-2]!=q && Tc[A.N-1][A.M-1]!=oq && Tc[A.N+1][A.M-1]!=oq && Tc[A.N][A.M-2]!=oq && Left){Left=false;pm--;}
    }
    if(pm==1)
    {
        if(Up==1)return 1;
        if(Right==1)return 2;
        if(Down==1)return 3;
        if(Left==1)return 4;

    }
    //cout<<3;
    //block
    if(a.N==n && A.N==n-1)
    {
        if(A.M==a.M+1 && Left && T[a.N][A.M]==0)return 4;
        if(A.M==a.M-1 && Right && T[a.N][A.M]==0)return 2;
    }
    if(a.N==1 && A.N==2)
    {
        if(A.M==a.M+1 && Left && T[a.N][A.M]==0)return 4;
        if(A.M==a.M-1 && Right && T[a.N][A.M]==0)return 2;
    }
    if(a.M==m && A.M==m-1)
    {
        if(A.N==a.N+1 && Up && T[A.N][a.M]==0)return 1;
        if(A.N==a.N-1 && Down && T[A.N][a.M]==0)return 3;
    }
    if(a.M==1 && A.M==2)
    {
        if(A.N==a.N+1 && Up && T[A.N][a.M]==0)return 1;
        if(A.N==a.N-1 && Down && T[A.N][a.M]==0)return 3;
    }
    //cout<<5;

    //STOP
    bool FApple=false;
    if(A.l >a.l && (A.l-a.l>1 || a.l>2) && abs(a.N-Ax)+abs(a.M-Ay)-abs(A.N-Ax)-abs(A.M-Ay)>1)
    {

        // Circle the Apple
            if(A.l < 8 && AinSq )
            {

                int Bx,By;
                if(Tc[A.N-1][A.M]=='B'){Bx=A.N-1;By=A.M;}
                if(Tc[A.N+1][A.M]=='B'){Bx=A.N+1;By=A.M;}
                if(Tc[A.N][A.M-1]=='B'){Bx=A.N;By=A.M-1;}
                if(Tc[A.N][A.M+1]=='B'){Bx=A.N;By=A.M+1;}
                    if(Ax + Ay + Bx + By== 2*(A.N+A.M))//idvam sre6tu qbulkata
                    {
                        if(abs(a.N-Ax)+abs(a.M-Ay)-abs(A.N-Ax)-abs(A.M-Ay)>3)
                        {
                            if(Ax==A.N){
                            if(Up && Ax>a.N)return 1;
                            if(Down && Ax<a.N )return 3;

                            if(Up &&  abs(By-Ay)<abs(a.M-Ay))return 1;
                            if(Down && abs(By-Ay)<abs(a.M-Ay))return 3;
                            }
                            if(Ay==A.M){
                            if(Left && Ay>a.M )return 4;
                            if(Right && Ay<a.M )return 2;

                            if(Left && abs(By-Ay)<abs(a.M-Ay))return 4;
                            if(Right && abs(By-Ay)<abs(a.M-Ay))return 2;
                            }
                        }
                    }

                    else
                    {
                        if(A.N ==Ax-1  &&  A.M ==Ay-1 )
                        {
                            if(Bx == Ax -1 && By == Ay )
                            {
                                if(Down)return 3;
                            }
                            if(Bx == Ax && By == Ay-1)
                            {
                                if(Right)return 2;
                            }
                        }
                        if(A.N == Ax-1 &&  A.M == Ay)
                        {
                            if(Bx == Ax - 1 && By == Ay -1)
                            {
                                if(Right)return 2;
                            }
                            if(Bx == Ax-1&& By == Ay+1)
                            {
                                if(Left)return 4;
                            }
                        }
                        if(A.N ==  Ax-1&&  A.M == Ay+1)
                        {
                            if(Bx == Ax-1&& By == Ay)
                            {
                                if(Down)return 3;
                            }
                            if(Bx == Ax&& By ==Ay +1)
                            {
                                if(Left)return 4;
                            }
                        }
                        if(A.N ==  Ax&&  A.M == Ay+1)
                        {
                            if(Bx == Ax-1&& By == Ay+1)
                            {
                                if(Down)return 3;
                            }
                            if(Bx == Ax+1&& By == Ay+1)
                            {
                                if(Up)return 1;
                            }
                        }
                        if(A.N ==  Ax+1&&  A.M == Ay+1)
                        {
                            if(Bx == Ax&& By == Ay+1)
                            {
                                if(Left)return 4;
                            }
                            if(Bx ==Ax+1 && By == Ay)
                            {
                                if(Up)return 1;
                            }
                        }
                        if(A.N ==  Ax+1&&  A.M == Ay)
                        {
                            if(Bx == Ax+1&& By == Ay+1)
                            {
                                if(Left)return 4;
                            }
                            if(Bx == Ax+1&& By == Ay-1)
                            {
                                if(Right)return 2;
                            }
                        }
                        if(A.N ==  Ax+1&&  A.M == Ay-1)
                        {
                            if(Bx == Ax+1&& By == Ay)
                            {
                                if(Up)return 1;
                            }
                            if(Bx == Ax&& By == Ay-1)
                            {
                                if(Right)return 2;
                            }
                        }
                        if(A.N ==  Ax&&  A.M == Ay-1)
                        {
                            if(Bx == Ax+1&& By == Ay-1)
                            {
                                if(Up)return 1;
                            }
                            if(Bx == Ax-1&& By == Ay-1)
                            {
                                if(Down)return 3;
                            }
                        }
                    }

            }




        if(m>=n)
        {
            if(A.M<a.M && Ay<A.M)
            {
                if(A.N<a.N)
                {
                    if(T[A.N+1][A.M]==1 && Down)return 3;
                    if(a.M-A.M>=2 && T[A.N][A.M+1]==1 && Right) return 2;
                    if(a.M-A.M<2 && T[A.N][A.M-1]==1 && Left) return 4;
                }
                if(A.N>=a.N)
                {
                    if(T[A.N-1][A.M]==1 && Up)return 1;
                    if(T[A.N][A.M-1]==1 && Left)return 4;
                    if(T[A.N][A.M+1]==1 && Right)return 2;
                }

            }
            if(A.M>a.M && Ay>A.M)
            {
                if(A.N<a.N)
                {
                    if(T[A.N+1][A.M]==1 && Down)return 3;
                    if(A.M-a.M>=2 && T[A.N][A.M+1]==1 && Right) return 2;
                    if(a.M-A.M<2 && T[A.N][A.M-1]==1 && Left) return 4;
                }
                if(A.N>=a.N)
                {
                    if(T[A.N-1][A.M]==1 && Up)return 1;
                    if(T[A.N][A.M-1]==1 && Left) return 4;
                    if(T[A.N][A.M+1]==1 && Right) return 2;
                }

            }

        }
        if(m<n)
        {
            if(A.N<a.N && Ax<A.N)
            {
                if(A.M<a.N)
                {
                    if(T[A.N+1][A.M]==1)return 3;
                    if(T[A.N][A.M+1]==1) return 2;
                }
                if(A.N>=a.N)
                {
                    if(T[A.N-1][A.M]==1)return 1;
                    if(T[A.N][A.M-1]==1) return 4;
                }

            }
            if(A.M>a.M && Ay>A.M)
            {
                if(A.N<a.M)
                {
                    if(T[A.N][A.M+1]==1) return 2;
                    if(T[A.N+1][A.M]==1)return 3;

                }
                if(A.M>=a.M)
                {
                    if(T[A.N][A.M-1]==1) return 4;
                    if(T[A.N-1][A.M]==1)return 1;

                }

            }

        }
    }

    //cout<<6;
    //go for apple
    bool Aup=false,Aright=false,Adown=false,Aleft=false;
    if(Ax<=A.N)Aup=true;
    if(Ax>=A.N)Adown=true;
    if(Ay<=A.M)Aleft=true;
    if(Ay>=A.M)Aright=true;
    if(abs(A.N-Ax)>abs(a.N-Ax) && abs(A.M-Ay)<abs(a.M-Ay) && A.N<Ax && Down==true)return 3;
    if(abs(A.N-Ax)>abs(a.N-Ax) && abs(A.M-Ay)<abs(a.M-Ay) && A.N>Ax && Up==true)return 1;
    if(abs(A.M-Ay)>abs(a.M-Ay) && abs(A.N-Ax)<abs(a.N-Ax) && A.M>Ay && Left==true)return 4;
    if(abs(A.M-Ay)>abs(a.M-Ay) && abs(A.N-Ax)<abs(a.N-Ax) && A.M<Ay && Right==true)return 2;
  // cout<<7;
    if(abs(A.N-Ax)>=abs(A.M-Ay) && Ax<=A.N && Up==1)return 1;
    if(abs(A.N-Ax)>=abs(A.M-Ay) && Ax>=A.N && Down==1)return 3;
    if(abs(A.N-Ax)<=abs(A.M-Ay) && Ay<=A.M && Left==1)return 4;
    if(abs(A.N-Ax)<=abs(A.M-Ay) && Ay>=A.M && Right==1)return 2;
    //cout<<8;
    if(Aup && Up)return 1;
    if(Adown && Down)return 3;
    if(Aleft && Left)return 4;
    if(Aright && Right)return 2;
   // cout<<9;
    //cout<<"RANDOM"<<endl;
    //random
        if(Up==1)return 1;
        if(Right==1)return 2;
        if(Down==1)return 3;
        if(Left==1)return 4;
        return MOVES();
}
int MOVES()
{
    if(T[A.N-1][A.M]==0 || T[A.N-1][A.M]==3){up=false;pm--;}
    if(T[A.N][A.M-1]==0 || T[A.N][A.M-1]==3){lef=false;pm--;}
    if(T[A.N+1][A.M]==0 || T[A.N+1][A.M]==3){down=false;pm--;}
    if(T[A.N][A.M+1]==0 || T[A.N][A.M+1]==3){righ=false;pm--;}
    if(pm==1)
    {
        if(up==1)return 1;
        if(righ==1)return 2;
        if(down==1)return 3;
        if(lef==1)return 4;

    }
    if(Ax==A.N-1 && Ay==A.M && A.l==k)return 1;
    else
    {
        if(T[A.N-2][A.M]==0 && T[A.N-1][A.M-1]==0 && T[A.N-1][A.M+1]==0){up=false;pm--;}
    }

    if(Ax==A.N+1 && Ay==A.M && A.l==k)return 3;
    else
    {
        if(T[A.N+1][A.M-1]==0 && T[A.N+1][A.M+1]==0 && T[A.N+2][A.M]==0){down=false;pm--;}
    }

    if(Ax==A.N && Ay==A.M+1&& A.l==k)return 2;
    else
    {
        if(T[A.N-1][A.M+1]==0 && T[A.N][A.M+2]==0 && T[A.N+1][A.M+1]==0){righ=false;pm--;}
    }

    if(Ax==A.N && Ay==A.M-1 && A.l==k)return 4;
    else
    {
        if(T[A.N-1][A.M-1]==0 && T[A.N+1][A.M-1]==0 && T[A.N][A.M-2]==0){lef=false;pm--;}
    }


    if(pm==1)
    {
        if(up==1)return 1;
        if(righ==1)return 2;
        if(down==1)return 3;
        if(lef==1)return 4;

    }

        if(A.M==2 && a.M==1 && abs(A.N-a.N)==1 && lef==1)return 4;
        if(A.N==2 && a.N==1 && abs(A.M-a.M)==1 && up==1)return 1;
        if(A.M==m-1 && a.M==m && abs(A.N-a.N)==1 && righ==1)return 2;
        if(A.N==n-1 && a.N==n && abs(A.M-a.M)==1 && down==1)return 3;


    //if(abs(A.N-Ax)+abs(A.M-Ay) <= abs(a.N-Ax)+abs(a.M-Ay))
    //{
        if(abs(A.N-Ax)>=abs(A.M-Ay) && Ax<A.N && up==1)return 1;
        if(abs(A.N-Ax)>=abs(A.M-Ay) && Ax>A.N && down==1)return 3;
        if(abs(A.N-Ax)<=abs(A.M-Ay) && Ay<A.M && lef==1)return 4;
        if(abs(A.N-Ax)<=abs(A.M-Ay) && Ay>A.M && righ==1)return 2;

   // }
        if(A.N != n/2 && A.M!= m/2){
        if(abs(A.N-n/2)>=abs(A.M-m/2) && Ax<A.N && up==1)return 1;
        if(abs(A.N-n/2)>=abs(A.M-m/2) && Ax>A.N && down==1)return 3;
        if(abs(A.N-n/2)<=abs(A.M-m/2) && Ay<A.M && lef==1)return 4;
        if(abs(A.N-n/2)<=abs(A.M-m/2) && Ay>A.M && righ==1)return 2;
        }



        if(abs(A.N-a.N)>=abs(A.M-a.M) && a.N<A.N && up==1)return 1;
        if(abs(A.N-a.N)>=abs(A.M-a.M) && a.N>A.N && down==1)return 3;
        if(abs(A.N-a.N)<=abs(A.M-a.M) && a.N<A.M && lef==1)return 4;
        if(abs(A.N-a.N)<=abs(A.M-a.M) && a.N>A.M && righ==1)return 2;

            if(up==1)return 1;
            if(righ==1)return 2;
            if(down==1)return 3;
            if(lef==1)return 4;



}
int main()
{
    INPUT();
    int k;
    //k=MOVES();
    k=MOVES_Second_Ed();
    if(k==1)cout<<"Up"<<endl;
    if(k==2)cout<<"Right"<<endl;
    if(k==3)cout<<"Down"<<endl;
    if(k==4)cout<<"Left"<<endl;
    return 0;
}

