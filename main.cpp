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
		
	public:
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

		//constructor
		//not started
		tournament(std::string tournament_name);
		tournament(std::string tournament_name, std::vector <player> players);
		
		//main function for tournament (menu)
		//not started
		void main();
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
tournament add_tournament();					//complete
tournament add_tournament(std::string input);	//complete

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
			tour.push_back(add_tournament());
		else if(input == "exit")
			break;
		else if(input == "enter")
			enter_tournament(&tour);
		else if(input == "load")
			tour.push_back(load_tournament());
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

tournament add_tournament()
{
	std::string name;
	getline(name, std::cin);
	while(name == "help")
	{
		name_new_tournament_help();
		getline(name, std::cin);
	}
	return add_tournament(name);
}

tournament add_tournament(std::string input)
{
	tournament output(input);
	return output;
}

