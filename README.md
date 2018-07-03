# remoteCall

Narzędzie do zdalnego wywołania programu, wraz z obsługą standardowych strumieni - wejścia, wyścia i błędów

## Wykorzystanie

### Kompilacja
należy wydać polecenie
```bash
make -f Makefile.remoteCall
```
Spowoduje to utworzenie dwóch plików wykonywalnych: remoteCall_client i remoteCall_server

### Serwer

Przed uruchomieniem trzeba uruchomić program rpcinfo, a następnie serwer jako uprzywilejowany aby mógł zarejestrować usługę.

```bash
rpcinfo
sudo ./remoteCall_server
```
### Klient

```bash
./remoteCall_client <adres> <komenda>
```
Jako pierwszy argument należy podać adres na jakim uruchomiony jest serwer, jeśli lokalnie to na przykłąd localhost.

Jako drugi trzeba podać komendę do wykonania przez serwer. Jeśli zawiera spacje lub znaki specjalne to otoczyć ją znakami ' ', np. 'ls -la'.

Dane wejściowe należy dostarczyc przez strumień (<), potok(|), lub wprowadzić przez konsolę po uruchomieniu programu.

##Zasada działania

### Klient

Po uruchomieniu tworzony jest nowy proces, który wywsyła na serwer komendę, a następnie w pętli czyta standardowe wejście i je wysyła w paczkach o wielkości do 1024 bajtów. 

Wątek główny uruchamia serwer wywołąń zwrotnych, który po otrzymaniu danych wypisuje je na ekran, a po otrzymaniu wyniku wykonania programu zabija proces wysyłajacy dane, który juz nie jest potrzebny, i konczy sie zwracając otrzymany rezultat.

### Serwer

Serwer rejestruje procedury przyjmującą komendę i przyjmującą dane. Po otrzymaniu komendy otwierane są trzy potoki i tworzone trzy procesy. Jeden wykonuje komendę poleceniem system, ze strumieniami przekierowanymi na potoki. Drugi i trzeci czytają potoki, na które przekierowane są odpowiednio standardowe wyjście i błędy, i uruchamiają procedurę klienta wywołań zwrotnych, wysyłajać paczki po mmaksymalnie 1024 bajty. 

Po otrzymaniu danych wpisywane są one do strumienia, na który zostało przekierowane standardowe wejście, co pozwala je dostarczyć do komendy podczas jej działania. Proces pierwszy po zakończeniu zamyka potoki, i czeka na zakończenie procesów potomnych, co pozwala wysłać wynik dopiero po wysłaniu wszystkich danych. 

