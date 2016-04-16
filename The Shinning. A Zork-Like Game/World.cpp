#include <iostream>
#include "World.h"
#include "Room.h"
#include "Player.h"
#include "Exit.h"

// Constructor
World::World(){
	//Room Construction
	Room* YourRoom = new Room("Your Room", "You are at your Room. There is a book with some inscription that says\n<Game instructions>,maybe it is from the game you played with your \nfriends yesterday.\nNext to you there is a stair that takes you down to the living Room.");
	Room* LivingRoom = new Room("Living Room", "You can see a newspaper next to the chair. You left an apple at the\ntop of your table,it is from yesterday. Next to it there is a knife. \nThe exit is to the north");
	Room* Galia = new Room("Galia", "An injured soldier is yelling desperately at the people; it seems \nhe started a fight with the wrong person. The people is surrounding\nthe soldier in a circle.");
	Room* Mountains1 = new Room("Mountains", "You are surrounded by mountains. You can see at the south the Mountains \nof Madness. To the east and to the west there are more mountains.");
	Room* Mountains2 = new Room("Mountains", "You are surrounded by mountains. At the northeast there is a path to \nGalia. There is a shield next to the path.");
	Room* Mountains3 = new Room("Mountains", "You are surrounded by mountains. At the northwest there is a path to Galia.");
	Room* ValSar_e = new Room("Val'Sar: Entrance", "You are at the entrance to the caves of Val'sar. The view is incredible,\nlooking to the distant north you can see a giant meadow,and next to it \nthere is a large tower. \nTo your left there is a soldier that protects the caves. He sees your \nbadge and enters the cave,leaving a scroll and a lamp.");
	Room* ValSar_c = new Room("Val'Sar Caves", "The cave is narrow and wet. You can see a distant light in front of \nyou,it is probably the only way out. The entrance is behind you.");
	Room* TheGreatSea = new Room("The Great Sea", "You can see how large is the southern sea of Nir.");
	Room* Meadow1 = new Room("Meadow", "You are in a huge meadow that goes in all directions. You can see a lake to the north and a tall tower. ");
	Room* Meadow2 = new Room("Meadow", "You are surrounded by mountains,the only way out is the way you came \nfrom. A graveyard is placed in the center of the field");
	Room* Meadow3 = new Room("Meadow", "You are looking to the north. The tower is even taller from where are \nyou at. To the west there is a small field surrounded by mountains.");
	Room* Lake = new Room("Lake", "You can almost see the tower in front of you. There is a path to the \nnortheast that leads to somewhere. To the south you can see how small \nis the metropolis in comparison with the world");
	Room* Bay = new Room("Bay", "A giant rock is blocking the way to the eastern part of the tower,\nyou could go down the rock,but it does not seems to be climbable");
	Room* BigRock_d = new Room("Big Rock", "It doesn't seem to be climbable but you could climb it down");
	Room* BigRock_u = new Room("Big Rock", "It doesn't seem to be climbable but you could climb it down");
	Room* STower = new Room("South of the tower", "Next to you there is an immense door. You cannot probably open it. \nTo the east it seems to be an opened window. To the west there is \na cottage,maybe there were people living inside");
	Room* ETower = new Room("East of the tower", "Next to you there is a wide window where you culd probably fit in. To \nthe north you can see an entrance to an ominous cave");
	Room* WTower = new Room("West of the tower", "Next to you there is a cottage,the doors are broken and you can see \nthe only Room that survived time. It is all dust");
	Room* NTower = new Room("North of the tower", "To the north the only thing you see is an ominous entrance to a cave \nknown by the inhabitants as The Underground");
	Room* TheUnderground = new Room("The Underground: Entrance", "You fell like this is the end of your adventure... There is a door \nthat you could open if you use all of your strenght...");
	Room* Maze1 = new Room("Maze", "You are surrounded by walls and you don't know where the way out is");
	Room* Maze2 = new Room("Maze", "You are surrounded by walls and you don't know where the way out is");
	Room* Maze3 = new Room("Maze", "You are surrounded by walls and you don't know where the way out is");
	Room* End = new Room("Thank you for playing The Shinning", "Game made by Simon Stoyanov Beltran for college.\nBased on the game Zork.\n\t\thttps://github.com/SimonStoyanov");

	entities.push_back(YourRoom);		entities.push_back(LivingRoom);		entities.push_back(Galia);		entities.push_back(Mountains1);
	entities.push_back(Mountains2);		entities.push_back(Mountains3);		entities.push_back(ValSar_e);	entities.push_back(ValSar_c);
	entities.push_back(TheGreatSea);	entities.push_back(Meadow1);		entities.push_back(Meadow2);	entities.push_back(Meadow3);
	entities.push_back(Lake);			entities.push_back(Bay);			entities.push_back(BigRock_d);	entities.push_back(BigRock_u);
	entities.push_back(STower);			entities.push_back(ETower);			entities.push_back(WTower);		entities.push_back(NTower);
	entities.push_back(TheUnderground);	entities.push_back(Maze1);			entities.push_back(Maze2);		entities.push_back(Maze3);
	entities.push_back(End);

	// Exits
	//Exit* _YourRoom = new Exit("down", "up", "stairs", YourRoom, LivingRoom);
	//Exit* _LivingRoom = new Exit("out", "in", "door", LivingRoom, Galia, true);


	//entities.push_back(_YourRoom);		entities.push_back(_LivingRoom);

	// Player
	player = new Player("Aisu", "An 18 year old that is looking for the truth", YourRoom);

	entities.push_back(player);
}
// Destructor
World::~World(){
	for (int i = 0; i >= entities.size();){
		entities.pop_back();
	}

	entities.clear();
}
// Methods
void World::Game_Loop(){
	system("color 0A");

	// Init
	p2String player_input;
	char input_aux[25];
	p2Vector<p2String> commands;
	commands.reserve(10);

	//The Game
	printf("Welcome to The Shinning! Before playing you may consider read the text \nbellow so you can play freely");
	printf("    (all commands should be in lower case and they must be one word)\n\nSimple movement commands:\n   > north, south, east, west, in, out, down & up\n");
	printf("   > n, s, e, w, i, o, d & up (respectively to the upper commands)\n");
	printf("   > open, close\n\n");

	commands.push_back("look");

	while (player_input != "quit"){
		scanf_s("%s", &input_aux, 25);
		player_input = input_aux;

		player_input.Tokenize(' ', commands);
	


		Command(commands);
	}

	
}

bool World::Command(p2Vector<p2String>& commands){
	bool ret = true;

	switch (commands.size()){
	case 1:
	{
		if ((commands[0] == "look") || (commands[0] == "l")){
			player->Look(commands);
		}
		if ((commands[0] == "quit") || (commands[0] == "q")){
			ret = false;
		}
	}
	default:
		ret = false;
	}

	return ret;
}