#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){

	ifstream inText;
	inText.open("HungerGames.txt");

	ifstream inIgnore;
	string temp; //variable to temporarily hold ignored words

	string tempString; // variable to temporarily hold words from the Text
	int indicator; //indicates if current Text word is an Ignored word

	ofstream outfile;
	outfile.open("cleanedText.txt");


	while(inText >> tempString)
		{
			inIgnore.open("ignoreWords.txt");

			while(inIgnore >> temp && indicator == 0)
				{
//indicates if the word from the text file is any of the 50 ignored words
					if(tempString == temp) 
						{
							indicator = 1;
						}
				}
			
			if(indicator == 0)
				{
					outfile <<tempString<<" ";	
				}
			indicator = 0;
			inIgnore.close();
		}


	return 0;
}