예전에 한번 시도했었다가 DP인것 같아 많이 고민했던 문제

계속 생각해보니 이게 될까 싶었지만 해결했다.

이 문제를 풀 수 있었던 생각은 다음과 같다.

1. 2번 누르면 원래 상태가 되는 행.
2. 한 행이 켜져있다는 것을 가정한 것.

한 행이 켜져있다고 생각해보자. 
그리고 그 행을 위해서 열의 버튼을 누르기 시작하면, 
그 한 행을 키기 위한 상황은 단 한가지만 나온다.
절대 그 행을 키기 위한 2가지 이상의 상황은 나오지 않는다. 

열의 버튼이 한 행에 종속되어 있다고 생각하면 된다. 
열의 상황은 2가지만 존재한다. 
1. 버튼을 누르지 않은 상황
2. 버튼을 누른 상황

이 열의 상황은 한 행을 키기 위해서 2가지중 무조건 한 상태에 존재하게 된다. 