


#include "include.h"
#define __TP__

#define _TP_XMIN                                         32
#define _TP_XMAX                                         244
#define _TP_YMIN                                     25
#define _TP_YMAX                                    231

#define _TP_SAM_NUM            50
#define _TP_DET_START         30
#define _TP_DET_NUM             15
#define _TP_MARGIN                15

u16 CSystemAverageFilter(u16 ArrSize, u16 *Arr)
{
    int i=0;
    u32 sum=0;
    u32 temp=0;
    
    for(i=0;i<ArrSize;i++)
        sum+= Arr[i];

    sum = sum*1000;
    temp = sum/ArrSize;
    if((temp%1000)>500)
    {
    temp+=(1000-(temp%1000));
    }

    temp = temp/1000;

    return temp;
}

u16 CSystemMedianFilter(u16 ArrSize, u16 *Arr)
{
    int i;
    int j;
    int temp; 
    BOOL bFinish = FALSE;
    u8 DesNum = 0;
    
    for(j=1;j<ArrSize;j++) 
    { 
        for (i=0;i<ArrSize-j;i++) 
        {
            if (Arr[i]>Arr[i+1]) 
            {
                temp=Arr[i]; 
                Arr[i]=Arr[i+1]; 
                Arr[i+1]=temp;
                bFinish = TRUE;
            } 
        }
        if(!bFinish)
            break;
    } 
    DesNum = ArrSize/2;
    return Arr[DesNum];
}
u8 TP_Detect(u8 *Array)
{
    u16 i=0;
    u32 min=0;
    u32 max=0;
    u8 result=0;

    min=Array[0];
    max=Array[0];
    for(i=1;i<_TP_DET_NUM;i++)
    {
        if(Array[i]>max)
            max=Array[i];
        if(Array[i]<min)
            min=Array[i];
    }
    if((max-min)<_TP_MARGIN)
        result=1;
    else
        result=0;

    return result;
}
void TP_ClearBuff(void)
{
    u16 i=0;

    for(i=0;i<_TP_SAM_NUM;i++)
    {
        g_stTPx[i]=0;
        g_stTPy[i]=0;
    }
}
u8 TP_IsClickDown(u16 x1, u16 y1, u16 x2, u16 y2)
{
    if((g_u32TP_D_x>=x1)&&(g_u32TP_D_x<=x2)&&(g_u32TP_D_y>=y1)&&(g_u32TP_D_y<=y2))
    {
        return 1;
    }
    else
        return 0;
}
u8 TP_IsClickUp(u16 x1, u16 y1, u16 x2, u16 y2)
{
    if((g_u32TP_U_x>=x1)&&(g_u32TP_U_x<=x2)&&(g_u32TP_U_y>=y1)&&(g_u32TP_U_y<=y2))
    {
        return 1;
    }
    else
        return 0;
}
//****************触摸坐标显示
void CTPHandle(void)	
{
    u16 i=0;  
    u32 sum;
    u8 result_x=0;
    u8 result_y=0;
    u32 Tp_down_x=0;
    u32 Tp_down_y=0;
    
    //g_u32TP_D_x=0;
    //g_u32TP_D_y=0;
    //g_u32TP_U_x=0;
    //g_u32TP_U_y=0;

    Write_Dir(0xf1,0x04);//clear INT state 確保上次觸碰後 TP_interrupt 清除
    delay(2000);
    if((Touch_Status())&&(g_u16TPSamIndex<_TP_SAM_NUM))
    {
        g_stTPx[g_u16TPSamIndex] =ADC_X();
        g_stTPy[g_u16TPSamIndex] = ADC_Y();
        g_u16TPSamIndex++;
        if(g_u16TPSamIndex==_TP_SAM_NUM)
        {
            g_u16TPSamIndex = 0;
            Write_Dir(0xf1,0x04);//clear INT state 確保上次觸碰後 TP_interrupt 清除
            result_x = TP_Detect(&g_stTPx[_TP_DET_START]);
            result_y = TP_Detect(&g_stTPy[_TP_DET_START]);
            if((result_x==1)&&(result_y==1))
            {
                g_u8TPDown=1;

                sum=0;
                for(i=0;i<_TP_DET_NUM;i++)
                    sum+=g_stTPx[_TP_DET_START+i];
                Tp_down_x=sum/_TP_DET_NUM;


                sum=0;
                for(i=0;i<_TP_DET_NUM;i++)
                    sum+=g_stTPy[_TP_DET_START+i];
                Tp_down_y=sum/_TP_DET_NUM;

                Tp_down_x=abs(_TP_XMAX-Tp_down_x);
                g_u32TP_D_x = Tp_down_x*(4800000/(_TP_XMAX-_TP_XMIN))/10000;
                Tp_down_y=abs(_TP_YMAX-Tp_down_y);
                g_u32TP_D_y = Tp_down_y*(2720000/(_TP_YMAX-_TP_YMIN))/10000;
                if(g_u32TP_D_x>479)
                    g_u32TP_D_x=479;
                if(g_u32TP_D_y>271)
                    g_u32TP_D_y=271;
                g_u32TP_U_x=0;
                g_u32TP_U_y=0;
                //g_u8TPStatus = _TP_DOWN;
            }
        }
    }
    else
    {
        if(g_u8TPDown==1)
        {
            g_u8TPDown=0;
            g_u8TPUp=1;
            TP_ClearBuff();
            g_u32TP_U_x=g_u32TP_D_x;
            g_u32TP_U_y=g_u32TP_D_y;
            g_u32TP_D_x=0;
            g_u32TP_D_y=0;
        }
    }


}

