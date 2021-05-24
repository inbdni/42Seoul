# get_next_line

## Mandatory Part

### 프로토타입

`int get_next_line(int fd, char **line)`

`fd` : 파일 디스크립터

`line` : 이전에 읽은 값

### 리턴값

`1` : 라인을 읽은 경우

`0` : EOF까지 읽은 경우

`-1` : 오류가 발생한 경우

### 파일명

`get_next_line.h` 

`get_next_line.c` 

`get_next_line_utils.c`

### 허용 함수

`malloc` `free`

`ssize_t read(int fd, void *buf, size_t nbytes)`

### 주의사항

1. BUFFER_SIZE 매크로 변수 사용하기
2. `gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c` 명령으로 컴파일하기
→ `-D` 옵션은 define 하기 위한 것
1. `libft` 사용 금지, 필요한 함수는 `get_next_line_utils.c` 에 작성하기
2. 파일의 끝(EOF)까지 반복해서 `get_next_line` 함수를 호출하며, 한 번 호출될 때 한 줄 씩 읽고, 개행은 버퍼에 포함하지 않기
3. 전역변수 금지
4. 바이너리 파일의 경우는 정의하지 않기
5. 한 파일을 끝까지 읽기 전에 파일디스크립터가 다른 파일로 바뀌는 경우는 정의하지 않기
6. [https://en.wikipedia.org/wiki/Static_variable](https://en.wikipedia.org/wiki/Static_variable) 참고
7. static 변수는 초기화하지 않으면 bss영역에 할당되어 0으로 초기화되고, 초기화하면 data영역에 할당됨
8.  빈 파일을 읽은 경우, 빈 문자열을 할당하고 0을 반환하면 됨

### 질문
1. 버퍼 사이즈를 `1`, `9,999`, `10,000,000` 으로 해도 동작하는가? 그 이유를 아는가?
→ 제대로 동작해야 함
1. 새 줄을 만나면 현재 줄을 반환해야 한다. 파일 전체를 읽고 각 줄을 처리하면 안된다.
2. 표준 파일, 리디렉션, 표준 입력으로부터 읽기를 시도해야 한다. 표준 입력에서 개행과 ctrl-d를 입력하면 어떻게 되는가?

## Bonus Part

- 하나의 정적 변수로 get_next_line 구현하기
- 여러 개의 파일 디스크립터로 각 파일을 읽을 수 있어야 함
