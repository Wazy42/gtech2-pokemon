class Entity
{
protected:
	sf::Sprite spriteEntity;
	const sf::Texture &textureEntity;

public:
	Entity(const sf::Texture &texture);

	sf::Sprite &getSprite();
	const sf::Sprite &getSprite() const;
};