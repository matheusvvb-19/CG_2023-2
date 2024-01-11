<h1>Atividade 06</h1>

Nesta atividade, foram realizadas as seguintes funcionalidades:

- [x] Implementação de materiais com reflexão e refração;
- [x] Visualização de uma cena com objetos metálicos e de vidro.

<h2>Construção</h2>

1\. As classes referentes aos materiais metálicos e de vidro foram implmentadas no arquivo `at05_material.h` ([Atividade 05]());

2\. O arquivo principal `at05_main.cpp` foi implementado de forma a criar a cena e inserir seus objetos. Conforme requisito da atividade, os objetos inseridos apresentam material metálico e de vidro. Alguns dos objetos foram renderizados utilizando-se esferas, enquanto outro foi renderizado através de interceptação de triângulos. Cada vértice do triângulo apresenta um vetor normal.

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
  <img src="/Atividade06/images/cam1.png" width="60%">
</div>

<div align="center">
  <img src="/Atividade06/images/cam2.png" width="60%">
</div>

**Observação**: a documentação das novas classes (metal e vidro) já esão inclusas na Atividade 05.

<h2>Referências</h2>

* [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)
