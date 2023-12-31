<h1>Atividade 02</h1>

Nesta atividade, foram criadas as classes `vec2`, `vec4`, `mat2`, `mat3` e `mat4`, responsáveis por implementar operações básicas (soma, subtração, divisão e multiplicação) entre vetores e/ou matrizes de 2, 3 e 4 dimensões.

<h2>Construção</h2>

1\. Primeiramente, as classes foram implementadas em seus respectivos arquivos de extensão `.hpp` e armazenados na pasta `src`;

2\. O *framework* CMake foi instalado a partir do comando abaixo. Além dele a extensão *CMake Tools* (Microsoft) também foi instalada no Visual Studio Code:

```
sudo apt install cmake
```

3\. O repositório do GoogleTest, *framework* do Google para testes unitários em C++, foi clonado para a pasta raiz da atividade:

```
git clone https://github.com/google/googletest.git
```

4\. Os arquivos `CMakeLists.txt` e `tests/CMakeLists.txt` foram criados, de forma a se definir configurações específicas para a execução dos testes; e

5\. O arquivo `tests/at02_tests.cpp` foi escrito de forma a conter os testes a serem executados.

<h2>Resultados</h2>
Os testes foram executados através da interface gráfica do Visual Studio Code, no botão *Run CTest* indicado a seguir. Todos os testes realizados foram bem sucedidos, conforme imagem abaixo.
<div align="center">
  <img src="/Atividade02/images/testsOutput.png" width="60%">
</div>

<h2>Referências</h2>

* [GoogleTest User's Guide](http://google.github.io/googletest/reference/assertions.html)
* [Introduction to Google Test and CMake](https://www.youtube.com/watch?v=Lp1ifh9TuFI)
