#pragma once
#include "../Config.hpp"

class Text
{
private:
	TTF_Font* m_font;// con trỏ đến fon chữ được sử dụng cho văn bản
	SDL_Color m_color; //màu sắc font chữ
	SDL_Rect m_position;// vị trí và kích thước của chữ

public:
	Text(TTF_Font*);// khơir tạo lớp text được sử dụng để thiết lạp font chữ cho văn bản

	void SetColor(SDL_Color);//thiết lập màu cho văn bản
	void SetPosition(SDL_Point);//thiết lập vị trị cho chữ

	bool IsSelected(SDL_Point) const;//kiểm tra xem điểm có được chỉ định nằm trong vùng của văn bản không

	void RenderText(SDL_Renderer*, const std::string&);// vẽ chữ lên màn hình với chuối sử dụng renddeer chuỗi cung cấp
};
