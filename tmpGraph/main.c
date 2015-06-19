/*
** main.c for  in /home/degand/Projects/PSU_2014_zappy/tmpGraph
** 
** Made by Alaric
** Login   <degand@epitech.net>
** 
** Started on  Thu Jun 18 15:58:26 2015 Alaric
** Last update Fri Jun 19 19:54:13 2015 Alaric
*/

//#include	<SDL/SDL_ttf.h>
#include	<SDL2/SDL.h>
//#include	<SDL/SDL_image.h>
#include	<unistd.h>
#define		SHAPE_SIZE 24
#define		SIZE_X 1000
#define		SIZE_Y 1000

void		draw_grid(SDL_Renderer *renderer)
{
  int		a;

  a = 0;
  while (a <= 1000)
    {
      SDL_RenderDrawLine(renderer, a, 0, a, 1000);
      a += SIZE_X / 40;
    }
  a = 0;
  while (a <= 1000)
    {
      SDL_RenderDrawLine(renderer, 0, a, 1000, a);
      a += SIZE_Y / 40;
    }
}

int		main()
{
  SDL_Window	*fenetre;
  SDL_Renderer	*renderer;
  SDL_Texture	*Linemate;
  SDL_Surface	*loader;
  SDL_Rect	DestR;

  DestR.x = 1;
  DestR.y = 1;
  DestR.w = SHAPE_SIZE;
  DestR.h = SHAPE_SIZE;

  //SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP, &fenetre, &renderer);
  fenetre = SDL_CreateWindow("SDL_RenderCopy Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SIZE_X + 1, SIZE_Y + 1, 0);
  renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
  //load image -> tranfert texture -> free image
  loader = Bmp_Loader("BMP/Linemate.bmp");
  Linemate = SDL_CreateTextureFromSurface(renderer, linemate);
  SDL_FreeSurface(loader);
  //clear de la fenetre
  SDL_RenderClear(renderer);
  //affichage BMP => a modif pour toutes les images
  SDL_RenderCopy(renderer, Linemate, NULL, &DestR);
  //Changement couleur pour la grille
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  draw_grid(renderer);
  //actualisation de l'affichage
  SDL_RenderPresent(renderer);

  sleep(5);

  SDL_Quit();
  return (0);
}
