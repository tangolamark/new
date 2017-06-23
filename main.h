struct memory{
  void* fp;
  void* bp;
  int size;
  int used;
} *sp;

//void init(void);
void* my_malloc(size_t);//, const void*);
void my_free(void*);

