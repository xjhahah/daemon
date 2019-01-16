#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>


using namespace std;

void mydaemon()
{
  umask(0);

  pid_t pid =fork();
  if(pid<0)
  {
    cout<<"fork false"<<endl;
  }
  else if(pid > 0)
  {
    exit(0);
  }
  setsid();  //创建一个会话

  signal(SIGCHLD,SIG_IGN);//忽略SIGCHLD信号
  chdir("/");  //从根目录开始

  //会重定向到 /dev/null
  close(0);
  close(1);
  close(2);

}

int main()
{
  mydaemon();
  //daemon(1,1);
  while(1)
  {
    sleep(1);
  }
  return 0;
}
