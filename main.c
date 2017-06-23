#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
#include <malloc.h>
#include <mcheck.h>
int numberOfArea = 0;

void my_free(void* addr){
  int i;
  for(i=0;i<numberOfArea;++i){
    if(sp[i].bp == addr){
      sp[i].used = 0;
      break;
    }
  }
  while(numberOfArea && !sp[numberOfArea-1].used){
    --numberOfArea;
  }
}

void* my_malloc(size_t size){//, const void* cnst){
  void* tmp = sbrk(0);
//  sp = realloc(sp,sizeof(*sp)*(numberOfArea + 1));
  if(!numberOfArea){
    sp[numberOfArea].bp = tmp;
  }else{
    sp[numberOfArea].bp = sp[numberOfArea-1].bp;
  }
  /*sp[numberOfArea].used = 1;
  sp[numberOfArea].size = size;
  ++numberOfArea;
  tmp = sbrk(2*size);*/
  return tmp;
}

void init(void){
  __malloc_hook = my_malloc;
  __free_hook = my_free;
  sp = malloc(sizeof(*sp)*1000);
}


void (*__malloc_initialize_hook)(void) = init;

int main(){
  init();
  return 0;
}
