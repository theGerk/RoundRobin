#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

//class declarations:
class tournament;
class player;			//complete
class match;			//complete
class flexible_input;	//complete



//global constants
#define PROGRAM_NAME "Jacksan Wail"


//global variables
flexible_input fin;


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
		
		//prints the current standings to terminal
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
		//complete
		tournament(std::string tournament_name, unsigned int rds);									//complete
		tournament(std::string tournament_name, unsigned int rds, std::vector <player> players);	//complete
		
		//main function for tournament (menu)
		//in progress
		void main();
		
		//returns name
		//complete
		std::string get_name() const;
		
		//loads tournament from file
		//not started
		bool load(const std::string &location);
		bool load(std::ifstream &input);
};

class player {
	private:
		std::vector <match> games_played;			//opponents played by the player
		std::string name;							//player's name
		player* current;							//current opponent
		
	public:
		//starts game
		//complete
		void start_game(player* opponent);
		
		//adds points, ending game
		//complete
		unsigned int end_game(const unsigned int points, const unsigned int gamesPlayed);
		
		//constructor
		//complete
		player(const std::string &input);
		
		//number of games played
		//complete
		unsigned int games_played() const;
		
		//returns number of points
		//complete
		unsigned int points() const;
		
		//returns the tie-break score
		//complete
		unsigned int tie_break() const;
		
		//gets the name
		//complete
		std::string get_name() const;
		
		
		//friends defined elsewhere:
		friend match::match(const player &me, player &other, const unsigned int pts, const unsigned int gamesPlayed);
};

class match {
	private:
		player* opponent;
		unsigned int points;
		
	public:
		//constructor: sets points and opponent
		//complete
		match(const player &me, player &other, const unsigned int pts, const unsigned int gamesPlayed);
		
		//gets points
		//complete
		unsigned int getPoints() const;
		
		//gets opponent's address
		//complete
		player* getOpponent() const; 
}

class flexible_input {
	private:
		std::ifstream feed;
		
		//checks for end of file and will close feed
		//complete
		bool check_for_close();
		
	public:
		//sets feed to a file
		//complete
		bool setFeed(const std::string &name);
		
