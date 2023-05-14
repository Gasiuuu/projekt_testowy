#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>

using namespace std;


struct stos
{
    int *dane;
    int ile;
    int top;
};



void init(stos *s, int ile)
{
    s->ile = ile;
    s->top = 0;
    s->dane = new int[s->ile];
}


void destroy(stos *s)
{
    delete[] s->dane;
    s->ile = 0;
    s->top = 0;
}


void push(stos *s, int wartosc)
{
    s->dane[++s->top] = wartosc;
}


int pop(stos *s)
{
    return s->dane[--s->top];
}


int top(stos *s)
{
    return s->dane[s->top];
}


bool empty(stos *s)
{
    if(s->ile == 0)
    return 0;
    return 1;
}


bool full(stos *s, int ilosc)
{
    if(s->ile == ilosc)
    return 1;
    else
    return 0;
}




int main()
{

int i = 0;
stos s1;

srand(time(NULL));

int ilosc;
int liczba;

ilosc = rand()%100+1;


init(&s1, ilosc); // tworzenie miejsc na stosie w zaleznosci od ilosci liczb ktore zostana umieszczone na stosie

for(i=1; i<ilosc; i++) // umieszczanie liczb na stosie i wypisywanie kolejnych liczb na ekranie
{
    liczba = rand()%100+1;
    push(&s1, liczba);
    top(&s1);
    cout << s1.dane[i] << endl;
}

                               
    return 0;
}