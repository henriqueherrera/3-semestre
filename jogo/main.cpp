#include<iostream>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <chrono>
#include <thread>

using namespace std;
SDL_Surface *screen, *imgBackGroung[2], *text, *imgGround, *imgPerson = NULL;
SDL_Rect rect, movBackGround[3], movGround[3];
SDL_Rect rectBackGroung[2], rectGround, rectPerson[9];
Uint32 color;
Uint32 color2;
int mov = 0, mov_ground[3] = {0,620,1240};
int animacaoPerson = 0;
void delayBlitPerson()
{
	while( !close )
        {
                std::this_thread::sleep_for(chrono::milliseconds(50));
		if( animacaoPerson+1 == 10)
		{
			animacaoPerson = 0;
		}
		animacaoPerson++;
		

        }
}
void setBackGroung() //set a imagem de fundo
{
    //load image
    imgBackGroung[0] = SDL_DisplayFormat(SDL_LoadBMP("fundo.bmp"));
    imgBackGroung[1] = SDL_DisplayFormat(SDL_LoadBMP("fundo2.bmp"));
    for(int i = 1; i<= 2; i++)
    {
        rectBackGroung[i-1].w = 1200;
       le( !close )
        {
                std::this_thread::sleep_for(chrono::milliseconds(50));
		count_mov_personagem++;
		if(count_mov_personagem == 15 )
               	{
                     	count_mov_personagem = 0;
              	}
        	walk.rect.y +=5; 

        } rectBackGroung[i-1].h = 600;
        rectBackGroung[i-1].x = rect.x;
        rectBackGroung[i-1].y = rect.y;
    }
    movBackGround[0].x = 0;
    movBackGround[0].y = 0;
    movBackGround[1].x = 1200;
    movBackGround[1].y = 0;
    movBackGround[2].x = 1200*2;
    movBackGround[2].y = 0;
}
void setPerson()
{
	int posX[10] = {4,134,254,369,479,609,729,859,979,1079};
	int posW[10] = {101,96,96,96,116,100,96,96,96,116};
	
	imgPerson = IMG_Load("personagem.png");
	
	for(int i = 0; i<10; i++)
	{
		rectPerson[i].y = 916; 
		rectPerson[i].x = posX[i];
		rectPerson[i].h = 284;
		rectPerson[i].w = posW[i];
	}
}
void setGround()
{
    imgGround = SDL_DisplayFormat(SDL_LoadBMP("ground.bmp"));
    rectGround.x = 10;
    rectGround.y = 0;
    rectGround.w = 620;
    rectGround.h = 450;
    movGround[0].x = 0;
    movGround[0].y = 460;
    movGround[1].x = 640;
    movGround[1].y = 460;
    movGround[2].x = 640*2;
    movGround[2].y = 460;

    SDL_SetColorKey(imgGround, SDL_SRCCOLORKEY, SDL_MapRGB(screen->format, 255,255,255));
}
int runBackGround()
{
    mov-=1;
    movBackGround[2].x = 2325+mov;

    if(movBackGround[2].x <= -75)
    {
        mov = -75;   
        movBackGround[0].x = 0;
        
    }

    return mov;
}
int runGround()
{
	mov_ground[0]-=1;
	mov_ground[1]-=1;
	mov_ground[2]-=1;
	
	movGround[0].x = mov_ground[0];
	movGround[1].x = mov_ground[1];
	movGround[2].x = mov_ground[2];
	
	if(mov_ground[0] <= -620)
	{
		mov_ground[0] = 1240;
	}

	else if (mov_ground[1] <= -620)
	{
		mov_ground[1] = 1240;
	}
	
	else if (mov_ground[2] <= -620)
	{
		mov_ground[2] = 1240;
	}
	cout<<mov_ground[2]<<endl;
}
void blitScreen()
{
    SDL_FillRect(screen, &screen->clip_rect, color2);
    SDL_BlitSurface(imgBackGroung[0],&rectBackGroung[0], screen, &movBackGround[0]);
    SDL_BlitSurface(imgBackGroung[0],&rectBackGroung[0], screen, &movBackGround[2]);
    SDL_BlitSurface(imgBackGroung[1],&rectBackGroung[1], screen, &movBackGround[1]);
    SDL_BlitSurface(imgGround,&rectGround, screen, &movGround[0]);
    SDL_BlitSurface(imgGround,&rectGround, screen, &movGround[1]);

    SDL_BlitSurface(imgPerson,&rectPerson[animaPerson], screen, &rect);
    SDL_BlitSurface(imgGround,&rectGround, screen, &movGround[2]);
    SDL_BlitSurface(text,NULL, screen, NULL);
    SDL_Flip(screen);
}

int main (int argc, char ** argcv)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    TTF_Init();
    TTF_Font *font = TTF_OpenFont("air.TTF",32);
    
    screen = SDL_SetVideoMode(800,600,32,SDL_SWSURFACE);
    
    bool running = true;

    const int FPS = 60;

    bool b[4] = { 0, 0, 0, 0 };
    
    Uint32 start; //int de 32bits
    color = SDL_MapRGB(screen->format, 0xff, 0xff, 0xff);
    color2 = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
    
    rect.x = 0;
    rect.y = 0;
    rect.w = 100;
    rect.h = 200;

   thread = (delayBlitPerson 
	setPerson();
    setBackGroung();
    setGround();
    //tira o fundo que esta de determinada cor;
    
    //SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(screen->format, #00BFFF, #00BFFF, #00BFFF));
    
    SDL_Color color3 = {0,0,0};
    text = TTF_RenderText_Solid(font,"Joguinho",{210,40,89});
    
    while(running)
    {
        start = SDL_GetTicks();
        
        SDL_Event event;

        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    running = false;
                    break;

                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_UP:
                            b[0] = 1;
                            break;
                        
                        case SDLK_DOWN:
                            b[1] = 1;
                            break;

                        case SDLK_LEFT:
                            b[2] = 1;
                            break;
                        
                        case SDLK_RIGHT:
                            b[3] = 1;
                            break;
                    default:
                        break;
                    }
                    break;

                case SDL_KEYUP:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_UP:
                            b[0] = 0;
                            break;
                        
                        case SDLK_DOWN:
                            b[1] = 0;
                            break;

                        case SDLK_LEFT:
                            b[2] = 0;
                            break;
                        
                        case SDLK_RIGHT:
                            b[3] = 0;
                            break;
                    default:
                        break;
                    }
                    break;
            }
            break;
        } 
        //logic e render
        if(b[0])
        {
            rect.y--;
        }

        if(b[1])
        {
            rect.y++;
        }
        
        if(b[2])
        {
            rect.x--;
            
        }

        if(b[3])
        {
            rect.x++;
        }

	blitScreen();
	runGround(); 
	movBackGround[0].x = runBackGround();
        
    	movBackGround[1].x = 1200+movBackGround[0].x;
	//SDL_FillRect(screen, &rect, color);

        

        if( 1000/FPS > SDL_GetTicks()-start) 
        {
                SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
        }
    }
    SDL_FreeSurface(text);
    SDL_FreeSurface(imgBackGroung[0]);
    TTF_CloseFont(font);
    SDL_Quit();

    return 0;
}
