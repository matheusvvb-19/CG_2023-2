<h1>Atividade 04</h1>

Nesta atividade, foram realizadas as seguintes funcionalidades:
* Implementação de visualização de esfera um uma imagem de extensão `.png`, integrando a classe `myClass_Image` (Atividade 01) e a classe `vec3` (Atividade 02). Os arquivos `color.h` e `ray.h` ([Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)) foram empregados nesta atividade. Algumas alterações precisaram ser feitas na classe `MyClass_Image` - para mais detalhes, veja a pasta referente à [Atividade 01](https://github.com/matheusvvb-19/CG_2023-2/tree/main/Atividade01);
* Implementação de visualização de um trinângulo em uma imagem de extensão `.png`: semelhantemente ao caso da esfera, foi gerada uma imagem contendo um triângulo, baseado na análise de intercepção do raio (*ray tracing*) com a superfície do trinângulo. Para isso, foi utilizado o algoritmo de interseção de [Möller–Trumbore](https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm); e

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
