#include "Text.hpp"

Text::Text(TTF_Font* font) :
	m_color({255, 255, 255, 255}),//màu trắng
	m_position({0, 0, 0, 0}),//tọa độ chữ và kích thuóc chữ
	m_font(font)
{
}

void Text::SetColor(SDL_Color color)//thiết lập màu
{
	this->m_color = color;
}

void Text::SetPosition(SDL_Point position)//thiết lập vị trí
{
	this->m_position.x = position.x;
	this->m_position.y = position.y;
}

bool Text::IsSelected(SDL_Point point) const//kiểm tra xem điểm số có nămd trong cùng chứa văn bản không
{
	return (point.x >= m_position.x && point.x <= m_position.x + m_position.w && point.y >= m_position.y && point.y <= m_position.y + m_position.h);
}

void Text::RenderText(SDL_Renderer* renderer, const std::string& text)//vẽ văn bản lên màn hình
{
	SDL_Surface* surf = TTF_RenderText_Blended(this->m_font, text.c_str(), this->m_color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_FreeSurface(surf);
	SDL_QueryTexture(texture, nullptr, nullptr, &this->m_position.w, &this->m_position.h);

	SDL_RenderCopy(renderer, texture, nullptr, &this->m_position);//////
	SDL_DestroyTexture(texture);
}
