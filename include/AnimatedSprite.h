#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class AnimatedSprite : public sf::Sprite {
public:
    AnimatedSprite(const std::string& file, int fps = 7);

    void addAnimationFrame(const sf::IntRect& rec);
    void step(const sf::Time& elapsed);

private:
    sf::Texture texture;

    int fps, ptr = -1;
    std::vector<sf::IntRect> rectSeq;
    double elapsed = 0;
};
