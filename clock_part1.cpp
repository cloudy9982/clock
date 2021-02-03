#include<iostream>
#include<stdlib.h>
#include <time.h>
#include<string.h>
using namespace std;

int main(){
int a;
cin>>a;
if(a==1){
  cout<<"早安，來個問題醒醒腦吧!"<<endl;
  char question[6][70]={"what letter is an animal?","What letter stands for the ocean?","what man cannot live in a house?","Are you a magician?","You have a lighter?","Which side do you think my heart is on? Left or right?"};
  char correct_answer[6][70]={"b","c","snowman","♥ Because whenever I look at you, everything else disappears. ♥","♥ Then how did you set my heart on fire? ♥","♥ It's on your side. ♥"};
  srand( time(NULL) );
  int x=rand()%6+0;
  for(int i=0;i<40;i++){
    cout<<question[x][i];   //抽問題
  }
  cout<<endl;
  char ans[20];
  cin>>ans;     //輸入答案
  if(x<=2&& strcmp(ans,correct_answer[x])==0){  //腦經急轉彎答對者
    cout<<"恭喜你答對了!"<<endl;
  }
  else if(x<=2 && strcmp(ans,correct_answer[x])!=0 ){   //腦經急轉彎答錯者:再抽一題情話
    cout<<"差一點點qq，正確答案是:";
    for(int i=0;i<strlen(correct_answer[x]);i++){
      cout<<correct_answer[x][i];
    }
    cout<<endl;
    cout<<endl<<"再來一題吧!"<<endl;
    x=rand()%3+3;
    for(int i=0;i<70;i++){
      cout<<question[x][i];
    }
    cout<<endl;
    char ans[20];
    cin>>ans;
    for(int i=0;i<strlen(correct_answer[x]);i++){
      cout<<correct_answer[x][i];
    }
    cout<<endl;
  }
  else{   //抽到情話者
    for(int i=0;i<strlen(correct_answer[x]);i++){
      cout<<correct_answer[x][i];
    }
    cout<<endl;
  }
  cout<<endl<<"祝你有個美好的一天(๑ơ ₃ ơ)♥"<<endl;
}
  return 0;
}


//https://zhuanlan.zhihu.com/p/36329100
//https://kknews.cc/news/avvvb36.html
//https://zhuanlan.zhihu.com/p/42568548
