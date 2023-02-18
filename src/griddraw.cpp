#include <SDL2/SDL.h>
#include <iostream>
#include "custom.h"

using namespace std;

int pixel_size = 20;
int alpha_val = 25;
int x_start = 0;
int y_start = 400;

int grid_x, grid_y;

extern SDL_Renderer *renderer; 

void grid_to_pixel(int col,int row){
    grid_x = x_start + pixel_size * col;
    grid_y = y_start - pixel_size * row;
}

void pixel_to_grid(int x, int y){
    int pix_x = (x - x_start)/pixel_size;
    int pix_y = (-y + y_start)/pixel_size;
    grid_to_pixel(pix_x,pix_y+1);
}

void draw_for(int x, int y, int colour){
    SDL_Rect rect_to_draw;
	
    pixel_to_grid(x,y);
	cout<<grid_x<<","<<grid_y<<endl;
    rect_to_draw.x = grid_x; // - pixel_size/2;
    rect_to_draw.y = grid_y; // - pixel_size/2;
    rect_to_draw.w = pixel_size;
    rect_to_draw.h = pixel_size;
   
	
	
	switch(colour){
	case 0:
		SDL_SetRenderDrawColor(renderer,0,0,0,255);
		break;
	case 1:	
		SDL_SetRenderDrawColor(renderer,255,255,255,alpha_val);
		break;
	case 2:	
		SDL_SetRenderDrawColor(renderer,255,0,0,alpha_val);
		break;
	case 3:	
		SDL_SetRenderDrawColor(renderer,0,255,0,alpha_val);
		break;
	case 4:	
		SDL_SetRenderDrawColor(renderer,0,0,255,alpha_val);
		break;	
		
	}
    if(y<=y_start && y>=0)	
    SDL_RenderFillRect(renderer, &rect_to_draw);     //use SDL_RenderFillRect(renderer,&rect_to_draw) here
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderPresent(renderer);
	
}