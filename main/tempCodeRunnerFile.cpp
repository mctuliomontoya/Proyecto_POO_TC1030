
    _setmode(_fileno(stdout),_O_TEXT);
    mnerv();
}
else if (opc == "N" || opc == "n")
{
    setmode(_fileno(stdout), _O_U16TEXT);
    wcout << L"\n !Muchas Gracias por su atención!";
    getch();
    wcout << L"\n Código hecho por: ";
    wcout << L"\n Ángel Marín - A00835132";
    wcout << L"\n Marco Montoya - A01254155";
    getch();
    

}


}