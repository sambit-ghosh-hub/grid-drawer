#include <SDL2/SDL.h>
#include <iostream>

#include "custom.h"

using namespace std;


    int height=500;     
    int width=600;      
    SDL_Renderer *renderer = NULL;      
    SDL_Window *window = NULL;  


int main(int argc, char * argv[])
{
        
	    SDL_Init(SDL_INIT_VIDEO);      
        SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
		 SDL_RenderClear(renderer);
		 SDL_SetRenderDrawBlendMode(renderer,SDL_BlendMode(SDL_BLENDMODE_BLEND)); 
		 
		SDL_Rect rect,red,green,blue,white,generate,clear;
		
		rect.x = 0;       red.x = 100;    green.x = 200;  blue.x = 300;  white.x = 400;  	generate.x = 0; 	clear.x = 500;
		rect.y = 0;       red.y = 425;    green.y = 425;  blue.y = 425;  white.y = 425;		generate.y = 425;	clear.y = 425;
		rect.w = 600;	  red.w = 100;    green.w = 100;  blue.w = 100;  white.w = 100;		generate.w = 100;	clear.w = 100;
		rect.h = 400;     red.h = 50;     green.h = 50;   blue.h = 50;   white.h = 50;		generate.h = 50;	clear.h = 50;

		//const SDL_Rect *sreenshot_rect = rect; 
		

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);
	
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &red);
	
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &green);
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &blue);
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &white);
	
	//SDL_SetRenderDrawColor(renderer,127,127, 127, 255);
    //SDL_RenderFillRect(renderer, &generate);
	SDL_SetRenderDrawColor(renderer,0,127, 0, 255);
	SDL_RenderDrawRect(renderer, &generate);
	SDL_RenderDrawLine(renderer,generate.x+50,generate.y,generate.x+50,generate.y+generate.h);
	SDL_RenderDrawLine(renderer,generate.x,generate.y+25,generate.x+generate.w,generate.y+25);

	SDL_SetRenderDrawColor(renderer,255,0, 0, 255);
    SDL_RenderDrawRect(renderer, &clear);
	SDL_RenderDrawLine(renderer,clear.x,clear.y,clear.x+clear.w,clear.y+clear.h);
	SDL_RenderDrawLine(renderer,clear.x,clear.y+clear.h,clear.x+clear.w,clear.y);
	
	
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);     
           
        SDL_RenderPresent(renderer);   
        
    

    SDL_Event event;  int x,y;  Uint32 buttons;
	
	    int colour=1;  int i=1; bool saved = false;
    while(!(event.type == SDL_QUIT))
	
	{
		
		if(event.type == SDL_MOUSEBUTTONDOWN)
		{    
		
	       buttons= SDL_GetMouseState(&x, &y);
		   //button check
		   if(event.button.button == (SDL_BUTTON_RIGHT))colour=0;
		   else
		   if(x>=red.x && x <= red.x+red.w && y>= red.y && y<= red.y+red.h){
				colour = 2;
			}
			else if(x>=green.x && x <=green.x+green.w && y>= green.y && y<= green.y+green.h){
				colour = 3;
			}
			else if(x>=blue.x && x <= blue.x+blue.w && y>= blue.y && y<= blue.y+blue.h){
				colour = 4;
			}
			else if(x>=white.x && x <= white.x+white.w && y>= white.y && y<= white.y+white.h){
				colour = 1;
			}
			else if(x>=clear.x && x <= clear.x+clear.w && y>= clear.y && y<= clear.y+clear.h){
				 
				//save screenshot
				SDL_Surface* pScreenShot = SDL_CreateRGBSurface(0, rect.w, rect.h, 32, 0,0,0,0); //0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);

   				if(pScreenShot && !saved){
      			// Read the pixels from the current render target and save them onto the surface
				
      			if(SDL_RenderReadPixels(renderer, &rect, SDL_GetWindowPixelFormat(window), pScreenShot->pixels, pScreenShot->pitch) == 0)
				  cout<<"success"<<endl;

     			// Create the bmp screenshot file
				
     			SDL_SaveBMP(pScreenShot, "Screenshot.bmp");
				saved = true;
				
      			// Destroy the screenshot surface
      			SDL_FreeSurface(pScreenShot);
   				}

				//clear screen
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    			SDL_RenderFillRect(renderer, &rect);

				

			}
			else if(x>=generate.x && x <= generate.x+generate.w && y>= generate.y && y<= generate.y+generate.h){
				
				while(i<=100)
				{	
					
					x = rand()%600;
					y = rand()%400;
					colour= rand()%5;
					draw_for(x,y,colour);
					i++;
				}
				colour = 1;
			}
			i=0;
			
		   
		    
			
			cout << colour<<endl; 
		   	draw_for(x,y,colour);

		   	//draw border
		   	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    	   	SDL_RenderDrawRect(renderer, &rect);
			SDL_RenderPresent(renderer); 
		   
		}
		if(event.type == SDL_MOUSEBUTTONUP)saved = false;
        SDL_Delay(10);  
        SDL_PollEvent(&event); 
    }
	
	return 0; 
}

