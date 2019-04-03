#include<iostream>
#include<map>
#include<utility>
#include<string>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;

map <char , pair<vector<int>,bool>> Letter;
map <char , pair<vector<int>,bool>> :: iterator I_Letter;

map <string , bool> Word;
map <string , bool> :: iterator I_Word;

int N,K,CHANGED_DISTANCE=0;
char Available_Letter[7];
char AllLetters[10005];
int AllLettersIterator=0;
bool IsLetterNeeded[7];
float D;

void MakeWord()
{
    for(I_Word = next(Word.end(),-1); I_Word != Word.begin(); I_Word++){// I_Word != Word.end();

        for(int l = 0; l < 7; l++)IsLetterNeeded[l]=false;
        if(I_Word -> second == true)continue;
        int WordSize = I_Word->first . size();
        if(WordSize > 7)continue;
        int NeededLetters[WordSize];
        string NeededWord = I_Word -> first;
        cout<<NeededWord<<endl;
        for(int j = 0; j < WordSize; j++){

            if(Letter[I_Word->first[j]].second == true && Letter['_'].second == true)goto Next;
            if(Letter[I_Word->first[j]].second == false){
                NeededLetters[j] = Letter[I_Word->first[j]].first.front()-CHANGED_DISTANCE;
                if(NeededLetters[j]<0)
                {
                    NeededLetters[j]+=N;
                }
            }

            if(Letter['_'].second == false){
                NeededLetters[j] = Letter['_'].first.front()-CHANGED_DISTANCE;

                if(NeededLetters[j]<0)
                {
                    NeededLetters[j]+=N;

                }
                NeededWord[j] = '_';

            }
            for(int l = 0; l < 7; l++){
                if(IsLetterNeeded[l]==true)continue;
                if(Available_Letter[l] == I_Word->first[j]){IsLetterNeeded[l]=true;break;}
            }
        }
        //sort(NeededLetters, NeededLetters + WordSize);
        for(int o = 0; o < WordSize; o++){
            if(NeededLetters[o] == 0)continue;
            for(int l = 6; l >= 0; l--){
                if(IsLetterNeeded[l] == false)
                {
                    cout<<"iskame "<<NeededWord[o]<<endl;
                    cout<<"C"<<" "<<Available_Letter[l]<<endl;
                    Available_Letter[l] = AllLetters[l-CHANGED_DISTANCE+1];
                    if(l!=6)Available_Letter[l]=Available_Letter[l+1];
                    //for(int p = 0; p < l; p++)Letter[Available_Letter[p]].first.at(0)-=NeededLetters[o];
                    CHANGED_DISTANCE++;
                    for(int p = 1; p < NeededLetters[o]; p++){
                        cout<<"C"<<" "<<Available_Letter[6]<<endl;
                        Available_Letter[l] = AllLetters[6-CHANGED_DISTANCE+1];
                        CHANGED_DISTANCE++;
                    }
                    Available_Letter[6] = NeededWord[o];
                }
            }
        }
        for(int l = 0; l < 7; l++)cout<<Available_Letter[l]<<endl;

        Next: ;
    }
}

int main()
{
    for(int i = 0; i < 25; i++)
    {
        char letter = 'A' + i;
        Letter[letter];
        Letter[letter].second = true;
       // Letter.insert(make_pair(letter, make_pair(1,true)));
    }
    for(int l = 0; l < 7; l++)IsLetterNeeded[l]=false;
    //Letter.insert(make_pair('_', make_pair(0,true)));
    Letter['_'];
    Letter['_'].second = true;

    cin>>N>>D;
    for(int i = 0; i < N; i++){
        char symbol;
        int myDist;
        cin>>symbol;
        AllLetters[AllLettersIterator] = symbol;
        AllLettersIterator++;
        if(i<7)
        {
            Available_Letter[i] = symbol;
        }
        myDist = i;

        Letter[symbol].first.push_back(myDist);
        Letter[symbol].second = false;
    }

    cin>>K;
    for(int i = 0; i < K; i++){
        string myWord;
        cin>>myWord;
        Word.insert(make_pair(myWord,false));
    }

    MakeWord();

    return 0;
}
