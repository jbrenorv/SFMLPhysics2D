#include "Assets.hpp"

Font &Assets::getFont(string fontName)
{
    // Returns the font if it's already loaded in memory
    if (fonts.find(fontName) != fonts.end())
        return fonts[fontName];

    // Load font and store it
    Font font;
    font.loadFromFile(fontName);
    fonts[fontName] = font;

    return fonts[fontName];
}

Sprite &Assets::getSprite(string spriteName)
{
    if (sprites.find(spriteName) != sprites.end())
        return sprites[spriteName];

    sprites[spriteName] = Sprite(getTexture(spriteName));

    return sprites[spriteName];
}

Texture &Assets::getTexture(string textureName)
{
    if (textures.find(textureName) != textures.end())
        return textures[textureName];

    Texture texture;
    texture.loadFromFile(textureName);

    textures[textureName] = texture;

    return textures[textureName];
}

Sound &Assets::getSound(string soundName)
{
    if (sounds.find(soundName) != sounds.end())
        return sounds[soundName];

    SoundBuffer soundBuffer;
    soundBuffer.loadFromFile(soundName);
    
    sound_buffers[soundName] = soundBuffer;
    sounds[soundName] = Sound(sound_buffers[soundName]);

    return sounds[soundName];
}
