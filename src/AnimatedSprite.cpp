#include <AnimatedSprite.h>

AnimatedSprite::AnimatedSprite(const std::string& file, int fps) : fps(std::max(1, fps)) {
	texture.loadFromFile(file);
	setTexture(texture);
}

void AnimatedSprite::addAnimationFrame(const sf::IntRect& rec) {
	rectSeq.push_back(rec);
}
void  AnimatedSprite::step(const sf::Time& elapsed) {
	if (rectSeq.empty())
		return;
	this->elapsed += elapsed.asSeconds();
	if (this->elapsed > 1./fps) {
		++ptr;
		if (ptr >= (int)rectSeq.size()) ptr = 0;
		//ptr = ++ptr%rectSeq.size();
		setTextureRect(rectSeq[ptr]);
		this->elapsed = 0;
	}
}
