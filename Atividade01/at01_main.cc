/**
 * @file at01_main.cc
 * @author Matheus Vargas Volpon Berto
 * @brief Programa principal, instancia um objeto da classe myClass_Image e invoca suas funções internas.
 * @version 1.0.0
 * @date 2023-10-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>

#include "at01_myClass_Image.h"

int main() {
    // instanciando um objeto para a imagem:
    myClass_Image myObject = myClass_Image();

    // gerando arquivos de extensão .ppm:
    myObject.RenderImageFade("imageFade.ppm");
    myObject.RenderImageRectangule("imageRectangule.ppm");
    myObject.RenderImageLine("imageLine.ppm");

    return 0;
}