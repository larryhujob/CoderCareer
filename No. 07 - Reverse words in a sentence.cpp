#include <iostream>
#include <string>
using namespace std;



void reverseWord(string& str, int i, int j)
{
	while(i < j)
	{
		char tem = str[i];
		str[i] = str[j];
		str[j] = tem;
		i++;
		j--;
	}

}

void reverseSentence(string& str)
{
	if(str.empty())
		return ;
	int n = str.size();
	reverseWord(str,0,n-1);
	bool inWord = false;
	int start = 0;
	for(int i = 0; i < n; i++)
	{
		if(str[i] == ' ' && inWord)	//end
		{
			inWord = false;
			reverseWord(str,start,i-1);
		}
		else if(str[i] != ' ' && !inWord) // begin
		{
			inWord = true;
			start = i;
		}

	}
	if(inWord)
		reverseWord(str,start,n-1);
}
