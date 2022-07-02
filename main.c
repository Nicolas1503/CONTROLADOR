
typedef enum{
    OUT,
    MAINMENU,
    AJUSTES,
    MEDICION,
    ULTIMAS_MEDICIONES,
    CONFIG_HELICES,
    CONFIG_PERIODO,
    REF_LUGAR,
    CONFIG_FECHA_HORA,
    BUZZER,
    ATRAS
}Menu_e;


A = [0,0,0,0];
B = [0,0,0,0];
Menu_e estado_actual;
Menu_e estado_anterior;

void GetEEPROMValue(char key)
{
    int value = eeprom.get(key)
    return value;
}

void SetEEPROMValue(char key, int value)
{
    eeprom.set(key,value);
}

void UpdateCursor(void)
{

}

Menu_e CheckButton(void)
{
    if (/*se presiona enter*/)
    {
        //fijarte en que valor esta el cursor
        return //menu donde estas
    }
    else{
        return OUT;
    }
}

void StateMachine_Update(void)
{
    Menu_e aux = CheckButton();
    if (aux != OUT)
    {
        switch(aux)
        {
            case AJUSTES:
                if (estado_anterior == MAINMENU)
                {
                    estado_actual = aux;
                }
            break;

            case CONFIG_HELICES:
                if (estado_anterior == AJUSTES)
                {
                    estado_actual = aux;
                }
            break;
        }
    }
}

void StateMachine_Control(void)
{
    switch(estado_actual)
    {
        case MAINMENU:
            //Mostrar menu principal
        break;

        case AJUSTES:
            //Mostrar menu ajustes
        break;

        case CONFIG_HELICES:
            while(1)
            {
                //mostrar opciones A y B
                if (/*Seleccionas A*/)
                {
                    GetEEPROMValue('digit1',A[1]);
                    //Mostrar digitos
                    //Te moves a un digito
                    //A = [0,1,0,0]
                    // Display -> lcd.setCursor(0,i) -> lcd.print(A[i])
                    SetEEPROMValue('digit1',A[1]);

                }
            }
        break;
    }
}


void loop(void)
{
    UpdateCursor();
    StateMachine_Update();
    StateMachine_Control();
}