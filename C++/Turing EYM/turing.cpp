/*
Projecto Primer Parcial Electricidad y Magnetismo
Daniel Charua : A01017419
Luis Barajas: A01370934
Mauricio Rico: A01370874
Eric Parton: A01023503
Lunes 12/09/2016
*/

#include <iostream>
#include <string>
using namespace std;

void user_menu();
void descifrar(string s);

int main()
{
    std::cout << std::endl;
    user_menu();
    return 0;
}

void user_menu()
{
    char option = 'a';
    string mensaje;

    while (option != 's')
    {
        std::cout << "========================================" << std::endl;
        std::cout << "======= Codificador Alan Turing ========" << std::endl;
        std::cout << "==  a. Escribir un mensaje codificado ==" << std::endl;
        std::cout << "==  b. Acerca de Alan Turing          ==" << std::endl;
        std::cout << "==  c. Sobre nosotros                 ==" << std::endl;
        std::cout << "==  s. Salir del programa             ==" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "Selecciona una opcion: " ;
        std::cin >> option;

        if (option == 'a')
        {
            std::cout << "Escribe tu mensaje en teclado ACBD: ";
            std::cin >> mensaje;
            descifrar(mensaje);


        }
        if (option == 'b')
        {
          while (option != 'v')
          {
              std::cout << std::endl;
              std::cout << "=================================================================================================================" << std::endl;
              std::cout << "=======================================Sobre Alan Turing ========================================================" << std::endl;
              std::cout << "==  a. Sabes quién fue Alan Turing y el trabajo que realizó en el campo del desarrollo de cálculos recursivos? ==" << std::endl;
              std::cout << "==  b. Qué era la máquina Enigma y cuál era su uso?                                                            ==" << std::endl;
              std::cout << "==  c. En qué forma puedes enviar información de forma segura y confidencial sin que sea interceptada?         ==" << std::endl;
              std::cout << "==  d. Describe la forma en que te comunicarías a casa y con tus amigos que se encuentran al otro lado del-    ==" <<endl<<  "== mundo e intercambiar información sin la existencia de computadoras, red, etc.                               ==" << std::endl;
              std::cout << "==  e. Consideras que se trató con justicia a Alan Turing en el juicio que se le llevó a cabo?                 ==" << std::endl;
              std::cout << "==  f. Consideras que las computadores podrán algún día llegar a realizar una cantidad de cálculos sin límite? ==" << std::endl;
              std::cout << "==  g. Referencias                                                                                             ==" << std::endl;
              std::cout << "==  v. Volver al menu anterior                                                                                 ==" << std::endl;
              std::cout << "=================================================================================================================" << std::endl;
              std::cout << "Selecciona una opcion: " ;
              std::cin >> option;

              if (option == 'a')
              {
                  std::cout << std::endl;
                  std::cout << "Alan Turing fue un matemático británico que fue un pionero en el área de" << std::endl;
                  std::cout << "computación.  Hizo su trabajo más importante durante La Segunda Guerra Mundia" << std::endl;
                  std::cout << "como un criptólogo descifrando la máquina Enigma." << std::endl;
                  std::cout << std::endl;
              }
              if (option == 'b')
              {
                std::cout << std::endl;
                std::cout << "La máquina Enigma era una máquina codificador de mensajes.  Fue inventado por " << std::endl;
                std::cout << "el ingeniero alemán, Arthur Scherbius en la década de 1910.  Famosamente, fue" << std::endl;
                std::cout << "utilizado por los Nazis durante La Segunda Guerra Mundial.  Tres criptologos " << std::endl;
                std::cout << "polacos descubrieron cómo descifrar los códigos alemanes producidos por la" << std::endl;
                std::cout << "máquina en 1932 utilizando una máquina y matemática teórica.  Usando sus" << std::endl;
                std::cout << "conocimientos, crearon dispositivos mecánicos que podían romper el código.  Con el" << std::endl;
                std::cout << "paso del tiempo, los alemanes pudieron modificar las máquinas para producir" << std::endl;
                std::cout << "codigos aún más complejos hasta el punto de que los matemáticos polacos ya no " << std::endl;
                std::cout << "podían descifrarlos." << std::endl;
                std::cout << std::endl;
              }
              if (option == 'c')
              {
                std::cout << std::endl;
                std::cout << "El proceso de la comunicación está mostrado en el diagrama a la derecha.  Hay " << std::endl;
                std::cout << "varios puntos entre la fuente y destino en la cual se podría hacer que la información" << std::endl;
                std::cout << "sea muy difícil de interceptar. " << std::endl;
                std::cout << "   El más relevante a este proyecto es el transmisor porque ahí es donde el" << std::endl;
                std::cout << "mensaje se codifica.  En una conversación, la codificación sería el idioma que se " << std::endl;
                std::cout << "está hablando por ejemplo.  Para el caso de los Nazis en La Segunda Guerra " << std::endl;
                std::cout << "Mundial, la maquina enigma codificaba a los mensajes." << std::endl;
                std::cout << "   Otra manera de mantener la privacidad de información sería por el canal " << std::endl;
                std::cout << "usado.  Por ejemplo, mandar un mensaje por radio, en ciertos casos, podría ser más " << std::endl;
                std::cout << "difícil de interceptar que mandarlo por correo." << std::endl;
                std::cout << "   Por último, el ruido alrededor de un mensaje puede causar que sea muy difícil " << std::endl;
                std::cout << "de interceptar, hasta para el receptor.  En un concierto de rock, si dos personas " << std::endl;
                std::cout << "quieren hablar pero hablan muy quedito, la interferencia causada por la música hará " << std::endl;
                std::cout << "que sea imposible la comunicación.  Hay ocasiones en donde el ruido es útil porque " << std::endl;
                std::cout << "el receptor tiene mejores herramientas para detectar el mensaje que el interceptor." << std::endl;
                std::cout << std::endl;
              }
              if (option == 'd')
              {
                std::cout << std::endl;
                std::cout << "La historia nos puede enseñar mucho acerca de cómo se puede comunicar a través " << std::endl;
                std::cout << "de grandes distancias sin computadoras.  Una respuesta sería mandar un mensaje " << std::endl;
                std::cout << "escrito u oral con un mensajero pero suele ser muy lento.  Es un método que lleva " << std::endl;
                std::cout << "milenios pero ahora tenemos formas más eficientes de mandar información." << std::endl;
                std::cout << "   La solución más efectiva no-computarizada de los últimos dos siglos ha sido " << std::endl;
                std::cout << "con la electricidad.  El telégrafo y el teléfono utilizan señales eléctricos para " << std::endl;
                std::cout << "transmitir mensajes, que significa que el límite de velocidad es la velocidad de la " << std::endl;
                std::cout << "electricidad.  Es una forma de comunicarse que se utiliza mucho todavía." << std::endl;
                std::cout << "   La última forma que se puede usar para comunicar a través de largas" << std::endl;
                std::cout << "distancias sería con ondas de radio.  Radios, celulares, televisiones y otros usan " << std::endl;
                std::cout << "ondas electromagnéticas para mandar información.  Consiste en la ampliación de " << std::endl;
                std::cout << "señales de radio usando un conductor que induce una corriente alterna.  Está es la " << std::endl;
                std::cout << "forma más rápida de comunicarse porque las ondas, como son un tipo de radiación" << std::endl;
                std::cout << "electromagnética, viajan a la velocidad de la luz.  La limitación es que las ondas " << std::endl;
                std::cout << "viajan más lentamente cuando pasan por objetos (incluyendo el aire)." << std::endl;
                std::cout << std::endl;
              }

              if (option == 'e')
              {
                std::cout << std::endl;
                std::cout << "No consideramos que fue justo el trato de Alan Turing.  El fue un héroe de guerra, " << std::endl;
                std::cout << "se sabe que la clave de la victoria de la fuerzas aliadas fue la desencriptación de los " << std::endl;
                std::cout << "mensajes gracias a Turing. " << std::endl;
                std::cout << "    El fue puesto en un tratamiento hormonal una decisión muy inhumana, " << std::endl;
                std::cout << "simplemente por ser diferente. Hoy en dia vivimos en una sociedad más tolerante a " << std::endl;
                std::cout << "la diferencia de ideas, aun nos falta mucho por evolucionar pero sin duda Alan " << std::endl;
                std::cout << "Turing se adelantó a su época, es una lastima ya que estaba tomando las riendas " << std::endl;
                std::cout << "en el área de la computación." << std::endl;
                std::cout << std::endl;

              }
              if (option == 'f')
              {
                std::cout << std::endl;
                std::cout << "No consideramos que la computadoras podrán realizar un número ilimitado de " << std::endl;
                std::cout << "cálculos en el futuro.  Una computadora siempre está limitado en el número de " << std::endl;
                std::cout << "cálculos que puede realizar en una instancia por el hardware que tiene.  Se " << std::endl;
                std::cout << "necesitaría una computadora de tamaño infinito para hacer una cantidad infinita de" << std::endl;
                std::cout << "cálculos en una instancia." << std::endl;
                std::cout << "    Tomando eso en consideración, podemos pensar en una computadora que " << std::endl;
                std::cout << "puede hacer una cantidad de cálculos relativamente sin límite.  Es decir, una " << std::endl;
                std::cout << "computadora que tiene una capacidad de procesar que rebasa cualquier posible" << std::endl;
                std::cout << "función que la podemos dar.  Actualmente, el Sunway TaihuLight" << std::endl;
                std::cout << std::endl;
              }
              if (option == 'g')
              {
                std::cout << std::endl;
                std::cout << "N. (2013, January 10). 158,962,555,217,826,360,000 (Enigma Machine) - Numberphile. " << std::endl;
                std::cout << "Retrieved September 4, 2016, from https://www.youtube.com/watch?v=G2_Q9FoD-oQ" << std::endl;
                std::cout << std::endl;
              }
          }
      }


        if (option == 'c')
        {
          std::cout <<std::endl;
          std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
          std::cout << "------- Projecto Primer Parcial Electricidad y Magnetismo ------" << std::endl;
          std::cout << "++++              Daniel Charua  A01017419                  ++++" << std::endl;
          std::cout << "++++              Luis Barajas   A01370934                  ++++" << std::endl;
          std::cout << "++++              Mauricio Rico  A01370874                  ++++" << std::endl;
          std::cout << "++++              Eric Parton    A01023503                  ++++" << std::endl;
          std::cout << "----------------------------------------------------------------" << std::endl;
          std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
          std::cout << std::endl;

        }
   }
}


