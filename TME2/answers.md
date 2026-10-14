# TME2 : réponses et traces

Un titre par question. Sous chaque titre : la réponse si la question en demande une, et la trace de l'exécution
de votre code, collée telle quelle entre triples backquotes. On peut couper le milieu d'une trace longue, on garde
les dernières lignes, avec le temps d'exécution.

## Machine de mesure

Collez ici le bloc produit par 
`./machine-info.sh`:


 puis complétez le contexte de mesure.

## Question 1

Exemple de trace : à remplacer par la vôtre.

```
$ ./build-debug/countword WarAndPeace.txt count
565500: to
Finished parsing.
Found a total of 565527 words.
Total runtime (wall clock) : 1153 ms
                                       
```
                                       
```
$ ./build-release/countword WarAndPeace.txt count
565500: to
Finished parsing.
Found a total of 565527 words.
Total runtime (wall clock) : 111 ms
                                       
```
Il y'a donc 565527 mots dans le livre

## Question 2

Debug est bien plus lent que release , ce qui peut se comprendre car l'un veille a debuger pendant que l'autre tient la performance comme but premier 
avec debug et trace:

Finished parsing.
Found a total of 565527 words.
Total runtime (wall clock) : 1179 ms
```
avec debug et sans trace:
```
┌──(ania㉿kali)-[~/PSCR-TME/TME2]
└─$ ./build-debug/countword WarAndPeace.txt count
Parsing WarAndPeace.txt (mode=count)
Finished parsing.
Found a total of 565527 words.
Total runtime (wall clock) : 1061 ms
                              

avec release et trace
565500: to
Finished parsing.
Found a total of 565527 words.
Total runtime (wall clock) : 113 ms


avec release sans trace:

┌──(ania㉿kali)-[~/PSCR-TME/TME2]
└─$ ./build-release/countword WarAndPeace.txt count
Parsing WarAndPeace.txt (mode=count)
Finished parsing.
Found a total of 565527 words.
Total runtime (wall clock) : 96 ms
                                    

## Question 3

──(ania㉿kali)-[~/PSCR-TME/TME2]
└─$ ./build-release/countword WarAndPeace.txt unique
Parsing WarAndPeace.txt (mode=unique)
Found 20332 unique words.
Total runtime (wall clock) : 1436 ms

## Question 4

## Question 5

└─$ ./build-debug/countword WarAndPeace.txt freq
Parsing WarAndPeace.txt (mode=freq)
the:34562
and:22148
to:16709
of:14990
a:10513
he:9809
in:8800
his:7965
that:7806
was:7327
Total runtime (wall clock) : 10400 ms

## Question 6

## Question 7

## Question 8

## Question 9
comparaison entre les deux resultats:
──(ania㉿kali)-[~/PSCR-TME/TME2]
└─$ ./build-debug/countword WarAndPeace.txt freq    
Parsing WarAndPeace.txt (mode=freq)
the:34562
and:22148
to:16709
of:14990
a:10513
he:9809
in:8800
his:7965
that:7806
was:7327
Total runtime (wall clock) : 10660 ms
                                                                                                                                                                                                                
┌──(ania㉿kali)-[~/PSCR-TME/TME2]
└─$ ./build-debug/countword WarAndPeace.txt freqhash
Parsing WarAndPeace.txt (mode=freqhash)
the:34562
and:22148
to:16709
of:14990
a:10513
he:9809
in:8800
his:7965
that:7806
was:7327
Total runtime (wall clock) : 1183 ms

┌──(ania㉿kali)-[~/PSCR-TME/TME2]
└─$ ./build-debug/countword WarAndPeace.txt freqhash
Parsing WarAndPeace.txt (mode=freqhash)
Total runtime (wall clock) : 1271 ms
                                                                                                                                                                                                                
┌──(ania㉿kali)-[~/PSCR-TME/TME2]
└─$ ./build-debug/countword WarAndPeace.txt freq    
Parsing WarAndPeace.txt (mode=freq)

Total runtime (wall clock) : 11339 ms


On remarque que plus la taille initiale de la table de hachage augmente, plus le temps d'exécution tend à diminuer. En effet, lorsque le nombre de buckets augmente, les collisions sont généralement moins nombreuses. Il y a donc moins d'entrées à parcourir dans chaque liste chaînée, ce qui accélère les recherches et les insertions.

Mais comme notre table ne grandie jamais, les performances peuvent vite se degrader si le nombre d'entrée augmente.


pour 10000 buckets:
┌──(ania㉿kali)-[~/PSCR-TME/TME2]
└─$ ./build-debug/countword WarAndPeace.txt freqhash
Parsing WarAndPeace.txt (mode=freqhash)
Total runtime (wall clock) : 1350 ms
                                        
Pour 1024 buckets:
┌──(ania㉿kali)-[~/PSCR-TME/TME2]
└─$ ./build-debug/countword WarAndPeace.txt freqhash
Parsing WarAndPeace.txt (mode=freqhash)
Total runtime (wall clock) : 1426 ms

Pour 100 buckets:
┌──(ania㉿kali)-[~/PSCR-TME/TME2]
└─$ ./build-debug/countword WarAndPeace.txt freqhash
Parsing WarAndPeace.txt (mode=freqhash)
Total runtime (wall clock) : 2417 ms

## Question 10 (bonus)
