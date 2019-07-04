#ifndef SPRITEMANAGER__H
#define SPRITEMANAGER__H


class SpriteManager
{

public:
	SpriteManager();
	~SpriteManager();

	sf::Sprite getSprite(string name);
	sf::Sprite getTileSprite(string name, int wtile, int htile, int x, bool isVertical);
	sf::Sprite getTileSprite(string name, int wtile, int htile, int x, int y);

	inline sf::Texture* getTexture(string name) { return &textures[name]; }

private:

	map <string, Texture> textures;
};


#endif // !SPRITEMANAGER__H