void descifrar(string s){
  for(int i=0; i< s.size(); i++){
    if (s[i]=='q'||s[i]=='Q') s[i]='a';
    else if (s[i]=='w'||s[i]=='W') s[i]='b';
    else if (s[i]=='e'||s[i]=='E') s[i]='c';
    else if (s[i]=='r'||s[i]=='R') s[i]='d';
    else if (s[i]=='t'||s[i]=='T') s[i]='e';
    else if (s[i]=='y'||s[i]=='Y') s[i]='f';
    else if (s[i]=='u'||s[i]=='U') s[i]='g';
    else if (s[i]=='i'||s[i]=='I') s[i]='h';
    else if (s[i]=='o'||s[i]=='O') s[i]='i';
    else if (s[i]=='p'||s[i]=='P') s[i]='j';
    else if (s[i]=='a'||s[i]=='A') s[i]='k';
    else if (s[i]=='s'||s[i]=='S') s[i]='l';
    else if (s[i]=='d'||s[i]=='D') s[i]='m';
    else if (s[i]=='f'||s[i]=='F') s[i]='n';
    else if (s[i]=='g'||s[i]=='G') s[i]='o';
    else if (s[i]=='h'||s[i]=='H') s[i]='p';
    else if (s[i]=='j'||s[i]=='J') s[i]='q';
    else if (s[i]=='k'||s[i]=='K') s[i]='r';
    else if (s[i]=='l'||s[i]=='L') s[i]='s';
    else if (s[i]=='z'||s[i]=='Z') s[i]='t';
    else if (s[i]=='x'||s[i]=='X') s[i]='u';
    else if (s[i]=='c'||s[i]=='C') s[i]='v';
    else if (s[i]=='v'||s[i]=='V') s[i]='w';
    else if (s[i]=='b'||s[i]=='B') s[i]='x';
    else if (s[i]=='n'||s[i]=='N') s[i]='y';
    else if (s[i]=='m'||s[i]=='M') s[i]='z';
  }
  std::cout << std::endl;
  std::cout << "-----------------------------------" << std::endl;
  std::cout << "---Tu mensaje ha sido decifrado!!--" << std::endl;
  std::cout <<"** "<< s << "**"<< std::endl;
  std::cout << "-----------------------------------" << std::endl;
  std::cout << std::endl;
}
