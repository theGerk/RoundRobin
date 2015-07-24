#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

//class declarations:
class tournament;
class player;
class flexible_input;
class flexible_output;

//global constants
#define PROGRAM_NAME "Jacksan Wail"


//global variables
flexible_input fin;
flexible_output fout;

//class definitions:
class tournament {
	private:
		std::vector <player> player_list;			//players
		std::vector <unsigned int> players_out_of_game;
		std::string name;							//tournament name
		unsigned int rounds;
		
		//gives new game(s)
		//not started
		void start_game();
		
		//saves the standings to a file
		//not started
		void save(std::ofstream &save_file);
		
		//prints the standings to terminal
		//not started
		void print();
		
		//takes in a game and a result, then tries to pair new game
		//not started
		void end_game(unsigned int player);
		void end_game(std::string player);
		
		//adds players until exited
		//complete
		void registar();
		
	public:

		//constructor
		//not started
		tournament(std::ifstream file);
		tournament(std::string tournament_name);
		tournament(std::string tournament_name, std::vector <player> players);
		
		//main function for tournament (menu)
		//not started
		void main();
		
		//returns name
		//complete
		std::string get_name() const;
};

class player {
	private:
		std::vector <unsigned int> games_played;	//opponents played by the player
		std::vector <unsigned int> points;			//number of points the player has scored in each match
		std::string name;							//player's name
		
	public:
		//starts game
		//not started
		void start_game(unsigned int opponent);
		
		//adds points, ending game
		//not started
		unsigned int end_game(unsigned int points);
		
		//constructor
		//complete
		player(const std::string &input);
		
		//number of games played
		//complete
		unsigned int games_played() const;
		
		//returns number of points
		//not started
		unsigned int points() const;
		
		//returns the tie-break score
		//not started
		unsigned int tie_break(const std::vector <player> &player_table) const;
		
		//gets the name
		//not started
		std::string get_name() const;
};

class flexible_input {
	private:
		static std::ifstream feed;
		
		//checks for end of file and will close feed
		//not started
		void check_for_close();
		
	public:
		//sets feed to a file
		//not started
		setFeed(const std::string &name);
		
		//overloading << operator, takes in input
		//not started
		friend flexible_input operator <<(flexible_input &in_stream, bool &foo);
		friend flexible_input operator <<(flexible_input &in_stream, signed char &foo);
		friend flexible_input operator <<(flexible_input &in_stream, unsigned char &foo);
		friend flexible_input operator <<(flexible_input &in_stream, signed short &foo);
		friend flexible_input operator <<(flexible_input &in_stream, unsigned short &foo);
		friend flexible_input operator <<(flexible_input &in_stream, signed int &foo);
		friend flexible_input operator <<(flexible_input &in_stream, unsigned int &foo);
		friend flexible_input operator <<(flexible_input &in_stream, float &foo);
		friend flexible_input operator <<(flexible_input &in_stream, signed long &foo);
		friend flexible_input operator <<(flexible_input &in_stream, unsigned long &foo);
		friend flexible_input operator <<(flexible_input &in_stream, double &foo);
		friend flexible_input operator <<(flexible_input &in_stream, signed long long &foo);
		friend flexible_input operator <<(flexible_input &in_stream, unsigned long long &foo);
		friend flexible_input operator <<(flexible_input &in_stream, long double &foo);
		friend flexible_input operator <<(flexible_input &in_stream, std::string &foo);
		
