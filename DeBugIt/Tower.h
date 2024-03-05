#pragma once
#include <SFML/Graphics.hpp>

enum TowerType {
	POTATO,
	CORN,
	TRUNK
};

class Tower
{
public:
	virtual void setPosition(const sf::Vector2f& position) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void update(float deltaTime) = 0;
	virtual void setScale() = 0;
	virtual const sf::Vector2f& getPosition() const = 0;
	virtual sf::FloatRect getGlobalBounds() const = 0;

	virtual bool getDrawEnabled() const =0;
	virtual void setDrawEnabled(bool drawEnabled) = 0;

};

class PotatoTower : public Tower
{
public:
	PotatoTower();
	void setScale() override { m_spritePotatoT.setScale(0.8f, 0.8f); }

	const sf::Vector2f& getPosition() const override {return m_spritePotatoT.getPosition();}
	void setPosition(const sf::Vector2f& position) override { m_spritePotatoT.setPosition(position); }
	void draw(sf::RenderWindow& window) override { if (m_drawEnabled) { window.draw(m_spritePotatoT); } }
	void update(float deltaTime)override;

	sf::FloatRect getGlobalBounds() const override {return m_spritePotatoT.getGlobalBounds();}

	bool getDrawEnabled() const override { return m_drawEnabled; }
	void setDrawEnabled(bool drawEnabled) override { m_drawEnabled = drawEnabled; }

private:
	std::vector<sf::Texture> m_texturePotatoT;
	sf::Sprite m_spritePotatoT;

	int m_currentTextureIndex;
	float m_elapsed;
	float m_frameDuration;

	bool m_drawEnabled=false;
};

class CornTower : public Tower
{
public:
	CornTower();

	CornTower(TowerType type, const sf::Vector2f& position);
	~CornTower();

	void setScale() override { m_spriteCornT.setScale(0.9f, 0.9f); }

	const sf::Vector2f& getPosition() const override { return m_spriteCornT.getPosition(); }
	void setPosition(const sf::Vector2f& position) override { m_spriteCornT.setPosition(position); }
	void draw(sf::RenderWindow& window) override {
		if (m_drawEnabled) { window.draw(m_spriteCornT); }
	}
	void update(float deltaTime)override{}

	sf::FloatRect getGlobalBounds() const override {
		return m_spriteCornT.getGlobalBounds();
	}

	bool getDrawEnabled() const override { return m_drawEnabled; }
	void setDrawEnabled(bool drawEnabled) override { m_drawEnabled = drawEnabled; }

private:
	sf::Texture m_textureCornT;
	sf::Sprite m_spriteCornT;

	bool m_drawEnabled;
	TowerType m_type;
	const sf::Vector2f& m_pos;
};

class TrunkTower : public Tower
{
public:
	TrunkTower();
	void setScale()override { m_spriteTrunkT.setScale(1.5f, 1.5f); }

	const sf::Vector2f& getPosition() const override { return m_spriteTrunkT.getPosition(); }
	void setPosition(const sf::Vector2f& position) override { m_spriteTrunkT.setPosition(position); }
	void draw(sf::RenderWindow& window) override { if (m_drawEnabled) { window.draw(m_spriteTrunkT); } }
	void update(float deltaTime)override {}

	sf::FloatRect getGlobalBounds() const override {
		return m_spriteTrunkT.getGlobalBounds();
	}

	bool getDrawEnabled() const override { return m_drawEnabled; }
	void setDrawEnabled(bool drawEnabled) override { m_drawEnabled = drawEnabled; }

private:
	sf::Texture m_textureTrunkT;
	sf::Sprite m_spriteTrunkT;

	bool m_drawEnabled;
};