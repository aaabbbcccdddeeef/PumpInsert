


#define _TP_NONE                               0
#define _TP_DOWN                              1
#define _TP_UP                                    2
#define _TP_DOWN_MOVE                   3


#ifdef __TP__
//--------------------------------------------------
// Global Variables
//--------------------------------------------------


//--------------------------------------------------
// Function Prototypes
//--------------------------------------------------

#else
//--------------------------------------------------
// Extern Global Variables


//--------------------------------------------------
// Extern Function Prototypes
//--------------------------------------------------
extern void CTPHandle(void);
extern u8 TP_IsClickDown(u16 x1, u16 y1, u16 x2, u16 y2);
extern u8 TP_IsClickUp(u16 x1, u16 y1, u16 x2, u16 y2);
extern u16 CSystemAverageFilter(u16 ArrSize, u16 *Arr);

extern u16 CSystemMedianFilter(u16 ArrSize, u16 *Arr);

#endif
//----------------------------------------------------------------------------------------------------


