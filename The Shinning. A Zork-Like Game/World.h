#include "Entity.h"
#include "Player.h"

class Entity;
class Player;

class World{
private:
	p2Vector<Entity*> entities;
	Player* player;
public:
	World();
	~World();

	void Game_Loop();

	bool Command(p2Vector<p2String>& commands);

};


#endif