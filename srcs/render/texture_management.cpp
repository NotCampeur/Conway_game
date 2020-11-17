#include "life_game.hpp"

SDL_Texture	**create_image_texture(std::string path)
{
	SDL_Surface	*img;
	SDL_Texture	**result;
	result = new SDL_Texture*;
	img = IMG_Load(path.c_str());
	if (img == NULL)
		throw std::invalid_argument(E_SDL IMAGE_LOAD);
	*result = SDL_CreateTextureFromSurface(sys->render, img);
	if (result == NULL)
		throw std::invalid_argument(E_SDL TEXTURE);
	SDL_FreeSurface(img);
	return result;
}

SDL_Texture	**create_texture(SDL_Surface *surface)
{
	SDL_Texture	**result;

	result = new SDL_Texture*;
	*result = SDL_CreateTextureFromSurface(sys->render, surface);
	if (result == NULL)
		throw std::invalid_argument(E_SDL TEXTURE);
	SDL_FreeSurface(surface);
	return result;
}