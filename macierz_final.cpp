#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;
char wybor;
int W;
int K;
float** A;
float** B;
float** C;
//Function to show the MACIERZ
void wyswietl(float** naPokaz, int K, int W){
    for(int i = 0; i < W; i++){
        for(int j = 0; j < K; j++){
            cout<<naPokaz[i][j]<<"\t";
            }
        cout<<endl;
        }
    }
//Function to fill the MACIERZ
float** fill(float** pustak, int K, int W){
    float r2;

    for(int i = 0; i < W; i++){
        for(int j = 0; j < K; j++){
            cout<<"Podaj liczbe dla pozycji ["<<i<<"] , ["<<j<<"] :"<<endl;
            cin>>r2;
            pustak[i][j] = r2;
            }
        }
    return pustak;
    }
//Function to create the MACIERZ
float** tworzenie(int K, int W ){
    //Tu robi tablice
    float** ary = new float*[W];
    for(int i = 0; i < W; ++i)
        ary[i] = new float[K];
        return ary;
    }
//Cleaning service
void clear(){
    system("clear");
    }
//Creating The Output MACIERZ and filling that with a sum of two MACIERZ's
void dodaj(float** a, float** b, int K, int W){
    C=tworzenie(K,W);
    cout<<"DODAJE TUTAJ###############################"<<endl;
    for(int i = 0; i < W; i++){
        for(int j = 0; j < K; j++){
            C[i][j]=a[i][j]+b[i][j];
            }
        }
    wyswietl(C, K, W);
    }

void dodawanie(){
    cout<<"Ile kolum chcesz dla pierwszej macierzy?"<<endl;
    cin>>K;
    cout<<"Ile wierszy chcesz dla pierwszej macierzy?"<<endl;
    cin>>W;
//----Macierz1--------------------------------------------
    A=tworzenie(K, W);
    A=fill(A, K, W);
    wyswietl(A, K, W);
//----Macierz2--------------------------------------------
    B=tworzenie(K, W);
    B=fill(B, K, W);
    wyswietl(B, K, W);
 cout<<"============================================================"<<endl;
            dodaj(A, B, K, W);
    cout<<endl;
    }
//Creating The Output MACIERZ and filling that with a subtraction of two MACIERZ's
void odejm(float** a, float** b, int K, int W){
	C=tworzenie(K,W);
    cout<<"Odejmuje tutaj ##########################"<<endl;
    for(int i = 0; i < W; i++){
        for(int j = 0; j < K; j++){
            C[i][j]=a[i][j]-b[i][j];
            }
        }
    wyswietl(C, K, W);
	}

void odejmowanie(){
	cout<<"Ile kolum chcesz dla pierwszej macierzy?"<<endl;
    cin>>K;
    cout<<"Ile wierszy chcesz dla pierwszej macierzy?"<<endl;
    cin>>W;
//----Macierz1--------------------------------------------
    A=tworzenie(K, W);
    A=fill(A, K, W);
    wyswietl(A, K, W);
//----Macierz2--------------------------------------------
    B=tworzenie(K, W);
    B=fill(B, K, W);
    wyswietl(B, K, W);
 cout<<"============================================================"<<endl;
            odejm(A, B, K, W);
    cout<<endl;
    }
//Creating The Output MACIERZ and filling that with a multiplication by a digit
void mnozRazyL(float** a, int K, int W){
	float Liczebka;
	C=tworzenie(K,W);
	cout<<"Razy ile Ci pomnozyc kochaniutki? ";
	cin>>Liczebka;
    cout<<"Iloczynuje TUTAJ###############################"<<endl;
	for(int i = 0; i < W; i++){
		for(int j = 0; j < K; j++){
			C[i][j]=a[i][j]*Liczebka;
			}
		}
    wyswietl(C, K, W);
	}

void PrzezLic(){
	cout<<"Ile kolum chcesz dla pierwszej macierzy?"<<endl;
    cin>>K;
    cout<<"Ile wierszy chcesz dla pierwszej macierzy?"<<endl;
    cin>>W;
//----Macierz1--------------------------------------------
    A=tworzenie(K, W);
    A=fill(A, K, W);
    wyswietl(A, K, W);
 cout<<"============================================================"<<endl;
            mnozRazyL(A, K, W);
    cout<<endl;
	}
