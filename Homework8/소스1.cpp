#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*
두 정수 사이의 합을 구하는 프로그램을 만들어 올것.
 ㄴ 두개의 숫자를 사용자를 통해 입력 받는다.
 ㄴ 입력한 두 숫자 사이의 합을 출력하면 OK
 ㄴ 예외처리: 5번1번을 누른다 > 재입력
     ( 큰수가 앞으로 나오지 말것)
 ㄴ 예외처리: 숫자의 합이 100이상이면 프로그램은 종료된다.

ex) 1과 5를 입력 => 2+3+4 = 9
결과값이 100이상 이면 프로그램이 종료됨. 아니면 루프
*/
int num1;
int num2;
int sum;
void main()
{
    while(true)
    {
     sum = 0;
    cout << " 서로 다른 두 정수를 입력 받겠습니다.(작은수를 먼저 적어주세요)" << endl;
    cout << "첫번째 정수를 입력해주세요." << endl;
    cin >> num1;
    cout << "두번째 정수를 입력해주세요." << endl;
    cin >> num2;
    if (num1 > num2)
    {
        cout << "작은수를 먼저 적어주세요." << endl;
        continue;
    }
    else if(num1 == num2)
    {
        cout << "서로 다른 두 수를 적어주세요" << endl;
        continue;
    }
    else
    {
        cout << num1 << "과(와)" << num2 << "사이의 합을 출력합니다." << endl;
        
        for (int i = num1 + 1; i < num2; i++)
        {
            sum += i;
        }
        cout << sum << endl;

        if (sum >= 100)
        {
            cout << "합이 100 이상이므로 프로그램을 종료합니다." << endl;
            break;
        }
    }
      
    }


    
}