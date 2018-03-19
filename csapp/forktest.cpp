#include<unistd.h>
#include<sys/types.h>
#include<iostream>
using namespace std;
int main(void){
	int pid;
	pid=fork();
	cout<<pid<<endl;
	return 1;}

