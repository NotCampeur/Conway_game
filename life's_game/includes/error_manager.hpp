#ifndef ERROR_MANAGER_HPP
# define ERROR_MANAGER_HPP

# define E_SDL std::string("Line ") + std::to_string(__LINE__) + " in " + __FUNCTION__ 

# define CREATEWINANDRENDERER + " -> SDL_CreateWindowAndRenderer() " + "reason : " + SDL_GetError()
# define INIT  + " -> SDL_Init() " + "reason : " + SDL_GetError()
# define RENDERCLEAR  + " -> SDL_RenderClear() " + "reason : " + SDL_GetError()
# define SETRENDERDRAWCOLOR  + " -> SDL_SetRenderDrawColor() " + "reason : " + SDL_GetError()
# define FONT + " -> TTF_Init() " + "reason : " + TTF_GetError()
# define TEXTURE + " -> SDL_CreateTextureFromSurface() " + "reason : " + SDL_GetError()
# define IMAGE_LOAD + " -> IMG_Load() " + "reason : " + IMG_GetError()
# define IMAGE_INIT + " -> IMG_Init() " + "reason : " + IMG_GetError()
# define RENDER_COPY_EX + " -> SDL_RenderCopyEx() " + "reason : " + SDL_GetError()
# define RENDER_COPY + " -> SDL_RenderCopy() " + "reason : " + SDL_GetError()
#endif