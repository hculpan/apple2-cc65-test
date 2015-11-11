#include <apple2enh.h>
#include <tgi.h>
#include <conio.h>

#define COLOR_BACK      TGI_COLOR_BLACK
#define COLOR_FORE      TGI_COLOR_WHITE

/* Driver stuff */
static unsigned MaxX;
static unsigned MaxY;
static unsigned AspectRatio;

extern char a2e_hi;

static void DoCircles(void);

int main() {
//  tgi_load_driver(tgi_stddrv);
  tgi_install(&a2e_hi);

  tgi_init();
  tgi_clear();

  /* Get stuff from the driver */
  MaxX = tgi_getmaxx();
  MaxY = tgi_getmaxy();
  AspectRatio = tgi_getaspectratio ();

  /* Set the palette, set the border color */
//  Border = bordercolor (COLOR_BLACK);

  DoCircles();

  tgi_uninstall();

  cprintf("MaxX=%d\n", MaxX);
  cprintf("MaxY=%d\n", MaxY);

  cgetc();

  return 0;
}

static void DoCircles (void) {
//    static const unsigned char Palette[2] = { TGI_COLOR_WHITE, TGI_COLOR_ORANGE };

//    tgi_setpalette(Palette);
    int color = 0;
    int timer = 0;
    while (!kbhit()) {
      timer++;
      if (timer % 1000 == 0) {
        tgi_setcolor(color);
        color = (color + 1) % 6;
        tgi_line(1, 1, MaxX - 1, 1);
        tgi_lineto(MaxX - 1, MaxY - 1);
        tgi_lineto(1, MaxY - 1);
        tgi_lineto(1, 1);
        timer = 0;
      }
    }
/*    unsigned char I;
    unsigned char Color = COLOR_FORE;
    unsigned X = MaxX / 2;
    unsigned Y = MaxY / 2;

    tgi_setpalette (Palette);
    while (!kbhit ()) {
        tgi_setcolor (COLOR_FORE);
        tgi_line (0, 0, MaxX, MaxY);
        tgi_line (0, MaxY, MaxX, 0);
        tgi_setcolor (Color);
        for (I = 10; I < 240; I += 10) {
            tgi_ellipse (X, Y, I, tgi_imulround (I, AspectRatio));
        }
        Color = Color == COLOR_FORE ? COLOR_BACK : COLOR_FORE;
    }*/

    cgetc ();
//    tgi_clear ();
}
