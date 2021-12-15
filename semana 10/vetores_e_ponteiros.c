#include <stdio.h>

int main(){

	char vetor[2][2][2][2] = {
		{
			{{'b','f'}, {'g', 'l'}},
			{{'m', 'l'},{'k', 's'}}
		}, 
		
		{
			{{'c','m'}, {'p', 'l'}},
			{{'j', 'p'},{'p', 'n'}}
		}
	};

	printf("%c\n", *(*(*(*(vetor)))) );             

	return 0;
}
