#include <iostream>

#include "at01_myClass_Image.h"

int main() {
    myClass_Image myObject = myClass_Image();

    myObject.RenderImageFade("imageFade.ppm");
    myObject.RenderImageRectangule("imageRectangule.ppm");
    myObject.RenderImageLine("imageLine.ppm");

    return 0;
}
