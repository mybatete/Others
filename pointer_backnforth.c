
#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
 int main(){
	 char dog[] = "ab";
	 char *padrito = nullptr;
	 padrito =dog;
	 cout << strcmp(padrito, "aa") << endl;
	 cout << strlen(dog) <<endl;
	 return 0;
	 
 }
