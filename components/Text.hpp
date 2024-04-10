#pragma once
#include "../Config.hpp"

class Text
{
private:
	TTF_Font* m_font;
	SDL_Color m_color;
	SDL_Rect m_position;
public:
	Text(TTF_Font*);
	void SetColor(SDL_Color);
	void SetPosition(SDL_Point);
	bool IsSelected(SDL_Point) const;
	void RenderText(SDL_Renderer*, const std::string&);
};
