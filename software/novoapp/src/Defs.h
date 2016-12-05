#ifndef DEFS_H_
#define DEFS_H_

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

typedef enum {T_NONE, T_COFFE, T_COFFEMILK, T_MOCACCHINO} coffeTypes;
typedef enum {COFFE, MILK, SUGAR, CHOCOLATE} supplies;
typedef enum {st_SELECT, st_CHECK_REFILL, st_NO_SUPPLIES, st_MAKE, st_RESET} states;

#endif // DEFS_H_
