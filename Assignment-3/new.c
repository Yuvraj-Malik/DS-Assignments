#include <stdio.h>
int main()
{
    int x = 4, y = 7, z = 2, w = 5;

    x = y++ * --z + x-- % ++w - z++;
    y = --x + y-- * z++ - w++ % ++x;
    z = x++ - --y + ++z * w-- - x-- % y++;
    w = z++ * --x - y++ + w-- % ++z + --y;

    printf("%d %d %d %d\n", x, y, z, w);
    return 0;
}
