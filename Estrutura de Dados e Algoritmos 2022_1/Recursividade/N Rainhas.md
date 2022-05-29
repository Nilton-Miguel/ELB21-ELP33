# N Rainhas

Esse código tem por objetivo posicionar num tabuleiro NxN N rainhas de forma que nenhuma fique na linha de ataque das demais. Outro requisito do exercício é que isso seja implementado de forma recursiva. Segue abaixo uma explicação dos principais componentes de minha solução:

# atualiza_tabuleiro()

Essa função toma como argumentos um tabuleiro de ordem N, as coordenadas (linha e coluna) da célula a ser atualizada e as coordenadas da última rainha posicionada no tabuleiro. A ideia é que toda vez que uma rainha for posicionada essa função seja chamada com as devidas coordenadas e atualize o tabuleiro, que significa, neste contexto, marcar com um inteiro 2 toda célula na linha de ataque dessa rainha. Assim, toda célula marcada com um 0 pode receber uma rainha, toda célula marcada com um 1 já contém uma rainha, e toda célula marcada com um 2 está numa linha de ataque e não pode mais receber rainhas.

**atualiza_tabuleiro()** é recursiva, sendo assim, chamamo-la com as coordenadas iniciais de 0,0 para atualizar a primeira célula, e ela se chamará recursivamente até as coordenadas N,N. ou seja, um loop recursivo de forma a verificar e possivelmente atualizar todas as células.