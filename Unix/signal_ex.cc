#include <iostream>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h> // pause()

using namespace std;

void sig_usr(int s)
{
    cout << "s is " << s << endl;
    cout << "SIGUSR1 is " << SIGUSR1 << endl;
    cout << "SIGUSR2 is " << SIGUSR2 << endl;
}

int main()
{
    if (signal(SIGUSR1, sig_usr) == SIG_ERR)
        cout << "error" << endl;
    if (signal(SIGUSR2, sig_usr) == SIG_ERR)
        cout << "error" << endl;
    for (;;)
        pause();
}