//Calculating the value of a specific position in MACIERZ C
float obliczKonkretnaLiczbe(float** a, float** b, int K, int K2, int W, int i, int j){
	float Liczba=0;
	for(int n=0; n<W;n++){
		Liczba+=a[i][n]*b[n][j];
		}
	return Liczba;
	}
//Creating the Output MACIERZ and filling it up with a multiplication of two MACIERZ's
void iloczynMacierz(float** a, float** b, int K, int K2, int W){
	C=tworzenie(K2,W);
	for(int i=0;i<W;i++){
		for(int j = 0; j<K2; j++){
			C[i][j]=obliczKonkretnaLiczbe(a, b, K, K2, W, i, j);
			}
		}
	wyswietl(C, K2, W);
	}

void PrzezMac(){
	cout<<"Ile kolum chcesz dla pierwszej macierzy?"<<endl;
    cin>>K;
    cout<<"Ile wierszy chcesz dla pierwszej macierzy?"<<endl;
    cin>>W;
//----Macierz1--------------------------------------------
    A=tworzenie(K, W);
    A=fill(A, K, W);
    wyswietl(A, K, W);
//----Macierz2--------------------------------------------
	cout<<"Ile kolum chcesz dla drugiej macierzy?"<<endl;
	int K2;
	cin>>K2;
    B=tworzenie(K2, W);
    B=fill(B, K2, W);
    wyswietl(B, K2, W);
 cout<<"============================================================"<<endl;
    iloczynMacierz(A, B, K, K2, W);
	}
//Making of the WYZNACZNIK's MACIERZ
float WDwaNaDwa(float** a){
	return (a[0][0]*a[1][1])-(a[0][1]*a[1][0]);
	}
void WDuze(float** a, int k, int w){
	// -3 -6 -3			1 2 3
	// -6 -12 -6		4 5 6
	// -3  -6 -3		7 8	9
	float wynik;
	float** temp;
	float* WektorTemp;
	int n=0;
	temp=tworzenie(k-1,w-1);
	WektorTemp= new float [(k-1)*(w-1)];
	for(int i = 0; i<w; i++){
		for(int j = 0; j<k; j++){
			for(int z=0; z<w; z++){
				for(int y=0; y<k; y++){
					if(z==i||y==j){continue;}
					WektorTemp[n]=a[z][y];
					n++;
					}
				}
			while(n>0){
				for(int i = 0; i<w-1; i++){
					for(int j = 0; j<k-1; j++){
						temp[i][j]=WektorTemp[n-1];
						n--;
						}
					}
				}
			if(k-1 == 2 && w-1 == 2){
				wynik = WDwaNaDwa(temp);
				C[i][j]= wynik;
				}
				else{WDuze(temp,k-1,w-1);}
			}
		delete [] temp;
		delete [] WektorTemp;
	}
}
void wyznacz(){
	cout<<"Ile kolum chcesz dla pierwszej macierzy?"<<endl;
	cin>>K;
	cout<<"Ile wierszy chcesz dla pierwszej macierzy?"<<endl;
	cin>>W;
//----MInput----------------------------------------------
	A=tworzenie(K, W);
	C=tworzenie(K, W); //macierz z wynikiem
	A=fill(A, K, W);
	wyswietl(A, K, W);
	if(K == 2 && W == 2){cout<<"Wyznacznik tej macierzy to: "<<WDwaNaDwa(A)<<endl;}
	else{
		WDuze(A, K, W);
		}
	wyswietl(C,K,W);

	}

void dopelnien(float** a,int k,int w){
	 for(int i = 0; i<w; i++){
		for(int j = 0; j<k; j++){
			float wykladna=i+j;

			B[i][j]=a[i][j]*pow(-1,wykladna);
			}
		}
	}

void transportowa(float** a, int k, int w){
	float temp;
	for(int i = 0; i<w; i++){
		for(int j = 0; j<k; j++){
			if(i!=j||i<1){continue;}
				for(int n=0;n<=i;n++){
				 temp=a[i-n][j];
				 a[i-n][j]=a[j][i-n];
				 a[j][i-n]=temp;
               	}
			}
		}
	}


