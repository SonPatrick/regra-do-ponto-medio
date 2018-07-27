#include <iostream>
#include <cmath>

using namespace std;

//Nesta função é definido a equação que será resolvida
double eqc(double x) {
    double f;
    f = x/1;
    //f = pow(x,2); //x^2
    //f = sqrt(x);//raiz quadrada de x
    //f = cbrt(x);//raiz cúbica de x
    return f;
}

//Nesta função é definido o passo-a-passo de como resolver de forma algoritmica a regra do ponto médio
double integral(double a, double b, int n){
    //recebe o valor de delta x
    double dx = (b - a)/n;
    double vet1[n - 1];
    double vet2[n];
    double sum = 0;
    double result = 0;
    //armazena os valores da primeira divisão de pontos em vet1
    cout << "Primeira divisao" << endl;
    for (int i = 1; i < n; ++i) {
    //este primeiro if existe para definir o primeiro ponto depois de 'a' (sendo 'a' o primeiro ponto no intervalo ('a', 'b'))
        if (i == 1){
            vet1[i] = a + dx;
            cout << vet1[i] << endl;
        } else{
            vet1[i] = vet1[i-1] + dx;
            cout << vet1[i] << endl;
        }
    }
    //armazenas os valores dos pontos médios
    cout << "Segunda divisao" << endl;
    //pm define o valor que vai servir pra definir os pontos médios
    double pm = (vet1[1] - a)/2;
    for (int j = 1; j <= n; ++j) {
    //este primeiro if existe para definir o primeiro ponto médio após 'a' (sendo 'a' o primeiro ponto no intervalo ('a', 'b'))
        if (j == 1){
            vet2[j] = a + pm;
            cout << vet2[j] << endl;
        } else{
            vet2[j] = vet1[j-1] + pm;
            cout << vet2[j] << endl;
        }
        //neste ponto é realiza o somatório de todos os pontos médios na equação(que foi definida na função eqc(x))
        //onde o valor de x vai ser igual ao valor armazenado em vet2[j]
        sum = sum + eqc(vet2[j]);
    }
//-----------------Esta parte é puro enfeite---------------------------------------------------------
    //Exibe todas as divisões em uma "reta"
    for (int k = 1; k < n; ++k) {
        if(k == 1){
            cout << a << "--" << vet2[k] << "--" << vet1[k] << "--";
        }else{
            cout << vet2[k] << "--" << vet1[k] << "--";
        }
    }
    cout << b << endl;
//----------------Acaba aqui o enfeite---------------------------------------------------------------
    //multiplica delta x com o somatorio
    result = dx * sum;
    //cout.precision(10); define a quantidade de casas decimais após a vírgula
    cout.precision(10);
    //exibe o resultado
    cout << "Resultado: " << fixed << result << endl;
}
//Basta declarar a função 'integral'. Dentro do parenteses as variáveis são (a, b, n), onde, 'a' e 'b'
//definem o intervalo e 'n' o número de divisões.
//O main aqui é utilizado apenas para receber a estrela do show, a função integral(a, b, n)
int main() {
    integral(1, 2, 5);
    return 0;
}