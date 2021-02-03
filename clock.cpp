#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <string.h>
using namespace std;

void choise1();
void choise2();

//停頓一秒
void tick1();
#define Blink "\033[33;5m"

#define PUR_BOLD "\x1b[;35;1m"

#define RED_BOLD "\x1b[;31;1m"

#define BLU_BOLD "\x1b[;34;1m"

#define YEL_BOLD "\x1b[;33;1m"

#define GRN_BOLD "\x1b[;32;1m"

#define CYAN_BOLD_ITALIC "\x1b[;36;1;3m"

#define RESET "\x1b[0;m"
//時間類別
class Time{
	private:
		int hour;
		int minute;
		int second;
	public:
		//設置時間
		void set(int h,int m,int s){
			hour = h;
			minute = m;
			second = s;
		}
		//時間走一秒，變化情況
		void next(){
			if(second<59)
				second++;
			else if(minute<59){
				second=0;
				minute++;}
			else if(hour<23){
				minute=0;
				second=0;
				hour++;}
			else
				hour=0;
		}
		//得到時間
		int get(){
			return hour*10000+minute*100+second;
		}
		int gethour(){
			return hour;
		}
		int getminute(){
			return minute;
		}
		int getsecond(){
			return second;
		}
};
//時鐘類別
class Clock{
	private:
		Time now;
		Time ring_time;
	public:
		//設定初始時間
		void adjust_now(int h,int m,int s){
			now.set(h,m,s);
			cout<<BLU_BOLD"現在的時間是："<<h<<"時"<<m<<"分"<<s<<"秒"<<RESET<<endl;
		}
		//設定鬧鐘時間
		void adjust_ring(int h,int m,int s){
			ring_time.set(h,m,s);
			cout<<BLU_BOLD"鬧鐘時間是："<<h<<"時"<<m<<"分"<<s<<"秒"<<RESET<<endl;
		}
		//過一秒
		void tick(){
			tick1();
			now.next();
		}
		//顯示當前時間
		void showtime(){
			cout<<PUR_BOLD<<now.gethour()<<"時"<<now.getminute()<<"分"<<now.getsecond()<<"秒"<<RESET<<endl;
		}
		//時間到了之後開始響起來
		void run(){
			int choise;
			do{
				tick();
				showtime();
				if(now.get()>=ring_time.get()){
					cout<<'\a';
					cout<<RED_BOLD"時間到了！！！"RESET<<endl;
					cout<<Blink"選1：起床，選2：繼續睡"RESET<<endl;
					cin>> choise;//第一次選擇
					//第Ｎ次選擇
					if(choise==1) choise1();
					while(choise==2){
						if(choise==2) choise2();
						cout<<Blink"選1：起床，選2：繼續睡"RESET<<endl;
						cin>>choise;
						if(choise==1) choise1();
					}
					break;
				}
			}while(1);
		}
};

int main(){
	Clock c;
	time_t rawtime;
	struct tm * timeinfo;

	int h1,m1,s1,count=0,num_sec=0,num_min=0;
	char time_now[10]={},time_hour[100]={},time_min[10]={},time_sec[10]={},tmp[100]={},tmp1[100]={},tmp2[10]={},tmp3[10];
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	sscanf(asctime (timeinfo),"%s %s %s %s",tmp,tmp1,tmp2,time_now);//分段
	sscanf(time_now,"%[^:]",time_hour);//取小時

	for(int i=0;i<8;i++){
		if(time_now[i]==':') count++;
		if(time_now[i]!=':' && count == 1){
			time_min[num_min++] = time_now[i];
		}
		if(time_now[i]!=':' && count == 2){
			time_sec[num_sec++] = time_now[i];
		}
	}//時間輸入

	cout <<RED_BOLD"現在時間："<<asctime (timeinfo)<<RESET<<endl;
	cout <<"\033[36;7m請設定鬧鐘時間：(?時?分?秒)"<<endl<<"一次輸入一行"<<RESET<<endl;
	cin >> h1 >> m1 >> s1;
	srand(time(NULL));
	c.adjust_now(atoi(time_hour),atoi(time_min),atoi(time_sec));     //起始時間
	c.adjust_ring(h1,m1,s1);    //鬧鐘時間
	c.run();
}

