#include <stdio.h>

char* reverse(char *word);

int main(int argc, char const *argv[])
{
	char word[] = "happy birthday!";

	printf("%s\n", word);
	printf("%s\n", reverse(word));
	return 0;
}

char* reverse(char *word)
{
	int ctr;
	while (word[ctr] != '\0'){
		ctr++;
	}
	char p[ctr];
	int i =0;
	int j = 0;

	for (i = ctr - 1; i >= 0; i--){
		p[j] = word[i];
		j++;
	}
	for (i = 0; i < ctr; i++){
		word[i] = p[i];
	}
	return word;


}