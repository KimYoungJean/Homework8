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


#pragma region ī�� �ʱ�ȭ ����
	/*
	4�� ���� (��+1)���� ���ڸ� ����
	4�� ���� �������� ������ ����
	0�� ��0 ������0  1 S
	1�� ��0 ������1  1 D
	2     0  	 2  1 C
	3     0      3  1 H

	4      1     0  2 S

	48�� ���� 12 ������0  13 S
	49�� ���� 12 ������1  13 D
	50�� ���� 12 ������2  13 C
	51�� ���� 12 ������3  13 H
	*/
#pragma endregion

	for (int i = 0; i < 52; i++) // ����
	{
		int random;
		random = rand() % 52;
		temp = Deck[i];
		Deck[i] = Deck[random];
		Deck[random] = temp;
	}

	cout << "������ ������ �����մϴ�." << endl;
	cout << "���� ��������:" << money << "�Դϴ�." << endl;
	while (true)
	{

		selectCard(0);
		selectCard(1);
#if (CHEAT==1)
		selectCard(2);
#endif // (CHEAT==1)

		cout << "�������ּ��� (����:õ��)" << endl;
		cin >> bet;
		if (money < bet * minBet)
		{
			cout << "�����ݺ��� ���� �ݾ��� ������ �� �����ϴ�." << endl;
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
				cout << "������ :" << money << endl << endl;
			}
			else
			{
				money -= bet * minBet;
				cout << "������ :" << money << endl << endl;
			}
		}
			sum = 0;
			for (int i = 0; i < 52; i++)
			{
				sum += Deck[i];
			}
			if (money <= 0 || sum <= -52)
			{
				cout << "���α׷��� �����մϴ�" << endl;
				break;
			}
			
	}
}
void selectCard(int x)
{
	cout << x + 1 << " ��° ī�带 �̽��ϴ�" << endl;
	do {
		away = rand() % 52;

		card[x] = Deck[away];
		Deck[away] = -1;

	} while (card[x] <= 0);
	
	
	cout << "���� ī���" << Pattern[card[x] % 4];
	if (Number[card[x] / 4] == 1)
	{
		cout << "-A �Դϴ�" << endl;
	}
	else if (Number[card[x] / 4] == 11)
	{
		cout << "-J �Դϴ�" << endl;
	}
	else if (Number[card[x] / 4] == 12)
	{
		cout << "-Q �Դϴ�" << endl;
	}
	else if (Number[card[x] / 4] == 13)
	{
		cout << "-K �Դϴ�" << endl;
	}
	else
	{
		cout<<"-" << Number[card[x] / 4] << "�Դϴ�" << endl;
	}
}
int cardNum(int x)
{
	return card[x] / 4;
}



