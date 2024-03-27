 #include "BaseObject.hpp"

BaseObject::BaseObject() :
	m_texture(nullptr),
	m_angle(0.f),
	m_flipH(false)
{
	this->m_rectSrc = new SDL_Rect();
	this->m_rectDst = new SDL_Rect();
	this->m_origin = new SDL_Point();//cấu trúc xác định 1 điểm hai chiều
}

void BaseObject::Render(SDL_Renderer* renderer)
{
	if (this->m_texture != nullptr)//sdl_point xac din vi tri doi tuong voi 2 diem x y
	{
		SDL_Point* center = new SDL_Point();
		center->x = this->m_rectDst->w / 2;
		center->y = this->m_rectDst->h / 2;

		SDL_RendererFlip flip = this->m_flipH ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
//?toan tu 3 ngoi tru truoc false sau            lat ngang                khong lat
		SDL_RenderCopyEx(
			renderer,//xac dinh renderer ma hinh anh duoc ve len//trinhket xuat
			this->m_texture,//xac dinh hinh anh can duoc ve len
			this->m_rectSrc,//xac dinh vung texture sao chep len//hinh chu nhat nguon
			this->m_rectDst,//xac dinh vung man hinh ve vao// hinh hcu nhat dich
			this->m_angle,//goc xoay cua doi tuong
			center,//diem trug tam doi tuong
			flip//xac dinh xem co lat ngang hay kh
		);
	}
}

SDL_Point BaseObject::GetOrigin() const //tra ve diem goc doi tuong
{
	this->m_origin->x = this->m_rectDst->w / 2 + this->m_rectDst->x;//dtoa do x khi hinh chu nhat xuat hien tren man hinh
	this->m_origin->y = this->m_rectDst->w / 2 + this->m_rectDst->y;// tuong tu

	return *this->m_origin;
}

void BaseObject::SetOrigin(SDL_Point origin)
{
	SDL_Point o = this->GetOrigin();
	int xOffset = origin.x - o.x;//diem goc moi va diem goc hien tai//di chuyen doi tuong
	int yOffset = origin.y - o.y;

	this->m_rectDst->x += xOffset;
	this->m_rectDst->y += yOffset;

	this->m_origin->x = origin.x;
	this->m_origin->y = origin.y;
}

float BaseObject::GetAngle() const
{
	return this->m_angle;
}

void BaseObject::SetAngle(float angle)
{
	while (angle >= 360)
	{
		angle -= 360;
	}

	this->m_angle = angle;
}

bool BaseObject::GetFlipH() const
{
	return this->m_flipH;
}

void BaseObject::SetFlipH(bool flip)
{
	this->m_flipH = flip;
}

void BaseObject::Move(Vector2f vector)
{
	auto origin = this->GetOrigin();//lay điẻm goóc cuar đói tuọng
	origin.x += (int) vector.x;
	origin.y += (int) vector.y;

	this->SetOrigin(origin);
}
