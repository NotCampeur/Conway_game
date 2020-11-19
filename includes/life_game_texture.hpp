#ifndef LIFE_GAME_TEXTURE_HPP
# define LIFE_GAME_TEXTURE_HPP

SDL_Texture	**create_image_texture(std::string path);
SDL_Texture	**create_texture(SDL_Surface *surface);

#endif