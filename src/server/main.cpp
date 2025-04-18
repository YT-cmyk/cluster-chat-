#include "chatserver.hpp"
#include "chatservice.hpp"
#include <iostream>
#include <signal.h>
using namespace std;

// 处理服务器ctrl+c结束后，重置user的状态信息
void resetHandler(int)
{
    ChatService::instance()->reset();
    exit(0);
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        cerr << "command invalid! example: ./ChatServer 127.0.0.1 6000" << endl;
        exit(-1);
    }

    // 解析通过命令行参数传递的ip和port
    char *ip = argv[1];
    uint16_t port = atoi(argv[2]);

    signal(SIGINT, resetHandler);
    /*
    设置信号处理函数的系统调用，主要用于捕获和处理特定的信号
    SIGINT：
        信号编号（Interrupt Signal）
        通常由用户按下 Ctrl+C 产生
        信号值为 2
    resetHandler：
    信号处理函数指针
    当收到 SIGINT 信号时，操作系统会调用此函数
    函数形式应为：void handler_func(int sig)
    */

    EventLoop loop;
    InetAddress addr(ip, port);
    ChatServer server(&loop, addr, "ChatServer");

    server.start();
    loop.loop();

    return 0;
}