		//overloading << operator, takes in input
		//complete
		friend flexible_input operator >>(flexible_input &in_stream, bool &foo);				//complete
		friend flexible_input operator >>(flexible_input &in_stream, signed char &foo);			//complete
		friend flexible_input operator >>(flexible_input &in_stream, unsigned char &foo);		//complete
		friend flexible_input operator >>(flexible_input &in_stream, signed short &foo);		//complete
		friend flexible_input operator >>(flexible_input &in_stream, unsigned short &foo		//complete
		friend flexible_input operator >>(flexible_input &in_stream, signed int &foo);			//complete
		friend flexible_input operator >>(flexible_input &in_stream, unsigned int &foo);		//complete
		friend flexible_input operator >>(flexible_input &in_stream, float &foo);				//complete
		friend flexible_input operator >>(flexible_input &in_stream, signed long &foo);			//complete
		friend flexible_input operator >>(flexible_input &in_stream, unsigned long &foo);		//complete
		friend flexible_input operator >>(flexible_input &in_stream, double &foo);				//complete
		friend flexible_input operator >>(flexible_input &in_stream, signed long long &foo);	//complete
		friend flexible_input operator >>(flexible_input &in_stream, unsigned long long &foo);	//complete
		friend flexible_input operator >>(flexible_input &in_stream, long double &foo);			//complete
		friend flexible_input operator >>(flexible_input &in_stream, std::string &foo);			//complete
		
		//getline equivalent
		//complete
		friend flexible_input operator >(flexible_input &in_stream, std::string &foo);
};

//function declarations:
//reads the help for different areas in program
//not started
void main_help();
void add_tournament_help();
void enter_tournament_help();
void tournament_registar_help();
void startRead_help();
void load_tournament_help();
void tournament_main_help();

//creates a new tournament
//complete
void add_tournament(std::vector <tournament> &list);

//enters a tournament
//complete
void enter_tournament(std::vector <tournament> &list);

//load's a tournament from external file
//complete
void load_tournament(std::vector <tournament> &list);

//reads the names of objects
//complete
void read_names(const std::vector <tournament> &input);	//complete
void read_names(const std::vector <player> &input);		//complete

//starts reading from a file
//complete
void startRead();


//main function:
int main(){
	//intro to program
	std::cout << "Welcome to " << PROGRAM_NAME << ".\nPlease enter the command for what you would like to do.\nTyping \"help\" at any time will give you a list of commands and instructions.\n";
	std::string input;
	std::vector <tournament> tour;
	
	//where the program runs
	do {
		fin >> input;
		
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
	std::cout << "Goodbye ;)";
	return 0;
}


//function definitions:
void tournament::registar(){
	std::string input;
	do{
		fin > input;
		if(input == "help")
			tournament_registar_help();
		else if(input == "exit")
			break;
		else if(input = "read")
			startRead();
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
tournament::tournament(std::string tournament_name, unsigned int rds){
	name = tournament_name;
	rounds = rds;
}
tournament::tournament(std::string tournament_name, unsigned int rds, std::vector <player> players){
	name = tournament_name;
	rounds = rds;
	player_list = players;
}
void tournament::main(){
	std::string input;
	do{
		fin >> input;
		
		/*
		Commands:
		
		help - info
		register - registers a group of players
		add - adds a single player
		exit - leaves tournament
		save - saves to text file
		look - shows current standings
		report - report a game
		start - starts the tournament
		
		
		*/
		
		if(input == "help")
			tournament_main_help();
		else if(input == "register")
			registar();
		else if(input == "")
	}while(true);
}
std::string tournament::get_name(){
	return name;
}
void player::start_game(player* opponent){
	current = opponent;
	opponent->current = &this;
}
void player::end_game(const unsigned int points, const unsigned int gamesPlayed){
	match temp(this, current, points, gamesPlayed);
	games_played.push_back(temp);
	
	current->current = NULL;
	current = NULL;
}
player::player(const std::string &input){
	name = input;
}
unsigned int player::games_played(){
	return games_played.length();
}
unsigned int player::points(){
	unsigned int output = 0;
	for(int i = 0; i < games_played.length(); i++)
		output += games_played[i].getPoints();
	return output;
}
unsigned int player::tie_break(){
	unsigned int output = 0;
	for(int i = 0; i < games_played.length(); i++)
		output += games_played[i].getPoints() * games_played[i].getOpponent->points();
	return output;
}
std::string player::get_name(){
	return name;
}
match::match(const player &me, player* other, const unsigned int pts, const unsigned int gamesPlayed){
	opponent = other;
	points = pts;
	
	//do stuff for other player
	match temp;
	temp.points = gamesPlayed - pts;
	temp.player = &me;
	
	other->games_played.push_back(temp);
}
unsigned int match::getPoints(){
	return points;
}
player* match::getOpponent(){
	return opponent;
}
bool flexible_input::check_for_close(){
	if(feed.eof())
	{
		feed.close();
		return false;
	}
	else
		return true;
}
bool flexible_input::setFeed(const std::string &name){
	if(feed.is_open())
		feed.close();
	feed.open(name);
	if(feed.fail())
	{
		feed.close();
		return false;
	}
	else
		return true;
}
flexible_input operator >>(flexible_input &in_stream, bool &foo){
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed >> foo;
		else
			std::cin >> foo;
	else
		std::cin >> foo;
	return in_stream;
}
flexible_input operator >>(flexible_input &in_stream, signed char &foo){
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed >> foo;
		else
			std::cin >> foo;
	else
		std::cin >> foo;
	return in_stream;
}
flexible_input operator >>(flexible_input &in_stream, unsigned char &foo){
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed >> foo;
		else
			std::cin >> foo;
	else
		std::cin >> foo;
	return in_stream;
}
flexible_input operator >>(flexible_input &in_stream, signed short &foo){
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed >> foo;
		else
			std::cin >> foo;
	else
		std::cin >> foo;
	return in_stream;
}
flexible_input operator >>(flexible_input &in_stream, unsigned short &foo){
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed >> foo;
		else
			std::cin >> foo;
	else
		std::cin >> foo;
	return in_stream;
}
flexible_input operator >>(flexible_input &in_stream, signed int &foo){
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed >> foo;
		else
			std::cin >> foo;
	else
		std::cin >> foo;
	return in_stream;
}
flexible_input operator >>(flexible_input &in_stream, unsigned int &foo){
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed >> foo;
		else
			std::cin >> foo;
	else
		std::cin >> foo;
	return in_stream;
}
flexible_input operator >>(flexible_input &in_stream, float &foo){
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed >> foo;
		else
			std::cin >> foo;
	else
		std::cin >> foo;
	return in_stream;
}
flexible_input operator >>(flexible_input &in_stream, signed long &foo){
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed >> foo;
		else
			std::cin >> foo;
	else
		std::cin >> foo;
	return in_stream;
}
flexible_input operator >>(flexible_input &in_stream, unsigned long &foo){
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed >> foo;
		else
			std::cin >> foo;
	else
		std::cin >> foo;
	return in_stream;
}
flexible_input operator >>(flexible_input &in_stream, double &foo){
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed >> foo;
		else
			std::cin >> foo;
	else
		std::cin >> foo;
	return in_stream;
}
flexible_input operator >>(flexible_input &in_stream, signed long long &foo){
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed >> foo;
		else
			std::cin >> foo;
	else
		std::cin >> foo;
	return in_stream;
}
flexible_input operator >>(flexible_input &in_stream, unsigned long long &foo){
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed >> foo;
		else
			std::cin >> foo;
	else
		std::cin >> foo;
	return in_stream;
}
flexible_input operator >>(flexible_input &in_stream, long double &foo){
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed >> foo;
		else
			std::cin >> foo;
	else
		std::cin >> foo;
	return in_stream;
}
flexible_input operator >>(flexible_input &in_stream, std::string &foo){
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			in_stream.feed >> foo;
		else
			std::cin >> foo;
	else
		std::cin >> foo;
	return in_stream;
}
flexible_input operator >(flexible_input &in_stream, std::string &foo){
	if(in_stream.feed.is_open())
		if(in_stream.check_for_close())
			getline(foo, in_stream.feed);
		else
			getline(foo, std::cin);
	else
		getline(foo, std::cin);
	return in_stream;
}
void add_tournament(std::vector <tournament> &vec){
	std::string name;
	do{
		fin > name;
		if(name == "help")
			name_new_tournament_help();
		else if(name == "exit")
			break;
		else if(name = "read")
			startRead();
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
				//get number of rounds
				unsigned int rds;
				do{
					fin >> rds;
				}while(rds > 0)
				tournament newOne(name, rds);
				vec.push_back(newOne);
				break;
			}
		}
	}while(true);
}
void enter_tournament(std::vector <tournament> &list){
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
			fin > input;
			if(input == "help")
				enter_tournament_help();
			else if(input == "exit")
				return;
			else if(input == "read")
				startRead();
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
void load_tournament(std::vector <tournament> &list){
	std::string loc;
	do{
		fin >> loc;
		if(loc == "help")
			load_tournament_help();
		else if(loc == "exit")
			break;
		else if(loc == "read")
			startRead();
		else
		{
			tournament tourny;
			if(tourny.load(loc))
				break;
			else
				std::cout << loc << " Was not found.";
		}
	}while(true);
}
void read_names(const std::vector <tournament> &input){
	std::cout << "There are " << input.length() << " tournaments loaded.\n";
	for(int i = 0; i < input.length(); i++)
		std::cout << input[i].get_name() << std::endl;
	std::cout << std::endl;
}
void read_names(const std::vector <player> &input){
	std::cout << "There are " << input.length() << " tournaments loaded.\n";
	for(int i = 0; i < input.length(); i++)
		std::cout << input[i].get_name() << std::endl;
	std::cout << std::endl;
}
void startRead(){	
	std::string name;
	do{
		fin >> name;
		if(name == "help")
			startRead_help();
		else if(name == "exit")
			break;
		else if(name == "read")
			startRead();
		else if(setFeed(name))
			break;
	}while(true);	
}
