#include <stdio.h>
#include <sys/prctl.h>
/*
* <sys/prctl.h> 헤더 파일은 프로세스 관련 컨트롤을 위한 POSIX(Portable Operating System Interface) 시스템 콜을 정의하고 있습니다. 
* 주로 리눅스 시스템에서 사용되며, 프로세스에 대한 다양한 제어와 속성 설정을 위한 함수들을 포함하고 있습니다.
* 
* 그 중에서도 prctl() 함수는 프로세스의 동작에 대한 제어를 할 수 있도록 해주는 시스템 콜
    1. 프로세스 속성 설정: prctl()은 프로세스의 여러 속성을 설정하거나 가져올 수 있습니다. 예를 들어, 자식 프로세스의 종료 신호를 부모 프로세스에 전달하는 것과 같은 행동을 설정할 수 있습니다.
    2. 자원 관리: 프로세스가 사용하는 자원에 대한 제어를 할 수 있습니다. 예를 들어, 자원 관리를 위해 프로세스가 사용할 수 있는 최대 스택 크기를 조정하는 데 사용될 수 있습니다.
    3. 특정 동작 설정: 프로세스의 특정 동작을 제어하기 위해 사용될 수 있습니다. 예를 들어, 프로세스의 이름을 변경하거나, 프로세스의 간격(period)을 설정하여 커널에게 프로세스의 스케줄링 방법을 알려줄 수 있습니다.
*/

#include <system_server.h>
#include <gui.h>
#include <input.h>
#include <web_server.h>

int system_server()
{
    printf("나 system_server 프로세스!\n");

    while (1) {
        sleep(1);
    }

    return 0;
}

int create_system_server()
{
    pid_t systemPid;
    const char *name = "system_server";

    printf("여기서 시스템 프로세스를 생성합니다.\n");

    /* fork 를 이용하세요 */
    switch (systemPid = fork()) {
    case -1:
        printf("fork failed\n");
    case 0:
        /* 프로세스 이름 변경 */
        if (prctl(PR_SET_NAME, (unsigned long) name) < 0) // prctl의 프로세스의 이름을 변경 기능을 이용해서 프로세스 이름을 const char *name = "system_server"; 에서처럼 system_server로 변경. 
            perror("prctl()");
        system_server();
        break;
    default:
        break;
    }

    return 0;
}
