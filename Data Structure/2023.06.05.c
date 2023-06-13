//hashing

//O(1)
//메모리가 많이 필요함
//산술연산을 적용하여 항목이 저장된 주소 계산

//hash table
//hash해서 데이터가 들어가는 공간
//그냥 array

//hash function
//hash address를 반환

//key
//유일해야함

//value (data)

//value = hash_function(key)

//bucket

//slot

//collision 충돌
//서로 다른 key들이 동일한 hash address를 갖는 현상
//overflow
    //collision 발생시 bucket에 빈 slot이 없는 현상
    //linked list로 확장
    //linear probing k+1, k+2 bucket으로 빈 Bucket 탐색
    //quadratic probing k+1^2, k+2^2, k+3^2 bucket으로 빈 bucket 탐색
        //일반적으로 collision이 일어나는 곳은 밀집되어있기 때문에 회피시킴
    //double hashing

//해싱성능분석
//loading density / loading factor 적재밀도
//a=n(데이터 개수)/M(전체 저장용량)

//loading density a와 평균 탐색 횟수
    //성공 : 1/2 * (1 + 1/(1-a))
    //실패 : 1/2 * (1 + 1/ (1-a)^2)

//hashing 응용 : SHA-256
    //Secure Hash Algorithm
    //hash address : 256bit
    //무조건 32byte 출력
    //무결성 검증에 사용
    //hash address로 입력데이터 복구 불가
    

