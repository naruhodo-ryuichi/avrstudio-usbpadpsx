#ifndef PSX_H_
#define PSX_H_

void psxInit(void);
void psxtalk(unsigned char* report, _Bool sMotor, unsigned char bMotor);

#endif