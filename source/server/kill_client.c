/*
** kill_client.c for kill_client in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Jul  2 17:04:08 2015 Antoine Plaskowski
** Last update Thu Jul  2 18:08:07 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	"client.h"
#include	"game.h"

static bool	kill_timeout(t_time *client, t_time const * const timeout)
{
  t_time	time;

  if (clock_gettime(CLOCK_MONOTONIC, &time) == -1)
    {
      perror("clock_gettime :");
      return (true);
    }
  if (time_sub(&time, client) == true)
    return (true);
  if (time_small(&time, timeout) == true)
    return (true);
  return (false);
}

t_client	*kill_client(t_client *list)
{
  t_time	timeout;
  t_client	*client;
  t_client	*client2;

  timeout.tv_sec = 5;
  timeout.tv_nsec = 0;
  client = first_node(&list->node);
  while (client != NULL)
    {
      client2 = client->node.next;
      if (client->to_kill == true && client->to_write == NULL)
	list = sup_client(client);
      else if (client->player == NULL)
	if (kill_timeout(&client->time, &timeout) == true)
	  {
	    printf("je timeout un client\n");
	    list = sup_client(client);
	  }
      client = client2;
    }
  return (list);
}