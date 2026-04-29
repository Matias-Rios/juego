# include <iostream> 
# include <string> 
# include <cstdlib>
# include <ctime> 
#include <array>
using namespace std; 


class Jugador{
private:
	int monedas=100;
	string nombre;
public:
	Jugador(string n){
		nombre =n;
	}
	int getMonedas(){
		return monedas;
	}
	string getNombre(){
		return nombre;
	}
	void apostar(int cantidad){
		monedas-=cantidad;
	}
	void mostrarSaldo(){
		cout<<"Tienes "<<monedas<<"$ "<<nombre<<endl;
	}
	void ganarpremio(int premio){
		monedas+=premio;
	}
};

bool continuar(string d){
    while(d!="y" and d!="Y" and d!="n" and d!= "N"){
        cout <<"Entrada invalida. Escriba y o n: ";
        cin >>d;
    }

    if(d =="n" or d=="N"){
        return false;
    }
  return true;
}

int main(){
	srand(time(0));
	string n;
	bool flag=true;
	string desicion;
	char simbolos [4] = {'@','#','$','%'};
	cout<<"====SLOT MACHINE===="<<endl;
	cout<<"Ingrese nombre: ";
	cin>>n;
	Jugador j1(n);
	cout<<"Tire la palanca (y/n)"<<endl;
	cin>>desicion;
	flag=continuar(desicion);
	if(flag){
		while(flag){
        cout << "------------------------------" << endl;
        cout << "        NUEVA TIRADA          " << endl;
        cout << "------------------------------" << endl;

			j1.apostar(10);
			char r1 = simbolos [ rand () % 4];
			char r2 = simbolos [ rand () % 4];
			char r3 = simbolos [ rand () % 4];
			cout << " ["<<r1<<"] ["<<r2<<"] ["<<r3<<"]"<< endl;
			if(r1==r2 and r1==r3){
				cout<<"Gana 50 monedas"<<endl;
				j1.ganarpremio(50);
			}
			else if(r1==r2 or r1==r3 or r2==r3){
				cout<<"Gana 20 monedas"<<endl;
				j1.ganarpremio(20);
			}
			else{
				cout<<"Pierdes 10 monedas"<<endl;
			}
			if (j1.getMonedas() < 10) {
      			cout <<"No tienes suficientes monedas para seguir jugando."<<endl;
      		}
			j1.mostrarSaldo();
			cout<<"Desea continuar? (y/n): "<<endl;
			cin>>desicion;
			flag=continuar(desicion);
		}
	}

	cout<<"Vuelva pronto "<<endl;
	j1.mostrarSaldo();
	
	return 0;
}