#ifndef LIBMANAGE_GLOBAL_H
#define LIBMANAGE_GLOBAL_H
#include "user.h"
#include "reader.h"
#include "manager.h"
#include "Book.h"
extern Book* bhead = NULL;
extern Book* bend = NULL;
extern manager* mhead = NULL, * mend = NULL;
extern Reader* rhead = NULL;
extern Reader* _rend = NULL;
char code[20] = "521225zsz";

#endif //LIBMANAGE_GLOBAL_H