void choise1(){
	cout<<PUR_BOLD"早安，來個問題醒醒腦吧!"RESET<<endl;
	char question[6][70]={"what letter is an animal?","What letter stands for the ocean?","what man cannot live in a house?","Are you a magician?","You have a lighter?","Which side do you think my heart is on? Left or right?"};
	char correct_answer[6][70]={"b","c","snowman","♥ Because whenever I look at you, everything else disappears. ♥","♥ Then how did you set my heart on fire? ♥","♥ It's on your side. ♥"};
	srand( time(NULL) );
	int x=rand()%6+0;
	for(int i=0;i<40;i++){
		cout<<"\033[40;35m"<<question[x][i]<<RESET;   //抽問題
	}
	cout<<endl;
	char ans[20];
	cin>>ans;     //輸入答案
	tick1();
	cout <<RED_BOLD"."RESET<<endl;
	tick1();
	cout << PUR_BOLD".."RESET<<endl;
	tick1();
	cout <<YEL_BOLD"..."RESET<<endl;
	tick1();
	if(x<=2&& strcmp(ans,correct_answer[x])==0){  //腦經急轉彎答對者
		cout<<"\033[40;34;5m恭喜你答對了!"RESET<<endl;
	}
	else if(x<=2 && strcmp(ans,correct_answer[x])!=0 ){   //腦經急轉彎答錯者:再抽一題情話
		cout<< CYAN_BOLD_ITALIC"差一點點qq，正確答案是:"RESET<<endl;
		tick1();
		cout << BLU_BOLD"."RESET<<endl;
		tick1();
		cout << PUR_BOLD".."RESET<<endl;
		tick1();
		cout <<YEL_BOLD"..."RESET<<endl;
		tick1();
		for(int i=0;i<strlen(correct_answer[x]);i++){
			cout<<"\033[32;4m"<<correct_answer[x][i]<<RESET;
		}
		cout<<endl;
		tick1();
		cout<<endl<<"再來一題吧!"<<endl;
		x=rand()%3+3;
		for(int i=0;i<70;i++){
			cout<<"\033[44;31;1m"<<question[x][i]<<RESET;
		}
		cout<<endl;
		char ans[20];
		cin>>ans;
		for(int i=0;i<strlen(correct_answer[x]);i++){
			cout<<"\033[32m"<<correct_answer[x][i]<<RESET;
		}
		cout<<endl;
	}
	else{   //抽到情話者
		for(int i=0;i<strlen(correct_answer[x]);i++){
			cout<<BLU_BOLD<<correct_answer[x][i]<<RESET;
		}
		cout<<endl;
	}
	tick1();
	cout<<endl<<"\033[32;5;7m祝你有個美好的一天(๑ơ ₃ ơ)♥"RESET<<endl;

}

void choise2(){
	for(int i=0;i<5;i++){
		tick1();
		cout<<"\033[32;5m趕快起床,再賴床你試試看!"<<'\a'<<RESET<<endl;
	}
	char  lucky[7][100] = {"Pupu💩", "Diamond💎", "Lipstick💄", "Necklace📿", "A bag of money💰", "Love letters💌","Flying money💸"};
	/* 產生 [min , max] 的整數亂數 */
	int min=0;
	int max=6;
	int x = rand() % (max-min+1)+min;
	char str[]="Your lucky item today is : ";
	cout << "\033[32;7m"<<str<<RESET<<endl;
	tick1();
	cout << GRN_BOLD"."RESET<<endl;
	tick1();
	cout << PUR_BOLD".."RESET<<endl;
	tick1();
	cout <<YEL_BOLD"..."RESET<<endl;
	tick1();
	if(x==0){
		cout<<RED_BOLD<<lucky[0]<<RESET<<endl;
		cout<<"Please be careful not to step on the shit while walking today!"<<endl;
	}
	else if(x==1){
		cout<<PUR_BOLD<<lucky[1]<<RESET<<endl;
		cout<<"Maybe someone will propose to you today!"<<endl;
	}
	else if(x==2){
		cout<<BLU_BOLD<<lucky[2]<<RESET<<endl;
		cout<<"Dress yourself up and welcome a beautiful day!"<<endl;
	}
	else if(x==3){
		cout<<YEL_BOLD<<lucky[3]<<RESET<<endl;
		cout<<"Bringing a necklace may bring you a wonderful encounter"<<endl;
	}
	else if(x==4){
		cout<<"\033[36;5m"<<lucky[4]<<RESET<<endl;
		cout<<"Hurry up and buy lotto!"<<endl;
	}
	else if(x==5){
		cout<<RED_BOLD<<lucky[5]<<RESET<<endl;
		cout<<"Your destiny is coming!"<<endl;
	}
	else if(x==6){
		cout<<PUR_BOLD<<lucky[6]<<RESET<<endl;
		cout<<"Be optimistic about your money, don't let it lose!"<<endl;
	}
}

void tick1(){
	long int old=time(0);
	while(time(0)==old);
}

