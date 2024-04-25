 <div align="center">
  <font size="5">🐲 DINO GUN 🐉</font>
</div>

<div align="center">
* Thử nghiệm game: 
    </div>

<div align="center">
* Phá đảo game: 
</div>

<div lang="vi">

## Giới thiệu
Trong một thế giới xa xôi, các loài khủng long sống hòa bình bị đe dọa bởi một nguy hiểm mới. Cổng tử thần mở ra, phóng ra những quái vật đáng sợ, tấn công các cộng đồng khủng long.
Chiến binh khủng long dũng cảm đã đeo súng, sẵn sàng chiến đấu chống lại đại quân quái vật. Bạn sẽ đóng vai trò của một chỉ huy tài ba, xây dựng và củng cố trận địa, sắp xếp chiến lược, và dẫn dắt quân đội vào cuộc chiến chống lại đại bàng đen.

Hãy tham gia vào cuộc phiêu lưu và khám phá thế giới đầy màu sắc của DINO GUN ngay bây giờ 🎮 !
- [Information](#information)
- [Idea](#idea)
- [Milestone](#milestone)
- [Prerequisites](#prerequisites)
-  [Download](#download)
    - [No code](#download-no-code)
    -  [Include code](#download-with-code)
- [Gameplay](#gameplay)
    - [Begin](#begin)
    - [Level](#level)
    - [Object](#object)
        - [Player](#player)
        - [Threat](#threat)
    - [Play](#play)
- [Graphics](#graphics)
- [Notes](#notes)
## **Information** <a name="information"></a>
Name: Lê Thị Tú Phương
Student ID: 22020695
Class: K68J
Email: 23020695@vnu.edu.vn
Facebook: https://www.facebook.com/Lethituphuong2005
## **Idea** <a name="idea"></a>
    Phát triển theo game CASTLE DEFENDER: game thủ thành chiến thuật 


## **Milestone** <a name="milestone"></a>

### **<font color="green">Ngày 17/3/2024</font>**
- Xác định ý tưởng và lập kế hoạch chi tiết cho "Dino Gun".

### **<font color="green">Ngày 19/3/2024</font>**
- Tìm kiếm và chọn lựa đồ họa phù hợp cho trò chơi.

### **<font color="green">Từ ngày 20/3 đến ngày 8/4/2024</font>**
- Phát triển phần chính của trò chơi, bao gồm môi trường chơi, màn chơi và tính năng đặc biệt.

### **<font color="green">Từ ngày 10/4 đến ngày 24/4/2024</font>**
- Hoàn thiện và điều chỉnh tính năng, đồ họa và gameplay của "Dino Gun".

### **<font color="green">Ngày 25/4/2024</font>**
- "Dino Gun" hoàn thành và sẵn sàng ra mắt!


## **Prerequisites** <a name="prerequisites"></a>

> C++
> SDL_2

## **Download** <a name="download"></a>
### **No code** <a name="download-no-code"></a>
Tải game (được nén thành .zip) tại link sau: https://github.com/nmhienbn/PVZ-Kaito-NMH-Edition/releases/tag/published
Cách này tiết kiệm bộ nhớ và thời gian tải đi rất nhiều .
Giải nén game vào một thư mục và bật pvz.exe lên và chơi.

### **Include code** <a name="download-with-code"></a>
Bước 1: Clone repo này về hoặc chọn Code -> Download Zip

![Ảnh chụp màn hình 2024-04-25 142446](https://hackmd.io/_uploads/HkY_BtDbC.png)

Tất cả code đều nằm trong thư mục src.
Có thể nhảy đến bước 5 để chơi luôn.
Bước 2: Cài mingw. Ở đây tôi cài đặt phiên bản MinGW-W64 GCC-8.1.0 x86_64-posix-seh.
Một số chú ý:

Nếu sử dụng trình biên dịch khác thì phải dịch lại icon: vào thư mục icon rồi dùng lệnh windres main.rc -O coff main.res trong cmd.
Phải xóa ba dll của c++ trong thư mục chứa pvz.exe: libgcc_s_seh-1.dll, libstdc++-6.dll, libwinpthread-1.dll. Ba dll này chỉ dành cho người chơi không cài sẵn c++ trong máy.
Bước 3: Cài GNU make

Bước 4: Mở cmd trong thư mục chứa Makefile và gõ lệnh make.

Bước 5: Bật pvz.exe và chơi
    

## **Gameplay** <a name="gameplay"></a>

### <span style="color: green;">**Begin**</span> <a name="begin"></a>
Khi vào màn hình menu game, có các con dino chuyển động , sẽ có 5 dòng chữ để bạn chọn, bạn có thể chơi game ngay lập tức ở đây sẽ không có level và chọn màu cho nhân vật, mặc định là màu vàng, hoặc vào hàm highscore để xem 5 điểm số cao nhất từng chơi, hàm help sẽ hướng dẫn bạn cách chơi và luật chơi, ở dòng chữ level khi bạn nhấp vào sẽ đổi sang level và mù cho nhân vật, exit sẽ giúp bạn thoát khỏi trò chơi, nút âm thanh sẽ giúp bạn tắt bật âm thanh chỉ cần nhấn vào biểu tượng.
![Ảnh chụp màn hình 2024-04-25 150508](https://hackmd.io/_uploads/ryHNZcvbR.png)

### <span style="color: green;">**Level**</span> <a name="level"></a>
Khi bạn chuyển từ menuscene sang levelscene sẽ cho các bạn chọn mức độ của game từ dễ đến khó 
![Uploading file..._ybctwqrx5]()

### <span style="color: green;">**Object**</span> <a name="object"></a>
#### <span style="color: orange;">**Player**</span> <a name="player"></a>

Sau khi bạn từ levelscene sang chọn màu dino sẽ có các hình ảnh và tên ở dưới để bạn chọn màu sắc cho con dino bạn muốn chơi 
![Ảnh chụp màn hình 2024-04-25 152023](https://hackmd.io/_uploads/Sy6375wWC.png)

#### <span style="color: orange;">**Threat**</span> <a name="threat"></a>
Để đối đầu với con dino, và đánh chiếm tòa tháp sẽ là những con threat, threat sẽ gồm các đối tượng:
![attack](https://hackmd.io/_uploads/BkaSNcPbR.png)
![attack](https://hackmd.io/_uploads/SJUDV9D-0.png)
![attack](https://hackmd.io/_uploads/r1-dE5DbC.png)


### <span style="color: green;">**Play**</span> <a name="play"></a>
Hãy dùng các nút A S W D  để di chuyển nhân vật, dùng chuột trái để bắn đạn gây sát thương cho Threat, bảo vệ tòa thành. Chú ý đừng để dino chạm vào quái vật và đừng bắn quá nhiều đạn, đạn có giới hạn. Khi dino hoặc tòa tháp hết máu thì GameOver
![attack](https://hackmd.io/_uploads/rJyc6cvWA.png)

## **Graphics** <a name="graphics"></a>
Sự hỗ trợ từ các thầy lý thuyết, thực hành, và các anh mentor.
    Các nguồn từ lazyfoo, chat gpt,thực hành 123,...
Những tài nguyên đã sử dụng:
![attack](https://hackmd.io/_uploads/BkNsTcvbC.png)
![attack](https://hackmd.io/_uploads/H1h2TqvbR.png)
![bullet](https://hackmd.io/_uploads/rk7RT9wbR.png)
![dino](https://hackmd.io/_uploads/HkmRp5vZC.png)
![dinoblue](https://hackmd.io/_uploads/SyXC69P-0.png)
![dinogreen](https://hackmd.io/_uploads/BJ70aqPbR.png)
![dinored](https://hackmd.io/_uploads/S14CT5DZC.png)
![dinoyellow](https://hackmd.io/_uploads/BkNApqP-A.png)
![gun](https://hackmd.io/_uploads/HJ4CpqDZR.png)![continue](https://hackmd.io/_uploads/HJqyAcwWA.png)
![continuebig](https://hackmd.io/_uploads/Sy9kR9DWR.png)
![end](https://hackmd.io/_uploads/SyqkC9DbA.png)
![endbig](https://hackmd.io/_uploads/HJq1CcPbA.png)
![background-4](https://hackmd.io/_uploads/rytXC5v-R.png)
![Uploading file..._1xxejdewd]()

    



    
    
## **Notes** <a name="notes"></a>
Ở đây sẽ có những thuật toán chính để tạo nên game:
    -Va chạm giữa các đối tượng 
   <div style="background-color: #f0f8ff; padding: 10px; border-radius: 5px;">
    <code>
bool BaseObject::IsCollision(const BaseObject* other) const
        {
            int left = other->GetRectCollision().x - (this->GetRectCollision().x + this->GetRectCollision().w);
            int top = (other->GetRectCollision().y + other->GetRectCollision().h) - this->GetRectCollision().y;
            int right = (other->GetRectCollision().x + other->GetRectCollision().w) - this->GetRectCollision().x;
            int bottom = other->GetRectCollision().y - (this->GetRectCollision().y + this->GetRectCollision().h);

return !(left > 0 || right < 0 || top < 0 || bottom > 0);}
    </code>
</div>
-Thuật toán để player di chuyển theo các nút A S W D
<div style="background-color: #f0f8ff; padding: 10px; border-radius: 5px;">
    <code>
        if (keyboardState[SDL_SCANCODE_A])
        {
            this->SetFlipH(true);
            vector.x = -1.f;
            isMoving = true;
        }

        if (keyboardState[SDL_SCANCODE_D])
        {
            this->SetFlipH(false);
            vector.x = 1.f;
            isMoving = true;
        }

        if (keyboardState[SDL_SCANCODE_W])
        {
            vector.y = -1.f;
            isMoving = true;
        }

        if (keyboardState[SDL_SCANCODE_S])
        {
            vector.y = 1.f;
            isMoving = true;
        }
    </code>
</div>
-Thuật toán để threat sinh ra ở vị trí ngẫu nhiên 
<div style="background-color: #e6f7ff; padding: 10px; border-radius: 5px;">
    <code>
        if (Random::RandomBool())
        {
            this->SetOrigin({ Random::RandomInt(0, WINDOW_WIDTH), Random::RandomBool() ? 0 : WINDOW_HEIGHT });
        }
        else
        {
            this->SetOrigin({ Random::RandomBool() ? 0 : WINDOW_WIDTH, Random::RandomInt(0, WINDOW_HEIGHT) }); //
        }
    </code>
</div>
-Thuật toán để threat luôn ở đến để di chuyển đến tower để tấn công 
<div style="background-color: #e6f7ff; padding: 10px; border-radius: 5px;">
    <code style="color: #008080;">
        if (this->m_state == ThreatState::WALK)
        {
            Vector2f vec = Vector2f((float)(WINDOW_WIDTH / 2 - o.x), (float)(WINDOW_HEIGHT / 2 - o.y));

            if (vec.Magnitude() > 80.f)
            {
                this->Move(vec.Normalize() * (float)(this->m_speed * delta));
            }
            else
            {
                this->SetState(ThreatState::ATTACK);
            }
        }
    </code>
</div>


-Sử dụng  singleton pattern để duy nhất 1 g_game được khởi tạo 
<div style="background-color: #e6f7ff; padding: 10px; border-radius: 5px;">
    <code style="background-color: transparent;">
        Game* Game::GetInstance()
        {
            if(g_game==nullptr)
            {
                g_game=new Game();
            }
            return g_game;
        }
    </code>
</div>
-Hàm để chuyển cảnh giữa các window
<div style="background-color: #e6f7ff; padding: 10px; border-radius: 5px;">
    <code style="color: #008080;">
        void Game::SetScene(BaseScene* scene)
        {
            m_scene = scene;
        }
    </code>
</div>

    



    

    
                                         |



</div>

<div lang="en">

## Introduction
<div align="center">
  <font size="5">🐲 DINO GUN 🐉</font>
</div>

<div align="center">
* Game trial: 
    </div>

<div align="center">
* Game breakdown: 
</div>

<div lang="en">

## Introduction
In a distant world, peaceful dinosaur species are threatened by a new danger. The death gate opens, releasing terrifying monsters that attack dinosaur communities. Brave dinosaur warriors have armed themselves and are ready to fight against the horde of monsters. You will play the role of a skilled commander, building and fortifying defenses, strategizing, and leading the army into battle against the dark eagle.

Join the adventure and explore the colorful world of DINO GUN now 🎮!
- [Information](#information)
- [Idea](#idea)
- [Milestone](#milestone)
- [Prerequisites](#prerequisites)
-  [Download](#download)
    - [No code](#download-no-code)
    -  [Include code](#download-with-code)
- [Gameplay](#gameplay)
    - [Begin](#begin)
    - [Level](#level)
    - [Object](#object)
        - [Player](#player)
        - [Threat](#threat)
    - [Play](#play)
- [Graphics](#graphics)
- [Notes](#notes)
## **Information** <a name="information"></a>
Name: Lê Thị Tú Phương
Student ID: 22020695
Class: K68J
Email: 23020695@vnu.edu.vn
Facebook: https://www.facebook.com/Lethituphuong2005
## **Idea** <a name="idea"></a>
    Developed based on the game CASTLE DEFENDER: a strategic castle defense game.


## **Milestone** <a name="milestone"></a>

### **<font color="green">March 17, 2024</font>**
- Define the concept and detailed plan for "Dino Gun".

### **<font color="green">March 19, 2024</font>**
- Search for and select suitable graphics for the game.

### **<font color="green">From March 20 to April 8, 2024</font>**
- Develop the main part of the game, including gameplay environment, levels, and special features.

### **<font color="green">From April 10 to April 24, 2024</font>**
- Polish and fine-tune game features, graphics, and gameplay of "Dino Gun".

### **<font color="green">April 25, 2024</font>**
- Completion of "Dino Gun" and ready for release!


## **Prerequisites** <a name="prerequisites"></a>

> C++
> SDL_2

## **Download** <a name="download"></a>
### **No code** <a name="download-no-code"></a>
Download the game (compressed into .zip) at the following link: [Game Link](https://github.com/nmhienbn/PVZ-Kaito-NMH-Edition/releases/tag/published)
This method saves a lot of memory and download time. 
Unzip the game into a folder and run pvz.exe to play.

### **Include code** <a name="download-with-code"></a>
Step 1: Clone this repo or choose Code -> Download Zip.

![Screenshot](https://hackmd.io/_uploads/HkY_BtDbC.png)

All the code is located in the src directory.
You can skip to step 5 to play directly.
Step 2: Install Mingw. Here, I installed the MinGW-W64 GCC-8.1.0 x86_64-posix-seh version.
Some notes:

If using a different compiler, you need to recompile the icon: go to the icon directory and use the command windres main.rc -O coff main.res in the cmd.
You need to delete three C++ dlls in the directory containing pvz.exe: libgcc_s_seh-1.dll, libstdc++-6.dll, libwinpthread-1.dll. These three dlls are only for players who do not have C++ installed on their machine.
Step 3: Install GNU make

Step 4: Open cmd in the directory containing Makefile and type the make command.

Step 5: Run pvz.exe and play


## **Gameplay** <a name="gameplay"></a>

### <span style="color: green;">**Begin**</span> <a name="begin"></a>
When entering the game menu screen, there are moving dinosaurs, there will be 5 lines of text for you to choose, you can play the game immediately here without levels and color selection for the character, default is yellow, or go to the highscore function to see the top 5 scores for each play, the help function will guide you on how to play and the rules, in the level line when you click will change to level and mute for the character, by default. There will be the exit button to help you exit the game, the sound button will help you turn on and off the sound, just click on the icon.
![Screenshot](https://hackmd.io/_uploads/ryHNZcvbR.png)

### <span style="color: green;">**Level**</span> <a name="level"></a>
When you switch from the menu scene to the level scene, you will be able to choose the difficulty level of the game from easy to hard.
![Screenshot](https://hackmd.io/_uploads/_ybctwqrx5)

### <span style="color: green;">**Object**</span> <a name="object"></a>
#### <span style="color: orange;">**Player**</span> <a name="player"></a>

After you go from level scene to choose dino color, there will be images and names below for you to choose colors for the dino you want to play
![Screenshot](https://hackmd.io/_uploads/Sy6375wWC.png)

#### <span style="color: orange;">**Threat**</span> <a name="threat"></a>
To confront the dino and capture the tower will be the threats, threats will include objects:
![Screenshot](https://hackmd.io/_uploads/BkaSNcPbR.png)
![Screenshot](https://hackmd.io/_uploads/SJUDV9D-0.png)
![Screenshot](https://hackmd.io/_uploads/r1-dE5DbC.png)


### <span style="color: green;">**Play**</span> <a name="play"></a>
Use the A S W D buttons to move the character, use the left mouse button to shoot bullets to damage the Threat, protect the tower. Be careful not to let the dino touch the monsters and don't shoot too many bullets, bullets are limited. When the dino or tower runs out of health, it's Game Over
![Screenshot](https://hackmd.io/_uploads/H13NU5w-C.jpg)
![Screenshot](https://hackmd.io/_uploads/HJJUUcwZC.png)
...

## **Graphics** <a name="graphics"></a>
Support from theoretical teachers, practical teachers, and mentors.
    Resources from lazyfoo, chat gpt, practice 123, ...
![attack](https://hackmd.io/_uploads/BkNsTcvbC.png)
![attack](https://hackmd.io/_uploads/H1h2TqvbR.png)
![bullet](https://hackmd.io/_uploads/rk7RT9wbR.png)
![dino](https://hackmd.io/_uploads/HkmRp5vZC.png)
![dinoblue](https://hackmd.io/_uploads/SyXC69P-0.png)
![dinogreen](https://hackmd.io/_uploads/BJ70aqPbR.png)
![dinored](https://hackmd.io/_uploads/S14CT5DZC.png)
![dinoyellow](https://hackmd.io/_uploads/BkNApqP-A.png)
![gun](https://hackmd.io/_uploads/HJ4CpqDZR.png)![continue](https://hackmd.io/_uploads/HJqyAcwWA.png)
![continuebig](https://hackmd.io/_uploads/Sy9kR9DWR.png)
![end](https://hackmd.io/_uploads/SyqkC9DbA.png)
![endbig](https://hackmd.io/_uploads/HJq1CcPbA.png)
![background-4](https://hackmd.io/_uploads/rytXC5v-R.png)
![Uploading file..._1xxejdewd]()

## **Notes** <a name="notes"></a>
Here will be the main algorithms to create the game:
    -Collision between objects
   <div style="background-color: #f0f8ff; padding: 10px; border-radius: 5px;">
    <code>
bool BaseObject::IsCollision(const BaseObject* other) const
        {
            int left = other->GetRectCollision().x - (this->GetRectCollision().x + this->GetRectCollision().w);
            int top = (other->GetRectCollision().y + other->GetRectCollision().h) - this->GetRectCollision().y;
            int right = (other->GetRectCollision().x + other->GetRectCollision().w) - this->GetRectCollision().x;
            int bottom = other->GetRectCollision().y - (this->GetRectCollision().y + this->GetRectCollision().h);

return !(left > 0 || right < 0 || top < 0 || bottom > 0);}
    </code>
</div>
-Move the player according to the A S W D keys
<div style="background-color: #f0f8ff; padding: 10px; border-radius: 5px;">
    <code>
        if (keyboardState[SDL_SCANCODE_A])
        {
            this->SetFlipH(true);
            vector.x = -1.f;
            isMoving = true;
        }

        if (keyboardState[SDL_SCANCODE_D])
        {
            this->SetFlipH(false);
            vector.x = 1.f;
            isMoving = true;
        }

        if (keyboardState[SDL_SCANCODE_W])
        {
            vector.y = -1.f;
            isMoving = true;
        }

        if (keyboardState[SDL_SCANCODE_S])
        {
            vector.y = 1.f;
            isMoving = true;
        }
    </code>
</div>
-Algorithm for threats to spawn at random positions
<div style="background-color: #e6f7ff; padding: 10px; border-radius: 5px;">
    <code>
        if (Random::RandomBool())
        {
            this->SetOrigin({ Random::RandomInt(0, WINDOW_WIDTH), Random::RandomBool() ? 0 : WINDOW_HEIGHT });
        }
        else
        {
            this->SetOrigin({ Random::RandomBool() ? 0 : WINDOW_WIDTH, Random::RandomInt(0, WINDOW_HEIGHT) }); //
        }
    </code>
</div>
-Algorithm for threats to always move towards the tower to attack
<div style="background-color: #e6f7ff; padding: 10px; border-radius: 5px;">
    <code style="color: #008080;">
        if (this->m_state == ThreatState::WALK)
        {
            Vector2f vec = Vector2f((float)(WINDOW_WIDTH / 2 - o.x), (float)(WINDOW_HEIGHT / 2 - o.y));

            if (vec.Magnitude() > 80.f)
            {
                this->Move(vec.Normalize() * (float)(this->m_speed * delta));
            }
            else
            {
                this->SetState(ThreatState::ATTACK);
            }
        }
    </code>
</div>


-Using the singleton pattern to ensure only one g_game is initialized 
<div style="background-color: #e6f7ff; padding: 10px; border-radius: 5px;">
    <code style="background-color: transparent;">
        Game* Game::GetInstance()
        {
            if(g_game==nullptr)
            {
                g_game=new Game();
            }
            return g_game;
        }
    </code>
</div>
-Function to switch scenes between windows
<div style="background-color: #e6f7ff; padding: 10px; border-radius: 5px;">
    <code style="color: #008080;">
        void Game::SetScene(BaseScene* scene)
        {
            m_scene = scene;
        }
    </code>
</div>

</div>

<div lang="en">

