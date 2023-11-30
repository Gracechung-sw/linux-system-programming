#include <stdio.h>

#include <system_server.h>
#include <gui.h>
#include <input.h>
#include <web_server.h>

int create_gui()
{
    pid_t systemPid;

    printf("여기서 GUI 프로세스를 생성합니다.\n");

    sleep(3);
    /* fork + exec 를 이용하세요 */
    /* exec으로 google-chrome-stable을 실행 하세요. */

    switch (systemPid = fork()) {
    case -1:
        printf("fork failed\n");
    case 0:
        // 자식 process일 경우, chrome browser를 띄우는데, 이 "http://localhost:8282" 주소로 브라우저가 떠지게 하는 역할을 실행시킨다. 
        if (execl("/usr/bin/google-chrome-stable", "google-chrome-stable", "http://localhost:8282", NULL)) {
            printf("execfailed\n");
        }
        break;
    default:
        break;
    }

    return 0;
}
