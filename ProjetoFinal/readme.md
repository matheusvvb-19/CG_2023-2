<h1>Projeto Final</h1>

O objetivo desta atividade é o desenvolvimento de uma animação utilizando as implementações desenvolvidas em aula.

O projeto deve gerar uma animação com pelo menos 5 segundos. Como a implementação não é otimizada e não temos muito poder de processamento, a animação pode ter uma baixa resolução e poucos quadros por segundo. A composição dos quadros pode ser realizada com ferramenta externa (exportando em um formato avi/mp4/etc), mas a geração das imagens deve utilizar as implementações dos membros do grupo.

Utilize pelo menos 3 objetos, sendo pelo menos um deles formado por triângulos. Utilize materiais difusos e reflexivos. Faça pelo menos um movimento com a câmera e outro com pelo menos um dos objetos.

O projeto será avaliado considerando os seguinte requisitos:
- Atendimento aos requisitos;
- Documentação do código e de apesentação do projeto;
- Qualidade visual final da animação;

<h2>Construção</h2>

1\. Foram utilizadas as classes auxiliares (e.g., `vec3`, `sphere`, `material`), presentes no próprio repositório e implementadas em atividades anteriores;

2\. O arquivo principal `projeto_main.cpp`, localizado na pasta `src` foi implementado de forma a criar a cena e inserir seus objetos. Conforme requisito da atividade, os objetos inseridos apresentam material difusos e reflexivos. Alguns dos objetos foram renderizados utilizando-se esferas, enquanto outro foi renderizado através de interceptação de triângulos;

3\. Garantiu-se que a biblioteca [ImageMagick](https://imagemagick.org/script/magick++.php) estivesse instalada, a partir do comando abaixo:

```
sudo apt-get install libmagick++-dev
```

4\. Por fim, o arquivo `at04_main.cpp` foi inteiramente compilado e executado com os seguintes comandos:

```
g++ projeto_main.cpp -o main `pkg-config --cflags --libs Magick++`
./main
```

<h2>Resultados</h2>

A execução da atividade a partir do comandos indicados anteriormente resoluta nas seguintes cenas (`cam1.png` e `cam2.png`), respectivamente:


**Observação**: a documentação das novas classes (metal e vidro) já esão inclusas na Atividade 05.

<h2>Integrantes do Grupo</h2>

* Arthur Felipe Bravo Pita
* Guilherme Brante
* Lucca Marques
* Matheus Vargas Volpon Berto
