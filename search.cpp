#include <iostream.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char wordsearch[12][12]=
	{
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
	};


class Search
{
private:
	int guess_x;
	int guess_y;
	int wordsleft;
public:
	void Intro();
	void Randomletters();
	void Wordbank();
	void Placewords(char word[]);
	void Showboard();
	void Outro();
}player1;


void Search::Intro()
{
	cout<<" ________________________________________________________ "<<endl;
	cout<<"| Welcome to Word Search                                 |"<<endl;
	cout<<"|--------------------------------------------------------|"<<endl;
	cout<<"|                                                        |"<<endl;
	cout<<"|                                                        |"<<endl;
	cout<<"|                                                        |"<<endl;
	cout<<"|                                                        |"<<endl;
	cout<<"|                                                        |"<<endl;
	cout<<"|                                                        |"<<endl;
	cout<<"|                                                        |"<<endl;
	cout<<"| Good luck                                              |"<<endl;
	cout<<"|________________________________________________________|"<<endl;
	cout<<endl;
	system("pause");
}


void Search::Randomletters()
{
	srand(time(0));
	for (int a=0;a<12;a++)
	{
		for (int b=0;b<12;b++)
		{
			if (wordsearch[a][b]==' ')
				wordsearch[a][b]=(char)(rand()%26+65);
			else {}
		}
	}
	system("cls");
}


void Search::Wordbank()
{
	int wordnumber[6]={0,0,0,0,0,0};
	int x=0;

		while(x!=6)
			{
				int randomword=rand()%5+1;
				//int randomword=1;

				if (randomword==1)
				{
					if (wordnumber[1]!=1)
					{
						char word[5]={'@','!','!','!','\0'};
						wordnumber[1]=1;
						x++;
						Placewords(word);
					}

					else
					{
						randomword++;
					}


				}

				else if (randomword==2)
				{
					if (wordnumber[2]!=1)
					{
						char word[6]={'&','!','!','!','!','\0'};
						wordnumber[2]=1;
						x++;
						Placewords(word);
					}

					else
					{
						randomword++;
					}


				}


				else if (randomword==3)
				{
					if (wordnumber[3]!=1)
					{
						char word[7]={'+','!','!','!','!','!','\0'};
						wordnumber[3]=1;
						x++;
						Placewords(word);
					}

					else
					{
						randomword++;
					}


				}


				else if (randomword==4)
				{
					if (wordnumber[4]!=1)
					{
						char word[8]={'%','!','!','!','!','!','!','\0'};
						wordnumber[4]=1;
						x++;
						Placewords(word);
					}

					else
					{
						randomword++;
					}


				}


				else if (randomword==5)
				{
					if (wordnumber[5]!=1)
					{
						char word[9]={'~','!','!','!','!','!','!','!','\0'};
						wordnumber[5]=1;
						x++;
						Placewords(word);
					}

					else
					{
						randomword++;
					}


				}


				else if (randomword==6)
				{
					if (wordnumber[6]!=1)
					{
						char word[9]={'*','!','!','!','!','!','!','!','\0'};
						wordnumber[6]=1;
						x++;
						Placewords(word);
					}

					else
					{
						randomword++;
					}


				}

		

			}
	
}


void Search::Placewords(char word[])
{
	int place_x=rand()%12;
	int place_y=rand()%12;
	int charsinword=strlen(word);
	int direction=rand()%4;


	if (direction==0) //Move Left
	{
		if (charsinword>(place_y+1))
		{
			Placewords(word);
		}
		else
		{
			int value=0;
			for (int lettercheck=0;lettercheck<charsinword;lettercheck++)
			{
				if (wordsearch[place_x][place_y-value]!=' ')
				{
					if (wordsearch[place_x][place_y-value]==word[lettercheck])
						value++;
					else
						Placewords(word);
				}
				else
					value++;
			}
			int y=0;
			for (int placeme=0;placeme<charsinword;placeme++)
			{
			wordsearch[place_x][place_y-y]=word[placeme];
			y++;
			}
		}
	}

	else if (direction==1) //Move Down
	{
		if (charsinword>(11-place_x))
			Placewords(word);
		else
		{
			int value=0;
			for (int lettercheck=0;lettercheck<charsinword;lettercheck++)
			{
				if (wordsearch[place_x+value][place_y]!=' ')
				{
					if (wordsearch[place_x+value][place_y]==word[lettercheck])
						value++;
					else
						Placewords(word);
				}
				else
					value++;
			}
			int y=0;
			for (int placeme=0;placeme<charsinword;placeme++)
			{
			wordsearch[place_x+y][place_y]=word[placeme];
			y++;
			}
		}

	}

	else if (direction==2) //Move Right
	{
		if (charsinword>(11-place_y))
			Placewords(word);
		else
		{
			int value=0;
			for (int lettercheck=0;lettercheck<charsinword;lettercheck++)
			{
				if (wordsearch[place_x][place_y+value]!=' ')
				{
					if (wordsearch[place_x][place_y+value]==word[lettercheck])
						value++;
					else
						Placewords(word);
				}
				else
					value++;
			}
			int y=0;
			for (int placeme=0;placeme<charsinword;placeme++)
			{
			wordsearch[place_x][place_y+y]=word[placeme];
			y++;
			}
		}

	}

	else //Move Up
	{
		if (charsinword>(place_x+1))
			Placewords(word);
		else
		{
			int value=0;
			for (int lettercheck=0;lettercheck<charsinword;lettercheck++)
			{
				if (wordsearch[place_x-value][place_y]!=' ')
				{
					if (wordsearch[place_x-value][place_y]==word[lettercheck])
						value++;
					else
						Placewords(word);
				}
				else
					value++;
			}
			int y=0;
			for (int placeme=0;placeme<charsinword;placeme++)
			{
			wordsearch[place_x-y][place_y]=word[placeme];
			y++;
			}
		}
	}
	
}


void Search::Showboard()
{
	for (int a=0;a<12;a++)
	{
		for (int b=0;b<12;b++)
		{
			cout<<wordsearch[a][b]<<"  ";
		}
		cout<<endl;
	}
}


void Search::Outro()
{


}


int main()
{
	srand(time(0));
	Search thissearch;
	thissearch.Intro();
	thissearch.Wordbank();
	thissearch.Randomletters();
	thissearch.Showboard();
	thissearch.Outro();

	return 0;
}