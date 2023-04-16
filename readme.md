# Sobre o Hidra 

Assim como na mitologia, na história de Hidra de Lerna, a intenção desse pequeno estudo é criar um pequeno badware que se multiplica ao tentar fechar, claro que você poderá encerrar o processo dele.

Está escrito em C, ele usa o GTK para sua biblioteca gráfica, ao iniciar ele abre a janela pedindo o primeiro corte, após isso ele abre novas janelas a cada corte em locais aleatorios da tela de 1920 x 1080.

#### Testado em Pop! Os 22.04


## Brincadeiras possíveis: 

Colocar esse programa para inicialização autómatica no computador alvo, com isso ao logar em sua conta o usuário se deparará com a brincadeira da primeira janela, e enquanto não encerar o processo raiz ele continuara tentando sem sucesso fechar a janela.


## Em Windows

Compile o main.c com o comando abaixo: 
``` cmd
 gcc -o resultado main.c `pkg-config --cflags --libs gtk+-3.0`
```
Teremos um .exe após isso, basta executar para iniciar.

### Para a brincadeira funcionar melhor o passo a passo:
Para fazer o resultado.exe iniciar automaticamente ao iniciar o Windows, você pode seguir os seguintes passos:

* Pressione a tecla Windows + R para abrir o Executar.
* Digite shell:startup e pressione Enter. Isso abrirá a pasta de inicialização do Windows.
* Na pasta de inicialização, clique com o botão direito do mouse em um espaço vazio e selecione "Novo" -> "Atalho".
* Na janela que aparecer, clique em "Procurar" e navegue até o local onde o arquivo resultado.exe está salvo. Selecione-o e clique em "OK".
* Clique em "Avançar" e, em seguida, dê um nome para o atalho. Clique em "Concluir" para criar o atalho.

Agora, o resultado.exe será iniciado automaticamente toda vez que o Windows for iniciado.

Dica: Leve o ".exe" em um pendrive e coloque no computador de seu amigo.

## Em Linux
Compile o main.c com o comando abaixo: 
``` shell
 gcc -o resultado main.c `pkg-config --cflags --libs gtk+-3.0`
```
Execute com:
``` shell
 ./resultado
```

Dica: Leve o "resultado" em um pendrive e coloque no computador de seu amigo.


### Para a brincadeira funcionar no Linux o passo a passo:
Para Linux, é necessário utilizar um gerenciador de inicialização, como o systemd ou o cron. Uma forma de fazer isso é seguir os seguintes passos:

* Abra o terminal e navegue até a pasta onde o arquivo resultado está salvo.
* Abra o arquivo de texto com o comando nano resultado.service.
* Digite o seguinte conteúdo no arquivo:

``` shell

[Unit]
Description=My program

[Service]
ExecStart=/path/to/resultado
Restart=always

[Install]
WantedBy=multi-user.target
```

* Substitua /path/to/resultado pelo caminho absoluto do arquivo resultado.
* Salve o arquivo com o comando Ctrl + O, Enter e Ctrl + X.
* Copie o arquivo para a pasta /etc/systemd/system com o comando sudo cp resultado.service /etc/systemd/system.
* Inicie o serviço com o comando sudo systemctl start resultado.
* Verifique se o serviço está rodando com o comando sudo systemctl status resultado.
* Para fazer com que o serviço inicie automaticamente no boot do sistema, execute o comando sudo systemctl enable resultado.

Dessa forma, o arquivo resultado será iniciado automaticamente toda vez que o sistema for iniciado.


Eventuais danos não são responsabilizados pelo autor. Licença MIT.

# Divirta-se!