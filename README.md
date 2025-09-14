Esse projeto é uma tentativa de criar a simulação de um buraco negro em c++ utilizando openGL, eu sei c++ até a parte de criar uma função e nunca mexi com openGL, bora la.

# Criando uma tela
acostumado apenas com desenvolvimento web e projetos em console, eu não faço ideia de como se cria uma simples janela preta pra exibir graficos então esse ponto ja é um avanço.
## Configurando o ambiente
Primeiramente algumas dependencias, precisamos de um compilador C++, no caso do arch o ``GCC``, os drivers da nvidia pra rodar o openGL e os seguintes pacotes:
* **GLFW**: glfw3 é uma lib pra crirar janelas e contextos OpenGL
* **GLEW**: É um gerenciador de extensões pro OpenGL
* **GLM**: É uma biblioteca de matematica pra shaders

Rapaaaaaz isso vai ser interessante kkkkk

## Inicializando uma janela

Pra iniciar uma janela me parece que temos que criar um ``contexto com glfw`` para isso iniciamos o **glfw**, criamos um **objeto window**, então criamos o **contexto** passando como parametro a **window**, então iniciamos o glew e voilá! Temos uma janelinha.

## Estruturando o projeto

A referencia que eu utilizei pra esse projeto foi o [repositorio do Kavan ](https://github.com/kavan010/black_hole), mas uma conversa rapida com o **GPT** apontou que ele estava utilizando uma versão mais antiga do openGL e aqui entra a oportunidade de fazer diferente. Então para utilizar uma versão mais moderna, tive que estruturar o projeto da seguinte forma:
``` text
black.hole
|_include/
|_shaders/
|_src/
|_bhs.exe
|_README.md
```
**Includes** para as definições, **Src** para as implementações e como as versões mais recentes do openGL utilizam shaders... **Shaders**.

Agora podemos adicionar os arquivos e começar a brincadeira.


## O Buraco Negro
Buraco negro é um objeto astronômico denso e massivo cujo intenso campo gravitacional impede qualquer coisa de escapar, nem mesmo a luz. A teoria da relatividade geral prevê que uma massa suficientemente compacta pode deformar o espaço-tempo para formar um buraco negro. [Wikipedia](https://pt.wikipedia.org/wiki/Buraco_negro)

Dada essa breve introdução, precisamos definir algumas coisas que precisamos ter pra garantir que nosso buraco negro vai ficar lidão.
* Raio de Schwarzchild: É o que chamamos de "buraco", o vazio gerado pela singularidade que não deixa nem a luz escapar
* Lente gravitacional: A distorção optica causada ao redor do buraco negro
* Horizonte de Eventos: O ponto onde a força de atração do buraco negro se torna mais forte que a velocidade da luz e nada consegue escapar. Ele vai gerar o nosso **Disco de acreção**.

### Raio de Schwarzchild
O **raio de Schwarzschild** é dado pela fórmula:
$$
r_s = \frac{2GM}{c^2}
$$
- \( G \) é a constante gravitacional,
- \( M \) é a massa do buraco negro,
- \( c \) é a velocidade da luz.

