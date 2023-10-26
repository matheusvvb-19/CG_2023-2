<h1>Atividade 03</h1>

Nesta atividade, foi criada a classe `myClass_objLoader`, responsável por realizar a leitura de um arquivo de extensão `.obj`, extraindo suas informações (vértices, coordenadas de textura, normais e faces).

<h2>Construção</h2>

1\. Primeiramente, a classe foi implementada em seu respectivo arquivo de extensão `.hpp` e armazenado na pasta `src`;

2\. O *framework* CMake foi instalado a partir do comando abaixo. Além dele a extensão *CMake Tools* (Microsoft) também foi instalada no Visual Studio Code:

```
sudo apt install cmake
```

3\. O repositório do GoogleTest, *framework* do Google para testes unitários em C++, foi clonado para a pasta raiz da atividade:

```
git clone https://github.com/google/googletest.git
```

4\. Os arquivos `CMakeLists.txt` e `tests/CMakeLists.txt` foram criados, de forma a se definir configurações específicas para a execução dos testes; e

5\. O arquivo `tests/at03_tests.cpp` foi escrito de forma a conter os testes a serem executados.

<h2>Resultados</h2>
Os testes foram executados através da interface gráfica do Visual Studio Code, no botão *Run CTest* indicado a seguir. Todos os testes realizados foram bem sucedidos, conforme imagem abaixo.
<div align="center">
  <img src="/Atividade03/images/testsOutput.png" width="60%">
</div>

<h2>Referências</h2>

* [GoogleTest User's Guide](http://google.github.io/googletest/reference/assertions.html)
* [Introduction to Google Test and CMake](https://www.youtube.com/watch?v=Lp1ifh9TuFI)
