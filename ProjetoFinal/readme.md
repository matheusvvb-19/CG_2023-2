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

4\. Por fim, o arquivo `projeto_main.cpp` foi inteiramente compilado e executado com os seguintes comandos:

```
g++ projeto_main.cpp -o main `pkg-config --cflags --libs Magick++`
./main
```

<h2>Resultados</h2>

A cena construída apresenta um cubo metálico posicionado na origem, entre duas esferas - sendo uma delas de vidro e, a outra, difusa. As esferas se movimentam horizontalmente, enquanto a câmera também se move parcialmente ao redor dos objetos, voltando ao seu ponto inicial. A animação contém 5 segundos e apresenta 10 frames por segundo, totalizando 50 frames, os quais foram unidos através da ferramenta online [Clideo](https://clideo.com/pt/video-maker).

Foram criadas algumas variações da animação, alterando-se o valor de largura da imagem (atributo `image_width` da classe `camera`). Outros atributos da câmera foram mantidos constantes, como:

* `aspect_ratio`: 16 / 9
* `samples_per_pixel`: 10
* `max_depth`: 20
* `vfov`: 30
* `defocus_angle`: 0.6
* `focus_dist`: 10

A seguir, estão listados os valores testados, com acesso ao vídeo produzido.

* [image_width 144](https://drive.google.com/file/d/1TD5ir_JYE_QMG4NB8rd6F6YlKBYYVpVu/view?usp=drive_link)
* [image_width 320](https://drive.google.com/file/d/1Cq4PY9jNX12W1-8nP-t8k_wI4yMGPuB8/view?usp=drive_link)
* [image_width 500](https://drive.google.com/file/d/1nLQneh7DMxCckhW7keG_ljAWfTYAhDE3/view?usp=drive_link)
* [image_width 1280](https://drive.google.com/file/d/1CoT6I3p21mKlC8XibMZ8JRoH6PplwK8N/view?usp=drive_link)

Todos os vídeos podem ser encontrados [nesta pasta](https://drive.google.com/drive/folders/18PHfVBaKgD7IGaDz2KPG_7jaJL1Chcd8?usp=sharing) do Google Drive.

<h2>Integrantes do Grupo</h2>

* Arthur Felipe Bravo Pita
* Guilherme Brante
* Lucca Marques
* Matheus Vargas Volpon Berto
