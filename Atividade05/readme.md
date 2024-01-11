<h1>Atividade 05</h1>

Nesta atividade, foram realizadas as seguintes funcionalidades:

- [x] Implementação de material difuso, utilizando o vetor normal;
- [x] Visualização de uma cena com três objetos, sendo duas esferas e um cubo - criado a partir da leitura de um arquivo `.obj` e renderizado com triângulos - de dois pontos de vistas distintos.

<h2>Construção</h2>

1\. Primeiramente, os seguintes arquivos listados abaixo foram adicionados ao projeto, com base na leitura do tutorial disponibilizado:
* `at05_camera.h`
* `at05_color.h`
* `at05_hittable_list.h`
* `at05_hittable.h`
* `at05_interval.h`
* `at05_material.h`
* `at05_sphere.h`
* `at05_utils.h`
* `at05_vertex.h`

2\. O arquivo principal `at05_main.cpp` foi implementado de forma a criar a cena e inserir seus objetos. Conforme requisito da atividade, os objetos inseridos apresentam material difuso. Alguns dos objetos foram renderizados utilizando-se esferas, enquanto outro foi renderizado através de interceptação de triângulos. Cada vértice do triângulo apresenta um vetor normal.

3\. Garantiu-se que a biblioteca [ImageMagick](https://imagemagick.org/script/magick++.php) estivesse instalada, a partir do comando abaixo:

```
sudo apt-get install libmagick++-dev
```

4\. Por fim, o arquivo `at04_main.cpp` foi inteiramente compilado e executado com os seguintes comandos:

```
g++ at04_main.cpp -o main `pkg-config --cflags --libs Magick++`
./main
```

<h2>Resultados</h2>

A execução da atividade a partir do comandos indicados anteriormente resoluta nas seguintes cenas (`cam1.png` e `cam2.png`), respectivamente:

<div align="center">
  <img src="/Atividade04/images/cam1.png" width="60%">
</div>

<div align="center">
  <img src="/Atividade04/images/cam2.png" width="60%">
</div>

<h2>Referências</h2>

* [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)
* [Ray Tracing: Rendering a Triangle](https://github.com/scratchapixel/code/blob/main/ray-tracing-rendering-a-triangle/raytri.cpp)
