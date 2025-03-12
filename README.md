# Analiza și Compararea Metodelor Directe de Sortare

## Descriere
Această temă presupune implementarea și compararea a trei metode directe de sortare:
- **Sortarea Bulelor (Bubble Sort)**
- **Sortarea prin Inserție (Insertion Sort)**
- **Sortarea prin Selecție (Selection Sort)**

Scopul este analiza și compararea performanței acestora în cazurile **favorabil (best case)**, **mediu statistic (average case)** și **defavorabil (worst case)**. 

## Implementare
- **Fiecare metodă de sortare trebuie implementată într-o funcție separată.**
- **Datele de intrare**: un șir de numere întregi.
- **Datele de ieșire**: șirul ordonat crescător.
- **Se va demonstra corectitudinea algoritmilor folosind un vector de dimensiuni mici în funcția `main()`.**

## Analiză și Comparare
### 1. Analiza Complexității
- Se vor măsura **numărul de comparații și numărul de atribuiri** pentru fiecare algoritm.
- Se vor genera date pentru **cazurile favorabil, defavorabil și mediu statistic**.
- Pentru cazul mediu, **experimentul se repetă de 5 ori**, și se raportează media rezultatelor.

### 2. Analiza în Caz Favorabil și Defavorabil
- **Se vor varia dimensiunile șirului de la 100 la 10.000 cu un pas de 100.**
- **Se vor genera grafice pentru fiecare metodă de sortare, comparând:**
  - Numărul de atribuiri
  - Numărul de comparații
  - Suma acestora
- **Dacă este necesar, se vor utiliza grafice separate pentru vizualizarea clară a tendințelor.**

## Cum să Rulezi Proiectul
1. **Compilare**
2. **Executare**
3. **Interpretarea rezultatelor**
   - Verifică ordonarea corectă a șirului de numere
   - Analizează graficele rezultate pentru interpretarea performanței algoritmilor

## Resurse
- **Cormen, Thomas H. et al. - Introduction to Algorithms** (Secțiunea 2.1 pentru Sortarea prin Inserție)
- **Notițele Seminarului nr. 1** pentru pseudo-cod și explicații suplimentare

