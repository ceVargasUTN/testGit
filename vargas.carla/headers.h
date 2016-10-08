typedef struct{
    char nombre[50];
    char apellido[50];
    //char dni[50];
    int dni;
    int flag_estado;
    int id_cliente;
}eCliente;

typedef struct {
    //eCliente cliente[];
    char equipo[50];
    char operador[50];
    char cliente[50];
    int tiempo;
    int flag_estado;
    int id_Alquiler;
}eAlquiler;
//FUNCIONES GENERICAS
void obtenerDatosPorTeclado( char mensaje[], char input[]);
int validarSoloLetras(char soloString[]);
int getStringValidado(char mensaje[], char input[]);
int esNumerico(char strInput[]);
int getNumerosString(char mensaje[],char input[]);

//FUNCIONES CLIENTES
void iniciarDatosArrayC(eCliente arrayClient[], int cantElementos, int valor);
int buscarPrimerOcurrenciaC(eCliente arrayClien[], int cantElementos, int valor);

//FUNCIONES ALQUILER
void iniciarDatosArrayA(eAlquiler arrayAlquilo[], int cantElementos, int valor);
int buscarPrimerOcurrenciaA(eAlquiler arrayAlquilo[], int cantElementos, int valor);

