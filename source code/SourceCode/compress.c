/*****************************************************************************
 *   compress.c:  system module file for NXP LPC17xx Family Microprocessors
 *
 *   Copyright(C) 2009, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2009.05.25  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/

#include "include.h"
void CCurveCompress(u32 n, u32 *t_A)
{
    u16 Vchushu=0;
    u16 Vyushu=0;
    u16 VBreak=0;
    u16 i=0;
    u16 j=0;
    u16 k=0;

    u32 max=0;
    u32 min=0;
    u16 Ainterval=0;


    Vchushu = n/_H_LEN;
    max=min=t_A[0];
    	
    if(Vchushu < 1)
    {
        for(i=0;i<n;i++)
        {
        	if(max<t_A[i])
        		max=t_A[i];
        	if(min>t_A[i])
        		min=t_A[i];
        }


        Ainterval = (max-min)/_V_LEN;

        for(i=0;i<n;i++)
        {
        	t_A[i] = t_A[i]-((t_A[i]-min)%Ainterval);
        	t_u16CompressPoint[i] = (t_A[i]-min)/Ainterval;
        	//m_Series0.AddXY(i,t_AValue[i],NULL,1);
        }
    }
    else
    {
        Vyushu = n%_H_LEN;
        Vyushu = Vyushu/Vchushu;
        if(Vyushu!=0)
            VBreak = n/Vyushu;
        else
            VBreak = n/_H_LEN;

        j=0;
        k=0;
        for(i=0;i<n;i+=Vchushu)
        {
            j++;
            if(((j%(VBreak))==0)&&(j!=0));
            else
            {
                if(k<_H_LEN)
                {
                    t_HPoint[k] = i;
                    k++;
                }
            }
        }

        for(i=0;i<_H_LEN;i++)
        {
        	t_AValue[i] = t_A[t_HPoint[i]];
            if(i==94)
                j=0;
        	if(max<t_AValue[i])
        		max=t_AValue[i];
        	if(min>t_AValue[i])
        		min=t_AValue[i];
        }

        Ainterval = (max-min)/_V_LEN;

        for(i=0;i<_H_LEN;i++)
        {
        	t_AValue[i] = t_AValue[i]-((t_AValue[i]-min)%Ainterval);
        	t_u16CompressPoint[i] = (t_AValue[i]-min)/Ainterval;
        	//m_Series0.AddXY(i,200-t_AValue[i],NULL,1);
        }
    }
    
}


