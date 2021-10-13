#include "waves.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "JukeBox Hero");
	sf::SoundBuffer buffer;
	sf::Sound dope;
	vector<sf::Int16> sample;
	int i;

	for (i = 0; i < 44100; i++)
		sample.push_back(reg_note::SineWave(i, 400, 0.9));
	buffer.loadFromSamples(&sample[0], sample.size(), 1, 44100);
	dope.setBuffer(buffer);
	dope.play();
	while (window.isOpen())
	{
		sf::Event evan;
		while (window.pollEvent(evan))
		{
			if (evan.type == sf::Event::Closed)
				window.close();
		}
	}
	return 0;
}
