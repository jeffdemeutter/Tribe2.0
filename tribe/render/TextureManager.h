#pragma once
#include "pch.h"

struct Texture
{
    unsigned int data;
    int width;
    int height;
    int nrChannels;
};

class TextureManager final
{
public:
    TextureManager(const std::string_view directory);
    ~TextureManager() = default;
    TextureManager(const TextureManager&) = delete;
    TextureManager(TextureManager&&) noexcept  = delete;
    TextureManager& operator=(const TextureManager&) = delete;
    TextureManager& operator=(TextureManager&&) noexcept  = delete;
    
    Texture* LoadTexture(const std::string_view path);
    
    
private:
    std::string m_Directory;

    using TextureMap = std::unordered_map<std::string_view, Texture>;
    TextureMap m_Textures;
};