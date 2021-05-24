# ft_printf

<br>

## Mandatory Part

### 프로토타입

`int printf(const char * restrict format, ...);`

### 서식 문자

`c` : 문자

`s` : 문자열 → 정밀도(byte)만큼 출력, 정밀도가 0이거나 없는 경우 전체를 출력

`p` : 포인터 주소

`d` `i` : 부호 있는 10진법 정수

`u` : 부호 없는 10진법 정수

`x` `X` : 부호 없는 16진법 정수

`%` : `%` 문자 출력, 인자 불필요

### 리턴값

성공 시 : 출력한 byte 수

실패 시 : 음수

### 허용 함수

`malloc` `free` `wirte` 

`void va_start(va_list ap, last)`

처음으로 호출되어 `ap` 를 초기화함
`last` 는 가변인자 이전의 마지막 인자의 이름을 의미하며 선언 시 `register` 키워드를 사용하면 안 됨

`type va_arg(va_list ap, type)`

호출할 때마다 다음 전달인자를 리턴함, `type` 은 포인터형을 지정함(*을 제외하고 명시)
다음 전달인자가 없거나 type이 호환되지 않는 경우 `random error` 발생

`void va_copy(va_list dest, va_list src)`

초기화된 `src` 의 상태를 초기화되지 않은 `dest` 로 복사함
`dest` 는 `va_start` 에 의해 초기화되지 않으며 `va_end` 에 의해 무효화되지 않은 상태여야 함

`void va_end(va_list ap)`

더 이상의 전달인자가 없다는 시그널이며 `ap` 를 무효화함
무효화된 `ap` 는 다시 `va_start` 나 `va_copy` 에 의해 초기화될 수 있음
동일한 함수 내에서 `va_start` 와 `va_end` 는 쌍을 이루어야 함

### 주의사항

1. 실제 printf 함수와 동일하게 동작해야 함
2. 실제 printf 함수처럼 버퍼 관리를 하지 않아야 함
3. 라이브러리 생성을 위해 ar 명령어를 사용해야 함
4. `c` `s` `p` `d` `i` `u` `x` `X` `%` 서식 문자를 구현해야 함
5. 모든 형식지정자에 대해 `-0.*` 플래그와 최소 필드 너비를 조합하여 사용할 수 있어야 함

<br>

## Bonus Part

- `n` `f` `g` `e` 중 하나 이상의 서식 문자 구현하기
- `l` `ll` `h` `hh` 중 하나 이상의 플래그 구현하기
- `#`  `` `+` 플래그 모두 구현하기

### 서식 문자

`n` : 인자로 받은 `int *` 변수에 현재까지 쓴 문자의 수를 저장함 (출력 X)

`e` : 지수 표기법 → d.dddddde+dd, 소수점 위는 한 자리, 소수점 아래는 정밀도에 따라 출력 (default: 6) `inf` `nan`

`f` : 십진법 부동 소수점 → ddd.dddddd, 소수점 아래는 정밀도에 따라 출력 (default: 6)

`g` : `%e` `%f` 중 완전한 정밀도를 나타내는 데 더 적은 공간이 사용되는 방법으로 출력

### 플래그

`hh` : `d` `i` → `signed char` , `u` `x` `X` → `unsigned char` , `n` → `signed char *`

`h` : `d` `i` → `short` , `u` `x` `X` → `unsigned short` , `n` → `short *`

`l` : `d` `i` → `long` , `u` `x` `X` → `unsigned long` , `n` → `long *`

`ll` : `d` `i` → `long long` , `u` `x` `X` → `unsigned long long` , `n` → `long long *`

`#` : `c` `s` `p` `d` `i` `u` `n` 와 사용 시 영향이 없음

       `x` `X` 와 사용 시 앞부분에 `0` 을 붙여 `0x` `0X` 로 표기함
       `e` `f` 와 사용 시 강제적으로 소수점을 표기함
       `g` 와 사용 시 강제적으로 소수점을 표기하면서 소수점 아래 `0` 을 제거하지 않음

 ` ` : 출력값이 양수인 경우 앞부분에 공백을 포함함

`+` : 출력값이 양수인 경우 앞부분에 `+` 를 표기함
