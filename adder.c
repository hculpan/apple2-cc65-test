#include <apple2enh.h>
#include <tgi.h>
#include <conio.h>

#define COLOR_BACK      TGI_COLOR_BLACK
#define COLOR_FORE      TGI_COLOR_WHITE

/* Driver stuff */
static unsigned MaxX;
static unsigned MaxY;
static unsigned AspectRatio;

static void DoCircles(void);

int main() {
  tgi_load_driver(tgi_stddrv);

  tgi_init();
  tgi_clear();

  /* Get stuff from the driver */
  MaxX = tgi_getxres () + 1;
  MaxY = tgi_getyres () + 1;
  AspectRatio = tgi_getaspectratio ();

  /* Set the palette, set the border color */
//  Border = bordercolor (COLOR_BLACK);

  DoCircles();

  tgi_done();

  cprintf("MaxX=%d\n", MaxX);
  cprintf("MaxY=%d\n", MaxY);

  cgetc();

  return 0;
}

static void DoCircles (void) {
    static const unsigned char Palette[2] = { TGI_COLOR_WHITE, TGI_COLOR_ORANGE };

    tgi_setpalette(Palette);
    tgi_setcolor(TGI_COLOR_GREEN);
    tgi_line(0, 0, 100, 100);
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
