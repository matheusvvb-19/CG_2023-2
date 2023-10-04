<h1>Atividade 01</h1>

Nesta atividade, foi criada uma classe simples, denominada `myClass_Image`, responsável por gerar arquivos de extensão `.ppm` para as três imagens a seguir:

Posteriormente à geração dos arquivos mencionados, a biblioteca [ImageMagick](https://imagemagick.org/index.php) foi empregada de forma a converter tais arquivos para o formato `.png`. Uma documentação automática foi gerada a partir da ferramenta [Doxygen](https://www.doxygen.nl/) e está localizada na pasta `at01_doxygenOutput`.

Ao final desta atividade, as três seguintes imagens são geradas:
<div align="center">
  <img src="/Atividade01/expectedOutput.png" width="60%">
</div>

<h2>Execução</h2>
1. Instalar a biblioteca ImageMagick:

```
sudo apt install imagemagick
sudo apt install graphicsmagick-libmagick-dev-compat
```

2\. Gerar o arquivo executável a partir da compilação dos códigos em arquivos de extensão `.cc` e `.h`:

```
g++ at01_main.cc at01_myClass_Image.cc -o main `Magick++-config --cppflags --cxxflags --ldflags --libs`
```

3\. Executar o arquivo executável criado na etapa anterior:

```
./main
```

Os arquivos de extensão `.ppm` e `.png` serão criados na mesma pasta do código fonte. A pasta `at01_doxygenOutput` contém a documentação gerada automaticamente pela ferramenta [Doxygen](https://www.doxygen.nl/) em dois formtados: *html* e *latex*. Além disso, há um arquivo `.pdf` contendo tal documentação.
