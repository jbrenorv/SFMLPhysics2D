#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

// fonts
const string kArialFont = "assets/fonts/arial.ttf";
const string kMineFont = "assets/fonts/mine.ttf";
const string kPixelBloatedFont = "assets/fonts/pixel_bloated.ttf";

// images
const string kPlayerImage = "assets/images/player.png";

class Assets
{
private:
    inline static map<string, Font> fonts;
    inline static map<string, SoundBuffer> sound_buffers;
    inline static map<string, Sound> sounds;
    inline static map<string, Texture> textures;
    inline static map<string, Sprite> sprites;

public:
    static Font &getFont(string fontName);
    static Sound &getSound(string soundName);
    static Sprite &getSprite(string spriteName);
    static Texture &getTexture(string textureName);
};
