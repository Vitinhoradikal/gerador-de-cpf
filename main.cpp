#include <iostream>
#include <ctime>
#include <locale>
using namespace std;


string gerador()
{


     int num[9];
     string num_str = "";
    srand(time(nullptr));

    for(int i = 0; i < 9; i++)
    {
        num[i] = rand() % 10;
    }
      for (int i = 0; i < 9; i++) {
        num_str += to_string(num[i]); //converte cada elemento do array para uma string e adiciona à string resultante
    }

    return num_str;
}

int geraDigitosVerificadores(string cpf)
{
     int cpf_array[11];
    int index = 0;
    int verificaDigito1[10];
    int verificaDigito2[10];
    int acumulador1 = 0;
    int acumulador2 = 0;
    int digito1;
    int digito2;

    //transforma a string de cpf em uma string de inteiros.
    for (char c : cpf)
        {

        if (isdigit(c))
            {
                cpf_array[index] = stoi(string(1,c));
                index++;
            }
        }



 /*gera o primeiro digito do cpf*/
 for(int i = 0; i < 9; i++)
 {
     verificaDigito1[i] = cpf_array[i]*(10-i);
     acumulador1= acumulador1+verificaDigito1[i];
 }

  if(acumulador1 % 11 == 0|| acumulador1 % 11 == 1)
 {
    digito1 = 0;
 }
 else
 {
     digito1 = 11 - (acumulador1 % 11);
 }

 cpf_array[9] = digito1;

 /*gera segundo digito verificador*/

  for(int i = 1; i < 10; i++)
 {
     verificaDigito2[i] = cpf_array[i]*(11-i);
     acumulador2= acumulador2+verificaDigito2[i];
 }


  if(acumulador2 % 11 == 0|| acumulador2 % 11 == 1)
 {
    digito2 = 0;
 }
 else
 {
     digito2 = 11 - (acumulador2 % 11);
 }

 cpf_array[10] = digito2;

 /*imprime o cpf com os caracteres especiais*/
 cout << "#################" << endl;
 for(int i = 0; i<11;i++)
 {
     if(i == 3 || i == 6)
     {
        cout << ".";
     }else if(i == 9){cout << "-";}

     cout << cpf_array[i];
 }
  cout << endl << "#################" << endl;

    return 0;
}

int main()
{
    std::setlocale(LC_ALL, "pt_BR.utf8");
    int opcao;
    do{
            cout << endl <<"GERADOR DE CPF ALEATORIO" << endl << endl;
            cout << "Para sair do sist tecle [0]" << endl;
            cout << "Para Gerar um CPF tecle [1]" << endl;
            cin >> opcao;

            if(opcao == 1)
            {
                string cpf;
                cpf = gerador();
                geraDigitosVerificadores(cpf);
            }

    }while(opcao != 0);



    return 0;
}
