#include <iostream>
#include <Windows.h>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;


char pattern[4] = { 'D','S','H','C' };
int number[13] = { 1 ,2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 };

char cardPattern;
int cardNumber;

int bet;
int minbet = 1000;
int money = 10000;

int card[3];
void selectCard(int x);

void main()
{
	cout << "월남 뽕 게임을 시작합니다." << endl;
	while(money>0)
	{
	srand(time(NULL));
	
	
	cout << " 현재 소지금은" << money << "입니다" << endl;
	selectCard(1);
	selectCard(2);
	cout << "얼마를 배팅하시겠습니까?(단위:천원)" << endl;
	cin >> bet;
	if (bet*minbet > money) 
	{
		cout << "소지금보다 많은 금액을 배팅할 수 없습니다." << endl;
		continue; 
	}
	selectCard(3);

	if (card[2] > card[1] && card[2] < card[0] || card[2]<card[1] && card[2] > card[0])
	{
		money += 9 * bet * minbet;
		cout << "현재 소지금은" << money << "입니다." << endl << endl;
	}
	else
	{
		money -= bet * minbet;
		cout << "현재 소지금은" << money  << "입니다." << endl << endl ;
		
	}
	}
	
	cout << "프로그램을 종료합니다." << endl;
}


void selectCard(int x)
{
	int index;
	do {
		index = rand() % 52; 
	} while (index == card[0] || index == card[1]); 

	card[x - 1] = index;

	cardPattern = pattern[index % 4];
	cardNumber = number[index / 4];
	


	cout << x << "번째 카드는 " << cardPattern << cardNumber << "입니다." << endl;

}
