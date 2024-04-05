#include "Player.hpp"
#include "../types/Vector2f.hpp"
#include "../Resource.hpp"

Player::Player() :
	AnimatedObject(6, 0.1f),//6 hinh anh dong, khoang time giua cac khung hinh la 0.1s
	Damage(10),//muc do sat thuong la 10
	m_speed(150),//toc do 150
	m_isShotable(true)
{
	this->m_texture = Resource::TX_PLAYER;//duongdan anh`
	this->m_rectSrc->w = 72;
	this->m_rectSrc->h = 72;

	this->m_rectDst->w = 72;
	this->m_rectDst->h = 72;

	this->m_rectCollision->w = this->m_rectCollision->h = 50;
this->m_rectCollision->x = this->m_rectCollision->y = 11;

	this->SetOrigin({ 100, 100 });//toa do ban dau

	this->m_gun = new Gun();
}

void Player::Update(float delta)
{
    this->m_elapsedTime+=delta;//tính toán time
    if(m_elapsedTime>0.5f)
    {
        m_isShotable=true;//neu time lớn hơn 0.5 thì có thể bắn
    }
	this->UpdateAnimation(delta);// capaj nhật hình ảnh player

	const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);//trạng thái của bàn phím xem người chơi bấm nút nào để player di chuyển

	Vector2f vector;

	if (keyboardState[SDL_SCANCODE_A])
	{
		this->SetFlipH(true);//đảo ngươc hình ảnh và đặt thành -1 để di chuyển sang trái
		vector.x = -1.f;
	}

	if (keyboardState[SDL_SCANCODE_D])
	{
		this->SetFlipH(false);
		vector.x = 1.f;
	}

	if (keyboardState[SDL_SCANCODE_W])
	{
		vector.y = -1.f;
	}

	if (keyboardState[SDL_SCANCODE_S])
	{
		vector.y = 1.f;
	}

	vector = vector.Normalize();//chuyen doi vector ve 1 de khong anh huong toi di chuyen
	this->Move(vector * (delta * this->m_speed));//di chuyen doi tuong theo huong va toc do xac dinh//delta * this->m_speed được sử dụng để điều chỉnh tốc độ di chuyển của Player dựa trên thời gian trôi qua. Kết quả của phép nhân này sẽ là một giá trị tương tự với tốc độ di chuyển của Player nhưng đã được điều chỉnh phù hợp với thời gian trôi qua. Khi delta tăng, nghĩa là thời gian trôi qua giữa các lần cập nhật ngắn hơn, giá trị delta * this->m_speed cũng sẽ tăng, từ đó làm cho Player di chuyển nhanh hơn. Ngược lại, khi delta giảm, giá trị delta * this->m_speed cũng giảm, từ đó làm cho Player di chuyển chậm hơn.
    //dieu chinh toc do nguoi choi
	int xOffset = this->m_rectDst->w / 2;//lay trung tam cua hinh chu nhat dich
	int yOffset = this->m_rectDst->h / 2;

	if (this->m_origin->x < xOffset)
	{
		this->SetOrigin({ xOffset, this->m_origin->y });//dat lai x player neu co vuot qua ranh gioi ben trai cua cua so hien thi hay khong, neu co dat lai x, y giu nguyen
	}

	if (this->m_origin->x > WINDOW_WIDTH - xOffset)
	{
		this->SetOrigin({ WINDOW_WIDTH - xOffset, this->m_origin->y });//kiem tra xem x player co vuot qua ranh gioi ben phai cua cua so hien thi hay khong
	}

	if (this->m_origin->y < yOffset)
	{
		this->SetOrigin({ this->m_origin->x, yOffset });
	}

	if (this->m_origin->y > WINDOW_HEIGHT - yOffset)
	{
		this->SetOrigin({ this->m_origin->x, WINDOW_HEIGHT - yOffset });
	}

	this->m_gun->SetOrigin(this->GetOrigin());//cap nhat diem goc cua doi tuong gun theo player
	this->m_gun->Update(delta);//diem goc sung cung diem goc player
}

void Player::Render(SDL_Renderer* renderer)
{
	BaseObject::Render(renderer);//ve player len man hinh

	this->m_gun->Render(renderer);//cho phep sung cung hien thi player
}

bool Player::IsShotable() const//trả về giá trị của biến xem player có thể bắn hay không
{
    return m_isShotable;
}

Bullet* Player::Shot()
{
    m_isShotable=false;//ngăn player bắn liên tiếp
    m_elapsedTime=0.f;
     return new Bullet(m_gun->GetAngle(),GetOrigin());// tạo ra góc bắn , getangle trả về góc bắn hiện tại , get origin trả vè tọa độ điểm gốc player
}
