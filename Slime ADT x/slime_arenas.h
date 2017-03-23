
//  slime_arenas.h
//  Slime ADT x
//  [22/03/2017]

#ifndef slime_arenas_h
#define slime_arenas_h

typedef struct slime_arena_ slime_arena;

slime_arena *arenaCreate(void *(*create)(void),
                         void (*init)(void *),
                         void (*destroy)(void *));

void arenaDestroy(slime_arena *arena);

void *arenaRequest(slime_arena *arena);

void arenaReturn(slime_arena *arena, void *data);

#endif /* slime_arenas_h */
