#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct uniqueWord
{
	string word;
	int count;
};

int main(){
	int N = 99778; //number of words in original Text file

	ifstream infile;
	infile.open("cleanedText.txt");
	string tempString;

	uniqueWord Array[N]; //Array named A to hold informtion on words from text
	int size=0;
	int numUnique = 0;
	bool indicator;
	int valueRepeated;
	while(infile>>tempString)  	//use a set of nested loops
	{
		size++;
		indicator = true;

			for(int i=0;i<numUnique;i++){
					if(tempString == Array[i].word){
						indicator = false; //indicator states FALSE when the word is not unique
						valueRepeated = i;
					}	
						
			}

		
		if(indicator == true){
			Array[numUnique].word = tempString;
			Array[numUnique].count = 1;
			numUnique++;
		}
		else{ //when indicator == false	
			Array[valueRepeated].count++;
		}	
	}
//sort in ascending order
	uniqueWord temp;
	int i;
	for(i=0;i<numUnique;i++)
	 {
		 for(int h=0;h<numUnique-i;h++)
		 {
		 	if(h+1<numUnique)
		 	{
			 if(Array[h].count > Array[h+1].count)
			 {
				 temp = Array[h];
				 Array[h]=Array[h+1];
				 Array[h+1]=temp;
			 }
			}		
		 }
	 }

		ofstream outCount;				
		outCount.open("counts.txt");

		for(int i=0;i<numUnique;i++)
		{
		if(i!=numUnique-1)
			outCount<<Array[i].count<<" \n";
		else
			outCount<<Array[i].count;
		}


		ofstream outWord;
		outWord.open("words.txt");

		for(int i=0;i < numUnique;i++)
		{
		if(i!=numUnique-1)
			outWord<<Array[i].word<<" \n";
		else
			outWord<<Array[i].word;
		}


cout<<"There are "<<numUnique<<" unique words in the file."<<endl;
cout<<endl;

cout<<"10 Least Frequect Unique Words: "<<endl;
for(int i=0;i<10;i++)
	cout<<Array[i].word<<" occurs "<<Array[i].count<<" times."<<endl;
cout<<endl;
cout<<"10 Most Frequect Unique Words: "<<endl;
for(int i=numUnique-10;i<numUnique;i++)
	cout<<Array[i].word<<" occurs "<<Array[i].count<<" times."<<endl;
	return 0;
}