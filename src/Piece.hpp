#include <SFML/Graphics.hpp>
#include "Direction.hpp"

/**
  * A Piece object is defined as a movable square shaped object with a fixed
  * size. It moves in its current direction by the length of its edges.
  * Before it's move() method is called, its direction should be set so that
  * it moves in the desired direction.
  */
class Piece : public sf::Drawable
{
public:
	/**
	  * Constuctor. A Piece object is constructed at the given (x, y)
	  * coordinates with the given edge length. A single edge length is required
	  * since it is a square shaped object
	  */
	Piece(const float x, const float y, const float edgeLength);
	Piece(const sf::Vector2f, const float edgeLength);

	//setters
	void setDirection(const direction::Direction dir);
	void setPosition(const float x, const float y);
	void setPosition(const sf::Vector2f&);
	void setFillColor(const sf::Color&);
	//getters
	direction::Direction getDirection() const;
	const sf::Vector2f& getPosition() const;
	const sf::Color& getFillColor() const;
	/**
	  * Method checking if this Piece object is at the same (x, y) coordinates
	  * with the given Piece object.
	  */
	bool atTheSamePosition(const Piece&) const;
	/**
	  * Moves this Piece object in its current direction by distance equal to
	  * the length of one of its edges.
	  */
	void move();
private:
	/**
	  * Draws this Piece object to the screen. SFML specific function.
	  * See SFML RenderTarget
	  */
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
private:
	/**
	  * Composition is preferred over public inheritance mainly because there
	  * is no wish to expose all the interface sf::RectangleShape object is
	  * exposing publicly
	  */
	sf::RectangleShape mSquare; //Underlying RectangleShape object
	direction::Direction mDirection; //Current direction
};
