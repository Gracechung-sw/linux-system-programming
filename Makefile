# 해당 프로젝트 빌드를 위한 make 파일을 작성한다. 
# 파일 내용
# 	- Makefile
# 	- ui/gui.c, input.c
# 	- web_server/webserver.c
# 	- system/system_server.c
# 빌드
# 	- make
# 빌드 결과물(실행 파일)
# 	- toy_system

# 컴파일러 설정
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# 디렉토리 설정
SRC_DIR = ui system web_server
BUILD_DIR = build
BIN_DIR = bin

# 소스 파일 및 객체 파일 목록
SRCS = $(wildcard $(addsuffix /*.c, $(SRC_DIR)))
OBJS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(notdir $(SRCS)))

# 실행 파일 설정
TARGET = $(BIN_DIR)/toy_system

# 빌드 명령어
all: $(BUILD_DIR) $(BIN_DIR) $(TARGET)

# 빌드 디렉토리 및 실행 파일 디렉토리 생성
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# 실행 파일 빌드
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# 개별 소스 파일 컴파일
$(BUILD_DIR)/%.o: ui/%.c system/%.c web_server/%.c system/system_server.h ui/gui.h ui/input.h web_server/web_server.h
	$(CC) $(CFLAGS) -c $< -o $@

# 각 소스 파일들의 의존성 설정
$(BUILD_DIR)/%.o: ui/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I./system -I./ui -I./web_server -c $< -o $@
$(BUILD_DIR)/%.o: system/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I./system -I./ui -I./web_server -c $< -o $@
$(BUILD_DIR)/%.o: web_server/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I./system -I./ui -I./web_server -c $< -o $@



# 정리 작업
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean
