#ifndef D_RuntimeErrorStub_H
#define D_RuntimeErrorStub_H

#include "RuntimeError.h"

/* START: header */
void RuntimeErrorStub_Reset(void);
const char * RuntimeErrorStub_GetLastError(void);
int RuntimeErrorStub_GetLastParameter(void);
/* END: header */

#endif
