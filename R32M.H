/*
 *  random.h - �������� ��砩��� �ᥫ
 *  (C) ��ମ�, 1991
 */

void  rninit   ( unsigned long iufir );
void  rnrest   ( void );
void  rnconst  ( unsigned long iufir );
void  rnconfix ( unsigned nmb );

unsigned long rnfirst (void);
unsigned long rnlast  (void);
unsigned long rnconrd (void);

double  rnunif ( void );
double  rnexp  ( void );
double  rnnorm ( void );
