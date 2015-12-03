
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <peekpoke.h>

void setcrtmode(unsigned int CRTMODE)
{
    /* note: the following constants must be hex values
             or cc65 complains that the constant is a long
    switch(CRTMODE)
        {
    case 0:
                   POKE(0xc051,0);  /* text
                   POKE(0xc054,0);  /* page 1
                   break;
    case 2:
    default:
                  POKE(0xc057,0);   /* hi res
                  POKE(0xc055,0);   /* page 2
                  POKE(0xc050,0);   /* set graphics
                  POKE(0xc052,0);   /* full graphics

        }

}

/* provides base address for page2 hires scanlines
unsigned HB[]={
0x4000, 0x4400, 0x4800, 0x4C00, 0x5000, 0x5400, 0x5800, 0x5C00,
0x4080, 0x4480, 0x4880, 0x4C80, 0x5080, 0x5480, 0x5880, 0x5C80,
0x4100, 0x4500, 0x4900, 0x4D00, 0x5100, 0x5500, 0x5900, 0x5D00,
0x4180, 0x4580, 0x4980, 0x4D80, 0x5180, 0x5580, 0x5980, 0x5D80,
0x4200, 0x4600, 0x4A00, 0x4E00, 0x5200, 0x5600, 0x5A00, 0x5E00,
0x4280, 0x4680, 0x4A80, 0x4E80, 0x5280, 0x5680, 0x5A80, 0x5E80,
0x4300, 0x4700, 0x4B00, 0x4F00, 0x5300, 0x5700, 0x5B00, 0x5F00,
0x4380, 0x4780, 0x4B80, 0x4F80, 0x5380, 0x5780, 0x5B80, 0x5F80,
0x4028, 0x4428, 0x4828, 0x4C28, 0x5028, 0x5428, 0x5828, 0x5C28,
0x40A8, 0x44A8, 0x48A8, 0x4CA8, 0x50A8, 0x54A8, 0x58A8, 0x5CA8,
0x4128, 0x4528, 0x4928, 0x4D28, 0x5128, 0x5528, 0x5928, 0x5D28,
0x41A8, 0x45A8, 0x49A8, 0x4DA8, 0x51A8, 0x55A8, 0x59A8, 0x5DA8,
0x4228, 0x4628, 0x4A28, 0x4E28, 0x5228, 0x5628, 0x5A28, 0x5E28,
0x42A8, 0x46A8, 0x4AA8, 0x4EA8, 0x52A8, 0x56A8, 0x5AA8, 0x5EA8,
0x4328, 0x4728, 0x4B28, 0x4F28, 0x5328, 0x5728, 0x5B28, 0x5F28,
0x43A8, 0x47A8, 0x4BA8, 0x4FA8, 0x53A8, 0x57A8, 0x5BA8, 0x5FA8,
0x4050, 0x4450, 0x4850, 0x4C50, 0x5050, 0x5450, 0x5850, 0x5C50,
0x40D0, 0x44D0, 0x48D0, 0x4CD0, 0x50D0, 0x54D0, 0x58D0, 0x5CD0,
0x4150, 0x4550, 0x4950, 0x4D50, 0x5150, 0x5550, 0x5950, 0x5D50,
0x41D0, 0x45D0, 0x49D0, 0x4DD0, 0x51D0, 0x55D0, 0x59D0, 0x5DD0,
0x4250, 0x4650, 0x4A50, 0x4E50, 0x5250, 0x5650, 0x5A50, 0x5E50,
0x42D0, 0x46D0, 0x4AD0, 0x4ED0, 0x52D0, 0x56D0, 0x5AD0, 0x5ED0,
0x4350, 0x4750, 0x4B50, 0x4F50, 0x5350, 0x5750, 0x5B50, 0x5F50,
0x43D0, 0x47D0, 0x4BD0, 0x4FD0, 0x53D0, 0x57D0, 0x5BD0, 0x5FD0};

/* this version of fbox provides filled boxes in both hires palettes
   and conforms to the standard Apple II hires color numbers.
   it is not backwardly compatible due to my support for one
   palette only in the past. c'est la vie

void hibox(x1,y1,x2,y2,drawcolor)
int x1,y1,x2,y2,drawcolor;
{
    /* draws a filled box to the color specified
    int packet = (x2-x1)+1;
    int temp,ctr;
    char *ptr;
    char c[2];

    /* if on an odd byte boundary reverse color arg
    /* to match color mapping in the framebuffer
    if(x1%2!=0)
    {
        switch(drawcolor)
        {
            case 1 : drawcolor = 2; break;
            case 2 : drawcolor = 1; break;
            default: break;
        }
    }


    /* set the color
    switch(drawcolor)
    {
      case 8 : break;                      /* inverse video box
      case 7 : c[0]='\x7f'; c[1]='\x7f';   /* white  ... everything
               break;
      case 6 : c[0]='\x2a'; c[1]='\x55';   /* green
               break;
      case 5 : c[0]='\x55'; c[1]='\x2a';   /* purple
               break;
      case 4:  c[0]='\x00';c[1]='\x00';    /* black  ... nothing
               break;
      case 3 : c[0]='\xff'; c[1]='\xff';   /* white  ... everything
               break;
      case 2 : c[0]='\xaa'; c[1]='\xd5';   /* orange
               break;
      case 1 : c[0]='\xd5'; c[1]='\xaa';   /* blue
               break;
      default: c[0]='\x80';c[1]='\x80';    /* black  ... nothing
     }

   y2++;

   /* now write the pixels
   while(y1<y2)
   {
     temp=HB[y1];
     ptr = (char *)(temp+x1);
     for(ctr=0;ctr<packet;ctr++)
     {
        if(drawcolor!=8)
        {
        *ptr=c[0];
        *ptr++;
        ctr++;
        if(ctr<packet)
        {
            *ptr=c[1];
            *ptr++;
        }
        }
        else
        {
        *ptr^='\x7f';   /* xor in current palette
        *ptr++;
        }
     }
     y1++;
     }
}

int khit()
{
  unsigned char *KP = (unsigned char*)0xC000;
  unsigned char c;

  /* read the keyboard buffer
  /* and return 0 if no character is waiting

   c = KP[0];
   if(c<128)return 0;
   return (int)c;
}

void clearkey()
{

/* return the last key press
unsigned char *KEYPRESS = (unsigned char*)0xC000;
/* clear the last key press
unsigned char *KEYCLEAR = (unsigned char*)0xC010;

    /* clear stragglers from the keyboard buffer
    while(KEYPRESS[0] > 127)KEYCLEAR[0]=0;
}

int hrod ()
{

    int i, j, k, w, fmi, fmk, color, c=0;

    for (w = 3; w < 51; w++) {
        for (i = 1; i < 20; i++) {
            for (j = 0; j < 20; j++) {
                k = i + j;
                color = (j * 3) / (i + 3) + i * w / 12;
                fmi = 40 - i;
                fmk = 40 - k;

                color = (color/2)&7;

                hibox( i-1, k*4, i, k*4+3, color);
                hibox( k-1, i*4, k, i*4+3, color);

                hibox( fmi-1, fmk*4, fmi, fmk*4 + 3,color);
                hibox( fmk-1, fmi*4, fmk, fmi*4 + 3,color);

                hibox( k-1, fmi*4, k, fmi*4+3,color);
                hibox( fmi-1, k*4, fmi, k*4+3,color);

                hibox( i-1, fmk*4, i, fmk*4+3,color);
                hibox( fmk-1, i*4, fmk, i*4+3,color);
                if ((c = khit()) > 0) {
                    clearkey();
                    return c-128;

                }
            }
        }
    }

    if ((c = khit()) > 0) {
        clearkey();
        c-=128;
    }


    return c;

}

int main()
{


    setcrtmode(2);
    clearkey();
    for (;;) {
        hibox(0,0,39,191,0);
        if (hrod()==27)break;

    }
    setcrtmode(0);
    setcrtmode(0);
    clrscr();
    return EXIT_SUCCESS;

}
