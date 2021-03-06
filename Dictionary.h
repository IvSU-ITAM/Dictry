#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <qmap>
#include <qset>

class SetString : public QSet<QString>
  {
  public:
//    SetString(  ) : vector<string>( Size ) {} //2
  SetString( const class Dictionary& D );
  SetString( QSet<QString>& S ) : QSet<QString>( S ) {};
  };

class Dictionary : public QMap<QString, int> //1 Каждая переменная объекта QMAP состоит из двух частей: 1 ч- ключ, с помощью которого можно найти вторую часть.
        //В данном случае ключ - это переменная типа QString, с помощью которой можем найти значение второй переменной - int.
  {
  public:
    QString m_FileName;
    Dictionary( const SetString& Words ); //2
    Dictionary( char *Message = NULL );
    void operator >> ( const QString& Message );
    Dictionary operator & ( const Dictionary& D ); //Intersection dictionaries;
    Dictionary operator | ( const Dictionary& D ); //Combining dictionaries;
    Dictionary operator - ( const Dictionary& D ); //Difference of dictionaries;
    Dictionary operator ^ ( const Dictionary& D ); //Symmetrical difference of dictionaries;
  };

#endif // DICTIONARY_H
