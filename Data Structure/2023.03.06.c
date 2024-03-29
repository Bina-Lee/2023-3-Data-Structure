/*
데이터 구조 1주차 1차시

01. 자료구조와 알고리즘 p12

자료구조란 ?

알고리즘이란 ? p15

1.2 추상자료형 abstract data type p17
= > class
어떤 값이 들어가는지 어떤 오퍼레이팅까지 할수있는지를 담은 자료형
(기본 자료형은 int char 등등

	1.3 알고리즘의 성능 분석 p21~35

	time complexity 시간 복잡도
	데이터의 양이 무한대로 늘어날때 처리시간
	O(n) < -빅오 표기법 p27

	O(n)
	O(1)->상수, 항상 시간이 일정
	O(n ^ 2)
	O(n ^ 3)
	O(2 ^ n) ...etc

	대소비교 : O(n)
	소팅 : O(n log n)
	맨 앞 선택 : O(1)

	big O notation에서는 상수ultiple을 무시
	- n, 2n, n / 2등 사용 안함
	- n->무한대를 가정하기 문에 상수는 의미가 없음
	n수식이 복잡해도 제일 증가폭이 큰 친구로만 빅오 표현

	p30 time complexity
	O(1) > O(logn) > O(n) > O(n log n) > O(n ^ 2) > O(n ^ 3) > O(2 ^ n) ? O(n!)...
	(성능)

	일반적인 알고리즘 : O(n ^ 3)

	Space complexity

	================================================== =

	02. 순환 Recursion p40

	순환의 예 : factorial 계산
	자기호출 함수

	recursion의 문제점
	자원소모가 심함
	숫자가 커질수록 메모리를 무한대로 먹음

	~p46
*/