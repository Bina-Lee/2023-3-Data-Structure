//배열 : edge가 많을때 유리
//ll : edge가 별로 없을때 유리

//그래프 구성요소 : V,E vertex(node) edge(link)

//edge 종류 구분
    //undirected graph
    //directed graph
    //weighted graph : 가중치

//탐색 : 방문방법
    //DFS depth first search
    //BFS breadth first search
//특정 vertex에서 갈 수 있는, 도달할 수 있는 vertex를 모두 찾기 위해서

//===============

//spanning tree, 신장트리
//모든 vertex들을 연결된 subgraph
    //그냥 어떤 경로로던지 모든 vertex가 연결되어있으면 됨

//mininum spanning tree, 최소신장트리
//최소한의 edge 개수로 모든 vertex를 연결하는 spannig tree

//만약 weighted 그래프라고 하면, MST는 weight의 함이 최소가 되어야 함

//MST 응용
    //최소 비용으로 도로 건설
    //최소 비용으로 네트워크망 구축
    //etc...

//Cycle이 생성되면 MST를 못만듦

//MST 알고리즘
//Prim
//Kruskal

//Prim Algorithm : O(n^2)
//Vertex 기준
//1. 시작 vertex를 정함
//2. 시작vertex를 '포함'되었다고 표시
//3. 포함 vertex에서 불포함 vertex로 연결된 edge 중에 가장 작은 weight를 갖는 edge를 찾는다

//4. edge로 연결된 불포함 vertex를 '포함'되었다고 표시
//5. 3~4 반복, N-1개의 edge가 선택될 때까지

//Kruskal Algorithm : PrimA보다 빠름 : O(E log_E)
//edge 기준
//가장 작은 Weight를 갖는 Edge를 찾아서 순서대로 추가
//1. 가장 작은 weight를 갖는 edge선택
//2. 연결하려는 edge의 vertex 둘이 family인지 검사
    //union-find 과정
//2-1. family가 아니면 edge를 MST에 추가
//2-2. 둘을 family로 만듦

//3. 1~2 반복, N-1개의 edge가 선택될때까지

//family 판별법

//===========================

//graph알고리즘의 꽃 : Dijkstra Algorithm : 최단경로찾기 알고리즘
    //네비게이션
    //게임 유닛 이동은 A* Algorith...ㅋㅋ Dijkstra 진화버전

//특정 출발점에서 다른 모든 지점까지의 최단거리를 뽑아냄