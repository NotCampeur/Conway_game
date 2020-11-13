#ifndef ERROR_MANAGER_HPP
# define ERROR_MANAGER_HPP

# define E_SDL std::string("Line ") + std::to_string(__LINE__) + " in " + __FUNCTION__ 

# define CREATEWINANDRENDERER + " -> SDL_CreateWindowAndRenderer() " + "reason : " + SDL_GetError()
# define INIT  + " -> SDL_Init() " + "reason : " + SDL_GetError()
# define RENDERCLEAR  + " -> SDL_RenderClear() " + "reason : " + SDL_GetError()
# define SETRENDERDRAWCOLOR  + " -> SDL_SetRenderDrawColor() " + "reason : " + SDL_GetError()

#endif