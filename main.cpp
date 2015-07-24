#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

//defined constants
#define PROGRAM_NAME "Jacksan Wail"

//class declarations:
class tournament;
class player;

//class definitions:
class tournament {
	private:
		std::vector <player> player_list;			//players
		std::vector <unsigned int> players_out_of_game; 
		
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
tournament open(std::ifstream savedFile);
tournament open(std::string fileLocation);


//main function:
int main()
{
	//intro to program
	std::cout << "Welcome to " << PROGRAM_NAME << ".\nPlease enter the code for what you would like to do.\nTyping \"help\" at any time will give you a list of commands.\n";
	
	
	return 0;
}


//function definitions:
void tournament::add_player(std::string new_player)
{
	player a;
	a.name = new_player;
	tournament.player_list.push_back(a);
}
