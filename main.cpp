-#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

//defined constants
#define PROGRAM_NAME "Jacksan Wail"

//global variables
bool ReadFromCin = true;

//class declarations:
class tournament;
class player;

//class definitions:
class tournament {
	private:
		std::vector <player> player_list;			//players
		std::vector <unsigned int> players_out_of_game;
		std::string name;							//tournament name
		
		//gives new game(s)
		//not started
		void start_game();
		
		//adds a player to the player list
		//complete
		void add_player(std::string name);
		
		//saves the standings to a file
		//not started
		void save(std::ofstream);
		
		//prints the standings to terminal
		//not started
		void print();
		
		//takes in a game and a result, then tries to pair new game
		//not started
		void end_game(unsigned int player);
		void end_game(std::string player);
		
	public:

		//constructor
		//not started
		tournament(std::string tournament_name);
		tournament(std::string tournament_name, std::vector <player> players);
		
		//main function for tournament (menu)
		//not started
		void main();
		
		//returns name
		//complete
		std::string get_name();
};

class player {
	private:
		std::vector <unsigned int> games_played;	//opponents played by the player
		unsigned int points = 0;					//points the player has
		std::string name;							//player's name
};


//function declarations:
//opens a saved, unfinished tournament
//not started
tournament load_tournament(std::ifstream savedFile);
tournament load_tournament(std::string fileLocation);

//reads the help for different areas in program
//not started
void main_help();
void name_new_tournament_help();

//creates a new tournament
//complete
tournament add_tournament(const std::vector <tournament> &list);

//enters a tournament
//in progress
void enter_tournament(std::vector <tournament> &list);

//main function:
int main()
{
	//intro to program
	std::cout << "Welcome to " << PROGRAM_NAME << ".\nPlease enter the command for what you would like to do.\nTyping \"help\" at any time will give you a list of commands and instructions.\n";
	std::string input;
	std::vector <tournament> tour;
	std::ifstream in = std::cin;
	
	//where the program runs
	do {
		in >> input;
		
		//commands:
		/*
			help - shows list of commands and prompts to give instruction
			new - opens new tournament
			exit - ends program
			load - loads a tournament
			enter - enters a loaded tournament
			read (not yet implemented) - reads from file as if user input
		*/
		
		//find what the command is
		if(input == "help")
			main_help();
		else if(input == "new")
			tour.push_back(add_tournament(tour));
		else if(input == "exit")
			break;
		else if(input == "enter")
			enter_tournament(tour);
		else if(input == "load")
			tour.push_back(load_tournament());
		else if(input == "list")
			readout(tour);
		else
			std::cout << "not a command, please use \"help\" to get list of commands\n";
	}while(true);
	
	//may want to put in something so that
	
	
	//goodbye
	return 0;
}


//function definitions:
void tournament::add_player(std::string new_player)
{
	player a;
	a.name = new_player;
	tournament.player_list.push_back(a);
}

std::string tournament::get_name()
{
	return name;
}

void add_tournament(std::vector <tournament> &vec)
{
	std::string name;
	do{
		getline(name, std::cin);
		if(name == "help")
			name_new_tournament_help();
		else
		{
			bool exit = true;
			for(int i = 0; i < vec.length(); i++)
			{
				if(vec[i].get_name() == name)
				{
					exit = false;
					break;
				}
			}
			if(exit)
				break;
			else
			{
				std::cout << "That name is already in use.\n";
			}
		}
	}while(true);
	
	
	tournament jim(name);
	return jim;
}

void enter_tournament(std::vector <tournament> &list)
{
	std::string input;
}