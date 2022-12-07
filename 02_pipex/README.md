# pipex

> pipex 프로젝트는 shell의 파이프(`|`) 와 리다이렉트(`<<`, `>>`, `<`, `>`)를 직접 구현합니다.  

-  아래와 같이 `./pipex` 실행파일의 인자로 file 과 cmd 를 넘겨서 
    ```bash
    ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
    ```
- shell 명령어로 아래와 같이 입력한 결과와 같도록 구현되어 있습니다.
    ```bash
    < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
    ```
---
## 실행 명령어
-  실행파일을 만드는 명령어 : `make`
-  실행파일을 테스트하는 명령어 : `./_pipex.sh`
    - 테스트 결과 
        ```bash
        ./pipex infile wc rev outfile && cat outfile
        87 61 3 
        < infile wc | rev > outfile && cat outfile
        87 61 3 

        ./pipex infile grep a rev outfile && cat outfile
        zyx wv utsrq ponmlk jihgfed cba
        < infile grep a | rev > outfile && cat outfile
        zyx wv utsrq ponmlk jihgfed cba

        ./pipex infile grep 1 rev outfile && cat outfile
        9876543210
        < infile grep 1 | rev > outfile && cat outfile
        9876543210

        ./pipex infile grep A rev outfile && cat outfile
        ZYXW VUT SRQ PONMLKJI H G FE DC BA
        < infile grep A | rev > outfile && cat outfile
        ZYXW VUT SRQ PONMLKJI H G FE DC BA

        ./pipex infile grep A rev wc outfile && cat outfile
            1       9      35
        < infile grep A | rev | wc> outfile && cat outfile
            1       9      35

        ./pipex infile wc wc wc wc  outfile && cat outfile
            1       3      24
        < infile wc | wc | wc | wc > outfile && cat outfile
            1       3      24

        ./pipex infile grep a rev outfile && cat outfile
        zyx wv utsrq ponmlk jihgfed cba
        < infile grep a | rev > outfile && cat outfile
        zyx wv utsrq ponmlk jihgfed cba

        ./pipex infile grep a rev rev outfile && cat outfile
        abc defghij klmnop qrstu vw xyz
        < infile grep a | rev | rev > outfile && cat outfile
        abc defghij klmnop qrstu vw xyz

        ./pipex infile grep a rev rev rev outfile && cat outfile
        zyx wv utsrq ponmlk jihgfed cba
        < infile grep a | rev | rev | rev > outfile && cat outfile
        zyx wv utsrq ponmlk jihgfed cba

        ./pipex infile grep a rev rev rev rev outfile && cat outfile
        abc defghij klmnop qrstu vw xyz
        < infile grep a | rev | rev | rev | rev > outfile && cat outfile
        abc defghij klmnop qrstu vw xyz

        ./pipex infile grep a rev rev rev rev rev outfile && cat outfile
        zyx wv utsrq ponmlk jihgfed cba
        < infile grep a | rev | rev | rev | rev | rev > outfile && cat outfile
        zyx wv utsrq ponmlk jihgfed cba

        ./pipex infile grep a rev rev rev rev rev rev outfile && cat outfile
        abc defghij klmnop qrstu vw xyz
        < infile grep a | rev | rev | rev | rev | rev | rev > outfile && cat outfile
        abc defghij klmnop qrstu vw xyz

        ./pipex infile grep a rev rev rev rev rev rev rev outfile && cat outfile
        zyx wv utsrq ponmlk jihgfed cba
        < infile grep a | rev | rev | rev | rev | rev | rev | rev > outfile && cat outfile
        zyx wv utsrq ponmlk jihgfed cba

        ./pipex infile grep a rev rev rev rev rev rev rev rev outfile && cat outfile
        abc defghij klmnop qrstu vw xyz
        < infile grep a | rev | rev | rev | rev | rev | rev | rev | rev > outfile && cat outfile
        abc defghij klmnop qrstu vw xyz

        ./pipex infile grep a rev rev rev rev rev rev rev rev rev outfile && cat outfile
        zyx wv utsrq ponmlk jihgfed cba
        < infile grep a | rev | rev | rev | rev | rev | rev | rev | rev | rev > outfile && cat outfile
        zyx wv utsrq ponmlk jihgfed cba
        ```
---
## 배운내용 Notion에서 확인
https://donpark.notion.site/Pipex-67-46-21day-db9e4a8350d7495694055f08744d6dcb