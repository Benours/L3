#include <stdio.h>

char *s;

void g(void){
	printf("%c\n", s[0]);
}

void f(void){
	g();
}

int main(){
	f();
}