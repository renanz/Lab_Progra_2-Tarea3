
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>


SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *car,*stop,*torch,*background;
SDL_Rect rect_background,rect_character;



int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 500/*WIDTH*/, 250/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer, "background.png");
    SDL_QueryTexture(torch, NULL, NULL, &w, &h);
    rect_character.x = 0; rect_character.y = 0; rect_character.w = w; rect_character.h = h;

    car = IMG_LoadTexture(renderer,"car.png");
    SDL_QueryTexture(car, NULL, NULL, &w, &h);
    rect_background.x = 0; rect_background.y = 0; rect_background.w = w; rect_background.h = h;

    stop = IMG_LoadTexture(renderer, "stop.png");
    SDL_QueryTexture(stop, NULL, NULL, &w, &h);
    rect_character.x = 30; rect_character.y = 100; rect_character.w = w; rect_character.h = h;

    torch = IMG_LoadTexture(renderer, "torch.png");
    SDL_QueryTexture(torch, NULL, NULL, &w, &h);
    rect_character.x = 60; rect_character.y = 125; rect_character.w = w; rect_character.h = h;


    //Main Loop
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_d)
                    rect_character.x++;
            }
        }

        SDL_RenderCopy(renderer, car, NULL, &rect_background);
        SDL_RenderCopy(renderer, stop, NULL, &rect_character);
        SDL_RenderCopy(renderer, torch, NULL, &rect_character);
        SDL_RenderPresent(renderer);
    }

	return 0;
}
