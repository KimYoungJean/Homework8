#include <iostream>
#include <time.h>
#define CHEAT 1

const char Pattern[4] = { 'S','D','C','H' };
const int Number[13] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 }; // A=1,J=11,Q=12,K=13
const int minBet = 1000;


int Deck[52];
int card[3] = { 100, 101, 102 };
int money = 10000;

int bet;
int away;
int sum=0;

using std::cout;
using std::cin;
using std::endl;

int temp;


void selectCard(int x);
int cardNum(int x);
void main()
{
	srand(time(NULL));


	for (int i = 0; i < 52; i++)
	{
		Deck[i] = i;
	}


#pragma region 카드 초기화 패턴
	/*
	4로 나눈 (몫+1)으로 숫자를 적고
	4로 나눈 나머지로 패턴을 적음
	0은 몫0 나머지0  1 S
	1은 몫0 나머지1  1 D
	2     0  	 2  1 C
	3     0      3  1 H

	4      1     0  2 S

	48은 몫이 12 나머지0  13 S
	49은 몫이 12 나머지1  13 D
	50은 몫이 12 나머지2  13 C
	51은 몫이 12 나머지3  13 H
	*/
#pragma endregion

	for (int i = 0; i < 52; i++) // 셔플
	{
		int random;
		random = rand() % 52;
		temp = Deck[i];
		Deck[i] = Deck[random];
		Deck[random] = temp;
	}

	cout << "월남뽕 게임을 시작합니다." << endl;
	cout << "현재 소지금은:" << money << "입니다." << endl;
	while (true)
	{

		selectCard(0);
		selectCard(1);
#if (CHEAT==1)
		selectCard(2);
#endif // (CHEAT==1)

		cout << "베팅해주세요 (단위:천원)" << endl;
		cin >> bet;
		if (money < bet * minBet)
		{
			cout << "소지금보다 많은 금액은 베팅할 수 없습니다." << endl;
			continue;
		}
		if (bet > 0)
		{
#if (CHEAT==0)
			selectCard(2);
#endif
			if (cardNum(2) > cardNum(1) && cardNum(2) < cardNum(0) || cardNum(2) < cardNum(1) && cardNum(2) > cardNum(0))
			{
				money += 9 * bet * minBet;
				cout << "소지금 :" << money << endl << endl;
			}
			else
			{
				money -= bet * minBet;
				cout << "소지금 :" << money << endl << endl;
			}
		}
			sum = 0;
			for (int i = 0; i < 52; i++)
			{
				sum += Deck[i];
			}
			if (money <= 0 || sum <= -52)
			{
				cout << "프로그램을 종료합니다" << endl;
				break;
			}
			
	}
}
void selectCard(int x)
{
	cout << x + 1 << " 번째 카드를 뽑습니다" << endl;
	do {
		away = rand() % 52;

		card[x] = Deck[away];
		Deck[away] = -1;

	} while (card[x] <= 0);
	
	
	cout << "나온 카드는" << Pattern[card[x] % 4];
	if (Number[card[x] / 4] == 1)
	{
		cout << "-A 입니다" << endl;
	}
	else if (Number[card[x] / 4] == 11)
	{
		cout << "-J 입니다" << endl;
	}
	else if (Number[card[x] / 4] == 12)
	{
		cout << "-Q 입니다" << endl;
	}
	else if (Number[card[x] / 4] == 13)
	{
		cout << "-K 입니다" << endl;
	}
	else
	{
		cout<<"-" << Number[card[x] / 4] << "입니다" << endl;
	}
}
int cardNum(int x)
{
	return card[x] / 4;
}



