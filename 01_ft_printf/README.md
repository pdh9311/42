# ft_printf

> ft_printf 는 C에서 출력할때 자주 사용되는 printf 함수를 직접 구현하고 정적 라이브러리 파일(`libftprintf.a`)로 만들어 냅니다.

## 프로토 타입
```c
int ft_printf(const char *, …);
```

## 구현 해야하는 부분
- 서식 지정자 : cspdiuxX%
- 플래그 : '-0.*'

## 이해도가 향상되는 부분
- 메모리 누수에 대한 이해
- 가변인자를 사용 방법

## 실행 방법
- 라이브러리를 생성하는 명령어 : `make`

---
## 배운내용 Notion에서 확인
https://donpark.notion.site/ft_printf-76-56-20day-f682f2429f344a9ea27171457d2e6e28