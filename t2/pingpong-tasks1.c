// PingPongOS - PingPong Operating System
// Prof. Carlos A. Maziero, DINF UFPR
// Versão 1.4 -- Janeiro de 2022

// Teste da gestão básica de tarefas

#include <stdio.h>
#include <stdlib.h>
#include "ppos.h"

task_t Ping, Pong ;

// corpo da thread Ping
void BodyPing (void * arg)
{
   int i ;
   char* name = (char *) arg ;

   printf ("%s: inicio\n", name) ;
   for (i=0; i<4; i++)
   {
      printf ("%s: %d\n", name, i) ;
      task_switch (&Pong);
   }
   printf ("%s: fim\n", name) ;
   task_exit (0) ;
}

// corpo da thread Pong
void BodyPong (void * arg)
{
   int i ;
   char* name = (char *) arg ;

   printf ("%s: inicio\n", name) ;
   for (i=0; i<4; i++)
   {
      printf ("%s: %d\n", name, i) ;
      task_switch (&Ping);
   }
   printf ("%s: fim\n", name) ;
   task_exit (0) ;
}

int main (int argc, char *argv[])
{
   printf ("main: inicio\n");
  // printf("init");
   ppos_init () ;
  // printf("create ping\n");
   task_create (&Ping, BodyPing, "    Ping") ;
  // printf("create pong\n");
   task_create (&Pong, BodyPong, "        Pong") ;

  // printf("switch ping");
   task_switch (&Ping) ;
   //printf("switch pong");
   task_switch (&Pong) ;

   printf ("main: fim\n");

   exit (0);
}
