1. int *f(int, int);
2. int (*f)(int, int);
3. int (*f(int))(int, int);
4. int *(*f)(int, int);
5. int *(*f)(int, int)(int);
6. int (*p[10])(int *);
7. int (*(*p)[10])(int *);

void (*signal(int signo, void (*func)(int)))(int);

typedef void (*func)(int);

func signal(int, func);

int Inta;
typedef int Inta;
Inta a;

unsigned int UInta;
typedef unsigned int Uinta;
Uinta ua;

typedef int A[];

A a;
