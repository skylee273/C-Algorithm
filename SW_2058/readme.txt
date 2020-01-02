하나의 자연수를 입력 받아 각 자릿수의 합을 계산하는 프로그램을 작성하라.


[제약 사항]

자연수 N은 1부터 9999까지의 자연수이다. (1 ≤ N ≤ 9999)


[입력]

입력으로 자연수 N이 주어진다.


[출력]

각 자릿수의 합을 출력한다.

[나의 풀이]
재귀 함수를 이용하여 자릿수가 남아 있다면 계속 재귀문을 돌려주면서 나머지와 몫을 더해 나감

[베스트 풀이]
#include <iostream>
 
using namespace std;
 
int main(void) {
    string str;
     
    cin >> str;
     
    int result = 0;
     
    for(int i=0; i<str.length(); i++) {
        result += str.at(i) - '0';
    }
     
    cout << result;
     
    return 0;
}

문자열로 생각하고 자릿수로 더해버림 문자열이기 떄문에 아스키 코드를 빼주는 작업을
진행함. 

-> 문자열로 생각하는 문제가 많이 나오므로 다시한번 볼 필요 있음!