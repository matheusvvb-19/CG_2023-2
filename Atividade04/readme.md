<h1>Atividade 04</h1>

Nesta atividade, foram realizadas as seguintes funcionalidades:

- [x] Implementação de visualização de esfera um uma imagem de extensão `.png`, integrando a classe `myClass_Image` (Atividade 01) e a classe `vec3` (Atividade 02). Os arquivos `color.h` e `ray.h` ([Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)) foram empregados nesta atividade. Algumas alterações precisaram ser feitas na classe `MyClass_Image` - para mais detalhes, veja a pasta referente à [Atividade 01](https://github.com/matheusvvb-19/CG_2023-2/tree/main/Atividade01);
- [x] Implementação de visualização de um triângulo em uma imagem de extensão `.png`: semelhantemente ao caso da esfera, foi gerada uma imagem contendo um triângulo, baseado na análise de intercepção do raio (*ray tracing*) com a superfície do trinângulo. Para isso, foi utilizado o algoritmo de interseção de [Möller–Trumbore](https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm); e
- [x] Visualização completa de um objeto (arquivo `.obj`), a partir de integração com a [Atividade 03](https://github.com/matheusvvb-19/CG_2023-2/tree/main/Atividade03).

<h2>Construção</h2>

1\. Primeiramente, os arquivos `at04_ray.h` e `at04_color.h` foram adquiridos e inseridos na pasta `src`;

2\. Garantiu-se que a biblioteca [ImageMagick](https://imagemagick.org/script/magick++.php) estivesse instalada, a partir do comando abaixo:

```
sudo apt-get install libmagick++-dev
```

3\. A função `ray_color()` presente no arquivo `at04_main.cpp` foi alterada de forma a agir diferentemente, de acordo com a forma geométrica (esfera ou triângulo) desejada. Além disso, foi criada a função auxiliar `hit_trangle()`, a qual é respons´vale por implementar o algoritmo de Möller–Trumbore, identificando quando os raios da câmera interceptam um triângulo definido.

4\. Por fim, o arquivo `at04_main.cpp` foi inteiramente impelementado, compilado e executado com os seguintes comandos:

```
g++ at04_main.cpp -o main `pkg-config --cflags --libs Magick++`
./main
```

<h2>Resultados</h2>

As primeiras duas etapas desta atividade geram como resultado as imagens `sphere.png` e `triangle.png`, mostradas abaixo.

<div align="center">
  <img src="/Atividade04/images/sphereAndTiangleImages.png" width="60%">
</div>

Já a visualização do arquivo `.obj`, realizada na terceira e última etapa desta atividade, é mostrada a seguir.

<div align="center">
  <img src="/Atividade04/images/cube.png" width="60%">
</div>

<h2>Referências</h2>

* [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)
* [Möller–Trumbore algorithm](https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm)
* [Setting up an OpenGL Project in Ubuntu [VSCode, GLFW, GLAD, CMake]](https://www.youtube.com/watch?v=LxEFn-cGdE0)
