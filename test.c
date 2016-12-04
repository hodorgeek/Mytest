#include<stdio.h>
int main()
{
	char i = '1';
	switch(i)
	{
		case '1':
			printf("Hello");
		case '2' + '3':
			printf("there");
			break;
		case '5':
			printf("linkedin");
			break;
		default:
			printf("Hello linked");
	}		
	return 0;
}
