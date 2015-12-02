#include <apple2enh.h>
#include <tgi.h>
#include <conio.h>

#define BLACK         0
#define GREEN         1
#define VIOLET        2
#define WHITE         3

/* Driver stuff */
static unsigned MaxX;
static unsigned MaxY;
static unsigned AspectRatio;

extern char a2e_hi;

static void doStuff(void);

int main() {
//  tgi_load_driver(tgi_stddrv);
  tgi_install(&a2e_hi);

  tgi_init();
  tgi_clear();

  /* Get stuff from the driver */
  MaxX = tgi_getmaxx() ;
  MaxY = tgi_getmaxy();
  AspectRatio = tgi_getaspectratio ();

  doStuff();

  tgi_uninstall();

  return 0;
}

static void doStuff (void) {
  int x, y;

  tgi_setviewpage(0);
  tgi_setdrawpage(1);
  tgi_clear();

  for (x = 0; x <= MaxX; x++) {
    for (y = 0; y <= 10; y++) {
      if (x % 2 == 0) {
        tgi_setcolor(VIOLET & 0x55);
      } else {
        tgi_setcolor(GREEN & 0x55);
      }
      tgi_setpixel(x, y);
    }
  }

  tgi_setviewpage(1);

  while (!kbhit()) {

  }
}
