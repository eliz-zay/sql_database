# Task4 - SQL

## Структура проекта

`db` - место, где БД хранит таблицы  
`out` - исполняемые файлы  
`src` - исходный код  
`src/engine` - модуль движка БД  
`src/query_parser` - модуль парсинга запросов  
`src/socket` - ООП-обертка сокетов

## Синтаксис языка

### SQL запрос

- <SQL-запрос> ::= <SELECT-запрос> | <INSERT-запрос> | <UPDATE-запрос> | <DELETE-запрос> | <CREATE-запрос> | <DROP-запрос>  

### Виды запросов

- <SELECT-предложение> ::= SELECT <список полей> FROM <имя таблицы> [<WHERE-клауза>]  
- <INSERT-предложение> ::= INSERT INTO <имя таблицы> (<значение поля> { , <значение поля> })  
- <UPDATE-предложение> ::= UPDATE <имя таблицы> SET <имя поля> = <выражение> [<WHERE-клауза>]  
- <DELETE-предложение> ::= DELETE FROM <имя таблицы> <WHERE-клауза>  
- <CREATE-предложение> ::= CREATE TABLE <имя таблицы> ( <список описаний полей> )  
- <DROP-предложение> ::= DROP TABLE <имя таблицы>  

### WHERE клауза

- <WHERE-клауза> ::= WHERE (<логическое выражение> | ALL)  
- <логическое выражение> ::= <логическое слагаемое> { OR <логическое слагаемое> }  
- <логическое слагаемое> ::= <логический множитель> { AND <логический множитель> }  
- <логический множитель> ::= ( NOT <логический множитель> ) | ((<логическое выражение>)) | <операция>  
- <операция> ::= <отношение> | <like-выражение> | <in-выражение>  
- <like-выражение> ::= <имя поля> [ NOT ] LIKE <строка>  
- <in-выражение> ::= <выражение> [ NOT ] IN ( <список констант> )  
- <отношение> ::= <string-отношение> | <number-отношение>  
- <string-отношение> ::= <string-выражение> <операция сравнения> <string-выражение>  
- <number-отношение> ::= <number-выражение> <операция сравнения> <number-выражение>  
- <операция сравнения> ::= = | > | < | >= | <= | !=  

### Общие определения

- <список полей> ::= <имя поля> { , <имя поля> } | *  
- <имя таблицы> ::= <имя>  
- <имя поля> ::= <имя>  
- <значение поля> ::= <строка> | <число>  
- <имя> ::= <имя> [ <буква> | <цифра> | _ ] | <буква>  
- <значение поля> ::= <строка> | <число>  
- <строка> ::= '<символ> { <символ> }'  
- <символ> ::= <любой символ клавиатуры кроме '>  
- <список описаний полей> ::= <описание поля> { , <описание поля> }  
- <описание поля> ::= <имя поля> <тип поля>  
- <тип поля> ::= TEXT ( <целое без знака> ) | NUMBER  
- <выражение> ::= <string-выражение> | <number-выражение>  
- <string-выражение> ::= <имя поля> | <строка>  
- <number-выражение> ::= <имя поля> | <число>  
- <число> ::= <цифра кроме нуля><последовательность цифр>[ .[ <последовательность цифр> ] <цифра кроме нуля> ]  
- <последовательность цифр> ::= <цифра> [ <последовательность цифр> ]  

## Модуль 1 - ООП-обертка сокетов

- BaseSocket - абстрактный базовый класс  
- ServerSocket - управялющий сокет сервера, осуществляющий подключение клиентов  
- ClientSocket - клиентский сокет, осуществляющий обмен сообщениями  
- SocketException - ислкючение, возникающее при некорректной работе сокетов  

## Авторы

- Кислов Евгений  
- Зайденварг Елизавета  