int wyznacz(float** A, int w, int *wierszkolumn,int n){
	double suma;
	int i,j,k,mnoznik, *nowywektorkolumn;
  if(n==1) //rekurencja
    return A[w][wierszkolumn[0]];
  else
  {
    nowywektorkolumn = new int[n - 1]; //nowy wektor kolumn
    suma=0;
    mnoznik=1;   // mnoznik na przemienno +/-
	for(i=0;i<n;i++){
      k=0;
	  for(j=0; j<n-1; j++){
		if(k == i){k++;}
        nowywektorkolumn[j] = wierszkolumn[k++];
      }
      suma= suma+(mnoznik * A[w][wierszkolumn[i]] * wyznacz(A, w+1,nowywektorkolumn, n-1));
      mnoznik=-mnoznik; //zmiana znaku mnoznika i dalej lecimy do kolejnej
    }
    return suma;
  }
}

void odwrot(float** a, int k, float wyznacznik){
	 float** D;
	 D=tworzenie(k,k);
	 for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++){
			D[i][j]=a[i][j]/wyznacznik;
			}
		}
	 wyswietl(D,k,k);
	}

void odwrotna(){
	int wyznak;

	cout<<"Ile kolum chcesz dla pierwszej macierzy?"<<endl;
	cin>>K;
	cout<<"Ile wierszy chcesz dla pierwszej macierzy?"<<endl;
	cin>>W;

//----MInput----------------------------------------------
	A=tworzenie(K, W);
	C=tworzenie(K, W); //macierz wyznacznikow
	B=tworzenie(K, W);
	A=fill(A, K, W);
	wyswietl(A, K, W);
	int *wierszkolumn = new int[K];
	for(int i = 0; i < K; i++){
		wierszkolumn[i] = i; //wiersz kol
	}
	if(K == 2 && W == 2){cout<<"Wyznacznik tej macierzy to: "<<WDwaNaDwa(A)<<endl;}
	else{
		WDuze(A, K, W);
		}
	dopelnien(C,K,W);
	cout<<"Macierz dopelnien: "<<endl;
	wyswietl(B, K, W);
	cout<<endl;
	transportowa(B, K, W);
	cout<<"Macierz transponowana: "<<endl;
	wyswietl(B, K, W);
	cout<<endl;
	wyznak=wyznacz(A,0,wierszkolumn,K);
	cout<<"Wyznacznik macierzy wejsciowej: "<<wyznak<<endl;
	odwrot(B,K,wyznak);
	}


void koniec(){
    cout<<endl<<"Do nastepnego";
	}

//Menu 
void menu(){
    cout<<"---------Co bys chcial robic-------------"<<endl;
        cout<<"1. Dodawanie"<<endl;
        cout<<"2. Odejmowanie"<<endl;
        cout<<"3. Mnozenie (przez liczbe)"<<endl;
        cout<<"4. Mnozenie (przez miecierz)"<<endl;
        cout<<"5. Macierz wyznacznikow"<<endl;
        cout<<"6. Macierz odwrotna"<<endl;
        cout<<"C lub c -> czysc ekran"<<endl;
        cout<<"Q lub q -> zamknij aplikacje"<<endl;
 cout<<"==========================================="<<endl;
	}


int _tmain(int argc, _TCHAR* argv[]){
    do{
        menu();
        cin>>wybor;

        switch(wybor){
            case '1':{dodawanie();
                    break;
                }
            case '2':{odejmowanie();
                    break;
                }
            case '3':{PrzezLic();
                    break;
                }
            case '4':{PrzezMac();
                    break;
                }
            case '5':{wyznacz();
                    break;
                }
            case '6':{odwrotna();
                    break;
                }
            case 'C':{clear();
                    break;
                }
            case 'c':{clear();
                    break;
                }
            case 'Q':{koniec();
                    break;
                }
            case 'q':{koniec();
                    break;
                }
            default : {cout<<"Czego chcesz?";}
            }
        }while((wybor!='Q')&&(wybor!='q'));

    delete [] A;
    delete [] B;
    delete [] C;

	return 0;
}

