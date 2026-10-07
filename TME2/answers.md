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

## Question 6

## Question 7

## Question 8

## Question 9

## Question 10 (bonus)
