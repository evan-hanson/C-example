#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	ifstream infile;
	infile.open("HungerGames.txt");
	string tempString;
	int count = 0;
	string firstHundred[100];
	
	ofstream outfile;
	outfile.open("testText.txt");
		
	while(infile >> tempString)
		{
			if(count<100)
				outfile <<tempString<<" ";

			count++;
		}
	cout<<"The Humger Games book has "<<count<<" words."<<endl;
	
	infile.close();
	outfile.close();
	return 0;
}