		//getline equivalent
		//not started
		friend flexible_input operator <(flexible_input &in_stream, std::string &foo);
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
void enter_tournament_help();
void tournament_registar_help();

//creates a new tournament
//complete
void add_tournament(std::vector <tournament> &list);

//enters a tournament
//in progress
void enter_tournament(std::vector <tournament> &list);

//load's a tournament from external file
//not started
void load_tournament(std::vector <tournament> &list);

//reads the names of objects
//complete
void read_names(const std::vector <tournament> &input);	//complete
void read_names(const std::vector <player> &input);		//complete

//starts reading from a file
//not started
void startRead();


//main function:
int main()
{
	//intro to program
	std::cout << "Welcome to " << PROGRAM_NAME << ".\nPlease enter the command for what you would like to do.\nTyping \"help\" at any time will give you a list of commands and instructions.\n";
	std::string input;
	std::vector <tournament> tour;
	
	//where the program runs
	do {
		std::cin >> input;
		
		//commands:
		/*
			help - shows list of commands and prompts to give instruction
			new - opens new tournament
			exit - ends program
			load - loads a tournament
			enter - enters a loaded tournament
			list - lists tournaments loaded
			read - reads from file as if user input
		*/
		
		//find what the command is
		if(input == "help")
			main_help();
		else if(input == "new")
			add_tournament(tour);
		else if(input == "exit")
			break;
		else if(input == "enter")
			enter_tournament(tour);
		else if(input == "load")
			load_tournament(tour);
		else if(input == "list")
			read_names(tour);
		else if(input == "read")
			startRead();
		else
			std::cout << "not a command, please use \"help\" to get list of commands\n";
	}while(true);
	
	//may want to put in something so that it auto-saves for when reopened 
	
	
	//goodbye
	std::cout << "goodbye ;)";
	return 0;
}


//function definitions:
void tournament::registar()
{
	std::string input;
	do{
		getline(input, std::cin);
		if(input == "help")
			tournament_registar_help();
		else if(input == "exit")
			break;
		else
		{
			bool found = false;
			for(int i = 0; i < player_list.length(); i++)
			{
				if(player_list[i].get_name() == name)
				{
					found = true;
					std::cout << "That name is already in use.\n";
					break;
				}
			}
			if(!found)
			{
				tournament newOne(name);
				vec.push_back(newOne);
				break;
			}
		}
	}while(true);
}

std::string tournament::get_name()
{
	return name;
}

player::player(const std::string &input)
{
	name = input;
}

flexible_input operator <<(flexible_input &in_stream, bool &foo);
{
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed << foo;
		else
			std::cin << foo;
	else
		std::cin << foo;
	return in_stream;
}

flexible_input operator <<(flexible_input &in_stream, signed char &foo);
{
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed << foo;
		else
			std::cin << foo;
	else
		std::cin << foo;
	return in_stream;
}

flexible_input operator <<(flexible_input &in_stream, unsigned char &foo);
{
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed << foo;
		else
			std::cin << foo;
	else
		std::cin << foo;
	return in_stream;
}

flexible_input operator <<(flexible_input &in_stream, signed short &foo);
{
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed << foo;
		else
			std::cin << foo;
	else
		std::cin << foo;
	return in_stream;
}

flexible_input operator <<(flexible_input &in_stream, unsigned short &foo);
{
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed << foo;
		else
			std::cin << foo;
	else
		std::cin << foo;
	return in_stream;
}

flexible_input operator <<(flexible_input &in_stream, signed int &foo);
{
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed << foo;
		else
			std::cin << foo;
	else
		std::cin << foo;
	return in_stream;
}

flexible_input operator <<(flexible_input &in_stream, unsigned int &foo);
{
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed << foo;
		else
			std::cin << foo;
	else
		std::cin << foo;
	return in_stream;
}

flexible_input operator <<(flexible_input &in_stream, float &foo);
{
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed << foo;
		else
			std::cin << foo;
	else
		std::cin << foo;
	return in_stream;
}

flexible_input operator <<(flexible_input &in_stream, signed long &foo);
{
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed << foo;
		else
			std::cin << foo;
	else
		std::cin << foo;
	return in_stream;
}

flexible_input operator <<(flexible_input &in_stream, unsigned long &foo);
{
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed << foo;
		else
			std::cin << foo;
	else
		std::cin << foo;
	return in_stream;
}

flexible_input operator <<(flexible_input &in_stream, double &foo);
{
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed << foo;
		else
			std::cin << foo;
	else
		std::cin << foo;
	return in_stream;
}

flexible_input operator <<(flexible_input &in_stream, signed long long &foo);
{
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed << foo;
		else
			std::cin << foo;
	else
		std::cin << foo;
	return in_stream;
}

flexible_input operator <<(flexible_input &in_stream, unsigned long long &foo);
{
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed << foo;
		else
			std::cin << foo;
	else
		std::cin << foo;
	return in_stream;
}

flexible_input operator <<(flexible_input &in_stream, long double &foo);
{
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed << foo;
		else
			std::cin << foo;
	else
		std::cin << foo;
	return in_stream;
}

flexible_input operator <<(flexible_input &in_stream, std::string &foo);
{
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed << foo;
		else
			std::cin << foo;
	else
		std::cin << foo;
	return in_stream;
}

flexible_input operator <(flexible_input &in_stream, std::string &foo);
{
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			getline(foo, in_stream.feed);
		else
			getline(foo, std::cin);
	else
		getline(foo, std::cin);
	return in_stream;
}


unsigned int games_played()
{
	return games_played.length();
}

void add_tournament(std::vector <tournament> &vec)
{
	std::string name;
	do{
		getline(name, std::cin);
		if(name == "help")
			name_new_tournament_help();
		else if(name == "exit")
			break;
		else
		{
			bool found = false;
			for(int i = 0; i < vec.length(); i++)
			{
				if(vec[i].get_name() == name)
				{
					found = true;
					std::cout << "That name is already in use.\n";
					break;
				}
			}
			if(!found)
			{
				tournament newOne(name);
				vec.push_back(newOne);
				break;
			}
		}
	}while(true);
}

void enter_tournament(std::vector <tournament> &list)
{
	if(list.length() == 0)
	{
		std::cout << "There is no tournament to enter.\n";
	}
	else if(list.length() == 1)
	{
		list[1].main();
	}
	else
	{
		unsigned int index;
		std::string input;
		do{
			getline(input, std::cin);
			if(input == "help")
				enter_tournament_help();
			else if(input == "exit")
				return;
			else{
				bool found = false;
				for(int i = 0; i < list.length; i++)
				{
					if(list[i].get_name() == input)
					{
						index = i;
						found = true;
						break;
					}
				}
				if(found)
					break;
				else
					std::cout << "The tournament \"" << input << "\" does not exist.";
			}
		}while(true);
		list[index].main();
	}
}

void read_names(const std::vector <tournament> &input)
{
	std::cout << "There are " << input.length() << " tournaments loaded.\n";
	for(int i = 0; i < input.length(); i++)
		std::cout << input[i].get_name() << std::endl;
	std::cout << std::endl;
}

void read_names(const std::vector <player> &input)
{
	std::cout << "There are " << input.length() << " tournaments loaded.\n";
	for(int i = 0; i < input.length(); i++)
		std::cout << input[i].get_name() << std::endl;
	std::cout << std::endl;
}

