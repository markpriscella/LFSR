#include "LFSR.hpp"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main(int argc, const char * argv[])
{
	/* image1 will not be altered in any way */
	sf::Image image1;
	if (!image1.loadFromFile(argv[1]))
		return -1;

	/* image2 will be altered and then saved */
	sf::Image image2;
	if (!image2.loadFromFile(argv[1]))
		return -1;

	/* p will be the original pixel color */
	sf::Color p;
	/* t will be the new pixel color */
	sf::Color t;

	sf::Vector2u size = image1.getSize();

	//string seed = argv[3];
	//int t = argv[4];

	LFSR lfsr(argv[3], atoi(argv[4]));

	/* This is where the encryption occurs */
	for (unsigned x = 0; x < size.x; x++) {
		for (unsigned y = 0; y < size.y; y++) {
			/* get the color of the pixel */
			p = image2.getPixel(x, y);
			/* XOR the rgb values with the values generated from LFSR */
			p.r = p.r ^ lfsr.generate(17);
			p.g = p.g ^ lfsr.generate(27);
			p.b = p.b ^ lfsr.generate(17);
			/* change the pixels color */
			image2.setPixel(x, y, p);
			
		}
	}

	/* create the two windows */
	//sf::RenderWindow window1(sf::VideoMode(size.x, size.y), argv[1]);
	//sf::RenderWindow window2(sf::VideoMode(size.x, size.y), argv[2]);

	/* create and load texture1 from image1 */
	sf::Texture texture1;
	texture1.loadFromImage(image1);

	/* create and load texture2 from image2 */
	sf::Texture texture2;
	texture2.loadFromImage(image2);

	/* create sprite1 and set to texture1 */
	sf::Sprite sprite1;
	sprite1.setTexture(texture1);

	sf::Sprite sprite2;
	sprite2.setTexture(texture2);
	

	// while (window1.isOpen() && window2.isOpen()) {

	// 	sf::Event event;

	// 	while (window1.pollEvent(event)) {
	// 		if (event.type == sf::Event::Closed)
	// 			window1.close();
	// 	}

	// 	while (window2.pollEvent(event)) {
	// 		if (event.type == sf::Event::Closed)
	// 			window2.close();
	// 	}

	// 	window1.clear();
	// 	window1.draw(sprite1);
	// 	window1.display();

	// 	window2.clear();
	// 	window2.draw(sprite2);
	// 	window2.display();
 	// }

	// fredm: saving a PNG segfaults for me, though it does properly
	//   write the file
	if (!image2.saveToFile(argv[2]))
		return -1;

	return 0;
}