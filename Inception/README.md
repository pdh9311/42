# Inception
> **Inception** 프로젝트는 가상 머신(Virtual Box)에서 docker 를 사용해서 아래와 같은 환경을 구성합니다.  
dockerHub에 이미 만들어진 nginx, mariadb, wordpress를 사용하는게 아니라  
`debian:buster` 이미지를 기반으로 각각의 컨테이너를 설정해본 프로젝트입니다.


<image src="readme-image/inception-structure.png" height="800" />

## Folder Structure

```bash
.
├── Makefile
└── srcs
    ├── docker-compose.yml
    └── requirements
        ├── mariadb
        │   ├── Dockerfile
        │   ├── conf
        │   │   └── query.sql
        │   └── tools
        │       └── setup.sh
        ├── nginx
        │   ├── Dockerfile
        │   └── conf
        │       └── default
        ├── tools
        │   └── setup.sh
        └── wordpress
            ├── Dockerfile
            └── tools
                └── setup.sh
```

## 실행방법

1. 환경 구성 명령어 : `make`
2. `https://localhost:443` 또는 `https://donpark.42.fr` 로 접속
	![](readme-image/inception-main.png)


---
## 배운내용 Notion에서 확인
https://donpark.notion.site/Inception-91-42-49day-45ce3ba4231544fb918acfea967eb7ab
