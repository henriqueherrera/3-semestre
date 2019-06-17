#include<iostream>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <chrono>
#include <thread>
#include <stdlib.h>

using namespace std;

SDL_Surface *screen, *imgFly, *imgBackGroung[2], *text, *imgPerson = NULL;
SDL_Rect movBackGround[3], movGround[2],rectFly[4], movFly;
SDL_Rect rectBackGroung[2], rectGround, rectPerson[3], movPerson;

Uint32 color;
Uint32 color2;

int mov_ground[3] = {0,620,1220};
int fly = 810;
int animaPerson = 0;
int animaFly = 0;
bool running = true;

void delayBlitPerson(){
	while( running ){
    	this_thread::sleep_for(chrono::milliseconds(150));
		animaPerson++;
		animaFly++;
		if( animaPerson == 3){
			animaPerson = 0;
		}
		if(animaFly == 4){
			animaFly = 0;
		}
	}
}
void setFly(){
	imgFly = IMG_Load("./fly.png");
	rectFly[0].x =6;
	rectFly[0].y =73;
	rectFly[0].h =54;
	rectFly[0].w =58;
	rectFly[1].x =70;
	rectFly[1].y =68;
	rectFly[1].h =55;
	rectFly[1].w =58;
	rectFly[2].x =130;
	rectFly[2].y =70;
	rectFly[2].h =55;
	rectFly[2].w =58;
	rectFly[3].x =195;
	rectFly[3].y =73;
	rectFly[3].h =54;
	rectFly[3].w =58;
	movFly.x = 810;
	movFly.y = 50;
}
void setBackGroung(){
	int movBg[3] = {0, 1280, 2520};
    imgBackGroung[0] = SDL_DisplayFormat(SDL_LoadBMP("fundo.bmp"));
    imgBackGroung[1] = SDL_DisplayFormat(SDL_LoadBMP("fundo2.bmp"));
    for(int i = 1; i<= 3; i++){
        rectBackGroung[i-1].w = 1280;
		rectBackGroung[i-1].h = 620;
        rectBackGroung[i-1].x = 0;
        rectBackGroung[i-1].y = 0;
    }
	for(int i = 0; i<3; i++){
		movBackGround[i].x = movBg[i];
		movBackGround[i].y = 0;
	}
	movGround[0].x = 0;
	movGround[0].y = 0;
	movGround[1].x = 1240;
	movGround[1].y = 0;
}
void setPerson(){
	imgPerson = IMG_Load("./drag.png");
	rectPerson[0].x  = 8;
	rectPerson[0].y  = 134;
	rectPerson[0].h  = 123;
	rectPerson[0].w  = 112;
	rectPerson[1].x  = 153;
	rectPerson[1].y  = 163;
	rectPerson[1].h  = 60;
	rectPerson[1].w  = 112;
	rectPerson[2].x  = 297;
	rectPerson[2].y  = 168;
	rectPerson[2].h  = 57;
	rectPerson[2].w  = 182;
	movPerson.x = 200;
	movPerson.y = 100;
}

void blitScreen(){
    SDL_FillRect(screen, &screen->clip_rect, color2);
    SDL_BlitSurface(imgBackGroung[0],&rectBackGroung[0], screen, &movBackGround[0]);
    SDL_BlitSurface(imgBackGroung[1],&rectBackGroung[0], screen, &movBackGround[1]);
	SDL_BlitSurface(imgFly,&rectFly[animaFly], screen, &movFly);
    SDL_BlitSurface(text,NULL, screen, NULL);
    SDL_BlitSurface(imgPerson,&rectPerson[animaPerson], screen, &movPerson);
    SDL_Flip(screen);
}

void setGame(){
	setPerson();
    setBackGroung();
    setFly();
}

void mov(){
	movGround[0].x--;
	movGround[1].x--;
	movBackGround[0] = movGround[0];
	movBackGround[1] = movGround[1];
	if(movGround[0].x == -1280){
		movGround[0].x = 1240;
	}
	if(movGround[1].x == -1280){
		movGround[1].x = 1240;
	}
}
int main (int argc, char ** argcv){

    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    TTF_Font *font = TTF_OpenFont("air.TTF",32);
    screen = SDL_SetVideoMode(800,600,32,SDL_SWSURFACE);
    const int FPS = 60;
    Uint32 start; //int de 32bits
    color = SDL_MapRGB(screen->format, 0xff, 0xff, 0xff);
    color2 = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
	thread  delay(delayBlitPerson);
    bool right = false;
	bool gameOver = false;
	int sort = 1;
    SDL_Color color3 = {0,0,0};
    bool leftPressed = false, rightPressed = false, saltPressed = false; 
    setGame();
	while(running){
        start = SDL_GetTicks();
        
        SDL_Event event;

        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    running = false;
                    break;

  				case SDL_KEYDOWN:
                	if(event.key.keysym.sym == SDLK_LEFT)
                    	leftPressed = true;
                	else if (event.key.keysym.sym == SDLK_RIGHT)
                    	rightPressed = true;
					else if (event.key.keysym.sym == SDLK_SPACE)
						saltPressed = true;
					cout<<event.key.keysym.sym<<endl;
					break;
		
             	case SDL_KEYUP:
                	if(event.key.keysym.sym == SDLK_LEFT)
                    		leftPressed = false;
                	else if (event.key.keysym.sym == SDLK_RIGHT)
                    		rightPressed = false;
					else if (event.key.keysym.sym == SDLK_SPACE)
						saltPressed = false;
                		break;
				default:
					break;
	   		}	     
		}
		fly-=sort;
		movFly.x = fly;
		if (fly <= -58)
		{
			fly = 810;
			movFly.y = rand()%500;
			sort = rand()%9+1;
		}
		if( movFly.y> movPerson.y){
			movFly.y--;
		}else{
			movFly.y++;
		}		
		if(saltPressed){
			movPerson.y-=5;
		}
		movPerson.y++;
		if(movPerson.y > 500){
			text = TTF_RenderText_Solid(font,"Game Over",{210,40,89});
		}else{
			text = TTF_RenderText_Solid(font,"Game Over",{210,40,89});			
		}
		if((movPerson.y >= movFly.y && movPerson.y <= movFly.y+56) && (movPerson.x+112>= movFly.x  && movPerson.x+112<= movFly.x+58))
		{
			text = TTF_RenderText_Solid(font,"Game Over",{210,40,89});
			gameOver = true;
		}else
		{
			text = TTF_RenderText_Solid(font,"Funciona",{210,40,89});
		}
		
		if(gameOver){
			delay.join();
			while (gameOver){
				blitScreen();
				cout<< "aaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
				switch (event.type)
				{
				case SDL_KEYDOWN:
					if(event.key.keysym.sym == SDLK_SPACE){
						gameOver = false;
					}
				
				default:
					break;
				}
			}
			thread  delay(delayBlitPerson);
		}
		
		blitScreen();
		mov();
		if( 500/FPS > SDL_GetTicks()-start) {
			SDL_Delay(500/FPS-(SDL_GetTicks()-start));
		}
		
    }
    SDL_FreeSurface(text);
    SDL_FreeSurface(imgBackGroung[0]);
    TTF_CloseFont(font);
    SDL_Quit();
    delay.join(); 
    return 0;
}
