# 베이스 이미지 설정
FROM ubuntu:latest

# 환경 변수 설정 (선택사항)
ENV LANG C.UTF-8

# 패키지 업데이트 및 필수 패키지 설치
RUN apt-get update && \
    apt-get install -y \
    build-essential \  
    gcc \              
    g++ \              
    gdb \              
    make \            
    && rm -rf /var/lib/apt/lists/*

# 작업 디렉토리 생성 및 설정 (선택사항)
WORKDIR /root/code 
