#include<iostream>
using namespace std;
int main()
{
    int n,br=0;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int k;
        cin>>k;
        switch(k)
        {
             case 1:
            if(br>6)br=0;
            cout<<1<<" "<<br<<" ";
            br+=4;
            if(br>9)br=0;
            break;
            case 2:
            if(br>7)br=0;
            cout<<3<<" "<<br<<" ";
            br+=3;
            if(br>9)br=0;
            break;
            case 3:

            if(br>7)br=0;
            cout<<1<<" "<<br<<" ";
            br+=3;
            if(br>9)br=0;
            break;
            case 4:
            if(br>8)br=0;
            cout<<0<<" "<<br<<" ";
            br+=2;
            if(br>9)br=0;
            break;
            case 5:
            if(br>7)br=0;
            cout<<1<<" "<<br<<" ";
            br+=3;
            if(br>9)br=0;
            break;
            case 6:
            if(br>7)br=0;
            cout<<3<<" "<<br<<" ";
            br+=3;
            if(br>9)br=0;
            break;
            case 7:
            if(br>7)br=0;
            cout<<1<<" "<<br<<" ";
            br+=3;
            if(br>9)br=0;
            break;
        }

    }
    int k;
        cin>>k;
        switch(k)
        {
            case 1:
            if(br>6)br=0;
            cout<<1<<" "<<br;
            br+=4;
            if(br>9)br=0;
            break;
            case 2:
            if(br>7)br=0;
            cout<<3<<" "<<br;
            br+=3;
            if(br>9)br=0;
            break;
            case 3:

            if(br>7)br=0;
            cout<<1<<" "<<br;
            br+=3;
            if(br>9)br=0;
            break;
            case 4:
            if(br>8)br=0;
            cout<<0<<" "<<br;
            br+=2;
            if(br>9)br=0;
            break;
            case 5:
            if(br>7)br=0;
            cout<<1<<" "<<br;
            br+=3;
            if(br>9)br=0;
            break;
            case 6:
            if(br>7)br=0;
            cout<<3<<" "<<br;
            br+=3;
            if(br>9)br=0;
            break;
            case 7:
            if(br>7)br=0;
            cout<<1<<" "<<br;
            br+=3;
            if(br>9)br=0;
            break;
        }

    cout<<endl;
    return 0;
}
