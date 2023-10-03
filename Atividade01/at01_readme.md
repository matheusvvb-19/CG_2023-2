<h1>Atividade 01</h1>

Nesta atividade, foi criada uma classe simples, denominada `myClass_Image`, responsável por gerar arquivos de extensão `.ppm` para as três imagens a seguir:

Posteriormente à geração dos arquivos mencionados, a biblioteca [ImageMagick](https://imagemagick.org/index.php) foi empregada de forma a converter tais arquivos para o formato `.png`. Uma documentação automática foi gerada a partir da ferramenta [Doxygen](https://www.doxygen.nl/) e está localizada na pasta `at01_doxygenOutput`.

<h2>Execução</h2>
1. Gerar o arquivo executável a partir da compilação dos códigos em arquivos de extensão `.cc` e `.h`:

```
g++ at01_main.cc at01_myClass_Image.cc -o main
```

2. Executar o arquivo executável criado na etapa anterior:

```
./main
```

3. Instalar a biblioteca ImageMagick:

```
sudo apt install imagemagick
```
*observação: você pode verificar a versão instalada a partir do comando `identify -version`.

4. Converter cada um dos arquivos `.ppm` para `.png` com o seguinte comando, substituindo `<arquivoEntrada>` e `<arquivoSaida>` pelo nome do respectivo arquivo `.ppm` e o nome desejado para o arquivo de saída (após conversão):
```
convert <arquivoEntrada>.ppm <arquivoSaida>.png
```
